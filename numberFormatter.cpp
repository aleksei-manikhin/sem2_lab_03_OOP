#include "numberFormatter.h"

#include <cmath>
#include <cctype>
#include <iomanip>
#include <sstream>
#include <stdexcept>

namespace {
bool isOperatorOrLeftParenthesis(char symbol) {
    return symbol == '+' || symbol == '-' || symbol == '*'
           || symbol == '/' || symbol == '(';
}

bool startsNegativeNumber(const std::string& expression, size_t position) {
    if (expression[position] != '-' || position + 1 >= expression.size()) {
        return false;
    }

    char next = expression[position + 1];
    bool nextStartsNumber = std::isdigit(static_cast<unsigned char>(next)) || next == '.';
    bool hasUnaryContext = position == 0 || isOperatorOrLeftParenthesis(expression[position - 1]);

    return nextStartsNumber && hasUnaryContext;
}

bool startsNumber(const std::string& expression, size_t position) {
    char current = expression[position];

    return std::isdigit(static_cast<unsigned char>(current))
           || current == '.'
           || startsNegativeNumber(expression, position);
}

bool isExponentSymbol(char symbol) {
    return symbol == 'e' || symbol == 'E';
}

std::string readNumberToken(const std::string& expression, size_t& position) {
    size_t start = position;

    if (expression[position] == '-') {
        ++position;
    }

    while (position < expression.size()) {
        char current = expression[position];

        if (std::isdigit(static_cast<unsigned char>(current)) || current == '.') {
            ++position;
            continue;
        }

        if (isExponentSymbol(current)) {
            ++position;

            if (position < expression.size()
                && (expression[position] == '+' || expression[position] == '-')) {
                ++position;
            }

            while (position < expression.size()
                   && std::isdigit(static_cast<unsigned char>(expression[position]))) {
                ++position;
            }
        }

        break;
    }

    return expression.substr(start, position - start);
}

int integerDigitCount(const std::string& token) {
    size_t position = 0;

    if (position < token.size() && (token[position] == '-' || token[position] == '+')) {
        ++position;
    }

    while (position < token.size() && token[position] == '0') {
        ++position;
    }

    int digits = 0;

    while (position < token.size()
           && std::isdigit(static_cast<unsigned char>(token[position]))) {
        ++digits;
        ++position;
    }

    return digits == 0 ? 1 : digits;
}
}

std::string NumberFormatter::formatResult(double value) {
    if (std::abs(value) < 0.000001) {
        value = 0;
    }

    if (shouldUseScientific(value)) {
        return formatScientific(value);
    }

    return formatPlain(value);
}

std::string NumberFormatter::formatExpressionForDisplay(const std::string& expression) {
    if (expression.empty()) {
        return "0";
    }

    std::string display;
    size_t position = 0;

    while (position < expression.size()) {
        if (startsNumber(expression, position)) {
            display += formatNumberTokenForDisplay(readNumberToken(expression, position));
        } else {
            display += expression[position];
            ++position;
        }
    }

    return display;
}

bool NumberFormatter::shouldUseScientific(double value) {
    return std::abs(value) >= 1000000000000000.0;
}

std::string NumberFormatter::formatPlain(double value) {
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(significantDigits) << value;

    return trimTrailingZeros(stream.str());
}

std::string NumberFormatter::formatScientific(double value) {
    std::ostringstream stream;
    stream << std::scientific << std::setprecision(significantDigits - 1) << value;

    return normalizeExponent(trimTrailingZeros(stream.str()));
}

std::string NumberFormatter::formatNumberTokenForDisplay(const std::string& token) {
    if (token.find('e') != std::string::npos || token.find('E') != std::string::npos) {
        return token;
    }

    if (integerDigitCount(token) <= maxPlainIntegerDigits) {
        return token;
    }

    try {
        return formatScientific(std::stod(token));
    } catch (const std::out_of_range&) {
        return token;
    }
}

std::string NumberFormatter::trimTrailingZeros(std::string value) {
    size_t exponentPosition = value.find_first_of("eE");
    std::string exponent;

    if (exponentPosition != std::string::npos) {
        exponent = value.substr(exponentPosition);
        value.erase(exponentPosition);
    }

    while (value.find('.') != std::string::npos && value.back() == '0') {
        value.pop_back();
    }

    if (!value.empty() && value.back() == '.') {
        value.pop_back();
    }

    return value + exponent;
}

std::string NumberFormatter::normalizeExponent(std::string value) {
    size_t exponentPosition = value.find_first_of("eE");

    if (exponentPosition == std::string::npos) {
        return value;
    }

    std::string mantissa = value.substr(0, exponentPosition);
    std::string exponent = value.substr(exponentPosition + 1);
    char sign = '+';
    size_t position = 0;

    if (position < exponent.size() && (exponent[position] == '+' || exponent[position] == '-')) {
        sign = exponent[position];
        ++position;
    }

    while (position < exponent.size() && exponent[position] == '0') {
        ++position;
    }

    std::string digits = exponent.substr(position);

    if (digits.empty()) {
        digits = "0";
    }

    return mantissa + "e" + sign + digits;
}
