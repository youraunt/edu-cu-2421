//
// Created by BK Allen on 2/13/20.
//


#include "functions.h"
#include "mystring.h"

/// @brief This function displays the formatted text to the screen.
/// @param text pre-processed data
void Functions::display(std::vector<HW3::my_string> &text) {
    /// @brief readability
    std::cout << std::endl;
    for (const auto &i : text) {
        std::cout << i << std::endl;
    }
}

/// @brief This function writes the formatted text to the file "output.dat"
/// @param text pre-processed data
void Functions::toFile(std::vector<HW3::my_string> &text) {
    std::ofstream outfile("../output.dat");
    if (!outfile.is_open()) {
        Functions::fileNotFound();
    }
    for (const auto &i : text) {
        outfile << i << std::endl;
    }
    outfile.close();
}

/// @brief This function formats the text to the users desired width by column value.
/// @param infile file stream
/// @param width The number of columns to format to
/// @param line Vector to hold the data
HW3::my_string
Functions::processInput(std::istream &infile, std::vector<HW3::my_string> &line, const unsigned int &width) {
    /// @brief declare local variable and allocate 128 bytes for each char array
    HW3::my_string iOString = "\0";
    iOString.reserve(1024);
    HW3::my_string tempString = "\0";
    tempString.reserve(1024);
    auto charNumber = 0;
    auto _width = width;
    auto first = true;
    /// @brief Reads in from file to iOString then concatenates with space into tempString
    for (auto i = 0; infile.peek() != EOF; i++) {
        getline(infile, iOString);
        tempString += iOString + " ";
    }
    /// @brief clears ioString or sets to "\0" ie NULL
    iOString = "\0";
    /// @brief formats data to user specified with
    /// @brief using _width so I can alter the width for blank chars at head of line
    while (charNumber < tempString.length() - 1) {
        for (auto loop = 0; loop < _width && charNumber < tempString.length() - 1; loop++) {
            ///@brief This prevents writing whitespace unnecessarily
            if (first && tempString[charNumber] == ' ') { _width++; }
            else { iOString += tempString[charNumber]; }
            /// @brief exit one loop
            first = false;
            ++charNumber;
        }
        /// @brief adds the '-' hyphen if the word is running over
        if (tempString[charNumber - 1] != '.'
            && tempString[charNumber - 1] != ' '
            && charNumber != tempString.length()-1) {
            iOString += "-";
        }

        /// @brief to vector
        line.push_back(iOString);
        iOString = "\0";
        _width = width;
        first = true;
    }///#while
    return "\0";
}///#processInput

/// @brief This function handles user input
/// in regards to the number of columns.
/// @return userInput if valid data is entered.
int Functions::setNumberOfColumns() {
    int userInput;
    while (true) {
        std::cout << "\nThis program lets you select the width of text by column number. " << std::endl
                  << "How many columns wide would you like your text to be \x1b[30;42m?\x1b[0m" << std::endl
                  << "For reference, the above highlighted question mark is 55 columns wide." << std::endl
                  << "\x1b[32m>\x1b[0m";
        std::cin >> userInput;
        if (userInput > 0) {
            return userInput;
        } else if (userInput <= 0) {
            std::cout << "\n\x1b[31mYour userInput must be a positive integer!\n\x1b[0m" << std::endl;
        } else {
            return false;
        }
    }///#while
}///#setNumberOfColumns

/// @brief This function checks to see if the user wants to
///     format the text to another width.
/// @return capitalized user input
int Functions::loopProgram() {
    std::cout << "\nAnother width? (y/n)" << std::endl;
    std::cout << "\x1b[32m>\x1b[0m";
    char userInput;
    std::cin >> userInput;
    int userInputCap = toupper(userInput);
    return userInputCap;
}///#loopProgram
