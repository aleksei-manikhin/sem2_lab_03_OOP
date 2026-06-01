#ifndef BINARYOPERATION_H
#define BINARYOPERATION_H

#include "operation.h"

class BinaryOperation : public Operation {
public:
    BinaryOperation(const std::string& symbol, int priority);

    int getArity() const override;
    virtual double calculate(double left, double right) const = 0;
};

#endif // BINARYOPERATION_H
