#ifndef OPERATION_H
#define OPERATION_H

#include <string>

class Operation {
public:
    Operation(const std::string& symbol, int priority);
    virtual ~Operation() = default;

    std::string getSymbol() const;
    int getPriority() const;
    virtual int getArity() const = 0; //количество аргументов

protected:
    static constexpr double eps = 0.000001;

private:
    std::string symbol;
    int priority;
};

#endif // OPERATION_H
