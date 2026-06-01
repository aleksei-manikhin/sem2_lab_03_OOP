#ifndef SINOPERATION_H
#define SINOPERATION_H

#include "unaryOperation.h"

class SinOperation : public UnaryOperation {
public:
    SinOperation();
    double calculate(double value) const override;
};

#endif // SINOPERATION_H
