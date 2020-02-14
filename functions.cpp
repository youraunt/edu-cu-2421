//
// Created by BK Allen on 2/13/20.
//

#include <iostream>
#include <vector>
#include <cassert>
#include <fstream>
#include "functions.h"
#include "mystring.h"

/// @brief
/// @param text
void Functions::display(vector<HW3::my_string> &text) {
    cout << "The formatted text is:\n";
    for (const auto &i : text) {
        cout << i << endl;
    }
}

/// @brief
/// @param text
void Functions::toFile(vector<HW3::my_string> &text) {
    ofstream outfile("../output.txt"); // open file for output, erases and data.out that exists
    if (!outfile.is_open()) {
        cout << "output.txt did not open\n";
        return;
    }
    for (const auto &i : text) { // send output to file
        outfile << i;
        outfile << endl;
    }
    outfile.close(); // close file
}

/// @brief
/// @param infile
/// @param text_width
/// @param lines
void Functions::formatText(ifstream &infile, const unsigned int &text_width, vector<HW3::my_string> &lines) {
    assert(infile.is_open()); // check a valid open input file.
    HW3::my_string incoming; // used for read in and out going text
    HW3::my_string housing; // houses intermediate my_string
    unsigned place = 0; // Keeps track of the character number
    unsigned int width = text_width; // width is a modifiable text_width, to increase the char read loop by one if the first is a space
    bool first = true; // Keeps track if the character is the first on the line (to eliminate a first char space)
    housing.reserve(1024); // reserves space to prevent re-sizing
    incoming.reserve(1024); // reserves space to prevent resize
    for (int i = 0; !infile.eof(); i++) {
        getline(infile, incoming);
        housing += incoming + " ";
    }
    incoming = "";

    while (place < housing.length() - 1) {
        for (int loop = 0;
             loop < width && place < housing.length() - 1; loop++) { //for loop control lines written to vector.
            if (first && housing[place] ==
                         ' ') { width++; } // determines if the character is first on a line and also a space, if so increase the width and skip the write.
            else { incoming += housing[place]; }
            first = false;// set first = false, as we are through the loop once
            ++place; // increment the place in the original string regardless of space status.
        }
        if (housing[place - 1] != ' ' &&
            housing[place - 1] != '.') { // if the word is running over the line then add a -
            incoming += '-';
        }
        lines.push_back(incoming); // push into the vector the completely formatted line
        incoming = "";
        width = text_width;
        first = true;
    }
}

/// @brief
/// @return
int Functions::setNumberOfColumns() {
    int input;
    while (true) {
        std::cout << "This program lets you select the width of text by column number. " << std::endl
                  << "How many columns wide would you like your text to be \x1b[30;42m?\x1b[0m" << std::endl
                  << "For reference, the above highlighted question mark is 55 columns wide." << std::endl
                  << "> ";
        std::cin >> input;
        if (input > 0) {
            return input;
        } else if (input <= 0) {
            std::cout << "\n\x1b[31mYour input must be a positive integer!\n\x1b[0m" << std::endl;
        } else {
            return false;
        }
    }///#while
}///#setNumberOfColumns


/// @brief sets the ordinal of k
/// @param userInput integer value of k
/// @return string value of matching ordinal
//HW3::my_string Functions::setOrdinal(int userInput) {
//    ordinal = userInput % 100 == 1 ? "st"
//            : userInput % 100 == 2 ? "nd"
//            : userInput % 100 == 3 ? "rd"
//            : "th";
//    return ordinal;
//}///#setOrdinal