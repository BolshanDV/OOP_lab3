//
// Created by Дмитрий on 27.03.2022.
//

#include "IfStruct.h"
#include <iostream>
#include <utility>
#include <regex>


IfStruct::IfStruct() = default;

IfStruct::IfStruct(string condition, string body) : condition(std::move(condition)), body(std::move(body)) {}

vector<IfStruct> IfStruct::extractAndProcessIf(const string& text) {
    vector<string> ifVector = split(text, "if(");
    vector<IfStruct> ifStorage;
    for (int i = 1; i < ifVector.size(); i++) {
        string body = extractBody(ifVector[i]);
        string condition = extractCondition(ifVector[i]);
        IfStruct ifElement (condition, body);
        ifStorage.push_back(ifElement);
    }
    return ifStorage;
}

vector<string> IfStruct::split(const string &s, const string &delimiter) {
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

string IfStruct::extractBody(const string& text) {
    string code = text.substr(text.find('{') + 1, text.find('}') - text.find('{') - 1);
    code = regex_replace(regex_replace(code,regex("\t"),""),
                                   regex("\n"),
                                   "") ;
    return code;
}

string IfStruct::extractCondition(const string& text) {
    return text.substr(0, text.find(')'));
}

