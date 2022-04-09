//
// Created by Дмитрий on 27.03.2022.
//

#ifndef OOP_LAB3_IFSTRUCT_H
#define OOP_LAB3_IFSTRUCT_H
#include <string>
#include <vector>

using namespace std;

class IfStruct {

public:
    IfStruct(string condition, string body);
    IfStruct();

    const string &getCondition() const;

    const string &getBody() const;

private:
    string condition;
    string body;

    static vector<string> split(const string& s, const string& delimiter);

    static string extractBody(const string &text);

    static string extractCondition(const string& text);

public:
    static vector<IfStruct> extractAndProcessIf(const string& text);
};

#endif //OOP_LAB3_IFSTRUCT_H
