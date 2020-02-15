//
// Created by BK Allen on 2/13/20.
//

#include <iostream>
#include <vector>
#include <cassert>
#include <fstream>
#include "functions.h"
#include "mystring.h"

/// @brief This function displays the formatted text to the screen.
/// @param text pre-processed data
void Functions::display(vector<HW3::my_string> &text) {
    /// @brief readability
    std::cout << std::endl;
    for (const auto &i : text) {
        cout << i << endl;
    }
}

/// @brief This function writes the formatted text to the file "output.dat"
/// @param text pre-processed data
void Functions::toFile(vector<HW3::my_string> &text) {
    ofstream outfile("../output.dat");
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
/// @param width
/// @param lines
void Functions::formatText(ifstream &infile, const unsigned int &width, vector<HW3::my_string> &lines) {

    HW3::my_string iOString; // used for read in and out going text
    iOString.reserve(1024); // reserves space to prevent resize
    HW3::my_string tempString; // houses intermediate my_string
    tempString.reserve(1024); // reserves space to prevent re-sizing
    unsigned place = 0; // Keeps track of the character number
    unsigned int _width = width; // _width is a modifiable width, to increase the char read loop by one if the first is a space
    bool first = true; // Keeps track if the character is the first on the line (to eliminate a first char space)

    for (int i = 0; infile.peek() != EOF; i++) {
        getline(infile, iOString);
        tempString += iOString + " ";
    }
    iOString = "";

    while (place < tempString.length() - 1) {
        for (int loop = 0;
                 loop < _width && place < tempString.length() - 1;
                 loop++) { //for loop control lines written to vector.
            if (first && tempString[place] == ' ') { _width++; } // determines if the character is first on a line and also a space, if so increase the _width and skip the write.
            else { iOString += tempString[place]; }
            first = false;// set first = false, as we are through the loop once
            ++place; // increment the place in the original string regardless of space status.
        }
        if (tempString[place - 1] != ' ' &&
            tempString[place - 1] != '.') { // if the word is running over the line then add a -
            iOString += "-";
        }
        lines.push_back(iOString); // push into the vector the completely formatted line
        iOString = "";
        _width = width;
        first = true;
    }
}

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

/// @brief
/// @return
int Functions::loopProgram() {
    std::cout << "\nAnother width? (y/n)" << std::endl;
    std::cout << "\x1b[32m>\x1b[0m";
    char userInput;
    std::cin >> userInput;
    int userInputCap = toupper(userInput);
    return userInputCap;
}///#loopProgram
