cmake_minimum_required(VERSION "3.16")

project("nil")

file(GLOB src_files
    "src/*.h"
    "src/*.cpp"
)

file(GLOB src_parser_files
    "src/parser/*.cpp"
    "src/parser/*.h"
)

file(GLOB src_lexer_files
    "src/lexer/*.cpp"
    "src/lexer/*.h"
)

add_executable("nil" ${src_files} ${src_parser_files} ${src_lexer_files})