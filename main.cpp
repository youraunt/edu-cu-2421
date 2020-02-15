

#include <iostream>
#include <fstream>
#include <vector>
#include "mystring.h"
#include "functions.h"

#define WHAT_IS(x) std::cerr << #x << " is " << (x) << std::endl;

using namespace HW3;
//using namespace std;

int main() {

    try {
        while (true) {
            // @brief Logical error on i/o operation
            ///        Fail() = true
            /// @param except, set to failbit, the error
            /// flag here, is a bitmask value of iostate
            std::cin.exceptions(std::istream::failbit);
            /// @brief
            vector<HW3::my_string> formattedText;
            /// @brief delcare variables and file stream
            unsigned int numberOfColumns;
            char inputFile[32] = "../input.dat";
            ifstream infile(inputFile);
            if (!infile || infile.fail()) { Functions::fileNotFound(); }


            numberOfColumns = Functions::setNumberOfColumns();
            Functions::formatText(infile, numberOfColumns, formattedText);

            Functions::display(formattedText);
            Functions::toFile(formattedText);
            int anotherRound = Functions::loopProgram();
            if (anotherRound != 'Y') Functions::exitProgram();
            infile.close();
        }

    } catch (const std::exception &) {
        Functions::unknownInput();
    }///#catch
}