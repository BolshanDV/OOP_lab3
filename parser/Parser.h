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
    ForStruct For;
    IfStruct If;
    SwitchStruct Switch;
public:

public:
    const ForStruct &getFor() const;

    const IfStruct &getIf() const;

    const SwitchStruct &getSwitch() const;

    void setFor (const ForStruct& forElement);

    void setIf (const IfStruct& ifElement);

    void setSwitch (const SwitchStruct& switchElement);

    void createText (const vector<Parser>& arr);

    vector<Parser> extract (const string& initialText);

    static int countSign (const string& body);

private:
    void creatureReadyFile (const string& text);
};



#endif //OOP_LAB3_PARSER_H
