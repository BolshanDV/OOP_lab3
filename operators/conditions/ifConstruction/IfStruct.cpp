//
// Created by Дмитрий on 27.03.2022.
//

#include "IfStruct.h"


void IfStruct::setCondition(const string &condition) {
    IfStruct::condition = condition;
}

void IfStruct::setBody(const string &body) {
    IfStruct::body = body;
}

IfStruct::IfStruct(const string &condition, const string &body) : condition(condition), body(body) {}
