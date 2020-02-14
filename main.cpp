#include <iostream>
#include "functions.h"
#include "mystring.h"


#include <iostream>
#include <fstream>
#include <vector>
#include "mystring.h"
#include "functions.h"

#define WHAT_IS(x) std::cerr << #x << " is " << (x) << std::endl;

using namespace Functions;
//using namespace std;

int main() {
    try {
        // @brief Logical error on i/o operation
        ///        Fail() = true
        /// @param except, set to failbit, the error
        /// flag here, is a bitmask value of iostate
        std::cin.exceptions(std::istream::failbit);
        /// @brief
        int number_of_columns;
        /// @brief
        vector<Functions::my_string> formatted_text;

        ifstream InFile("../data.txt"); // open the input file
        if (!InFile.is_open())
            return 0;

        number_of_columns = Functions::getWidth(); // get number of columns for output //
        Functions::Format_Input(InFile, number_of_columns, formatted_text); //

        InFile.close(); // close input file

        Functions::displayOutput(formatted_text); // Print the output to the screen

        Functions::SaveOutput(formatted_text); // output data to file
    } catch (const std::exception &) {
        cerr << "shit" << endl;
    }///#catch
}