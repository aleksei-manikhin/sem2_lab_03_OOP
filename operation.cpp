#include "operation.h"

Operation::Operation(const std::string& symbol, int priority)
    : symbol(symbol), priority(priority) {
}

std::string Operation::getSymbol() const {
    return symbol;
}

int Operation::getPriority() const {
    return priority;
}
