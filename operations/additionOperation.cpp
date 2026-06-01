#include "additionOperation.h"

AdditionOperation::AdditionOperation()
    : BinaryOperation("+", 1) {
}

double AdditionOperation::calculate(double left, double right) const {
    return left + right;
}
