#include "token.h"

Token::Token(TokenType type, const std::string& value)
    : type(type), value(value) {
}

TokenType Token::getType() const {
    return type;
}

std::string Token::getValue() const {
    return value;
}

bool Token::isNumber() const {
    return type == TokenType::NUMBER;
}

bool Token::isBinaryOperator() const {
    return type == TokenType::BINARY_OPERATOR;
}

bool Token::isUnaryOperator() const {
    return type == TokenType::UNARY_OPERATOR;
}

bool Token::isLeftParenthesis() const {
    return type == TokenType::LEFT_PARENTHESIS;
}

bool Token::isRightParenthesis() const {
    return type == TokenType::RIGHT_PARENTHESIS;
}
