#include "shuntingYard.h"

#include <stdexcept>

std::vector<Token> ShuntingYard::convertToRpn(const std::vector<Token>& tokens,
                                              const OperationRegistry& registry) const {
    std::vector<Token> output;
    std::vector<Token> operators;

    for (const Token& token : tokens) {
        if (token.isNumber()) {
            output.push_back(token);
        } else if (isOperator(token)) {
            handleOperator(token, output, operators, registry);
        } else if (token.isLeftParenthesis()) {
            operators.push_back(token);
        } else if (token.isRightParenthesis()) {
            handleRightParenthesis(output, operators);
        }
    }

    popRemainingOperators(output, operators);
    return output;
}

void ShuntingYard::handleOperator(const Token& token,
                                  std::vector<Token>& output,
                                  std::vector<Token>& operators,
                                  const OperationRegistry& registry) const {
    if (token.isBinaryOperator()) {
        popHigherPriorityOperators(token, output, operators, registry);
    }

    operators.push_back(token);
}

void ShuntingYard::handleRightParenthesis(std::vector<Token>& output,
                                          std::vector<Token>& operators) const {
    while (!operators.empty() && !operators.back().isLeftParenthesis()) {
        output.push_back(operators.back());
        operators.pop_back();
    }

    if (operators.empty()) {
        throw std::runtime_error("Mismatched parentheses");
    }

    operators.pop_back();

    if (!operators.empty() && operators.back().isUnaryOperator()) {
        output.push_back(operators.back());
        operators.pop_back();
    }
}

void ShuntingYard::popHigherPriorityOperators(const Token& token,
                                              std::vector<Token>& output,
                                              std::vector<Token>& operators,
                                              const OperationRegistry& registry) const {
    while (!operators.empty() && shouldPopOperator(token, operators.back(), registry)) {
        output.push_back(operators.back());
        operators.pop_back();
    }
}

void ShuntingYard::popRemainingOperators(std::vector<Token>& output,
                                         std::vector<Token>& operators) const {
    while (!operators.empty()) {
        if (operators.back().isLeftParenthesis() || operators.back().isRightParenthesis()) {
            throw std::runtime_error("Mismatched parentheses");
        }

        output.push_back(operators.back());
        operators.pop_back();
    }
}

bool ShuntingYard::shouldPopOperator(const Token& current,
                                     const Token& top,
                                     const OperationRegistry& registry) const {
    if (!isOperator(top)) {
        return false;
    }

    int currentPriority = registry.getPriority(current.getValue());
    int topPriority = registry.getPriority(top.getValue());
    return topPriority >= currentPriority;
}

bool ShuntingYard::isOperator(const Token& token) const {
    return token.isBinaryOperator() || token.isUnaryOperator();
}
