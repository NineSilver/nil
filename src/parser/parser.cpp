#include "parser.h"
#include "../lexer/tokens.h"
#include "ast.h"

#include <iostream>
#include <vector>

namespace Parser
{
    unsigned int line_count = 1;

    void parse_variables(std::vector<Tok> tokens) 
    {
        if (tokens[tokens.size()-1].kind != TokKind::SemiColon) {
            std::cerr << "ERROR : expecting a semi-colon at end of line " << line_count << '\n';
            exit(1);
        }

        

        if (tokens[0].kind == TokKind::Var) {

        } else if (tokens[0].kind == TokKind::Let) {

        } else if (tokens[0].kind == TokKind::Const) {

        }
    }

    void parse(std::vector<Tok> tokens)
    {
        
        line_count++;
    }
}