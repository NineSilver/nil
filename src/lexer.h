#pragma once

#include "tokens.h"
#include <vector>
#include <string>

namespace lexer
{
    std::vector<Tok> lex(std::string src);
}
