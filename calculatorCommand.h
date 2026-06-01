#ifndef CALCULATORCOMMAND_H
#define CALCULATORCOMMAND_H

#include "calculatorLogic.h"
#include "facadeOperationResult.h"

#include <string>

class CalculatorCommand {
public:
    virtual ~CalculatorCommand() = default;
    virtual FacadeOperationResult execute(CalculatorLogic& logic) const = 0;
};

class AppendCommand : public CalculatorCommand {
public:
    explicit AppendCommand(const std::string& value);
    FacadeOperationResult execute(CalculatorLogic& logic) const override;

private:
    std::string value;
};

class ClearCommand : public CalculatorCommand {
public:
    FacadeOperationResult execute(CalculatorLogic& logic) const override;
};

class DeleteCommand : public CalculatorCommand {
public:
    FacadeOperationResult execute(CalculatorLogic& logic) const override;
};

class EvaluateCommand : public CalculatorCommand {
public:
    FacadeOperationResult execute(CalculatorLogic& logic) const override;
};

class ApplyFunctionCommand : public CalculatorCommand {
public:
    explicit ApplyFunctionCommand(const std::string& functionName);
    FacadeOperationResult execute(CalculatorLogic& logic) const override;

private:
    std::string functionName;
};

class ChangeSignCommand : public CalculatorCommand {
public:
    FacadeOperationResult execute(CalculatorLogic& logic) const override;
};

#endif // CALCULATORCOMMAND_H
