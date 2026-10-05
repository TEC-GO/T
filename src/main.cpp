#include "lexer/lexer.hpp"
#include "parser/parser.hpp"
#include "compiler/compiler.hpp"
#include "codegen/codegen.hpp"

#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: T <archivo.t>\n";
        return 1;
    }

    try {
        Lexer lexer;
        Parser parser;
        Compiler compiler;
        Codegen codegen;

        auto tokens = lexer.tokenize(argv[1]);
        auto ast = parser.parse(tokens);
        auto program = compiler.compile(ast, argv[1]);

        return codegen.generate(program);
    }
    catch (const std::exception& error) {
        std::cerr << "T error: "
        << error.what()
        << '\n';

        return 1;
    }
}
