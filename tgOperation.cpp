#include "tgOperation.h"

#include <cmath>
#include <stdexcept>

TgOperation::TgOperation()
    : UnaryOperation("tg", 3) {
}

double TgOperation::calculate(double value) const {
    double cosValue = std::cos(value);

    if (std::abs(cosValue) < eps) {
        throw std::runtime_error("Tangent is undefined");
    }

    return std::tan(value);
}
