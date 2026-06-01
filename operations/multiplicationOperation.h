#ifndef MULTIPLICATIONOPERATION_H
#define MULTIPLICATIONOPERATION_H

#include "binaryOperation.h"

class MultiplicationOperation : public BinaryOperation {
public:
    MultiplicationOperation();
    double calculate(double left, double right) const override;
};

#endif // MULTIPLICATIONOPERATION_H
