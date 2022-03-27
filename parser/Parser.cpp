//
// Created by Дмитрий on 27.03.2022.
//

#include "Parser.h"
#include <regex>

void Parser::extract(const string& initialText) {
    setFor(ForStruct::extractAndProcessFors(initialText));
    setIf(IfStruct::extractAndProcessIf(initialText));
    setSwitch(SwitchStruct::extractAndProcessSwitch(initialText));
}
void Parser::setFor(const vector<ForStruct>& forElement) {
    this->For = forElement;
}

const vector<ForStruct> &Parser::getFor() const {
    return For;
}

const vector<IfStruct> &Parser::getIf() const {
    return If;
}

const vector<SwitchStruct> &Parser::getSwitch() const {
    return Switch;
}

void Parser::setIf(const vector<IfStruct> &ifElement) {
    this->If = ifElement;
}

void Parser::setSwitch(const vector<SwitchStruct> &switchElement) {
    this-> Switch = switchElement;
}
