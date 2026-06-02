#include "tokenizer.h"

#include <cctype>
#include <stdexcept>

std::vector<Token> Tokenizer::tokenize(const std::string& expression,
                                       const OperationRegistry& registry) const {
    std::vector<Token> tokens;

    for (size_t position = 0; position < expression.size();) {
        char current = expression[position];

        if (std::isspace(static_cast<unsigned char>(current))) {
            ++position;
        } else if (isSpecialUnaryStart(expression, position)) {
            tokens.push_back(readSpecialUnaryOperation(position));
        } else if (isNumberStart(expression, position, tokens)) {
            tokens.push_back(readNumber(expression, position));
        } else if (std::isalpha(static_cast<unsigned char>(current))) {
            tokens.push_back(readWordOperation(expression, position, registry));
        } else if (current == '(') {
            tokens.emplace_back(TokenType::LEFT_PARENTHESIS, "(");
            ++position;
        } else if (current == ')') {
            tokens.emplace_back(TokenType::RIGHT_PARENTHESIS, ")");
            ++position;
        } else {
            tokens.push_back(readBinaryOperation(current, registry));
            ++position;
        }
    }

    return tokens;
}

bool Tokenizer::isNumberStart(const std::string& expression,
                              size_t position,
                              const std::vector<Token>& tokens) const {
    char current = expression[position];

    return std::isdigit(static_cast<unsigned char>(current))
           || current == '.'
           || (isNegativeNumberStart(expression, position) && canStartNegativeNumber(tokens));
}

bool Tokenizer::isNegativeNumberStart(const std::string& expression, size_t position) const {
    if (expression[position] != '-' || position + 1 >= expression.size()) {
        return false;
    }

    char next = expression[position + 1];
    return std::isdigit(static_cast<unsigned char>(next)) || next == '.';
}

bool Tokenizer::canStartNegativeNumber(const std::vector<Token>& tokens) const {
    if (tokens.empty()) {
        return true;
    }

    const Token& lastToken = tokens.back();
    return lastToken.isBinaryOperator() || lastToken.isLeftParenthesis();
}

bool Tokenizer::isSpecialUnaryStart(const std::string& expression, size_t position) const {
    return expression.compare(position, 3, "1/x") == 0;
}

bool Tokenizer::isMantissaCharacter(char symbol) const {
    return std::isdigit(static_cast<unsigned char>(symbol)) || symbol == '.';
}

bool Tokenizer::isExponentSymbol(char symbol) const {
    return symbol == 'e' || symbol == 'E';
}

Token Tokenizer::readNumber(const std::string& expression, size_t& position) const {
    size_t start = position;
    bool hasDot = false;
    bool hasDigit = false;

    if (expression[position] == '-') {
        ++position;
    }

    while (position < expression.size() && isMantissaCharacter(expression[position])) {
        char current = expression[position];

        if (current == '.') {
            if (hasDot) {
                throw std::runtime_error("Invalid number format");
            }
            hasDot = true;
        } else {
            hasDigit = true;
        }

        ++position;
    }

    if (!hasDigit) {
        throw std::runtime_error("Invalid number format");
    }

    if (position < expression.size() && isExponentSymbol(expression[position])) {
        ++position;

        if (position < expression.size()
            && (expression[position] == '+' || expression[position] == '-')) {
            ++position;
        }

        bool hasExponentDigit = false;

        while (position < expression.size()
               && std::isdigit(static_cast<unsigned char>(expression[position]))) {
            hasExponentDigit = true;
            ++position;
        }

        if (!hasExponentDigit) {
            throw std::runtime_error("Invalid number format");
        }
    }

    return Token(TokenType::NUMBER, expression.substr(start, position - start));
}

Token Tokenizer::readWordOperation(const std::string& expression,
                                   size_t& position,
                                   const OperationRegistry& registry) const {
    size_t start = position;

    while (position < expression.size()
           && std::isalpha(static_cast<unsigned char>(expression[position]))) {
        ++position;
    }

    std::string operation = expression.substr(start, position - start);

    if (!registry.isUnary(operation)) {
        throw std::runtime_error("Unknown operation: " + operation);
    }

    return Token(TokenType::UNARY_OPERATOR, operation);
}

Token Tokenizer::readSpecialUnaryOperation(size_t& position) const {
    position += 3;
    return Token(TokenType::UNARY_OPERATOR, "1/x");
}

Token Tokenizer::readBinaryOperation(char symbol, const OperationRegistry& registry) const {
    std::string operation(1, symbol);

    if (!registry.isBinary(operation)) {
        throw std::runtime_error("Unknown symbol: " + operation);
    }

    return Token(TokenType::BINARY_OPERATOR, operation);
}
