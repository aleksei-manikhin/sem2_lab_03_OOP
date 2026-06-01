#ifndef EXPRESSIONEVALUATOR_H
#define EXPRESSIONEVALUATOR_H

#include "operations/operationRegistry.h"
#include "rpnEvaluator.h"
#include "shuntingYard.h"
#include "tokenizer.h"

#include <string>

class ExpressionEvaluator {
public:
    double evaluate(const std::string& expression) const;

private:
    OperationRegistry registry;
    Tokenizer tokenizer;
    ShuntingYard shuntingYard;
    RpnEvaluator rpnEvaluator;

    void validateExpression(const std::string& expression) const;
};

#endif // EXPRESSIONEVALUATOR_H
