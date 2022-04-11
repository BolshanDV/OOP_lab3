//
// Created by Дмитрий on 27.03.2022.
//

#include "Parser.h"
#include <regex>
#include "../ListStruct/List.h"
#include "fstream"
List<Parser> Parser::extract(const string& initialText) {
//    setFor(ForStruct::extractAndProcessFors(initialText));
//    setIf(IfStruct::extractAndProcessIf(initialText));
//    setSwitch(SwitchStruct::extractAndProcessSwitch(initialText));
//        vector<Parser> parserList;
        List<Parser> parserList;
        int ifCounter = 0;
        int forCounter = 0;
        int switchCounter = 0;
        for (int i = 0; i <= initialText.length(); i++) {
            Parser item;
            string type;
            type = type + initialText[i] + initialText[i + 1] + initialText[i + 2];
            if (type == "if(") {
                vector<IfStruct> ifStorage = IfStruct::extractAndProcessIf(initialText);
                item.setIf(ifStorage[ifCounter]);
                ifCounter++;
                parserList.pushBack(item);
                continue;
            }
            if (type == "or(") {
                vector<ForStruct> forStorage = ForStruct::extractAndProcessFors(initialText);
                item.setFor(forStorage[forCounter]);
                forCounter++;
                parserList.pushBack(item);
                continue;
            }
            if (type == "ch(") {
                vector<SwitchStruct> switchStorage = SwitchStruct::extractAndProcessSwitch(initialText);
                item.setSwitch(switchStorage[switchCounter]);
                switchCounter++;
                parserList.pushBack(item);
                continue;
            }
        }
    return parserList;
}
void Parser::setFor(const ForStruct& forElement) {
    this->For = forElement;
}

void Parser::setIf(const IfStruct &ifElement) {
    this->If = ifElement;
}

void Parser::setSwitch(const SwitchStruct &switchElement) {
    this-> Switch = switchElement;
}

void Parser::createText( List<Parser> arr) {
    for (int i = 0; i < arr.getSize() ; i++) {
        string item;
        if ( !arr[i].getFor().getConditionElement().empty()) {
            int num = countSign(arr[i].getFor().getBody());
            if (!arr[i].getFor().getBody().empty()) {
                if (num == 1) {
                    item = "for(" + arr[i].getFor().getInitElement() +
                           ";" +
                            arr[i].getFor().getConditionElement() +
                           ";" +
                            arr[i].getFor().getIncrementElement() +
                           ")\n\t" +
                            arr[i].getFor().getBody() +
                           "\n\n";
                } else {
                    item = "for(" + arr[i].getFor().getInitElement() +
                           ";" +
                            arr[i].getFor().getConditionElement() +
                           ";" +
                            arr[i].getFor().getIncrementElement() +
                           "){\n" +
                            arr[i].getFor().getBody() +
                           "\n}\n";
                }
            } else {
                item = "for(" + arr[i].getFor().getInitElement() +
                       ";" +
                        arr[i].getFor().getConditionElement() +
                       ";" +
                        arr[i].getFor().getIncrementElement() +
                       ");";
            }
            creatureReadyFile(item);
            continue;
        }
        if ( !arr[i].getIf().getCondition().empty()) {
            int num = countSign(arr[i].getIf().getBody());
            if (num == 1) {
                item = "if(" + arr[i].getIf().getCondition() +
                       ")\n\t" +
                        arr[i].getIf().getBody();
            } else {
                item = "if(" + arr[i].getIf().getCondition() +
                       "){\n\t" +
                        arr[i].getIf().getBody()+
                       "}";
            }
            creatureReadyFile(item);
            continue;
        }
        if ( !arr[i].getSwitch().getConditions().empty()){
            item = "switch( " + arr[i].getSwitch().getConditions() + "){" +
                    arr[i].getSwitch().getBody() + "}";
            creatureReadyFile(item);
            continue;
        }
    }
}

const ForStruct &Parser::getFor() const {
    return For;
}

const IfStruct &Parser::getIf() const {
    return If;
}

const SwitchStruct &Parser::getSwitch() const {
    return Switch;
}

void Parser::creatureReadyFile(const string &text) {
    ofstream out;
    out.open("/Users/dmitrij/CLionProjects/OOP_lab3/text/result", ios::app);
    out << text << endl;
}

int Parser::countSign(const string &body) {
    int counter = 0;
    for (char i : body) {
        if (i == ';') {
            counter++;
        }
    }
    return counter;
}

