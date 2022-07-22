#include "lexer.h"
#include "tokens.h"

#include <iostream>
#include <vector>

namespace lexer 
{
    std::vector<Tok> lex(std::string src) 
    {
        std::vector<Tok> tokens = {};

        for (int i = 0; i < src.size(); i++) {
            switch (src[i]) {
            case '=':
                tokens.push_back(Tok{ TokKind::Assign, "=" });
                break;
            case '+':
                tokens.push_back(Tok{ TokKind::Plus, "+" });
                break;
            case '-':
                tokens.push_back(Tok{ TokKind::Minus, "-" });
                break;
            case '*':
                tokens.push_back(Tok{ TokKind::Multiply, "*" });
                break;
            case '/':
                tokens.push_back(Tok{ TokKind::Divide, "/" });
                break;
            case '<':
                tokens.push_back(Tok{ TokKind::Lt, "<" });
                break;
            case '>':
                tokens.push_back(Tok{ TokKind::Gt, ">" });
                break;
            case '(':
                tokens.push_back(Tok{ TokKind::LParen, "(" });
                break;
            case ')':
                tokens.push_back(Tok{ TokKind::RParen, ")" });
                break;
            case '[':
                tokens.push_back(Tok{ TokKind::LBrack, "[" });
                break;
            case ']':
                tokens.push_back(Tok{ TokKind::RBrack, "]" });
                break;
            case '{':
                tokens.push_back(Tok{ TokKind::LBrace, "{" });
                break;
            case '}':
                tokens.push_back(Tok{ TokKind::RBrace, "}" });
                break;
            case ':':
                tokens.push_back(Tok{ TokKind::Colon, ":" });
                break;
            case ';':
                tokens.push_back(Tok{ TokKind::SemiColon, ";" });
                break;
            case ',':
                tokens.push_back(Tok{ TokKind::Comma, "," });
                break;
            case '.':
                tokens.push_back(Tok{ TokKind::Dot, "." });
                break;
            }
        }

        // Print out the tokens
        for (Tok& i : tokens) {
            std::cout << i.literal << '\n';
        }

        return tokens;
    }
}