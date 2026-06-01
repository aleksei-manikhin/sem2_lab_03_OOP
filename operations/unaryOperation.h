#ifndef UNARYOPERATION_H
#define UNARYOPERATION_H

#include "operation.h"

class UnaryOperation : public Operation {
public:
    UnaryOperation(const std::string& symbol, int priority);

    int getArity() const override;
    virtual double calculate(double value) const = 0;

protected:
    double degreesToRadians(double degrees) const;
};

#endif // UNARYOPERATION_H
