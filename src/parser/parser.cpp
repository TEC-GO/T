#include "parser/parser.hpp"

ASTNode Parser::parse(
    const std::vector<Token>& tokens
) {
    ASTNode program;

    program.type = "Program";
    program.value = "";

    for (const Token& token : tokens) {
        if (token.type == TokenType::EndOfFile) {
            break;
        }

        ASTNode node;

        node.type = "Token";
        node.value = token.text;

        program.children.push_back(node);
    }

    return program;
}
