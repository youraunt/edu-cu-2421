

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
        // @brief Logical error on i/o operation
        ///        Fail() = true
        /// @param except, set to failbit, the error
        /// flag here, is a bitmask value of iostate
        std::cin.exceptions(std::istream::failbit);
        /// @brief
        vector<HW3::my_string> formattedText;
        /// @brief
        unsigned int numberOfColumns;
        ifstream infile("../input.dat"); // open the input file
        if (!infile.is_open())
            return 0;


        numberOfColumns = Functions::setNumberOfColumns(); // get number of numberOfColumns for output //
        Functions::formatText(infile, numberOfColumns, formattedText); //

        infile.close(); // close input file

        Functions::display(formattedText); // Print the output to the screen

        Functions::toFile(formattedText); // output data to file
    } catch (const std::exception &) {
        Functions::unknownInput();
    }///#catch
}