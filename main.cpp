#include <iostream>
#include "fstream"
#include "parser/Parser.h"
#include "FileHandler.h"
#include <filesystem>

using namespace std;
using namespace std::filesystem;

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
    string i = current_path();

    if (!exists("/Users/dmitrij/CLionProjects/OOP_lab3/input")) {
        cout << "Input directory doesn't exist" << endl;
        return 0;
    }
    if (!exists("/Users/dmitrij/CLionProjects/OOP_lab3/output")) {
        create_directory("/Users/dmitrij/CLionProjects/OOP_lab3/output");
    }

    char fileNameIter = '1';
    for (const directory_entry dir : directory_iterator("/Users/dmitrij/CLionProjects/OOP_lab3/input")) {
        FileHandler file(dir.path(), "/Users/dmitrij/CLionProjects/OOP_lab3/output", fileNameIter);
        file.handleFile();
        fileNameIter++;
    }
    cout << "Successful" << endl;
    return 0;
}
