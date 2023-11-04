#include "userGUI.h"

using namespace System;
using namespace System::Windows::Forms;

void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	PhotoEditorBlurCPPASMx64::userGUI form;
	Application::Run(% form);
}