//
// Created by BK Allen on 2/13/20.
//

#ifndef _2188HW3_FUNCTIONS_H
#define _2188HW3_FUNCTIONS_H


#include <vector>
#include <iostream>
#include "mystring.h"

using namespace std;

class Functions {
private:
     static HW3::my_string ordinal;

public:

   // ifstream Open_Input(int &exist_test, char **filename);

    static int setNumberOfColumns();

    static void formatText(ifstream &infile, const unsigned int &text_width, vector<HW3::my_string> &lines);

    static void display(vector<HW3::my_string> &text);

    static void toFile(vector<HW3::my_string> &text);

    static HW3::my_string setOrdinal(int userInput);

    /// @brief Exits program successfully with message
    inline static std::string exitProgram() {
        std::cout << "Exiting program!" << std::endl;
        /// @brief I used EXIT_SUCCESS here to unwind the stack
        exit(EXIT_SUCCESS);
    }

    static void unknownInput() {
        std::cerr << "\nError?! Unknown input.\n" << std::endl;
        exitProgram();
    }
};

#endif //_2188HW3_FUNCTIONS_H
