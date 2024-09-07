//
// Created by jtog8 on 9/5/2024.
//

#include "Scanner.hpp"
#include <fstream>
#include <iostream>

using namespace std;

/*
 * Recognize all keywords
 * Assign value to each operation
 * Build tokens?
 */

Scanner::Scanner(const string& filePath)  {
    // open the file
    inputFile.open(filePath);
    cout << "eof?" << inputFile.eof()<< endl;
    if(!inputFile) {
        cerr << "No input file or error opening input file: " << filePath << endl;
        exit(65);
    }
}

//Helper function how badly does the cost modulartity and readability affect the compiler?
bool Scanner::matchNextChar(char expectedChar) {
    char currentChar = inputFile.peek();
    if(currentChar == expectedChar) {
        inputFile.get();
    }
    return currentChar == expectedChar;
}

void Scanner::readFile() {
    // while we are not at the end of the file
    // gather each char and look for each word
    //char currentChar = inputFile.peek();
    //cout<< currentChar;

    //<type of operation, actual characters that where matched in stream>

    while(! inputFile.eof()) {
        char currentChar = inputFile.peek();

        if(currentChar == '\n') {
            cout << "END OF LINE" << endl;
            inputFile.get();
            tokenStream.push_back({EOL, "\\n"});
        }

        // WORDS THAT START WITH S
        if(currentChar == 's') {
            inputFile.get();
            // Looking for STORE
            if(matchNextChar('t') && matchNextChar('o') && matchNextChar('r')
                && matchNextChar('e')) {
                cout << "Got STORE" << endl;
                tokenStream.push_back({MEMOP, "store"});
            }
            // Looking for SUB
            else if(matchNextChar('u') && matchNextChar('b')) {
                cout << "Got SUB" << endl;
                tokenStream.push_back({ARITHOP, "sub"});

            }
            else {
                // may have to call unget() here to put chars back in the stream
                // unget can be used multiple time essentially unwinding the stream characters i've gotten

            }

        }
        // Words what start with L {LOAD, LOADL, lSHIFT}
        else if (currentChar == 'l'){
            inputFile.get();
            if(matchNextChar('o') && matchNextChar('a') && matchNextChar('d')){

                //Check for accetped state LOADL
                if(matchNextChar('l')) {
                    cout << "Got LOADL" << endl;
                    tokenStream.push_back({LOADl, "loadl"});
                } else {
                    cout << "Got LOAD" << endl;
                    tokenStream.push_back({MEMOP, "load"});
                }

            }
            else if (matchNextChar('s') && matchNextChar('h') && matchNextChar('i') && matchNextChar('f') &&
                    matchNextChar('t')) {
                cout << "Got lshift" << endl;
                tokenStream.push_back({ARITHOP, "lshift"});
            }
            else {
                //unget?
            }
        }
        // Words what start with R {RSHIFT}
        else if( currentChar == 'r') {
            inputFile.get();
        }
        // Words what start with M {MULT}
        else if (currentChar == 'm') {
            inputFile.get();
        }
        // Words what start with A {ADD}
        else if(currentChar == 'a') {
            inputFile.get();
        }
        // Words what start with N {NOP}
        else if(currentChar == 'n') {
            inputFile.get();
        }
        // Words what start with O {OUTPUT}
        else if (currentChar == 'o') {
            inputFile.get();
        }
        else {
            inputFile.get();
            cout << "nothing now" << endl;
        }

    }

    //enum read as an int
    for(auto i : tokenStream) {
        cout << "Token is: " << i.second << endl;
    }

}

/*
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
                        cout << "Not r" << endl;
                    }
                } else {
                    inputFile.get();
                    cout << "Not o";
                }

                // Current State: S (T | U)
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
            // Words what start with M {MULT}
        else if (currentChar == 'm') {

        }
            // Words what start with A {ADD}
        else if(currentChar == 'a') {

        }
            // Words what start with N {NOP}
        else if(currentChar == 'n') {

        }
            // Words what start with O {OUTPUT}
        else if (currentChar == 'o') {

        }
        else {
            inputFile.get();
            cout << "nothing now" << endl;
        }

    }

}
 */