#include "lexer.h"

#include <iostream>
#include <vector>
#include <unordered_map>

namespace lexer 
{
    std::unordered_map<char, std::string> symbols{
        {'=', "TT_ASSIGN"},
        {'+', "TT_PLUS"},
        {'-', "TT_MINUS"},
        {'*', "TT_MULTIPLY"},
        {'/', "TT_DIVIDE"},
        {'>', "TT_GT"},
        {'<', "TT_LT"},
        {'(', "TT_LPAREN"},
        {')', "TT_RPAREN"},
        {'[', "TT_LBRACK"},
        {']', "TT_RBRACK"},
        {'{', "TT_LBRACE"},
        {'}', "TT_RBRACE"},
        {':', "TT_COLON"},
        {';', "TT_SEMICOLON"},
        {',', "TT_COMMA"},
        {'.', "TT_DOT"},
    };

    std::unordered_map<std::string, std::string> keywords{
        {"var", "TT_VAR"},
        {"let", "TT_LET"},
        {"const", "TT_CONST"},
        {"i8", "TT_I8"},
        {"i16", "TT_I16"},
        {"i32", "TT_I32"},
        {"i64", "TT_I64"},
        {"u8", "TT_U8"},
        {"u16", "TT_U16"},
        {"u32", "TT_U32"},
        {"u64", "TT_U64"},
        {"f32", "TT_F32"},
        {"f64", "TT_F64"},
        {"bool", "TT_BOOL"},
        {"string", "TT_STRING"},
    };

    std::vector<std::string> lex(std::string src) 
    {
        std::vector<std::string> tokens = {};

        for (int i = 0; i < src.size(); i++) {
            if (!isalnum(src[i])) {
                if (symbols.find(src[i]) != symbols.end()) {
                    tokens.push_back(symbols[src[i]]);
                }
            } else {
                std::string buf = "";
                while (isalnum(src[i])) {
                    buf += src[i];
                    i++;
                }
                i--;

                if (keywords.find(buf) != keywords.end()) {
                    tokens.push_back(keywords[buf]);
                } else {
                    tokens.push_back(buf);
                }
            }
        }

        // Print out the tokens
        for (std::string& i : tokens) {
            std::cout << i << '\n';
        }

        symbols.clear();
        keywords.clear();
        return tokens;
    }
}