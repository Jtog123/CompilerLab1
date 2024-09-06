#include <iostream>
#include <fstream>
#include "Scanner.hpp"

int main(int argc, char* argv[]) {
    cout << endl;
    Scanner scanner(argv[1]);
    scanner.readFile();

    return 0;
}

