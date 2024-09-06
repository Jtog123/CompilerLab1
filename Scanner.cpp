//
// Created by jtog8 on 9/5/2024.
//

#include "Scanner.hpp"
#include <fstream>
#include <iostream>

using namespace std;

Scanner::Scanner(const string& filePath)  {
    // open the file
    inputFile.open(filePath);
    cout << "eof?" << inputFile.eof()<< endl;
    if(!inputFile) {
        cerr << "No input file or error opening input file: " << filePath << endl;
        exit(65);
    }
}

void Scanner::readFile() {
    // while we are not at the end of the file
    // gather each char and look for each word
    //char currentChar = inputFile.peek();
    //cout<< currentChar;

    while(! inputFile.eof()) {
        char currentChar = inputFile.peek();

        // WORDS THAT START WITH S
        if(currentChar == 's') {
            inputFile.get();
            char currentChar = inputFile.peek();

            // Current State: S (T | U)
            if(currentChar == 't') {
                inputFile.get();
                char currentChar = inputFile.peek();
                if(currentChar == 'o') {
                    inputFile.get();
                    char currentChar = inputFile.peek();
                    if(currentChar == 'r') {
                        inputFile.get();
                        char currentChar = inputFile.peek();
                        if(currentChar == 'e') {
                            inputFile.get();
                            cout << "GOT STORE" << endl;
                        } else {
                            inputFile.get();

                        }
                    } else {
                        inputFile.get();
                        cout << 'Not r' << endl;
                    }
                } else {
                    inputFile.get();
                    cout << "Not o";
                }

            } else if (currentChar == 'u') {
                inputFile.get();
                char currentChar = inputFile.peek();
                if(currentChar == 'b') {
                    inputFile.get();
                    cout << "GOT SUB!" << endl;
                } else {
                    inputFile.get();
                    cout << "Not b" << endl;
                }

            } else {
                inputFile.get();
                cout << "not T" << endl;
            }

        }
        // Words what start with L {LOAD, LOADL, lSHIFT}
        else if (currentChar == 'l'){
            inputFile.get();
        }
        // Words what start with R {RSHIFT}
        else if( currentChar == 'r') {

        }
        // Words what start with R {MULT}
        else if (currentChar == 'm') {

        }
        // Words what start with R {ADD}
        else if(currentChar == 'a') {

        }
        // Words what start with R {NOP}
        else if(currentChar == 'n') {

        }
        // Words what start with R {OUTPUT}
        else if (currentChar == 'o') {

        }
        else {
            inputFile.get();
            cout << "nothing now" << endl;
        }

    }

}