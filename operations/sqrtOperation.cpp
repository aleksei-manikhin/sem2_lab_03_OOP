#include "sqrtOperation.h"

#include <cmath>
#include <stdexcept>

SqrtOperation::SqrtOperation()
    : UnaryOperation("sqrt", 3) {
}

double SqrtOperation::calculate(double value) const {
    if (value < 0) {
        throw std::runtime_error("Square root from negative number");
    }

    return std::sqrt(value);
}
