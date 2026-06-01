#include "rpnEvaluator.h"

#include <stdexcept>

double RpnEvaluator::evaluate(const std::vector<Token>& rpnTokens, const OperationRegistry& registry) const {
    std::vector<double> values;

    for (const Token& token : rpnTokens) {
        if (token.isNumber()) {
            handleNumber(token, values);
        } else if (token.isUnaryOperator()) {
            handleUnaryOperator(token, values, registry);
        } else if (token.isBinaryOperator()) {
            handleBinaryOperator(token, values, registry);
        } else {
            throw std::runtime_error("Invalid RPN expression");
        }
    }

    if (values.size() != 1) {
        throw std::runtime_error("Invalid RPN expression");
    }

    return values.back();
}

void RpnEvaluator::handleNumber(const Token& token, std::vector<double>& values) const {
    values.push_back(std::stod(token.getValue()));
}

void RpnEvaluator::handleUnaryOperator(const Token& token,
                                       std::vector<double>& values,
                                       const OperationRegistry& registry) const {
    double value = popValue(values);
    double result = registry.getUnary(token.getValue()).calculate(value);
    values.push_back(result);
}

void RpnEvaluator::handleBinaryOperator(const Token& token,
                                        std::vector<double>& values,
                                        const OperationRegistry& registry) const {
    double right = popValue(values);
    double left = popValue(values);
    double result = registry.getBinary(token.getValue()).calculate(left, right);
    values.push_back(result);
}

double RpnEvaluator::popValue(std::vector<double>& values) const {
    if (values.empty()) {
        throw std::runtime_error("Invalid RPN expression");
    }

    double value = values.back();
    values.pop_back();
    return value;
}
