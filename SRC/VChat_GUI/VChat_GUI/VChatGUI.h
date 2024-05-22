#pragma once
#include <iostream>
#include <process.h>
#include <exception>
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
			this->serv_h = (server_manage::ServerManager*)new server_manage::ServerManager(9999);
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
	private: System::Windows::Forms::Label^ Hello_Label;
	private: System::Windows::Forms::TextBox^ VChatOut;
	private: System::Windows::Forms::Button^ Stop_Button;
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
			this->Hello_Label = (gcnew System::Windows::Forms::Label());
			this->VChatOut = (gcnew System::Windows::Forms::TextBox());
			this->Stop_Button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Start_Button
			// 
			this->Start_Button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Start_Button->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->Start_Button->Location = System::Drawing::Point(12, 777);
			this->Start_Button->Name = L"Start_Button";
			this->Start_Button->Size = System::Drawing::Size(162, 76);
			this->Start_Button->TabIndex = 0;
			this->Start_Button->Text = L"Start-Server";
			this->Start_Button->UseVisualStyleBackColor = true;
			this->Start_Button->Click += gcnew System::EventHandler(this, &VChatGUI::Start_Button_Click);
			// 
			// Hello_Label
			// 
			this->Hello_Label->AutoSize = true;
			this->Hello_Label->Location = System::Drawing::Point(250, 364);
			this->Hello_Label->Name = L"Hello_Label";
			this->Hello_Label->Size = System::Drawing::Size(80, 20);
			this->Hello_Label->TabIndex = 1;
			this->Hello_Label->Text = L"Hello Test";
			// 
			// VChatOut
			// 
			this->VChatOut->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->VChatOut->Location = System::Drawing::Point(0, 0);
			this->VChatOut->Multiline = true;
			this->VChatOut->Name = L"VChatOut";
			this->VChatOut->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->VChatOut->Size = System::Drawing::Size(980, 274);
			this->VChatOut->TabIndex = 2;
			// 
			// Stop_Button
			// 
			this->Stop_Button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Stop_Button->Location = System::Drawing::Point(199, 777);
			this->Stop_Button->Name = L"Stop_Button";
			this->Stop_Button->Size = System::Drawing::Size(162, 76);
			this->Stop_Button->TabIndex = 4;
			this->Stop_Button->Text = L"Stop-Server";
			this->Stop_Button->UseVisualStyleBackColor = true;
			this->Stop_Button->Click += gcnew System::EventHandler(this, &VChatGUI::Stop_Button_Click);
			// 
			// VChatGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(979, 865);
			this->Controls->Add(this->Stop_Button);
			this->Controls->Add(this->VChatOut);
			this->Controls->Add(this->Hello_Label);
			this->Controls->Add(this->Start_Button);
			this->Location = System::Drawing::Point(1510, 1510);
			this->Name = L"VChatGUI";
			this->Text = L"VChatGUI";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
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
				std::cout << buff << "\n";
				System::String^ converted = gcnew System::String(buff);
				Write_Text_Box_Block(converted);
			}
		}
		// System::Threading::ThreadInterruptedException^
		catch (...) {
			
			return;
		}
	}

	private: System::Void Write_Text_Box_Block(System::String^ textBlock) {
		t_mutex->WaitOne();
		this->VChatOut->AppendText(textBlock);
		t_mutex->ReleaseMutex();
		return;
	}

	private: System::Void Write_Text_Box_Timed(System::String^ textBlock) {
		bool chk = 0;
		
		chk = t_mutex->WaitOne(1000);

		this->VChatOut->AppendText(textBlock);
		
		if(chk == 1)
			t_mutex->ReleaseMutex();

		return;

	}
	private: System::Void Start_Button_Click(System::Object^ sender, System::EventArgs^ e) {
			
			// If the server pointer has been allocated, and the server is started 
			if (serv_h != nullptr && this->serv_h->get_isStarted())
				return;
			
			// To prevent any conditions where the thread is killed in the middle of a mutex operation, we create a new one once we start a server 
			this->t_mutex = gcnew System::Threading::Mutex();


			// Notify Useer we are starting the server
			this->Write_Text_Box_Block("Starting Server\r\n");
			Hello_Label->Text = "Hello World 2";


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
