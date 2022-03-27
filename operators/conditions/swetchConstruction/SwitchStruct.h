//
// Created by Дмитрий on 27.03.2022.
//

#ifndef OOP_LAB3_SWITCHSTRUCT_H
#define OOP_LAB3_SWITCHSTRUCT_H
#include <string>
using namespace std;

class SwitchStruct {
public:
    SwitchStruct(const string &argument, const string &conditions, const string &body);

private:
    string argument;
    string conditions;
    string body;
public:
    void setArgument(const string &argument);

    void setConditions(const string &conditions);

    void setBody(const string &body);

    string print () {
        return argument + conditions + body;
    }
};


#endif //OOP_LAB3_SWITCHSTRUCT_H
