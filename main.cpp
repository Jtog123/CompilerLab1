#include <iostream>
#include <fstream>
#include "Scanner.hpp"
#include "Parser.hpp"

int main(int argc, char* argv[]) {
    cout << endl;
    //Scanner scanner(argv[1]);
    //scanner.readFile();

    Parser parser(argv[1]);
    parser.printTokens();

    return 0;
}

