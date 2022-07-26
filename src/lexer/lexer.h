#pragma once

#include "tokens.h"
#include <vector>
#include <string>

namespace Lexer
{
    std::vector<Tok> lex(std::string src);
}
