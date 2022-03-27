#include <iostream>
#include "fstream"
#include "parser/Parser.h"

using namespace std;

string readingFile() {
    ifstream file("/Users/dmitrij/CLionProjects/OOP_lab3/text/initial");
    string str;
    string content;
    while (getline(file, str)) {
        content += str;
        content.push_back('\n');
    };
    return content;
}

int main() {
    Parser parser;
    string initialText = readingFile();
    parser.extract(initialText);
    vector<ForStruct> i = parser.getFor();
    cout << "Successful" << endl;
    return 0;
}
