#include "QueueForm.h"
using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(cli::array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Simulator::QueueForm form;
	Application::Run(% form);
}

