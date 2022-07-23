#include "lexer.h"
#include "tokens.h"

#include <iostream>
#include <vector>
#include <unordered_map>

namespace Lexer 
{
    std::unordered_map<char, Tok> symbols{
        {'=', { TokKind::Assign, "="}},
        {'+', { TokKind::Plus, "+"}},
        {'-', { TokKind::Minus, "-"}},
        {'*', { TokKind::Multiply, "*"}},
        {'/', { TokKind::Divide, "/"}},
        {'>', { TokKind::Gt, ">"}},
        {'<', { TokKind::Lt, "<"}},
        {'(', { TokKind::LParen, "("}},
        {')', { TokKind::RParen, ")"}},
        {'[', { TokKind::LBrack, "["}},
        {']', { TokKind::RBrack, "]"}},
        {'{', { TokKind::LBrace, "{"}},
        {'}', { TokKind::RBrace, "}"}},
        {':', { TokKind::Colon, ":"}},
        {';', { TokKind::SemiColon, ";"}},
        {',', { TokKind::Comma, ","}},
        {'.', { TokKind::Dot, "."}},
    };

    std::unordered_map<std::string, Tok> keywords{
        {"func", { TokKind::Func, "func"}},
        {"var", { TokKind::Var, "var"}},
        {"let", { TokKind::Let, "let"}},
        {"const", { TokKind::Const, "const"}},
        {"i8", { TokKind::I8, "i8"}},
        {"i16", { TokKind::I16, "i16"}},
        {"i32", { TokKind::I32, "i32"}},
        {"i64", { TokKind::I64, "i64"}},
        {"u8", { TokKind::U8, "u8"}},
        {"u16", { TokKind::U16, "u16"}},
        {"u32", { TokKind::U32, "u32"}},
        {"u64", { TokKind::U64, "u64"}},
        {"f32", { TokKind::F32, "f32"}},
        {"f64", { TokKind::F64, "f64"}},
        {"bool", { TokKind::Bool, "bool"}},
        {"string", { TokKind::StringT, "string"}},
    };

    static inline bool is_ident(char c)
    {
        return isalpha(c) || c == '_' || c == '$';
    }

    std::vector<Tok> lex(std::string src) 
    {
        std::vector<Tok> tokens = {};

        for (int i = 0; i < src.size(); i++) {
            if (!isalnum(src[i])) {
                if (symbols.find(src[i]) != symbols.end()) {
                    tokens.push_back(symbols[src[i]]);
                }
            } else if (src[i] == '\"') {
                i++;
                std::string buf = "";
                while (src[i] != '\"') {
                    buf += src[i++];
                } i--;

                tokens.push_back(Tok{ TokKind::StringD, buf });
            } else {
                if (isdigit(src[i])) {
                    std::string buf = "";
                    while (isdigit(src[i])) {
                        buf += src[i++];
                    } i--;
                    
                    tokens.push_back(Tok{ TokKind::Number, buf});
                } else if (is_ident(src[i])) {
                    std::string buf = "";
                    while (is_ident(src[i]) || isdigit(src[i])) {
                        buf += src[i++];
                    } i--;

                    if (keywords.find(buf) != keywords.end()) {
                        tokens.push_back(keywords[buf]);
                    } else {
                        tokens.push_back(Tok{ TokKind::Identifier, buf});
                    }
                } else {
                    std::cerr << "Unknown character " << src[i++] << '\n';
                }
            }
        }

        // Print out the tokens
        for (Tok& i : tokens) {
            std::cout << i.literal << ' ' << i.kind << '\n';
        }

        symbols.clear();
        keywords.clear();
        return tokens;
    }
}