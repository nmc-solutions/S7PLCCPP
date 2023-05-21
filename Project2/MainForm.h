#pragma once
#include <snap7.h>

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;


	byte MyDB1[1] = { 1 }; // byte is a portable type of snap7.h
	byte MyDB0[1] = { 0 }; // byte is a portable type of snap7.h
	TS7Client* MyClient;
	void S7Connection()
	{
		MyClient = new TS7Client();
		MyClient->ConnectTo("192.168.0.1", 0, 1);
		
		
	
		//delete MyClient;
	}
	public ref class MainForm : public System::Windows::Forms::Form
	{
		
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(660, 52);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(128, 36);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Connect to PLC";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::ConnectPLC_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(632, 202);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(88, 16);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Sensor Value";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 44);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(119, 16);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Ambient Temp (°C)";
			this->label2->Click += gcnew System::EventHandler(this, &MainForm::label2_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Location = System::Drawing::Point(12, 28);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(433, 127);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Sensor Value";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(219, 44);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(26, 16);
			this->label5->TabIndex = 7;
			this->label5->Text = L"PH";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(131, 66);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(58, 22);
			this->textBox2->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(219, 72);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(86, 16);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Light Intensity";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(131, 41);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(58, 22);
			this->textBox1->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 71);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(113, 16);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Water Tank Level";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(979, 572);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ConnectPLC_Click(System::Object^ sender, System::EventArgs^ e) {
		S7Connection();
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		
		this->timer1->Interval = 1000;
		this->timer1->Start();
		this->timer2->Interval = 2000;
		this->timer2->Start();
		this->timer1->Tick += gcnew System::EventHandler(this, &Project2::MainForm::OnTick);
		this->timer2->Tick += gcnew System::EventHandler(this, &Project2::MainForm::OnTick2);
	}
		   void OnTick(System::Object^ sender, System::EventArgs^ e);
		   void OnTick2(System::Object^ sender, System::EventArgs^ e);
};
}


void Project2::MainForm::OnTick(System::Object^ sender, System::EventArgs^ e)
{
	S7Connection();
	MyClient->DBWrite(1, 0, 1, &MyDB1);
	//delete MyClient;
}
void Project2::MainForm::OnTick2(System::Object^ sender, System::EventArgs^ e)
{
	S7Connection();
	MyClient->DBWrite(1, 0, 1, &MyDB0);
}

