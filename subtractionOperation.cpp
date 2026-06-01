#include "subtractionOperation.h"

SubtractionOperation::SubtractionOperation()
    : BinaryOperation("-", 1) {
}

double SubtractionOperation::calculate(double left, double right) const {
    return left - right;
}
