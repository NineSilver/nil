#pragma once

#include <string>

enum TokKind
{
    Identifier,
    Number,
    StringD,

    Func,

    Var,
    Let,
    Const,

    I8,
    I16,
    I32,
    I64,
    U8,
    U16,
    U32,
    U64,
    F32,
    F64,
    Bool,
    StringT,

    Assign,
    Plus,
    Minus,
    Multiply,
    Divide,
    Gt,
    Lt,
    LParen,
    RParen,
    LBrack,
    RBrack,
    LBrace,
    RBrace,
    Colon,
    SemiColon,
    Comma,
    Dot,
};

struct Tok
{
    TokKind kind;
    std::string literal;
};