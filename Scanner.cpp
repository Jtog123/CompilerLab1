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
    char currentChar = inputFile.peek();
    cout<< currentChar;

}