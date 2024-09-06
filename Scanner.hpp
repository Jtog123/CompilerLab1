//
// Created by jtog8 on 9/5/2024.
//

#ifndef COMPILERLAB1_SCANNER_HPP
#define COMPILERLAB1_SCANNER_HPP

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Scanner {
    private:
        ifstream inputFile;
        int test;


    public:
        Scanner(const string& filePath);
        void readFile();
};


#endif //COMPILERLAB1_SCANNER_HPP
