#include "lexer.h"

#include <iostream>

int main(int argc, char** argv) 
{
    lexer::lex("var i: i8 = 123;");
    return 0;
}