#include "facadeOperationResult.h"

FacadeOperationResult::FacadeOperationResult(bool successStatus, const std::string& displayText, const std::string& errorMessage)
    : successStatus(successStatus), displayText(displayText), errorMessage(errorMessage) {
}

bool FacadeOperationResult::isSuccess() const {
    return successStatus;
}

std::string FacadeOperationResult::getDisplayText() const {
    return displayText;
}

std::string FacadeOperationResult::getErrorMessage() const {
    return errorMessage;
}
