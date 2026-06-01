#include "binaryOperation.h"

BinaryOperation::BinaryOperation(const std::string& symbol, int priority)
    : Operation(symbol, priority) {
}

int BinaryOperation::getArity() const {
    return 2;
}
