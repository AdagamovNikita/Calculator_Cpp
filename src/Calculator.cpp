#include "Calculator.h"
#include <stdexcept>

namespace CalculatorEXAM {

    Calculator::Calculator()
        : m_firstOperand(0.0), m_operation(Operation::None)
    {
    }

    void Calculator::SetOperation(double firstOperand, Operation op)
    {
        m_firstOperand = firstOperand;
        m_operation = op;
    }

    double Calculator::Calculate(double secondOperand)
    {
        switch (m_operation) {
        case Operation::Add:
            return m_firstOperand + secondOperand;

        case Operation::Subtract:
            return m_firstOperand - secondOperand;

        case Operation::Multiply:
            return m_firstOperand * secondOperand;

        case Operation::Divide:
            if (secondOperand == 0.0)
                throw std::invalid_argument("Division by zero");
            return m_firstOperand / secondOperand;

        case Operation::Percent:
            // x% от числа: first * second / 100
            return m_firstOperand * secondOperand / 100.0;

        default:
            return secondOperand;
        }
    }

    void Calculator::Reset()
    {
        m_firstOperand = 0.0;
        m_operation = Operation::None;
    }

    Operation Calculator::GetOperation() const
    {
        return m_operation;
    }

    double Calculator::GetFirstOperand() const
    {
        return m_firstOperand;
    }

} // namespace CalculatorEXAM
