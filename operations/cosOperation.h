#ifndef COSOPERATION_H
#define COSOPERATION_H

#include "unaryOperation.h"

class CosOperation : public UnaryOperation {
public:
    CosOperation();
    double calculate(double value) const override;
};

#endif // COSOPERATION_H
