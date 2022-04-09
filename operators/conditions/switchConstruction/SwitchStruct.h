//
// Created by Дмитрий on 27.03.2022.
//

#ifndef OOP_LAB3_SWITCHSTRUCT_H
#define OOP_LAB3_SWITCHSTRUCT_H
#include <string>
#include <vector>

using namespace std;

class SwitchStruct {
public:

    SwitchStruct(string conditions, const string& body);

    SwitchStruct();
    static vector<SwitchStruct> extractAndProcessSwitch(const string& text);

private:
    string conditions;
    string body;
public:
    const string &getConditions() const;

private:

    static vector<string> split(const string &s, const string &delimiter);

private:
    static string extractBody(string text);

public:
    const string &getBody() const;

private:
    static string extractCondition(const string& text);
};

#endif //OOP_LAB3_SWITCHSTRUCT_H
