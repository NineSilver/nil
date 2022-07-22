#pragma once

#include "tokens.h"
#include <vector>
#include <string>
#include <string_view>

namespace lexer
{
    std::vector<std::string> lex(std::string src);
}