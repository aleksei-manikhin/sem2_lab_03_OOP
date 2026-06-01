#ifndef SQRTOPERATION_H
#define SQRTOPERATION_H

#include "unaryOperation.h"

class SqrtOperation : public UnaryOperation {
public:
    SqrtOperation();
    double calculate(double value) const override;
};

#endif // SQRTOPERATION_H
