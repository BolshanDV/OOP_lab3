//
// Created by Дмитрий on 27.03.2022.
//

#include "Parser.h"
#include <regex>
#include "fstream"

vector<Parser> Parser::extract(const string& initialText) {
//    setFor(ForStruct::extractAndProcessFors(initialText));
//    setIf(IfStruct::extractAndProcessIf(initialText));
//    setSwitch(SwitchStruct::extractAndProcessSwitch(initialText));
        vector<Parser> parserList;
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
                parserList.push_back(item);
                continue;
            }
            if (type == "or(") {
                vector<ForStruct> forStorage = ForStruct::extractAndProcessFors(initialText);
                item.setFor(forStorage[forCounter]);
                forCounter++;
                parserList.push_back(item);
                continue;
            }
            if (type == "ch(") {
                vector<SwitchStruct> switchStorage = SwitchStruct::extractAndProcessSwitch(initialText);
                item.setSwitch(switchStorage[switchCounter]);
                switchCounter++;
                parserList.push_back(item);
                continue;
            }
        }
//    setMainStorage(parserList);
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

void Parser::createText(const vector<Parser>& arr) {
    for (const auto & i : arr) {
        string item;
        if ( !i.getFor().getConditionElement().empty()) {
            int num = countSign(i.getFor().getBody());
            if (!i.getFor().getBody().empty()) {
                if (num == 1) {
                    item = "for(" + i.getFor().getInitElement() +
                           ";" +
                           i.getFor().getConditionElement() +
                           ";" +
                           i.getFor().getIncrementElement() +
                           ")\n\t" +
                           i.getFor().getBody() +
                           "\n\n";
                } else {
                    item = "for(" + i.getFor().getInitElement() +
                           ";" +
                           i.getFor().getConditionElement() +
                           ";" +
                           i.getFor().getIncrementElement() +
                           "){\n" +
                           i.getFor().getBody() +
                           "\n}\n";
                }
            } else {
                item = "for(" + i.getFor().getInitElement() +
                       ";" +
                       i.getFor().getConditionElement() +
                       ";" +
                       i.getFor().getIncrementElement() +
                       ");";
            }
            creatureReadyFile(item);
            continue;
        }
        if ( !i.getIf().getCondition().empty()) {
            int num = countSign(i.getIf().getBody());
            if (num == 1) {
                item = "if(" + i.getIf().getCondition() +
                       ")\n\t" +
                       i.getIf().getBody();
            } else {
                item = "if(" + i.getIf().getCondition() +
                       "){\n\t" +
                       i.getIf().getBody()+
                       "}";
            }
            creatureReadyFile(item);
            continue;
        }
        if ( !i.getSwitch().getConditions().empty()){
            item = "switch( " + i.getSwitch().getConditions() + "){" +
                    i.getSwitch().getBody() + "}";
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

