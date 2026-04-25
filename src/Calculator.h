#pragma once

namespace CalculatorEXAM {

    /// <summary>
    /// Список поддерживаемых математических операций.
    /// </summary>
    enum class Operation {
        None,
        Add,
        Subtract,
        Multiply,
        Divide,
        Percent
    };

    /// <summary>
    /// Чистая логика калькулятора — без зависимостей от UI.
    /// Хранит первый операнд и текущую операцию,
    /// возвращает результат при вызове Calculate().
    /// </summary>
    class Calculator {
    public:
        Calculator();

        /// <summary>Сохраняет первый операнд и устанавливает операцию.</summary>
        void SetOperation(double firstOperand, Operation op);

        /// <summary>
        /// Вычисляет результат операции над сохранённым первым операндом
        /// и переданным вторым операндом.
        /// При делении на ноль выбрасывает std::invalid_argument.
        /// </summary>
        double Calculate(double secondOperand);

        /// <summary>Сбрасывает состояние в начальное.</summary>
        void Reset();

        /// <summary>Возвращает текущую операцию.</summary>
        Operation GetOperation() const;

        /// <summary>Возвращает сохранённый первый операнд.</summary>
        double GetFirstOperand() const;

    private:
        double m_firstOperand;
        Operation m_operation;
    };

} // namespace CalculatorEXAM
