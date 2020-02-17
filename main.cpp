/*******************************************************
*  Name         : Brice Allen
*  Student ID   : 107452188
*  Class        : CSC 2421
*  HW#          : 3
*  Due Date     : 11:59 PM Feb. 17, 2020
*  File Name    : 2188HW3
*******************************************************/
#include <iostream>
#include <vector>
#include "mystring.h"
#include "functions.h"

#define WHAT_IS(x) std::cerr << #x << " is " << (x) << std::endl;

using namespace HW3;

/// @brief This is the main function
/// Compilation begins and ends here.
/// @return imnplied zero
int main() {
    try {
        while (true) {
            // @brief Logical error on i/o operation
            ///        Fail() = true
            /// @param except, set to failbit, the error
            /// flag here, is a bitmask value of iostate
            std::cin.exceptions(std::istream::failbit);
            /// @brief declare variables,vector, and file stream.
            std::vector<HW3::my_string> formattedText;
            unsigned int numberOfColumns;
            /// @brief I could not figure out how to use mystring here??
            char inputFile[32] = "input.dat";
            std::ifstream infile(inputFile);
            /// @brief This checks to for a working file stream.
            /// @brief Exits program if files stream is not working.
            if (!infile || infile.fail()) { Functions::fileNotFound(); }
            /// @brief Sets up the number of columns the user prefers. Must be positive integer.
            numberOfColumns = Functions::setNumberOfColumns();
            /// @brief Calls function to format the file text to desired width.
            Functions::processInput(infile, formattedText, numberOfColumns);
            /// @brief A function to display formatted text to screen.
            Functions::display(formattedText);
            /// @brief Writes out to file.
            Functions::toFile(formattedText);
            /// @brief ask user if they want to format the text to a different width
            int anotherRound = Functions::loopProgram();
            /// @brief if y is entered loop program
            /// @brief y is capitalized by the loopProgram function.
            if (anotherRound != 'Y') Functions::exitProgram();
            infile.close();
        }
    } catch (const std::exception &exc) {
        std::cerr << exc.what() << std::endl;
        Functions::unknownInput();
    }///#catch
}