#include "MainForm.h"
#include <stdexcept>
#include <string>

namespace CalculatorEXAM {

    // ═════════════════════════════════════════════════════════
    //  Вспомогательная фабрика кнопок
    // ═════════════════════════════════════════════════════════

    static Button^ MakeButton(String^ text, Drawing::Point loc, Drawing::Size sz,
                              Drawing::Color bg, Drawing::Color fg,
                              float fontSize = 22.0f)
    {
        Button^ b  = gcnew Button();
        b->Text    = text;
        b->Location = loc;
        b->Size     = sz;
        b->BackColor = bg;
        b->ForeColor = fg;
        b->FlatStyle  = FlatStyle::Flat;
        b->FlatAppearance->BorderSize = 1;
        b->FlatAppearance->BorderColor = Drawing::Color::FromArgb(60, 60, 60);
        b->Font    = gcnew Drawing::Font(L"Segoe UI", fontSize,
                                         Drawing::FontStyle::Bold);
        b->Cursor  = Cursors::Hand;
        return b;
    }

    // ═════════════════════════════════════════════════════════
    //  Конструктор / деструктор
    // ═════════════════════════════════════════════════════════

    MainForm::MainForm()
        : m_calc(new Calculator()), m_afterEqual(false)
    {
        InitializeComponent();
    }

    MainForm::~MainForm()
    {
        delete m_calc;
    }

    // ═════════════════════════════════════════════════════════
    //  InitializeComponent
    // ═════════════════════════════════════════════════════════

