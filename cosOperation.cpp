#include "cosOperation.h"

#include <cmath>

CosOperation::CosOperation()
    : UnaryOperation("cos", 3) {
}

double CosOperation::calculate(double value) const {
    return std::cos(value);
}
