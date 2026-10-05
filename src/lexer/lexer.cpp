#include "lexer/lexer.hpp"

#include <cctype>
#include <fstream>
#include <stdexcept>

static bool isIdentifierStart(char c) {
    return std::isalpha(
        static_cast<unsigned char>(c)
    ) || c == '_';
}

static bool isIdentifierPart(char c) {
    return std::isalnum(
        static_cast<unsigned char>(c)
    ) || c == '_';
}

static bool isKeyword(const std::string& text) {
    return text == "int" ||
    text == "char" ||
    text == "void" ||
    text == "if" ||
    text == "else" ||
    text == "while" ||
    text == "return" ||
    text == "function";
}

std::vector<Token> Lexer::tokenize(
    const std::string& filename
) {
    std::ifstream file(filename);

    if (!file) {
        throw std::runtime_error(
            "no se puede abrir: " + filename
        );
    }

    std::string source(
        (std::istreambuf_iterator<char>(file)),
                       std::istreambuf_iterator<char>()
    );

    std::vector<Token> tokens;

    int line = 1;
    int column = 1;

    for (std::size_t i = 0; i < source.size();) {
        char c = source[i];

        if (c == '\n') {
            ++line;
            column = 1;
            ++i;
            continue;
        }

        if (std::isspace(
            static_cast<unsigned char>(c)
        )) {
            ++column;
            ++i;
            continue;
        }

        if (c == '/' &&
            i + 1 < source.size() &&
            source[i + 1] == '/') {

            while (
                i < source.size() &&
                source[i] != '\n'
            ) {
                ++i;
                ++column;
            }

            continue;
            }

            if (isIdentifierStart(c)) {
                int startColumn = column;
                std::string text;

                while (
                    i < source.size() &&
                    isIdentifierPart(source[i])
                ) {
                    text += source[i];
                    ++i;
                    ++column;
                }

                tokens.push_back({
                    isKeyword(text)
                    ? TokenType::Keyword
                    : TokenType::Identifier,
                    text,
                    line,
                    startColumn
                });

                continue;
            }

            if (std::isdigit(
                static_cast<unsigned char>(c)
            )) {
                int startColumn = column;
                std::string text;

                while (
                    i < source.size() &&
                    std::isdigit(
                        static_cast<unsigned char>(
                            source[i]
                        )
                    )
                ) {
                    text += source[i];
                    ++i;
                    ++column;
                }

                tokens.push_back({
                    TokenType::Number,
                    text,
                    line,
                    startColumn
                });

                continue;
            }

            if (c == '"') {
                int startColumn = column;
                std::string text;

                text += c;
                ++i;
                ++column;

                while (
                    i < source.size() &&
                    source[i] != '"'
                ) {
                    text += source[i];
                    ++i;
                    ++column;
                }

                if (i < source.size()) {
                    text += source[i];
                    ++i;
                    ++column;
                }

                tokens.push_back({
                    TokenType::String,
                    text,
                    line,
                    startColumn
                });

                continue;
            }

            const std::string operators =
            "+-*/%=<>!&|";

            const std::string symbols =
            "(){}[],;:";

    if (operators.find(c) != std::string::npos) {
        tokens.push_back({
            TokenType::Operator,
            std::string(1, c),
                         line,
                         column
        });
    }
    else if (
        symbols.find(c) != std::string::npos
    ) {
        tokens.push_back({
            TokenType::Symbol,
            std::string(1, c),
                         line,
                         column
        });
    }
    else {
        throw std::runtime_error(
            "caracter desconocido en linea " +
            std::to_string(line)
        );
    }

    ++i;
    ++column;
    }

    tokens.push_back({
        TokenType::EndOfFile,
        "",
        line,
        column
    });

    return tokens;
}
