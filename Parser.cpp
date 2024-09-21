//
// Created by jtog8 on 9/21/2024.
//

#include "Parser.hpp"
#include <iostream>

using namespace std;

void Parser::printTokens() {

    myScanner.readFile();

    for(auto token : myScanner.tokenStream) {
        cout << "Token is: " << token.second << endl;

        if(token.first == TokenType::ARITHOP) {
            cout << "CHECKING WE got Airthop" << endl;
        }
    }
}
