//
// Created by Дмитрий on 27.03.2022.
//

#include "ForStruct.h"

void ForStruct::setBody(const string &body) {
    ForStruct::body = body;
}

void ForStruct::setInitElement(const string &initElement) {
    ForStruct::initElement = initElement;
}

void ForStruct::setConditionElement(const string &conditionElement) {
    ForStruct::conditionElement = conditionElement;
}

void ForStruct::setIncrementElement(const string &incrementElement) {
    ForStruct::incrementElement = incrementElement;
}

ForStruct::ForStruct(const string &body, const string &initElement, const string &conditionElement,
                     const string &incrementElement) : body(body), initElement(initElement),
                                                       conditionElement(conditionElement),
                                                       incrementElement(incrementElement) {}
