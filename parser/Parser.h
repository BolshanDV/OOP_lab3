//
// Created by Дмитрий on 27.03.2022.
//

#ifndef OOP_LAB3_PARSER_H
#define OOP_LAB3_PARSER_H
#include <vector>
#include <iostream>
#include "../operators/cycle/ForStruct.h"
#include "../operators/conditions/ifConstruction/IfStruct.h"
#include "../operators/conditions/switchConstruction/SwitchStruct.h"

using namespace std;


class Parser {
private:
    vector<ForStruct> For;
    vector<IfStruct> If;
    vector<SwitchStruct> Switch;

public:
    [[nodiscard]] const vector<ForStruct> &getFor() const;

    [[nodiscard]] const vector<SwitchStruct> &getSwitch() const;

    [[nodiscard]] const vector<IfStruct> &getIf() const;

    void setFor (const vector<ForStruct>& forElement);

    void setIf (const vector<IfStruct>& ifElement);

    void setSwitch (const vector<SwitchStruct>& switchElement);

    void extract (const string& initialText);

};



#endif //OOP_LAB3_PARSER_H
