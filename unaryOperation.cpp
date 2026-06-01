#include "unaryOperation.h"

UnaryOperation::UnaryOperation(const std::string& symbol, int priority)
    : Operation(symbol, priority) {
}

int UnaryOperation::getArity() const {
    return 1;
}
