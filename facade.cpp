#include "facade.h"

#include <stdexcept>

FacadeOperationResult Facade::pressAction(const std::string& action) {
    try {
        std::unique_ptr<CalculatorCommand> command = createCommand(action);
        return command->execute(logic);
    } catch (const std::exception& exception) {
        return errorResult(exception.what());
    }
}

std::string Facade::getDisplayText() const {
    return logic.getDisplayText();
}

std::unique_ptr<CalculatorCommand> Facade::createCommand(const std::string& action) const {
    if (action == "C") {
        return std::make_unique<ClearCommand>();
    }

    if (action == "Del") {
        return std::make_unique<DeleteCommand>();
    }

    if (action == "=") {
        return std::make_unique<EvaluateCommand>();
    }

    if (action == "+/-") {
        return std::make_unique<ChangeSignCommand>();
    }

    if (isFunctionAction(action)) {
        return std::make_unique<ApplyFunctionCommand>(action);
    }

    if (isAppendAction(action)) {
        return std::make_unique<AppendCommand>(action);
    }

    throw std::runtime_error("Unknown action: " + action);
}

bool Facade::isAppendAction(const std::string& action) const {
    static const std::string allowedActions = "0123456789.+-*/()";
    return action.size() == 1 && allowedActions.find(action[0]) != std::string::npos;
}

bool Facade::isFunctionAction(const std::string& action) const {
    return action == "sqrt"
           || action == "1/x"
           || action == "sin"
           || action == "cos"
           || action == "tg"
           || action == "ctg";
}

FacadeOperationResult Facade::errorResult(const std::string& message) const {
    return FacadeOperationResult(false, logic.getDisplayText(), message);
}
