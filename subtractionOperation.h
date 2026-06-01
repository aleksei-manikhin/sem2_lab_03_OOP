#ifndef SUBTRACTIONOPERATION_H
#define SUBTRACTIONOPERATION_H

#include "binaryOperation.h"

class SubtractionOperation : public BinaryOperation {
public:
    SubtractionOperation();
    double calculate(double left, double right) const override;
};

#endif // SUBTRACTIONOPERATION_H
