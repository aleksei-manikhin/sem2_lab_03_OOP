#ifndef NUMBERFORMATTER_H
#define NUMBERFORMATTER_H

#include <string>

class NumberFormatter {
public:
    static std::string formatResult(double value);
    static std::string formatExpressionForDisplay(const std::string& expression);

private:
    static constexpr int maxPlainIntegerDigits = 15;
    static constexpr int significantDigits = 15;

    static bool shouldUseScientific(double value);
    static std::string formatPlain(double value);
    static std::string formatScientific(double value);
    static std::string formatNumberTokenForDisplay(const std::string& token);
    static std::string trimTrailingZeros(std::string value);
    static std::string normalizeExponent(std::string value);
};

#endif // NUMBERFORMATTER_H
