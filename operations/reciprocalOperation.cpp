#include "reciprocalOperation.h"

#include <cmath>
#include <stdexcept>

ReciprocalOperation::ReciprocalOperation()
    : UnaryOperation("1/x", 3) {
}

double ReciprocalOperation::calculate(double value) const {
    if (std::abs(value) < eps) {
        throw std::runtime_error("Division by zero");
    }

    return 1 / value;
}
