//
// Created by Дмитрий on 17.04.2022.
//

#ifndef OOP_LAB3_FILEHANDLER_H
#define OOP_LAB3_FILEHANDLER_H

#include "fstream"
#include <iostream>
#include <filesystem>
#include "parser/Parser.h"


using namespace std::filesystem;
using namespace std;


class FileHandler {

private:
    string inputText;
    string outputText;
    path inputDir;
    path outputDir;
    fstream file;
public:
    FileHandler(path inputDir, path outputDir, char fileNameIter) {
        this->inputDir = inputDir;

        string fileName = "output().txt";
        fileName.insert(7, 1, fileNameIter);

        this->outputDir = outputDir / fileName;
    }
    string addOutput(string text) {
        outputText = outputText + '\n' + text;
        return text;
    }
    string getInput() {
        return inputText;
    }
    string* getInputPtr() {
        return &inputText;
    }
    void readFile() {
        file.open(inputDir, fstream::in);
        string line;
        if (file.is_open()) {
            while (getline(file, line)) {
                inputText += line + '\n';
            }
        }
        else {
            cout << "Error during reading file" << endl;
        }
        file.close();
    }
    void writeFile() {
        file.open(outputDir, fstream::out);
        if (file.is_open()) {
            file << outputText << endl;
        }
        else {
            cout << "Error during writing file" << endl;
        }
        file.close();
    }

    int countSign(const string &body) {
        int counter = 0;
        for (char i : body) {
            if (i == ';') {
                counter++;
            }
        }
        return counter;
    }

    void handleFile() {
        this->readFile();
        Parser parser;
        string initialText = getInput();
        List<Parser> arr = parser.extract(initialText);
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
                    }
                    if (num == 0) {
                        item = "for(" + arr[i].getFor().getInitElement() +
                               ";" +
                               arr[i].getFor().getConditionElement() +
                               ";" +
                               arr[i].getFor().getIncrementElement() +
                               ")\n\t" +
                               arr[i].getFor().getBody() + ';'+
                               "\n\n";
                    }
                } else {
                    item = "for(" + arr[i].getFor().getInitElement() +
                           ";" +
                           arr[i].getFor().getConditionElement() +
                           ";" +
                           arr[i].getFor().getIncrementElement() +
                           ");";
                }
                addOutput(item);
                continue;
            }
            if ( !arr[i].getIf().getCondition().empty()) {
                int num = countSign(arr[i].getIf().getBody());
                if (num == 1) {
                    item = "if(" + arr[i].getIf().getCondition() +
                           ")\t" +
                           arr[i].getIf().getBody();
                } else {
                    item = "if(" + arr[i].getIf().getCondition() +
                           ") {\t" +
                           arr[i].getIf().getBody()+
                           "}";
                }
                addOutput(item);
                continue;
            }
            if ( !arr[i].getSwitch().getConditions().empty()){
                item = "switch(" + arr[i].getSwitch().getConditions() + ") {" +
                       arr[i].getSwitch().getBody() + "}";
                addOutput(item);
                continue;
            }
        }
        writeFile();
    }
};


#endif //OOP_LAB3_FILEHANDLER_H
