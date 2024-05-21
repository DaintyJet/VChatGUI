#pragma once
#include <iostream>
#include <process.h> 
#include "ServerManager.h"
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
		}
	public: server_manage::ServerManager*serv_h;
	private: System::Windows::Forms::Button^ Start_Button;
	private: System::Windows::Forms::Label^ Hello_Label;
	private: System::Windows::Forms::TextBox^ VChatOut;
	protected: bool isStarted = 0; // Bool to determine if the server has been started. This is always set to false when we intialize

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
			this->VChatOut->Size = System::Drawing::Size(1870, 274);
			this->VChatOut->TabIndex = 2;
			// 
			// Stop_Button
			// 
			this->Stop_Button->Location = System::Drawing::Point(233, 759);
			this->Stop_Button->Name = L"Stop_Button";
			this->Stop_Button->Size = System::Drawing::Size(214, 94);
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
			this->ClientSize = System::Drawing::Size(1869, 865);
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


	private: System::Void Start_Button_Click(System::Object^ sender, System::EventArgs^ e) {
			if (this->isStarted)
				return;
			// Init Server Comp // For whatever unknown reason if this is placed inside of some other function it fails
			this->serv_h = (server_manage::ServerManager*)malloc(sizeof(server_manage::ServerManager));
			*(this->serv_h) = server_manage::ServerManager(9999);
			

			this->VChatOut->AppendText("Starting Server\r\n");
			Hello_Label->Text = "Hello World 2";

			this->serv_h->initPipes();
			if (this->serv_h->CreateServerProcess("C:\\Local-Git\\VChatGUI\\SRC\\Test-Child\\x64\\Debug\\Test-Child.exe") == -1) {
				//MessageBox(NULL, (LPCTSTR)lpDisplayBuf, TEXT("Error"), MB_OK);
			}
			this->isStarted = 1;
	}
	private: System::Void Stop_Button_Click(System::Object^ sender, System::EventArgs^ e) {
			if (!isStarted)
				return;
			this->VChatOut->AppendText("Killing Server\r\n");

			std::cout << "Killing Server" << "\n";
			std::cout << this->serv_h->killServer() << "\n" << GetLastError() << "\n";
			//
			this->isStarted = 0;
		}
	}; // Class End
} // Namespace end
