#pragma once

#include "Calculator.h"
#include <msclr/marshal_windows.h>

namespace CalculatorEXAM {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;

    /// <summary>
    /// Главная форма калькулятора.
    /// Вся математическая логика делегирована классу Calculator.
    /// </summary>
    public ref class MainForm : public Form
    {
    public:
        MainForm();

    protected:
        ~MainForm();

    private:
        // ── Бизнес-логика ──────────────────────────────────────
        Calculator* m_calc;   // нативный объект логики
        bool        m_afterEqual; // флаг: результат только что вычислен

        // ── Вспомогательные методы ─────────────────────────────
        void OnOperationButton(Operation op);
        void AppendDigit(String^ digit);
        void RunTests();

        // ── Элементы управления ────────────────────────────────
        Label^  m_display;

        Button^ m_btnAC;
        Button^ m_btnToggleSign;
        Button^ m_btnPercent;
        Button^ m_btnDivide;

        Button^ m_btn7;
        Button^ m_btn8;
        Button^ m_btn9;
        Button^ m_btnMultiply;

        Button^ m_btn4;
        Button^ m_btn5;
        Button^ m_btn6;
        Button^ m_btnSubtract;

        Button^ m_btn1;
        Button^ m_btn2;
        Button^ m_btn3;
        Button^ m_btnAdd;

        Button^ m_btn0;
        Button^ m_btnDot;
        Button^ m_btnEqual;

        Button^ m_btnExit;
        Button^ m_btnTest;

        // ── Инициализация UI ───────────────────────────────────
        void InitializeComponent();

        // ── Обработчики кликов ─────────────────────────────────
        void BtnNumber_Click(Object^ sender, EventArgs^ e);
        void BtnAdd_Click    (Object^ sender, EventArgs^ e);
        void BtnSubtract_Click(Object^ sender, EventArgs^ e);
        void BtnMultiply_Click(Object^ sender, EventArgs^ e);
        void BtnDivide_Click  (Object^ sender, EventArgs^ e);
        void BtnPercent_Click (Object^ sender, EventArgs^ e);
        void BtnEqual_Click   (Object^ sender, EventArgs^ e);
        void BtnAC_Click      (Object^ sender, EventArgs^ e);
        void BtnToggleSign_Click(Object^ sender, EventArgs^ e);
        void BtnDot_Click     (Object^ sender, EventArgs^ e);
        void BtnExit_Click    (Object^ sender, EventArgs^ e);
        void BtnTest_Click    (Object^ sender, EventArgs^ e);
    };

} // namespace CalculatorEXAM
