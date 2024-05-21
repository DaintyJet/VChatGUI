#include "VChatGUI.h"
#include "ServerManager.h"
#include <stdio.h>
#include <strsafe.h>

using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
void main(array<String^>^ args) {

	//server_manage::ServerManager obj = server_manage::ServerManager(9999);
	LPVOID lpDisplayBuf;
	//obj.initPipes();
	//if (obj.CreateServerProcess("C:\\Windows\\System32\\calc.exe") == -1) {
	//	//MessageBox(NULL, (LPCTSTR)lpDisplayBuf, TEXT("Error"), MB_OK);
	//}

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