//
// Created by Дмитрий on 27.03.2022.
//

#include "SwitchStruct.h"
#include <regex>
#include <utility>

vector<SwitchStruct> SwitchStruct::extractAndProcessSwitch(const string &text) {
    vector<string> switchVector = split(text, "switch(");
    vector<SwitchStruct> switchStorage;
    for (int i = 1; i < switchVector.size(); i++) {
        string condition = extractCondition(switchVector[i]);
        string body = extractBody(switchVector[i]);
        SwitchStruct switchElement (condition, body);
        switchStorage.push_back(switchElement);
    }
    return switchStorage;
}
vector<string> SwitchStruct::split(const string &s, const string &delimiter) {
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
struct Case {
    string conditional;
    string body;
};
string SwitchStruct::extractBody(string text) {
//    Case caseObj;
//    vector<Case> caseVector;
    string code = text.erase(0, text.find('{') + 1);
    code = code.substr(code.find('{') + 1, code.find('}') - code.find('{') - 1);
//    vector<string> caseElement = split(code, "case");

//    for (int j = 1; j < caseElement.size(); j++) {
//        caseElement[j] = regex_replace(regex_replace(caseElement[j],regex("\t"),""),
//                      regex("\n"),
//                      "") ;
//
//        caseElement[j] = regex_replace(caseElement[j],regex(" "),"");
//
//        caseObj.conditional = caseElement[j].substr(0, caseElement[j].find(':'));
//
//        if (caseElement[j].find("break") == -1){
//            caseObj.body =  caseElement[j].substr(caseElement[j].find(':') + 1);
//        } else {
//            caseObj.body =  caseElement[j].substr(caseElement[j].find(':') + 1,
//                                                  caseElement[j].find("break") + 5 - caseElement[j].find(':'));
//        }
//
//        caseVector.push_back(caseObj);
//    }
//
//    string defaultElement = split(code, "default")[1];
//    defaultElement = regex_replace(regex_replace(defaultElement,regex("\t"),""),
//                                   regex("\n"),
//                                   "") ;
//    defaultElement = regex_replace(defaultElement,regex(" "),"");
//
//    caseObj.body = defaultElement.substr(defaultElement.find(':'));
//    caseObj.conditional = "";
//    caseVector.push_back(caseObj);

    return code;
}

string SwitchStruct::extractCondition(const string& text) {
    return text.substr(0, text.find(')'));
}

SwitchStruct::SwitchStruct(string conditions, const string& body) : conditions(std::move(conditions)), body(body) {}

const string &SwitchStruct::getConditions() const {
    return conditions;
}

const string &SwitchStruct::getBody() const {
    return body;
}

SwitchStruct::SwitchStruct() = default;


