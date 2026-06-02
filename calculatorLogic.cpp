#include "calculatorLogic.h"
#include "numberFormatter.h"

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
    std::string expression = builder.buildExpressionWithFunctionOnLastOperand(functionName);
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

std::string CalculatorLogic::currentExpressionOrZero() const {
    std::string expression = builder.getExpression();

    if (expression.empty()) {
        return "0";
    }

    return expression;
}

std::string CalculatorLogic::formatResult(double value) const {
    return NumberFormatter::formatResult(value);
}

void CalculatorLogic::setCalculatedResult(double value) {
    builder.setResult(formatResult(value));
}
