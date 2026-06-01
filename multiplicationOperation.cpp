#include "multiplicationOperation.h"

MultiplicationOperation::MultiplicationOperation()
    : BinaryOperation("*", 2) {
}

double MultiplicationOperation::calculate(double left, double right) const {
    return left * right;
}
