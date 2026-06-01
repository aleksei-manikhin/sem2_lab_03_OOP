#include "expressionBuilder.h"

#include <cctype>

namespace {
bool isNumberCharacter(char symbol) {
    return std::isdigit(static_cast<unsigned char>(symbol)) || symbol == '.';
}

bool isOperatorOrLeftParenthesis(char symbol) {
    return symbol == '+' || symbol == '-' || symbol == '*'
           || symbol == '/' || symbol == '(';
}
}

void ExpressionBuilder::append(const std::string& value) {
    expression += value;
    resultShown = false;
}

void ExpressionBuilder::clear() {
    expression.clear();
    resultShown = false;
}

void ExpressionBuilder::deleteLast() {
    if (resultShown) {
        clear();
        return;
    }

    if (!expression.empty()) {
        expression.pop_back();
    }
}

void ExpressionBuilder::setResult(const std::string& value) {
    expression = value;
    resultShown = true;
}

void ExpressionBuilder::changeSign() {
    size_t start = expression.size();

    while (start > 0 && isNumberCharacter(expression[start - 1])) {
        --start;
    }

    if (start == expression.size()) {
        return;
    }

    if (start > 0 && expression[start - 1] == '-'
        && (start == 1 || isOperatorOrLeftParenthesis(expression[start - 2]))) {
        expression.erase(start - 1, 1);
    } else {
        expression.insert(start, "-");
    }

    resultShown = false;
}

std::string ExpressionBuilder::getExpression() const {
    return expression;
}

std::string ExpressionBuilder::getDisplayText() const {
    if (expression.empty()) {
        return "0";
    }

    return expression;
}

bool ExpressionBuilder::isResultShown() const {
    return resultShown;
}
