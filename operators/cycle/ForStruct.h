//
// Created by Дмитрий on 27.03.2022.
//

#ifndef OOP_LAB3_FORSTRUCT_H
#define OOP_LAB3_FORSTRUCT_H
#include <string>
#include <vector>

using namespace std;

class ForStruct {
public:
    ForStruct(const string &body, const string &initElement, const string &conditionElement,
              const string &incrementElement);

private:
    string body;
    string initElement;
    string conditionElement;
    string incrementElement;
public:
    string print() {
        return incrementElement + conditionElement + incrementElement + body;
    }
};


#endif //OOP_LAB3_FORSTRUCT_H
