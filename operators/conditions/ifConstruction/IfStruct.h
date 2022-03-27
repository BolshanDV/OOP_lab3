//
// Created by Дмитрий on 27.03.2022.
//

#ifndef OOP_LAB3_IFSTRUCT_H
#define OOP_LAB3_IFSTRUCT_H
#include <string>
using namespace std;


class IfStruct {
public:
    IfStruct(const string &condition, const string &body);

private:
    string condition;
    string body;
public:
    void setCondition(const string &condition);

    void setBody(const string &body);

    void print ();
};


#endif //OOP_LAB3_IFSTRUCT_H
