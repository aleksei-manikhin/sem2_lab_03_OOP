#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "operationRegistry.h"
#include "token.h"

#include <cstddef>
#include <string>
#include <vector>

class Tokenizer {
public:
    std::vector<Token> tokenize(const std::string& expression,
                                const OperationRegistry& registry) const;

private:
    bool isNumberStart(const std::string& expression,
                       size_t position,
                       const std::vector<Token>& tokens) const;
    bool isNegativeNumberStart(const std::string& expression, size_t position) const;
    bool canStartNegativeNumber(const std::vector<Token>& tokens) const;
    bool isSpecialUnaryStart(const std::string& expression, size_t position) const;
    bool isNumberCharacter(char symbol) const;

    Token readNumber(const std::string& expression, size_t& position) const;
    Token readWordOperation(const std::string& expression,
                            size_t& position,
                            const OperationRegistry& registry) const;
    Token readSpecialUnaryOperation(size_t& position) const;
    Token readBinaryOperation(char symbol, const OperationRegistry& registry) const;
};

#endif // TOKENIZER_H
