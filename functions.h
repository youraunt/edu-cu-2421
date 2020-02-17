//
// Created by BK Allen on 2/13/20.
// This file holds the prototypes for
// functions used in the program
// see implementation file for comments
//

#ifndef _2188HW3_FUNCTIONS_H
#define _2188HW3_FUNCTIONS_H


#include <fstream>
#include <vector>
#include <iostream>
#include "mystring.h"

class Functions {
private:
    static HW3::my_string ordinal;

public:


    static int setNumberOfColumns();

    static HW3::my_string
    (processInput(std::istream &infile, std::vector<HW3::my_string> &line, const unsigned int &width));

    static void display(std::vector<HW3::my_string> &text);

    static void toFile(std::vector<HW3::my_string> &text);

    /// @brief Exits program successfully with message
    static inline std::string exitProgram() {
        std::cout << "Exiting program!" << std::endl;
        /// @brief I used EXIT_SUCCESS here to unwind the stack
        exit(EXIT_SUCCESS);
    }

    static void unknownInput() {
        std::cerr << "\nError?! Unknown input.\n" << std::endl;
        exitProgram();
    }

    static int loopProgram();

    static inline void fileNotFound() {
        std::cerr << "File not found!" << std::endl
                  << "Exiting Program!" << std::endl;
        /// @brief winds down stack
        exit(EXIT_FAILURE);
    }
};

#endif //_2188HW3_FUNCTIONS_H
