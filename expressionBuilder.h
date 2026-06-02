#ifndef EXPRESSIONBUILDER_H
#define EXPRESSIONBUILDER_H

#include <string>

class ExpressionBuilder {
public:
    void append(const std::string& value);
    void clear();
    void deleteLast();
    void setResult(const std::string& value);
    void changeSign();

    std::string getExpression() const;
    std::string buildExpressionWithFunctionOnLastOperand(const std::string& functionName) const;
    std::string getDisplayText() const;
    bool isResultShown() const;

private:
    std::string expression;
    bool resultShown = false;
};

#endif // EXPRESSIONBUILDER_H
