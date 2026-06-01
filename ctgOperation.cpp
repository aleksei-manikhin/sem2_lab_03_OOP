#include "ctgOperation.h"

#include <cmath>
#include <stdexcept>

CtgOperation::CtgOperation()
    : UnaryOperation("ctg", 3) {
}

double CtgOperation::calculate(double value) const {
    double sinValue = std::sin(value);

    if (std::abs(sinValue) < eps) {
        throw std::runtime_error("Cotangent is undefined");
    }

    return std::cos(value) / sinValue;
}
