//
// Created by Дмитрий on 27.03.2022.
//

#include "SwitchStruct.h"
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
    int i = 0;
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

string SwitchStruct::extractBody(string text) {
    text.erase(0, text.find('{') + 1);

    return text.substr(text.find('{') + 1, text.find('}') - text.find('{') - 1);
}

string SwitchStruct::extractCondition(const string& text) {
    return text.substr(0, text.find(')'));
}

SwitchStruct::SwitchStruct(string conditions, string body) : conditions(std::move(conditions)), body(std::move(body)) {}

SwitchStruct::SwitchStruct() = default;
