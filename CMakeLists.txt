cmake_minimum_required(VERSION "3.16")
project("nil")

file(GLOB src_files
    "src/*.h"
    "src/*.cpp"
)

add_executable("nil" ${src_files})