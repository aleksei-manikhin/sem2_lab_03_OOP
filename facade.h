#ifndef FACADE_H
#define FACADE_H

#include "calculatorCommand.h"
#include "calculatorLogic.h"
#include "facadeOperationResult.h"

#include <memory>
#include <string>

class Facade {
public:
    FacadeOperationResult pressAction(const std::string& action);
    std::string getDisplayText() const;

private:
    CalculatorLogic logic;

    std::unique_ptr<CalculatorCommand> createCommand(const std::string& action) const;
    bool isAppendAction(const std::string& action) const;
    bool isFunctionAction(const std::string& action) const;
    FacadeOperationResult errorResult(const std::string& message) const;
};

#endif // FACADE_H
