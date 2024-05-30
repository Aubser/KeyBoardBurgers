#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(cli::array<String^>^ args) {
   Application::EnableVisualStyles();
   Application::SetCompatibleTextRenderingDefault(false);

   KeyBoardBurgers::MyForm form;
   Application::Run(% form);
}