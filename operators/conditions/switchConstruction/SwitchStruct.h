//
// Created by Дмитрий on 27.03.2022.
//

#ifndef OOP_LAB3_SWITCHSTRUCT_H
#define OOP_LAB3_SWITCHSTRUCT_H
#include <string>
#include <vector>

using namespace std;

class SwitchStruct {
    struct Case {
        string conditional;
        string body;
    };
public:

    SwitchStruct(string conditions, const vector<Case>& body);

    SwitchStruct();
    static vector<SwitchStruct> extractAndProcessSwitch(const string& text);

private:
    string conditions;
    vector<Case> body;
public:
    const string &getConditions() const;

private:

    static vector<string> split(const string &s, const string &delimiter);

private:
    static vector<Case> extractBody(string text);

    static string extractCondition(const string& text);
};

#endif //OOP_LAB3_SWITCHSTRUCT_H
