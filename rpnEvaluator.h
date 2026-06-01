#ifndef RPNEVALUATOR_H
#define RPNEVALUATOR_H

#include "operations/operationRegistry.h"
#include "token.h"

#include <vector>

class RpnEvaluator {
public:
    double evaluate(const std::vector<Token>& rpnTokens,
                    const OperationRegistry& registry) const;

private:
    void handleNumber(const Token& token, std::vector<double>& values) const;
    void handleUnaryOperator(const Token& token,
                             std::vector<double>& values,
                             const OperationRegistry& registry) const;
    void handleBinaryOperator(const Token& token,
                              std::vector<double>& values,
                              const OperationRegistry& registry) const;
    double popValue(std::vector<double>& values) const;
};

#endif // RPNEVALUATOR_H
