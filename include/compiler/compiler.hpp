#pragma once

#include "parser/parser.hpp"

#include <string>

struct CompiledProgram {
    ASTNode ast;
    std::string sourceName;
};

class Compiler {
public:
    CompiledProgram compile(
        const ASTNode& ast,
        const std::string& sourceName
    );
};
