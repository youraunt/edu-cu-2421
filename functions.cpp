//
// Created by BK Allen on 2/13/20.
//

#include <iostream>
#include <vector>
#include <cassert>
#include <fstream>
#include "functions.h"
#include "mystring.h"

namespace Functions
{
    int getWidth(){
        int text_width;
        char input[25] = "a"; // used as an intermediate input to check number value is entered
        while (!isdigit(input[0]) || atoi(input) < 1){ // loop until a digit is inupt for the width
            cout << "How many columns wide should the output be?\n";
            cin >> input;
            if (isdigit(input[0]) && atoi(input) > 0){
                text_width = atoi(input); // convert to a int value
                return text_width;
            }
            cout << "Please enter a width as a number greater than 0 EX: 50\n";
        }
        return 0;
    }
    void Format_Input(ifstream& InFile, const int& text_width, vector<Functions::my_string>& lines){
        assert(InFile.is_open()); // check a valid open input file.
        Functions::my_string incoming; // used for read in and out going text
        Functions::my_string housing; // houses intermediate my_string
        unsigned place = 0; // Keeps track of the character number
        int width = text_width; // width is a modifiable text_width, to increase the char read loop by one if the first is a space
        bool first = true; // Keeps track if the character is the first on the line (to eliminate a first char space)
        housing.reserve(1000); // reserves space to prevent re-sizing
        incoming.reserve(1000); // reserves space to prevent resize
        for (int i = 0; !InFile.eof(); i++){
            getline(InFile, incoming);
            housing += incoming + " ";
        }
        incoming = "";

        while (place < housing.length() - 1){
            for (int loop = 0; loop < width && place < housing.length() - 1; loop++){ //for loop control lines written to vector.
                if (first && housing[place] == ' '){ width++; } // determines if the character is first on a line and also a space, if so increase the width and skip the write.
                else{ incoming += housing[place]; }
                first = false;// set first = false, as we are through the loop once
                ++place; // increment the place in the original string regardless of space status.
            }
            if (housing[place - 1] != ' ' && housing[place - 1] != '.'){ // if the word is running over the line then add a -
                incoming += '-';
            }
            lines.push_back(incoming); // push into the vector the completely formatted line
            incoming = "";
            width = text_width;
            first = true;
        }
    }
    void displayOutput(vector<Functions::my_string>& text){
        cout << "The formatted text is:\n";
        for (const auto & i : text){
            cout << i << endl;
        }
    }
    void SaveOutput(vector<Functions::my_string>& text){
        ofstream OutFile("../output.txt"); // open file for output, erases and data.out that exists
        if (!OutFile.is_open()){
            cout << "output.txt did not open\n";
            return;
        }
        for (const auto & i : text){ // send output to file
            OutFile << i;
            OutFile << endl;
        }
        OutFile.close(); // close file
    }
}