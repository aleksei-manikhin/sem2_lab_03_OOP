#ifndef RECIPROCALOPERATION_H
#define RECIPROCALOPERATION_H

#include "unaryOperation.h"

class ReciprocalOperation : public UnaryOperation {
public:
    ReciprocalOperation();
    double calculate(double value) const override;
};

#endif // RECIPROCALOPERATION_H
