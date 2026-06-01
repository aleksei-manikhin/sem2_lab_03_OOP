#include "calculatorLogic.h"

#include <cmath>

void CalculatorLogic::append(const std::string& value) {
    builder.append(value);
}

void CalculatorLogic::clear() {
    builder.clear();
}

void CalculatorLogic::deleteLast() {
    builder.deleteLast();
}

void CalculatorLogic::calculate() {
    double result = evaluator.evaluate(currentExpressionOrZero());
    setCalculatedResult(result);
}

void CalculatorLogic::applyFunction(const std::string& functionName) {
    std::string expression = buildFunctionExpression(functionName);
    double result = evaluator.evaluate(expression);

    setCalculatedResult(result);
}

void CalculatorLogic::changeSign() {
    builder.changeSign();
}

std::string CalculatorLogic::getExpression() const {
    return builder.getExpression();
}

std::string CalculatorLogic::getDisplayText() const {
    return builder.getDisplayText();
}

std::string CalculatorLogic::buildFunctionExpression(const std::string& functionName) const {
    return functionName + "(" + currentExpressionOrZero() + ")";
}

std::string CalculatorLogic::currentExpressionOrZero() const {
    std::string expression = builder.getExpression();

    if (expression.empty()) {
        return "0";
    }

    return expression;
}

std::string CalculatorLogic::formatResult(double value) const {
    if (std::abs(value) < eps) {
        value = 0;
    }

    std::string result = std::to_string(value);

    while (result.find('.') != std::string::npos && result.back() == '0') {
        result.pop_back();
    }

    if (result.back() == '.') {
        result.pop_back();
    }

    return result;
}

void CalculatorLogic::setCalculatedResult(double value) {
    builder.setResult(formatResult(value));
}
