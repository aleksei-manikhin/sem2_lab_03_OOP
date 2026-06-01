#ifndef ADDITIONOPERATION_H
#define ADDITIONOPERATION_H

#include "binaryOperation.h"

class AdditionOperation : public BinaryOperation {
public:
    AdditionOperation();
    double calculate(double left, double right) const override;
};

#endif // ADDITIONOPERATION_H
