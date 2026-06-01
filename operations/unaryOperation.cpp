#include "unaryOperation.h"

#include <numbers>

UnaryOperation::UnaryOperation(const std::string& symbol, int priority)
    : Operation(symbol, priority) {
}

int UnaryOperation::getArity() const {
    return 1;
}

double UnaryOperation::degreesToRadians(double degrees) const {
    return degrees * std::numbers::pi_v<double> / 180.0;
}
