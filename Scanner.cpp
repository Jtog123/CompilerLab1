//
// Created by jtog8 on 9/5/2024.
//

#include "Scanner.hpp"
#include <fstream>
#include <iostream>

using namespace std;

/*
 * Recognize all keywords seems good
 * handle all errors in each input file
 * form tokens and push them into container
 *
 * Parse?
 */

/////////////////////////////////////

Scanner::Scanner(const string& filePath)  {
    // open the file
    inputFile.open(filePath);
    if(!inputFile) {
        cerr << "No input file or error opening input file: " << filePath << endl;
        exit(65);
    }
}

bool Scanner::validateSpacing() {
    return matchNextChar(' ');
}

//Helper function how badly does the cost modulartity and readability affect the compiler?
bool Scanner::matchNextChar(char expectedChar) {
    char currentChar = inputFile.peek();
    if(currentChar == expectedChar) {
        inputFile.get();
    }
    return currentChar == expectedChar;
}

//read errors

//report errors

void Scanner::readFile() {
    // while we are not at the end of the file
    // gather each char and look for each word
    //char currentChar = inputFile.peek();
    //cout<< currentChar;

    //<type of operation, actual characters that where matched in stream>

    while(! inputFile.eof()) {
        char currentChar = inputFile.peek();

        // WORDS THAT START WITH S
        // check for new lines
        if (currentChar == '\n') {
            cout << "END OF LINE" << endl;
            inputFile.get();
            tokenStream.push_back({EOL, "\\n"});
            _lineNumber++;
        }
        else if(currentChar == ' ') {
            cout << "Whitespace" << endl;
            inputFile.get();
        }
        else if(currentChar == ',') {
            cout << "Comma" << endl;
            inputFile.get();
            tokenStream.push_back({COMMA, ","});
        }
        else if(currentChar == '/') {
            inputFile.get();
            if(matchNextChar('/')) {
                cout << "Comment" << endl;
                tokenStream.push_back({COMMENT, "//"});

                //Encounter a comment get the whole line till we reach a new line
                while(inputFile.peek() != '\n') {
                    inputFile.get();
                }
            }
            else {
                //unget initial slash ??
            }
        }
        else if(currentChar == '=') {
            inputFile.get();
            if(matchNextChar('>')) {
                cout << "Got Into" << endl;
                tokenStream.push_back({INTO,"=>"});
            }
            else {
                //undo?
            }
        }
        // get integers
        else if (isdigit(currentChar)) {
            //how do i handle the 10a, i dont want to keep it
            // only should be pushed back if valid

            string number;
            bool validInt = true;
            while(isdigit(inputFile.peek())) {
                number += inputFile.peek();
                inputFile.get();
            }

            //potential non digit character
            char nextChar = inputFile.peek();

            if(!isspace(nextChar) && nextChar != '=' && nextChar != ',') {
                cout << "Syntax error on line: " << _lineNumber << endl;
                validInt = false;

                //eat characters until a space or newline or end of file
                while(!isspace(inputFile.peek()) && inputFile.peek() != '/n' && !inputFile.eof()) {
                    inputFile.get();
                }
            }
            if(validInt) {
                cout << "got number: " << number << endl;
                tokenStream.push_back({CONSTANT, number});
            }

        }
        else if(currentChar == 's') {
            inputFile.get();
            // Looking for STORE
            if(matchNextChar('t') && matchNextChar('o') && matchNextChar('r')
                && matchNextChar('e')) {

                //After each word if next char is not a space report an error sith the line number
                // Error should probably be thrown here
                if(validateSpacing()) {
                    cout << "Got STORE" << endl;
                    tokenStream.push_back({MEMOP, "store"});
                }
                else {
                    cout << "Syntax Error on line: " << _lineNumber << " did you mean store?" << endl;
                }


            }
            // Looking for SUB
            else if(matchNextChar('u') && matchNextChar('b')) {
                cout << "Got SUB" << endl;
                tokenStream.push_back({ARITHOP, "sub"});

            }
            else {
                //on broken input files, I may need to initzilize and int and keep a count every time a new identifier is found
                // unget up to the count
                // every white space reset the count?
                // may have to call unget() here to put chars back in the stream
                // unget can be used multiple time essentially unwinding the stream characters i've gotten

            }

        }

        // Words what start with L {LOAD, LOADI, lSHIFT}
        else if (currentChar == 'l'){
            inputFile.get();
            if(matchNextChar('o') && matchNextChar('a') && matchNextChar('d')){

                //Check for accetped state LOADL
                if(matchNextChar('I')) {
                    cout << "Got LOADI" << endl;
                    tokenStream.push_back({LOADI, "loadi"});
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
            if(matchNextChar('s') && matchNextChar('h') && matchNextChar('i')
                && matchNextChar('f') && matchNextChar('t')) {
                cout << "Got RSHIFT" << endl;
                tokenStream.push_back({ARITHOP, "rshift"});

            }
            else {

                //its a register
                string registerName = "r";
                bool validRegister = true;

                // is char after r a number or not
                if(inputFile.eof() || ! isdigit(inputFile.peek())) {
                    cout << "Syntax on line : "<< _lineNumber << " not a valid register discard: " << (char)inputFile.peek() << endl;

                    //eat broken register until we reach a space
                    while(inputFile.peek() != ' ' && inputFile.eof()) {
                        inputFile.get();
                        if(matchNextChar('\n')) {
                            _lineNumber++;
                            inputFile.get();
                        }
                    }
                }
                //we have a valid register
                else if (isdigit(inputFile.peek())) {
                    while(isdigit(inputFile.peek())) {

                        registerName += inputFile.peek();
                        inputFile.get();
                    }
                    cout << registerName << endl;
                    tokenStream.push_back({REGISTER, registerName});
                }

                //r2a


            }





            //convert char to string check if its a number


        }
        // Words what start with M {MULT}
        else if (currentChar == 'm') {
            inputFile.get();
            if(matchNextChar('u') && matchNextChar('l') && matchNextChar('t')) {
                cout << "got mult" << endl;
                tokenStream.push_back({ARITHOP, "mult"});
            }
        }
        // Words what start with A {ADD}
        else if(currentChar == 'a') {
            inputFile.get();
            if(matchNextChar('d') && matchNextChar('d')) {
                cout << "Got Add" << endl;
                tokenStream.push_back({ARITHOP, "add"});
            }
        }
        // Words what start with N {NOP}
        else if(currentChar == 'n') {
            inputFile.get();
            if(matchNextChar('o') && matchNextChar('p')) {
                cout << "Got nop" << endl;
                tokenStream.push_back({NOP, "nop"});
            }
        }
        // Words what start with O {OUTPUT}
        else if (currentChar == 'o') {
            inputFile.get();
            if(matchNextChar('u') && matchNextChar('t') && matchNextChar('p')
                && matchNextChar('u') && matchNextChar('t')) {
                cout << "Got output" << endl;
                tokenStream.push_back({OUTPUT, "output"});

            }
        }
        else {
            inputFile.get();
            cout << "nothing now" << endl;
        }

    }
    tokenStream.push_back({_EOF, "eof"});
    //enum read as an int
    cout << endl;
    cout << "Reading out Tokens : " << endl;


    for(auto i : tokenStream) {
        cout << "Token is: " << i.second << endl;

        if(i.first == TokenType::ARITHOP) {
            cout << "WE got Airthop" << endl;
        }
    }







}



