#pragma once

#include "ast.h"
#include "../lexer/tokens.h"

#include <vector>

namespace Parser
{
    void parse(std::vector<Tok> tokens);
}