    void MainForm::InitializeComponent()
    {
        // ── Размеры ячейки сетки ────────────────────────────
        const int W = 90;   // ширина кнопки
        const int H = 70;   // высота кнопки
        const int G = 4;    // зазор
        const int X0 = 5;   // отступ слева
        const int Y0 = 100; // отступ сверху (под дисплей)

        // Цвета в стиле тёмного калькулятора
        auto clrDark  = Drawing::Color::FromArgb(50,  50,  50);   // цифры
        auto clrOp    = Drawing::Color::FromArgb(255, 149,  0);   // оранжевые операторы
        auto clrFunc  = Drawing::Color::FromArgb(100, 100, 100);  // серые функции (AC, ±, %)
        auto clrWhite = Drawing::Color::White;
        auto clrBlack = Drawing::Color::Black;

        auto Cell = [&](int col, int row) -> Drawing::Point {
            return Drawing::Point(X0 + col * (W + G), Y0 + row * (H + G));
        };
        auto Sz = Drawing::Size(W, H);

        // ═══ Форма ═══
        this->Text            = L"Calculator";
        this->ClientSize      = Drawing::Size(X0 * 2 + 4 * (W + G) - G, Y0 + 5 * (H + G) + 5);
        this->BackColor       = Drawing::Color::FromArgb(28, 28, 28);
        this->FormBorderStyle = Windows::Forms::FormBorderStyle::FixedSingle;
        this->MaximizeBox     = false;
        this->StartPosition   = FormStartPosition::CenterScreen;
        this->Cursor          = Cursors::Default;

        // ═══ Дисплей ═══
        m_display = gcnew Label();
        m_display->Text      = L"0";
        m_display->Location  = Drawing::Point(X0, 10);
        m_display->Size      = Drawing::Size(this->ClientSize.Width - X0 * 2, 80);
        m_display->BackColor = Drawing::Color::Transparent;
        m_display->ForeColor = clrWhite;
        m_display->Font      = gcnew Drawing::Font(L"Segoe UI Light", 36, Drawing::FontStyle::Regular);
        m_display->TextAlign = ContentAlignment::MiddleRight;
        this->Controls->Add(m_display);

        // ═══ Ряд 0: AC  ±  %  ÷ ═══
        m_btnAC         = MakeButton(L"AC", Cell(0,0), Sz, clrFunc, clrBlack);
        m_btnToggleSign = MakeButton(L"±",  Cell(1,0), Sz, clrFunc, clrBlack);
        m_btnPercent    = MakeButton(L"%",  Cell(2,0), Sz, clrFunc, clrBlack);
        m_btnDivide     = MakeButton(L"÷",  Cell(3,0), Sz, clrOp,   clrWhite);

        // ═══ Ряд 1: 7  8  9  × ═══
        m_btn7          = MakeButton(L"7",  Cell(0,1), Sz, clrDark, clrWhite);
        m_btn8          = MakeButton(L"8",  Cell(1,1), Sz, clrDark, clrWhite);
        m_btn9          = MakeButton(L"9",  Cell(2,1), Sz, clrDark, clrWhite);
        m_btnMultiply   = MakeButton(L"×",  Cell(3,1), Sz, clrOp,   clrWhite);

        // ═══ Ряд 2: 4  5  6  − ═══
        m_btn4          = MakeButton(L"4",  Cell(0,2), Sz, clrDark, clrWhite);
        m_btn5          = MakeButton(L"5",  Cell(1,2), Sz, clrDark, clrWhite);
        m_btn6          = MakeButton(L"6",  Cell(2,2), Sz, clrDark, clrWhite);
        m_btnSubtract   = MakeButton(L"−",  Cell(3,2), Sz, clrOp,   clrWhite);

        // ═══ Ряд 3: 1  2  3  + ═══
        m_btn1          = MakeButton(L"1",  Cell(0,3), Sz, clrDark, clrWhite);
        m_btn2          = MakeButton(L"2",  Cell(1,3), Sz, clrDark, clrWhite);
        m_btn3          = MakeButton(L"3",  Cell(2,3), Sz, clrDark, clrWhite);
        m_btnAdd        = MakeButton(L"+",  Cell(3,3), Sz, clrOp,   clrWhite);

        // ═══ Ряд 4: [0 wide]  .  = ═══
        auto SzWide = Drawing::Size(W * 2 + G, H);
        m_btn0       = MakeButton(L"0", Drawing::Point(X0, Y0 + 4*(H+G)), SzWide, clrDark, clrWhite);
        m_btn0->TextAlign = ContentAlignment::MiddleLeft;
        m_btn0->Padding   = System::Windows::Forms::Padding(18, 0, 0, 0);

        m_btnDot   = MakeButton(L",",  Cell(2,4), Sz, clrDark, clrWhite);
        m_btnEqual = MakeButton(L"=",  Cell(3,4), Sz, clrOp,   clrWhite);

        // ═══ Служебные кнопки ═══
        m_btnExit  = MakeButton(L"✕", Drawing::Point(this->ClientSize.Width - 30, 0),
                                Drawing::Size(30, 20),
                                Drawing::Color::Transparent, Drawing::Color::Gray, 9.0f);
        m_btnTest  = MakeButton(L"T", Drawing::Point(0, 0),
                                Drawing::Size(20, 20),
                                Drawing::Color::Transparent, Drawing::Color::Gray, 8.0f);

        // ═══ Привязка обработчиков ═══
        m_btnAC        ->Click += gcnew EventHandler(this, &MainForm::BtnAC_Click);
        m_btnToggleSign->Click += gcnew EventHandler(this, &MainForm::BtnToggleSign_Click);
        m_btnPercent   ->Click += gcnew EventHandler(this, &MainForm::BtnPercent_Click);
        m_btnDivide    ->Click += gcnew EventHandler(this, &MainForm::BtnDivide_Click);
        m_btn7         ->Click += gcnew EventHandler(this, &MainForm::BtnNumber_Click);
        m_btn8         ->Click += gcnew EventHandler(this, &MainForm::BtnNumber_Click);
        m_btn9         ->Click += gcnew EventHandler(this, &MainForm::BtnNumber_Click);
        m_btnMultiply  ->Click += gcnew EventHandler(this, &MainForm::BtnMultiply_Click);
        m_btn4         ->Click += gcnew EventHandler(this, &MainForm::BtnNumber_Click);
        m_btn5         ->Click += gcnew EventHandler(this, &MainForm::BtnNumber_Click);
        m_btn6         ->Click += gcnew EventHandler(this, &MainForm::BtnNumber_Click);
        m_btnSubtract  ->Click += gcnew EventHandler(this, &MainForm::BtnSubtract_Click);
        m_btn1         ->Click += gcnew EventHandler(this, &MainForm::BtnNumber_Click);
        m_btn2         ->Click += gcnew EventHandler(this, &MainForm::BtnNumber_Click);
        m_btn3         ->Click += gcnew EventHandler(this, &MainForm::BtnNumber_Click);
        m_btnAdd       ->Click += gcnew EventHandler(this, &MainForm::BtnAdd_Click);
        m_btn0         ->Click += gcnew EventHandler(this, &MainForm::BtnNumber_Click);
        m_btnDot       ->Click += gcnew EventHandler(this, &MainForm::BtnDot_Click);
        m_btnEqual     ->Click += gcnew EventHandler(this, &MainForm::BtnEqual_Click);
        m_btnExit      ->Click += gcnew EventHandler(this, &MainForm::BtnExit_Click);
        m_btnTest      ->Click += gcnew EventHandler(this, &MainForm::BtnTest_Click);

        // ═══ Добавление на форму ═══
        this->Controls->Add(m_btnAC);
        this->Controls->Add(m_btnToggleSign);
        this->Controls->Add(m_btnPercent);
        this->Controls->Add(m_btnDivide);
        this->Controls->Add(m_btn7);
        this->Controls->Add(m_btn8);
        this->Controls->Add(m_btn9);
        this->Controls->Add(m_btnMultiply);
        this->Controls->Add(m_btn4);
        this->Controls->Add(m_btn5);
        this->Controls->Add(m_btn6);
        this->Controls->Add(m_btnSubtract);
        this->Controls->Add(m_btn1);
        this->Controls->Add(m_btn2);
        this->Controls->Add(m_btn3);
        this->Controls->Add(m_btnAdd);
        this->Controls->Add(m_btn0);
        this->Controls->Add(m_btnDot);
        this->Controls->Add(m_btnEqual);
        this->Controls->Add(m_btnExit);
        this->Controls->Add(m_btnTest);
    }

