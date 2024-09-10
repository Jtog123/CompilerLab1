//
// Created by jtog8 on 9/5/2024.
//

#ifndef COMPILERLAB1_SCANNER_HPP
#define COMPILERLAB1_SCANNER_HPP

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "TokenType.hpp"

using namespace std;

class Scanner {
    private:
        ifstream inputFile;
        int _lineNumber = 1;
        bool validateSpacing();


    public:
        Scanner(const string& filePath);
        void readFile();
        bool matchNextChar(char);
        vector<pair <TokenType, string> > tokenStream;  // TokenType, lexeme
};





#endif //COMPILERLAB1_SCANNER_HPP
