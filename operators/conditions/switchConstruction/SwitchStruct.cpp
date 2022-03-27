//
// Created by Дмитрий on 27.03.2022.
//

#include "SwitchStruct.h"

void SwitchStruct::setArgument(const string &argument) {
    SwitchStruct::argument = argument;
}

void SwitchStruct::setConditions(const string &conditions) {
    SwitchStruct::conditions = conditions;
}

void SwitchStruct::setBody(const string &body) {
    SwitchStruct::body = body;
}

SwitchStruct::SwitchStruct(const string &argument, const string &conditions, const string &body) : argument(argument),
                                                                                                   conditions(
                                                                                                           conditions),
                                                                                                   body(body) {}
