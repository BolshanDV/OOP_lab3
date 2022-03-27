//
// Created by Дмитрий on 27.03.2022.
//

#ifndef OOP_LAB3_FORSTRUCT_H
#define OOP_LAB3_FORSTRUCT_H
#include <string>
#include <vector>

using namespace std;

class ForStruct {

public:
    ForStruct(string body, string initElement, string conditionElement,
              string incrementElement);
    ForStruct();

    static vector<ForStruct> extractAndProcessFors(const string& text);

private:
    string body;
    string initElement;
    string conditionElement;
    string incrementElement;

    static vector<string> split(const string& s, const string& delimiter);

    static string processForType(string &forBlock);

    static string leftTrim(string str);

    static vector<string> extractConditionals( const string& stringifyFor);

    static string extractBody(const string& body, const string& type);

    static string extractClassicBodyLines(const string& forBlock);

    static string extractWithoutBracketsBodyLines(const string& forBlock);

};

#endif //OOP_LAB3_FORSTRUCT_H
