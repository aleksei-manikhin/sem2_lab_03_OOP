#ifndef OPERATIONREGISTRY_H
#define OPERATIONREGISTRY_H

#include "binaryOperation.h"
#include "unaryOperation.h"

#include <map>
#include <memory>
#include <string>

class OperationRegistry {
public:
    OperationRegistry();

    void registerUnary(std::unique_ptr<UnaryOperation> operation);
    void registerBinary(std::unique_ptr<BinaryOperation> operation);

    bool isUnary(const std::string& symbol) const;
    bool isBinary(const std::string& symbol) const;
    bool isOperation(const std::string& symbol) const;

    const UnaryOperation& getUnary(const std::string& symbol) const;
    const BinaryOperation& getBinary(const std::string& symbol) const;
    int getPriority(const std::string& symbol) const;

private:
    std::map<std::string, std::unique_ptr<UnaryOperation>> unaryOperations;
    std::map<std::string, std::unique_ptr<BinaryOperation>> binaryOperations;

    void registerDefaultOperations();
};

#endif // OPERATIONREGISTRY_H
