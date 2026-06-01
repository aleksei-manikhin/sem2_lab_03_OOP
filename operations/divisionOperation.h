#ifndef DIVISIONOPERATION_H
#define DIVISIONOPERATION_H

#include "binaryOperation.h"

class DivisionOperation : public BinaryOperation {
public:
    DivisionOperation();
    double calculate(double left, double right) const override;
};

#endif // DIVISIONOPERATION_H
