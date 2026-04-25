#include "src/MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

/// <summary>
/// Точка входа Windows Forms приложения.
/// </summary>
[STAThreadAttribute]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    CalculatorEXAM::MainForm form;
    Application::Run(%form);

    return 0;
}
