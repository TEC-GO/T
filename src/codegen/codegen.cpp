#include "codegen/codegen.hpp"

#include <iostream>

int Codegen::generate(
    const CompiledProgram& program
) {
    std::cout << "T compiler\n";
    std::cout << "Archivo: "
    << program.sourceName
    << '\n';

    std::cout << "Tokens: "
    << program.ast.children.size()
    << '\n';

    return 0;
}
