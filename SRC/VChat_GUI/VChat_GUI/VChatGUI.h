#pragma once
#include <iostream>
#include <process.h>
#include <exception>
#include <msclr/marshal_cppstd.h>
#include "ServerManager.h"

// Define Buffer Size
#define BUFFSIZE 4096

namespace VChatGUI {


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for VChatGUI
	/// </summary>
	public ref class VChatGUI : public System::Windows::Forms::Form
	{
		 
	public:
		VChatGUI(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->serv_h = (server_manage::ServerManager*)new server_manage::ServerManager("9999");
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~VChatGUI()
		{
			if (components)
			{
				delete components;
			}
			
			// If the server is running we need to kill it
			if (this->serv_h != nullptr && this->serv_h->get_isStarted() == 1) 
				this->serv_h->killServer();
			
			// Clean up allocated resources
			delete this->serv_h;
			this->serv_h = nullptr; // Not necsissary but paranoia is good sometimes. In this case unlikely.
		}

	private: server_manage::ServerManager *serv_h; // Pointer to obj because it is unmanaged
	private: System::Threading::Thread^ t_handle; // Managaed Thread Object
	private: System::Threading::Mutex^ t_mutex; // Managaed Mutex Object Object
	private: System::Windows::Forms::Button^ Start_Button;

	private: System::Windows::Forms::TextBox^ VChatOut;
	private: System::Windows::Forms::Button^ Stop_Button;
	private: System::Windows::Forms::Label^ InputPortLabel;
	private: System::Windows::Forms::TextBox^ VChatPort;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ VChatPath;






	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Start_Button = (gcnew System::Windows::Forms::Button());
			this->VChatOut = (gcnew System::Windows::Forms::TextBox());
			this->Stop_Button = (gcnew System::Windows::Forms::Button());
			this->InputPortLabel = (gcnew System::Windows::Forms::Label());
			this->VChatPort = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->VChatPath = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// Start_Button
			// 
			this->Start_Button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Start_Button->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->Start_Button->Location = System::Drawing::Point(12, 800);
			this->Start_Button->Name = L"Start_Button";
			this->Start_Button->Size = System::Drawing::Size(162, 76);
			this->Start_Button->TabIndex = 0;
			this->Start_Button->Text = L"Start-Server";
			this->Start_Button->UseVisualStyleBackColor = true;
			this->Start_Button->Click += gcnew System::EventHandler(this, &VChatGUI::Start_Button_Click);
			// 
			// VChatOut
			// 
			this->VChatOut->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->VChatOut->Location = System::Drawing::Point(1, -2);
			this->VChatOut->Multiline = true;
			this->VChatOut->Name = L"VChatOut";
			this->VChatOut->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->VChatOut->Size = System::Drawing::Size(1664, 332);
			this->VChatOut->TabIndex = 2;
			// 
			// Stop_Button
			// 
			this->Stop_Button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Stop_Button->Location = System::Drawing::Point(204, 800);
			this->Stop_Button->Name = L"Stop_Button";
			this->Stop_Button->Size = System::Drawing::Size(162, 76);
			this->Stop_Button->TabIndex = 4;
			this->Stop_Button->Text = L"Stop-Server";
			this->Stop_Button->UseVisualStyleBackColor = true;
			this->Stop_Button->Click += gcnew System::EventHandler(this, &VChatGUI::Stop_Button_Click);
			// 
			// InputPortLabel
			// 
			this->InputPortLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->InputPortLabel->AutoSize = true;
			this->InputPortLabel->Location = System::Drawing::Point(12, 745);
			this->InputPortLabel->Name = L"InputPortLabel";
			this->InputPortLabel->Size = System::Drawing::Size(87, 20);
			this->InputPortLabel->TabIndex = 5;
			this->InputPortLabel->Text = L"VChat Port";
			// 
			// VChatPort
			// 
			this->VChatPort->Location = System::Drawing::Point(204, 745);
			this->VChatPort->MaxLength = 6;
			this->VChatPort->Name = L"VChatPort";
			this->VChatPort->Size = System::Drawing::Size(162, 26);
			this->VChatPort->TabIndex = 9;
			this->VChatPort->Text = L"9999";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 708);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(174, 20);
			this->label1->TabIndex = 7;
			this->label1->Text = L"VChat Executable Path";
			// 
			// VChatPath
			// 
			this->VChatPath->Location = System::Drawing::Point(204, 708);
			this->VChatPath->Name = L"VChatPath";
			this->VChatPath->Size = System::Drawing::Size(162, 26);
			this->VChatPath->TabIndex = 8;
			this->VChatPath->Text = L"Some-Path";
			// 
			// VChatGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1677, 901);
			this->Controls->Add(this->VChatPath);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->VChatPort);
			this->Controls->Add(this->InputPortLabel);
			this->Controls->Add(this->Stop_Button);
			this->Controls->Add(this->VChatOut);
			this->Controls->Add(this->Start_Button);
			this->Location = System::Drawing::Point(1510, 1510);
			this->Name = L"VChatGUI";
			this->Text = L"VChatGUI";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	/*
	* Background thread function that will be started when the server 
	* starts. This function will call the serverRead function from the 
	* server manager object (blocking) if this is successful we will
	* output the content to the message block.
	*
	* @param p: Not used.
	*
	* @return: None
	*/
	public: System::Void Server_Lisener(Object^ p) {
		std::cout << "Test\n";
		char buff[BUFFSIZE];
		
		// Catch any exceptions thrown by killing the processes we are 
		// trying to read from
		try {
			while (1) {
				if (this->serv_h->serverRead(buff, BUFFSIZE) == -1) {
					std::cout << GetLastError() << "\n";
					break;
				}
				System::String^ converted = gcnew System::String(buff);
				Write_Text_Box_Block(converted);
				delete converted;
			}
		}
		// System::Threading::ThreadInterruptedException^
		catch (...) {
			// If we catch an exception we probably should exit (Nothing to clean up)
			return;
		}
	}
	
