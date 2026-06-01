#include "expressionEvaluator.h"

#include <stdexcept>
#include <vector>

double ExpressionEvaluator::evaluate(const std::string& expression) const {
    validateExpression(expression);

    std::vector<Token> tokens = tokenizer.tokenize(expression, registry);
    std::vector<Token> rpnTokens = shuntingYard.convertToRpn(tokens, registry);

    return rpnEvaluator.evaluate(rpnTokens, registry);
}

void ExpressionEvaluator::validateExpression(const std::string& expression) const {
    if (expression.empty()) {
        throw std::runtime_error("Expression is empty");
    }
}
