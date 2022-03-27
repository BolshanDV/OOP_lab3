//
// Created by Дмитрий on 27.03.2022.
//

#include "Parser.h"
#include <regex>

void Parser::extract(const string& initialText) {
    extractAndProcessFors(initialText);
}

void Parser::extractAndProcessFors(const string& text) {
    vector<string> fors = split(text, "for(");
//    vector<ForStruct> Fors;
    for (int i = 1; i < fors.size(); i++) {
        string type = processForType(fors[i]);

        vector<string> conditionals = extractConditionals(fors[i]);
        string body = extractBody(fors[i], type);
        ForStruct forElement (body, conditionals[0], conditionals[1], conditionals[2]);
//        Fors.push_back(forElement);
        setFor(forElement);
    }
}

vector<string> Parser::split(const string& s, const string& delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

void Parser::setFor(const ForStruct &forElement) {
    For.push_back(forElement);
}

string Parser::leftTrim(string str) {
    string chars = "/ ";
    str.erase(0, str.find_first_not_of(chars));
    return str;
}

string Parser::processForType(string &forBlock) {
    forBlock = regex_replace(regex_replace(
                                     forBlock,
                                     regex("\t"),
                                     ""),
                             regex("\n"),
                             "") ;
    string extractedBody = leftTrim(split(forBlock, ")")[1]);
    extractedBody = extractedBody.substr(0, extractedBody.find(';'));
    string type;

    if (extractedBody.find('{') != -1) { type = "ClassicFor"; }
    else if(extractedBody.empty()) { type = "NotValidFor"; }
    else { type = "ForWithoutBrackets"; }
    // if check throw with exception
    return type;
}

vector<string> Parser::extractConditionals(const string &stringifyFor) {
    vector<string> conditionals;
    string stringifyForElement =  stringifyFor;
    stringifyForElement.insert(0, 1, '(');
    stringifyForElement = split(split(stringifyForElement, "(")[1], ")")[0];
    conditionals = split(stringifyForElement, ";");
    return conditionals;
}

string Parser::extractBody(const string &body, const string &type) {
    string bodyCode;

    if (type == "ClassicFor") bodyCode = extractClassicBodyLines(body);
    if (type == "ForWithoutBrackets") bodyCode = extractWithoutBracketsBodyLines(body);
//    if (type == "NotValidFor") bodyVector = extractOtherText(body);

    return bodyCode;
}
string Parser::extractClassicBodyLines(const string &forBlock) {
    // Double split text
    string splitedText = split(split(forBlock, "{")[1], "}")[0];
    // Replace all \n and " " to ""
    splitedText = regex_replace(regex_replace(splitedText, regex("\n"), ""), regex(" "), "");

    return splitedText;
}
string Parser::extractWithoutBracketsBodyLines(const string &forBlock) {
    string splitedText = split(split(forBlock, ")")[1], ";")[0];
    splitedText = regex_replace(
            regex_replace(splitedText, regex("\n"), ""), regex(" "), "");

    return splitedText;
}

const vector<ForStruct> &Parser::getFor() const {
    return For;
}

const vector<IfStruct> &Parser::getIf() const {
    return If;
}

const vector<SwitchStruct> &Parser::getSwitch() const {
    return Switch;
}
