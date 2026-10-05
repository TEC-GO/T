#include "compiler/compiler.hpp"

CompiledProgram Compiler::compile(
    const ASTNode& ast,
    const std::string& sourceName
) {
    CompiledProgram program;

    program.ast = ast;
    program.sourceName = sourceName;

    return program;
}
