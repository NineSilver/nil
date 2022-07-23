#include "lexer/lexer.h"
#include "parser/parser.h"

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv) 
{
    if (argc == 2) {
        std::fstream file(argv[1]);
        std::string line;
        while (std::getline(file, line)) {
            Parser::parse(Lexer::lex(line));
        }
        return 0;
    } else {
        std::cout << "error : expecting a file\n";
        std::cout << "usage : ./nil [file]\n";
        return 1;
    }
}