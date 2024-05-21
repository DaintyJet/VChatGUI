#include "VChatGUI.h"
#include "ServerManager.h"
using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
void main(array<String^>^ args) {

	server_manage::ServerManager obj = server_manage::ServerManager(9999);
	obj.initPipes();

	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	VChatGUI::VChatGUI frm;
	Application::Run(% frm);
}



		   // Helper Function to Initalize Unnamed Pipes
	void Init_Pipes() {

	}

	// Custom Function to start the server
	void Start_Server(int port) {
		Init_Pipes();

	}