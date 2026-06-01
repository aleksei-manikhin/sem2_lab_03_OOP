#ifndef FACADEOPERATIONRESULT_H
#define FACADEOPERATIONRESULT_H

#include <string>

class FacadeOperationResult {
public:
    FacadeOperationResult(bool successStatus, const std::string& displayText, const std::string& errorMessage = "");

    bool isSuccess() const;
    std::string getDisplayText() const;
    std::string getErrorMessage() const;

private:
    bool successStatus;
    std::string displayText;
    std::string errorMessage;
};

#endif // FACADEOPERATIONRESULT_H
