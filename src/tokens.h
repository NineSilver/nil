#pragma once

#include <string>


enum TokKind 
{
    Identifer,  // [any]
    Numeric,    // [any number]
    Function,   // func
    Let,        // let
    Variable,   // var
    Constant,   // const

    Int8,       // i8
    Int16,      // i16
    Int32,      // i32
    Int64,      // i64
    UInt8,      // u8
    UInt16,     // u16
    UInt32,     // u32
    UInt64,     // u64
    Float32,    // f32
    Float64,    // f64
    Boolean,    // bool
    String,     // string

    Assign,     // =
    Plus,       // +
    Minus,      // -
    Divide,     // /
    Multiply,   // *
    Gt,         // >
    Lt,         // <
    LParen,     // (
    RParen,     // )
    LBrack,     // [
    RBrack,     // ]
    LBrace,     // {
    RBrace,     // }
    Colon,      // :
    SemiColon,  // ;
    Comma,      // ,
    Dot,        // .

};

struct Tok
{
    TokKind kind;
    std::string literal;
};

