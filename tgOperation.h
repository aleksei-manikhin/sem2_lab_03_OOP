#ifndef TGOPERATION_H
#define TGOPERATION_H

#include "unaryOperation.h"

class TgOperation : public UnaryOperation {
public:
    TgOperation();
    double calculate(double value) const override;
};

#endif // TGOPERATION_H
