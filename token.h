#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum class TokenType {
    NUMBER,
    BINARY_OPERATOR,
    UNARY_OPERATOR,
    LEFT_PARENTHESIS,
    RIGHT_PARENTHESIS
};

class Token {
public:
    Token(TokenType type, const std::string& value);

    TokenType getType() const;
    std::string getValue() const;

    bool isNumber() const;
    bool isBinaryOperator() const;
    bool isUnaryOperator() const;
    bool isLeftParenthesis() const;
    bool isRightParenthesis() const;

private:
    TokenType type;
    std::string value;
};

#endif // TOKEN_H
