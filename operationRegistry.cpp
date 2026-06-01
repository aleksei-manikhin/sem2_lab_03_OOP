#include "operationRegistry.h"

#include "additionOperation.h"
#include "cosOperation.h"
#include "ctgOperation.h"
#include "divisionOperation.h"
#include "multiplicationOperation.h"
#include "reciprocalOperation.h"
#include "sinOperation.h"
#include "sqrtOperation.h"
#include "subtractionOperation.h"
#include "tgOperation.h"

#include <stdexcept>

OperationRegistry::OperationRegistry() {
    registerDefaultOperations();
}

void OperationRegistry::registerUnary(std::unique_ptr<UnaryOperation> operation) {
    unaryOperations[operation->getSymbol()] = std::move(operation);
}

void OperationRegistry::registerBinary(std::unique_ptr<BinaryOperation> operation) {
    binaryOperations[operation->getSymbol()] = std::move(operation);
}

bool OperationRegistry::isUnary(const std::string& symbol) const {
    return unaryOperations.find(symbol) != unaryOperations.end();
}

bool OperationRegistry::isBinary(const std::string& symbol) const {
    return binaryOperations.find(symbol) != binaryOperations.end();
}

bool OperationRegistry::isOperation(const std::string& symbol) const {
    return isUnary(symbol) || isBinary(symbol);
}

const UnaryOperation& OperationRegistry::getUnary(const std::string& symbol) const {
    auto iterator = unaryOperations.find(symbol);

    if (iterator == unaryOperations.end()) {
        throw std::runtime_error("Unknown unary operation: " + symbol);
    }

    return *iterator->second;
}

const BinaryOperation& OperationRegistry::getBinary(const std::string& symbol) const {
    auto iterator = binaryOperations.find(symbol);

    if (iterator == binaryOperations.end()) {
        throw std::runtime_error("Unknown binary operation: " + symbol);
    }

    return *iterator->second;
}

int OperationRegistry::getPriority(const std::string& symbol) const {
    if (isUnary(symbol)) {
        return getUnary(symbol).getPriority();
    }

    return getBinary(symbol).getPriority();
}

void OperationRegistry::registerDefaultOperations() {
    registerBinary(std::make_unique<AdditionOperation>());
    registerBinary(std::make_unique<SubtractionOperation>());
    registerBinary(std::make_unique<MultiplicationOperation>());
    registerBinary(std::make_unique<DivisionOperation>());

    registerUnary(std::make_unique<SqrtOperation>());
    registerUnary(std::make_unique<ReciprocalOperation>());
    registerUnary(std::make_unique<SinOperation>());
    registerUnary(std::make_unique<CosOperation>());
    registerUnary(std::make_unique<TgOperation>());
    registerUnary(std::make_unique<CtgOperation>());
}