	/*
	* This functions uses a mutex with an indefinate block. This will write to the 
	* VChat Output textbox.
	*
	* @param textblock: This is a block of text we will output to the screen (Should 
	*                   terminated in `\r\n`
	* 
	* @return: None
	*/
	private: System::Void Write_Text_Box_Block(System::String^ textBlock) {
		t_mutex->WaitOne();
		this->VChatOut->AppendText(textBlock);
		t_mutex->ReleaseMutex();
		return;
	}

	/*
	* This functions uses a mutex with an timed block. This will write to the 
	* VChat Output textbox.
	*
	* @param textblock: This is a block of text we will output to the screen (Should 
	*                   terminated in `\r\n`
	* 
	* @return: None
	*/
	private: System::Void Write_Text_Box_Timed(System::String^ textBlock) {
		bool chk = 0;
		chk = t_mutex->WaitOne(1000);
		this->VChatOut->AppendText(textBlock);
		if(chk == 1)
			t_mutex->ReleaseMutex();
		return;
	}

	/* Handler for start button being clicked */
	private: System::Void Start_Button_Click(System::Object^ sender, System::EventArgs^ e) {
			char* end;
			std::string portVal;

			// If the server pointer has been allocated, and the server is started 
			if (serv_h != nullptr && this->serv_h->get_isStarted())
				return;

			// Validate port value and only update if numeric.
			portVal = msclr::interop::marshal_as<std::string>(VChatPort->Text);
			if (portVal != this->serv_h->get_serverPort() &&
				strtol(portVal.c_str(), &end, 10) != 0 && *end == '\0') {
				std::cout << "Converted String" << portVal << "\n";
				//this->serv_h->set_port(const_cast<char*>(msclr::interop::marshal_as<std::string>(VChatPort->Text).c_str()));
				this->serv_h->set_port(portVal);
			}

			// To prevent any conditions where the thread is killed in the middle of a mutex operation, we create a new one once we start a server 
			this->t_mutex = gcnew System::Threading::Mutex();


			// Notify Useer we are starting the server
			this->Write_Text_Box_Block("Starting Server\r\n");
			//Hello_Label->Text = "Hello World 2";


			if (this->serv_h->initPipes() == -1) {
				this->VChatOut->AppendText("Failed to Create Unnamed Pipes\r\n");
				return;
			}

			if (this->serv_h->CreateServerProcess("C:\\Local-Git\\VChatGUI\\SRC\\Test-Child\\x64\\Debug\\Test-Child.exe") == -1) {
				this->VChatOut->AppendText("Failed to Create Child Process\r\n");
				return;
			}

			// Start Listener
			this->t_handle = gcnew System::Threading::Thread(gcnew System::Threading::ParameterizedThreadStart(this, &VChatGUI::Server_Lisener));
			this->t_handle->Start(10);

			// Set Started Tracker
			this->serv_h->set_isStarted(1);

			return;
	}

	/* Handler for stop button being clicked */
	private: System::Void Stop_Button_Click(System::Object^ sender, System::EventArgs^ e) {
			
			// Only allow killing the server if it has been started. 
			if (!this->serv_h->get_isStarted())
				return;
			
			//std::cout << this->serv_h->killServer() << "\n" << GetLastError() << "\n";
			
			// Kill Server
			this->t_handle->Interrupt(); // Abort since there is not much cleanup we do. This is illadvised.
			this->serv_h->killServer();
			this->serv_h->set_isStarted(0);


			// Display that we are killing/killed the server 
			this->Write_Text_Box_Timed("Killing Server\r\n");

			// We kill out 
			std::cout << "Killing Server" << "\n";

			delete this->t_mutex;
			return;

		}

}; // Class End
} // Namespace end
