

#include <iostream>
#include <fstream>
#include <vector>
#include "mystring.h"
#include "functions.h"

#define WHAT_IS(x) std::cerr << #x << " is " << (x) << std::endl;

using namespace Functions;
//using namespace std;

int main() {
    /// @brief
    vector<Functions::my_string> formattedText;
    /// @brief
    unsigned int columns;
    try {
        // @brief Logical error on i/o operation
        ///        Fail() = true
        /// @param except, set to failbit, the error
        /// flag here, is a bitmask value of iostate
        std::cin.exceptions(std::istream::failbit);

        ifstream InFile("../input.dat"); // open the input file
        if (!InFile.is_open())
            return 0;

        columns = Functions::getWidth(); // get number of columns for output //
        Functions::Format_Input(InFile, columns, formattedText); //

        InFile.close(); // close input file

        Functions::displayOutput(formattedText); // Print the output to the screen

        Functions::SaveOutput(formattedText); // output data to file
    } catch (const std::exception &) {
        cerr << "shit" << endl;
    }///#catch
}