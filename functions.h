//
// Created by BK Allen on 2/13/20.
//

#ifndef _2188HW3_FUNCTIONS_H
#define _2188HW3_FUNCTIONS_H




#include <vector>
#include <iostream>
#include "mystring.h"
using namespace std;
namespace Functions

{
    ifstream Open_Input(int& exist_test, char** filename);
    int getWidth();
    void Format_Input(ifstream& InFile, const unsigned int& text_width, vector<Functions::my_string>& lines);
    void displayOutput(vector<Functions::my_string>& text);
    void SaveOutput(vector<Functions::my_string>& text);
}

#endif //_2188HW3_FUNCTIONS_H
