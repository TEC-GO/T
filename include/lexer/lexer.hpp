#pragma once

#include <string>
#include <vector>

enum class TokenType {
    Identifier,
    Number,
    String,
    Keyword,
    Operator,
    Symbol,
    EndOfFile
};

struct Token {
    TokenType type;
    std::string text;
    int line;
    int column;
};

class Lexer {
public:
    std::vector<Token> tokenize(
        const std::string& filename
    );
};