    // ═════════════════════════════════════════════════════════
    //  Вспомогательные методы
    // ═════════════════════════════════════════════════════════

    void MainForm::AppendDigit(String^ digit)
    {
        if (m_display->Text == L"0" || m_afterEqual) {
            m_display->Text = digit;
            m_afterEqual = false;
        }
        else {
            m_display->Text += digit;
        }
    }

    void MainForm::OnOperationButton(Operation op)
    {
        double val = Convert::ToDouble(m_display->Text);
        m_calc->SetOperation(val, op);
        m_display->Text = L"0";
    }

    // ═════════════════════════════════════════════════════════
    //  Обработчики кликов — цифры
    // ═════════════════════════════════════════════════════════

    void MainForm::BtnNumber_Click(Object^ sender, EventArgs^ e)
    {
        Button^ btn = safe_cast<Button^>(sender);
        AppendDigit(btn->Text);
    }

    // ═════════════════════════════════════════════════════════
    //  Обработчики кликов — операторы
    // ═════════════════════════════════════════════════════════

    void MainForm::BtnAdd_Click(Object^ sender, EventArgs^ e)       { OnOperationButton(Operation::Add);      }
    void MainForm::BtnSubtract_Click(Object^ sender, EventArgs^ e)  { OnOperationButton(Operation::Subtract); }
    void MainForm::BtnMultiply_Click(Object^ sender, EventArgs^ e)  { OnOperationButton(Operation::Multiply); }
    void MainForm::BtnDivide_Click(Object^ sender, EventArgs^ e)    { OnOperationButton(Operation::Divide);   }
    void MainForm::BtnPercent_Click(Object^ sender, EventArgs^ e)   { OnOperationButton(Operation::Percent);  }

    void MainForm::BtnEqual_Click(Object^ sender, EventArgs^ e)
    {
        if (m_calc->GetOperation() == Operation::None)
            return;

        try {
            double second = Convert::ToDouble(m_display->Text);
            double result = m_calc->Calculate(second);
            m_display->Text = Convert::ToString(result);
            m_afterEqual = true;
            m_calc->Reset();
        }
        catch (std::invalid_argument&) {
            MessageBox::Show(this, L"Нельзя делить на ноль!", L"Ошибка",
                             MessageBoxButtons::OK, MessageBoxIcon::Error);
            m_display->Text = L"0";
            m_calc->Reset();
        }
    }

    // ═════════════════════════════════════════════════════════
    //  Обработчики кликов — прочие
    // ═════════════════════════════════════════════════════════

    void MainForm::BtnAC_Click(Object^ sender, EventArgs^ e)
    {
        m_display->Text = L"0";
        m_afterEqual    = false;
        m_calc->Reset();
    }

    void MainForm::BtnToggleSign_Click(Object^ sender, EventArgs^ e)
    {
        double val = Convert::ToDouble(m_display->Text) * -1.0;
        m_display->Text = Convert::ToString(val);
    }

    void MainForm::BtnDot_Click(Object^ sender, EventArgs^ e)
    {
        if (!m_display->Text->Contains(L","))
            m_display->Text += L",";
    }

    void MainForm::BtnExit_Click(Object^ sender, EventArgs^ e)
    {
        this->Close();
    }

    // ═════════════════════════════════════════════════════════
    //  Тесты (встроенные)
    // ═════════════════════════════════════════════════════════

    void MainForm::RunTests()
    {
        Calculator calc;
        std::string report;

        struct TestCase {
            double a, b, expected;
            Operation op;
            const char* name;
        };

        TestCase cases[] = {
            { 9999, 100,    10099,    Operation::Add,      "Test #1 (сложение)"   },
            { 9999, 100,  999900,    Operation::Multiply,  "Test #2 (умножение)"  },
            { 9999, 100,    99.99,   Operation::Divide,    "Test #3 (деление)"    },
            { 9999, 100,    9899,    Operation::Subtract,  "Test #4 (вычитание)"  },
            { 9999, 100,    9999,    Operation::Percent,   "Test #5 (проценты)"   },
        };

        for (auto& tc : cases) {
            calc.SetOperation(tc.a, tc.op);
            double res = calc.Calculate(tc.b);
            bool ok = (res == tc.expected);
            report += std::string(tc.name) + (ok ? " — ПРОЙДЕН\n" : " — ПРОВАЛЕН\n");
        }

        System::String^ msg = msclr::interop::marshal_as<System::String^>(report);
        MessageBox::Show(msg, L"Результаты тестов");
    }

    void MainForm::BtnTest_Click(Object^ sender, EventArgs^ e)
    {
        RunTests();
    }

} // namespace CalculatorEXAM
