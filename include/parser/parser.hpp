#pragma once

#include "lexer/lexer.hpp"

#include <string>
#include <vector>

struct ASTNode {
    std::string type;
    std::string value;
    std::vector<ASTNode> children;
};

class Parser {
public:
    ASTNode parse(
        const std::vector<Token>& tokens
    );
};
