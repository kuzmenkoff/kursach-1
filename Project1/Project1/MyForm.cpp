#include "MyForm.h"
#include <string>

using namespace std;
using namespace System;
using namespace System::Windows::Forms;



[STAThreadAttribute]

void main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Project1::MyForm form;
    Application::Run(% form);
}


