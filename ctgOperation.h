#ifndef CTGOPERATION_H
#define CTGOPERATION_H

#include "unaryOperation.h"

class CtgOperation : public UnaryOperation {
public:
    CtgOperation();
    double calculate(double value) const override;
};

#endif // CTGOPERATION_H
