#ifndef CALCULATORLOGIC_H
#define CALCULATORLOGIC_H

#include "expressionBuilder.h"
#include "expressionEvaluator.h"

#include <string>

class CalculatorLogic {
public:
    void append(const std::string& value);
    void clear();
    void deleteLast();
    void calculate();
    void applyFunction(const std::string& functionName);
    void changeSign();

    std::string getExpression() const;
    std::string getDisplayText() const;

private:
    static constexpr double eps = 0.000001;

    ExpressionBuilder builder;
    ExpressionEvaluator evaluator;

    std::string currentExpressionOrZero() const;
    std::string formatResult(double value) const;
    void setCalculatedResult(double value);
};

#endif // CALCULATORLOGIC_H
