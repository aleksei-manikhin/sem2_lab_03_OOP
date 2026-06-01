#ifndef SHUNTINGYARD_H
#define SHUNTINGYARD_H

#include "operations/operationRegistry.h"
#include "token.h"

#include <vector>

class ShuntingYard {
public:
    std::vector<Token> convertToRpn(const std::vector<Token>& tokens,
                                    const OperationRegistry& registry) const;

private:
    void handleOperator(const Token& token,
                        std::vector<Token>& output,
                        std::vector<Token>& operators,
                        const OperationRegistry& registry) const;
    void handleRightParenthesis(std::vector<Token>& output,
                                std::vector<Token>& operators) const;
    void popHigherPriorityOperators(const Token& token,
                                    std::vector<Token>& output,
                                    std::vector<Token>& operators,
                                    const OperationRegistry& registry) const;
    void popRemainingOperators(std::vector<Token>& output,
                               std::vector<Token>& operators) const;
    bool shouldPopOperator(const Token& current,
                           const Token& top,
                           const OperationRegistry& registry) const;
    bool isOperator(const Token& token) const;
};

#endif // SHUNTINGYARD_H
