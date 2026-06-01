#include "calculatorCommand.h"

AppendCommand::AppendCommand(const std::string& value)
    : value(value) {
}

FacadeOperationResult AppendCommand::execute(CalculatorLogic& logic) const {
    logic.append(value);
    return FacadeOperationResult(true, logic.getDisplayText());
}

FacadeOperationResult ClearCommand::execute(CalculatorLogic& logic) const {
    logic.clear();
    return FacadeOperationResult(true, logic.getDisplayText());
}

FacadeOperationResult DeleteCommand::execute(CalculatorLogic& logic) const {
    logic.deleteLast();
    return FacadeOperationResult(true, logic.getDisplayText());
}

FacadeOperationResult EvaluateCommand::execute(CalculatorLogic& logic) const {
    logic.calculate();
    return FacadeOperationResult(true, logic.getDisplayText());
}

ApplyFunctionCommand::ApplyFunctionCommand(const std::string& functionName)
    : functionName(functionName) {
}

FacadeOperationResult ApplyFunctionCommand::execute(CalculatorLogic& logic) const {
    logic.applyFunction(functionName);
    return FacadeOperationResult(true, logic.getDisplayText());
}

FacadeOperationResult ChangeSignCommand::execute(CalculatorLogic& logic) const {
    logic.changeSign();
    return FacadeOperationResult(true, logic.getDisplayText());
}
