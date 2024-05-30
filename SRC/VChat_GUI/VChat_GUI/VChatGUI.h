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
			srv_prompt = gcnew System::String("VChat Server: ");
			gui_prompt = gcnew System::String("VChat GUI: ");
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
	private: System::String^ srv_prompt;
	private: System::String^ gui_prompt;


	private: System::Windows::Forms::TextBox^ VChatOut;
	private: System::Windows::Forms::Button^ Stop_Button;
	private: System::Windows::Forms::Label^ InputPortLabel;
	private: System::Windows::Forms::TextBox^ VChatPort;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ VChatPath;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;








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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// Start_Button
			// 
			this->Start_Button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Start_Button->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->Start_Button->BackColor = System::Drawing::Color::DimGray;
			this->Start_Button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Start_Button->Location = System::Drawing::Point(963, 616);
			this->Start_Button->Name = L"Start_Button";
			this->Start_Button->Size = System::Drawing::Size(216, 121);
			this->Start_Button->TabIndex = 0;
			this->Start_Button->Text = L"Start-Server";
			this->Start_Button->UseVisualStyleBackColor = false;
			this->Start_Button->Click += gcnew System::EventHandler(this, &VChatGUI::Start_Button_Click);
			// 
			// VChatOut
			// 
			this->VChatOut->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->VChatOut->BackColor = System::Drawing::SystemColors::MenuText;
			this->VChatOut->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->VChatOut->ForeColor = System::Drawing::Color::ForestGreen;
			this->VChatOut->Location = System::Drawing::Point(-2, -1);
			this->VChatOut->Multiline = true;
			this->VChatOut->Name = L"VChatOut";
			this->VChatOut->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->VChatOut->Size = System::Drawing::Size(1677, 611);
			this->VChatOut->TabIndex = 2;
			// 
			// Stop_Button
			// 
			this->Stop_Button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Stop_Button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Stop_Button->Location = System::Drawing::Point(963, 771);
			this->Stop_Button->Name = L"Stop_Button";
			this->Stop_Button->Size = System::Drawing::Size(216, 118);
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
			this->InputPortLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->InputPortLabel->Location = System::Drawing::Point(12, 814);
			this->InputPortLabel->Name = L"InputPortLabel";
			this->InputPortLabel->Size = System::Drawing::Size(160, 32);
			this->InputPortLabel->TabIndex = 5;
			this->InputPortLabel->Text = L"VChat Port:";
			// 
			// VChatPort
			// 
			this->VChatPort->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->VChatPort->Location = System::Drawing::Point(362, 811);
			this->VChatPort->MaxLength = 6;
			this->VChatPort->Name = L"VChatPort";
			this->VChatPort->Size = System::Drawing::Size(113, 39);
			this->VChatPort->TabIndex = 9;
			this->VChatPort->Text = L"9999";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 674);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(316, 32);
			this->label1->TabIndex = 7;
			this->label1->Text = L"VChat Executable Path:";
			// 
			// VChatPath
			// 
			this->VChatPath->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->VChatPath->Location = System::Drawing::Point(362, 671);
			this->VChatPath->Name = L"VChatPath";
			this->VChatPath->Size = System::Drawing::Size(525, 39);
			this->VChatPath->TabIndex = 8;
			this->VChatPath->Text = L"C:\\Local-Git\\VChatGUI\\SRC\\Test-Child\\x64\\Debug\\Test-Child.exe";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(1232, 671);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(290, 48);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Server Status:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(1232, 811);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(249, 48);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Active Port: ";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::Red;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(1460, 649);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(178, 82);
			this->textBox1->TabIndex = 12;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(1464, 811);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(150, 39);
			this->textBox2->TabIndex = 13;
			this->textBox2->Text = L"NULL";
			// 
			// VChatGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->ClientSize = System::Drawing::Size(1677, 901);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
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
				Write_Text_Box_Block(srv_prompt, converted);
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
	private: System::Void Write_Text_Box_Block(System::String^ prepend, System::String^ textBlock) {
		t_mutex->WaitOne();
		this->VChatOut->AppendText(prepend + textBlock);
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
	private: System::Void Write_Text_Box_Timed(System::String^ prepend, System::String^ textBlock) {
		bool chk = 0;
		chk = t_mutex->WaitOne(1000);
		this->VChatOut->AppendText(prepend + textBlock);
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
				//this->serv_h->set_port(const_cast<char*>(msclr::interop::marshal_as<std::string>(VChatPort->Text).c_str()));
				this->serv_h->set_port(portVal);
			}

			// To prevent any conditions where the thread is killed in the middle of a mutex operation, we create a new one once we start a server 
			this->t_mutex = gcnew System::Threading::Mutex();


			// Notify Useer we are starting the server
			this->Write_Text_Box_Block(gui_prompt, "Starting Server\r\n");
			//Hello_Label->Text = "Hello World 2";


			if (this->serv_h->initPipes() == -1) {
				this->Write_Text_Box_Block(gui_prompt, "Failed to Create Unnamed Pipes\r\n");
				return;
			}

			// C:\\Local-Git\\VChatGUI\\SRC\\Test-Child\\x64\\Debug\\Test-Child.exe"
			if (this->serv_h->CreateServerProcess(msclr::interop::marshal_as<std::string>(VChatPath->Text)) == -1) {
				this->Write_Text_Box_Block(gui_prompt, "Failed to Create Child Process\r\n");
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
			this->Write_Text_Box_Timed(gui_prompt,"Killing Server\r\n");

			// Remove mutex
			delete this->t_mutex;
			return;

		}

}; // Class End
} // Namespace end
