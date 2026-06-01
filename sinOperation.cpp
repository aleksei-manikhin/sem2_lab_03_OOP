#include "sinOperation.h"

#include <cmath>

SinOperation::SinOperation()
    : UnaryOperation("sin", 3) {
}

double SinOperation::calculate(double value) const {
    return std::sin(value);
}
