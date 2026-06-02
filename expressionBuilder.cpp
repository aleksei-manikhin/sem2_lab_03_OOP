#include "expressionBuilder.h"
#include "numberFormatter.h"

#include <cctype>

namespace {
bool isDigitOrDot(char symbol) {
    return std::isdigit(static_cast<unsigned char>(symbol)) || symbol == '.';
}

bool isExponentSymbol(char symbol) {
    return symbol == 'e' || symbol == 'E';
}

bool isOperatorOrLeftParenthesis(char symbol) {
    return symbol == '+' || symbol == '-' || symbol == '*'
           || symbol == '/' || symbol == '(';
}

bool isBinaryOperator(char symbol) {
    return symbol == '+' || symbol == '-' || symbol == '*'
           || symbol == '/';
}

bool isUnarySign(const std::string& expression, size_t position) {
    if (expression[position] != '-') {
        return false;
    }

    return position == 0
           || isBinaryOperator(expression[position - 1])
           || expression[position - 1] == '(';
}

size_t findLastNumberStart(const std::string& expression) {
    size_t start = expression.size();

    while (start > 0 && isDigitOrDot(expression[start - 1])) {
        --start;
    }

    if (start == expression.size()) {
        return start;
    }

    if (start > 1
        && (expression[start - 1] == '+' || expression[start - 1] == '-')
        && isExponentSymbol(expression[start - 2])) {
        start -= 2;

        while (start > 0 && isDigitOrDot(expression[start - 1])) {
            --start;
        }
    }

    return start;
}

size_t includeUnarySign(const std::string& expression, size_t start) {
    if (start > 0 && isUnarySign(expression, start - 1)) {
        return start - 1;
    }

    return start;
}

size_t findLastNumberOperandStart(const std::string& expression) {
    size_t start = findLastNumberStart(expression);

    if (start == expression.size()) {
        return start;
    }

    return includeUnarySign(expression, start);
}

size_t findMatchingLeftParenthesis(const std::string& expression, size_t rightParenthesis) {
    int balance = 0;

    for (size_t position = rightParenthesis + 1; position > 0; --position) {
        size_t index = position - 1;

        if (expression[index] == ')') {
            ++balance;
        } else if (expression[index] == '(') {
            --balance;

            if (balance == 0) {
                return index;
            }
        }
    }

    return std::string::npos;
}

size_t includeFunctionName(const std::string& expression, size_t leftParenthesis) {
    if (leftParenthesis >= 3 && expression.compare(leftParenthesis - 3, 3, "1/x") == 0) {
        return leftParenthesis - 3;
    }

    size_t start = leftParenthesis;

    while (start > 0 && std::isalpha(static_cast<unsigned char>(expression[start - 1]))) {
        --start;
    }

    return start;
}

size_t findLastOperandStart(const std::string& expression) {
    if (expression.empty()) {
        return std::string::npos;
    }

    if (expression.back() == ')') {
        size_t leftParenthesis = findMatchingLeftParenthesis(expression, expression.size() - 1);

        if (leftParenthesis == std::string::npos) {
            return std::string::npos;
        }

        return includeFunctionName(expression, leftParenthesis);
    }

    size_t start = findLastNumberOperandStart(expression);

    if (start == expression.size()) {
        return std::string::npos;
    }

    return start;
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
    size_t start = findLastNumberStart(expression);

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

std::string ExpressionBuilder::buildExpressionWithFunctionOnLastOperand(const std::string& functionName) const {
    if (expression.empty()) {
        return functionName + "(0)";
    }

    size_t start = findLastOperandStart(expression);

    if (start == std::string::npos) {
        return functionName + "(" + expression + ")";
    }

    std::string result = expression.substr(0, start);
    result += functionName + "(";
    result += expression.substr(start);
    result += ")";

    return result;
}

std::string ExpressionBuilder::getDisplayText() const {
    return NumberFormatter::formatExpressionForDisplay(expression);
}

bool ExpressionBuilder::isResultShown() const {
    return resultShown;
}
