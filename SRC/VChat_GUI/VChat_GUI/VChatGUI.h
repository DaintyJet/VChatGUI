#pragma once
#include <iostream>
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
	private: System::Windows::Forms::Button^ Start_Button;
	protected:

	private: System::Windows::Forms::Label^ Hello_Label;
	private: System::Windows::Forms::TextBox^ VChatOut;

	protected:
		bool isStarted = 0; // Bool to determine if the server has been started. This is always set to false when we intialize
	protected:

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
			this->SuspendLayout();
			// 
			// Start_Button
			// 
			this->Start_Button->Location = System::Drawing::Point(12, 412);
			this->Start_Button->Name = L"Start_Button";
			this->Start_Button->Size = System::Drawing::Size(111, 86);
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
			this->VChatOut->Location = System::Drawing::Point(0, 0);
			this->VChatOut->Multiline = true;
			this->VChatOut->Name = L"VChatOut";
			this->VChatOut->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->VChatOut->Size = System::Drawing::Size(598, 175);
			this->VChatOut->TabIndex = 2;
			// 
			// VChatGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(591, 510);
			this->Controls->Add(this->VChatOut);
			this->Controls->Add(this->Hello_Label);
			this->Controls->Add(this->Start_Button);
			this->Name = L"VChatGUI";
			this->Text = L"VChatGUI";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Start_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		std::cout << "Hello World";
		System::String^ managedString = "Hello, World!";
		
		VChatOut->AppendText("Hello World\n");
		Hello_Label->Text = "Hello World 2";
	}
}; // Class End
} // Namespace end
