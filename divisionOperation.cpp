#include "divisionOperation.h"

#include <cmath>
#include <stdexcept>

DivisionOperation::DivisionOperation()
    : BinaryOperation("/", 2) {
}

double DivisionOperation::calculate(double left, double right) const {
    if (std::abs(right) < eps) {
        throw std::runtime_error("Division by zero");
    }

    return left / right;
}
