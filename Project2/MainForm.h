#pragma once
#include <snap7.h>

namespace MainProject {

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


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox6;

	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::RadioButton^ radioButton9;
	private: System::Windows::Forms::RadioButton^ radioButton10;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::RadioButton^ radioButton11;
	private: System::Windows::Forms::RadioButton^ radioButton12;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::RadioButton^ radioButton13;
	private: System::Windows::Forms::RadioButton^ radioButton14;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::RadioButton^ radioButton15;
	private: System::Windows::Forms::RadioButton^ radioButton16;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::RadioButton^ radioButton7;
	private: System::Windows::Forms::RadioButton^ radioButton8;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::RadioButton^ radioButton5;
	private: System::Windows::Forms::RadioButton^ radioButton6;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::RadioButton^ radioButton4;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::TextBox^ textBox13;
	private: System::Windows::Forms::TextBox^ textBox14;
	private: System::Windows::Forms::TextBox^ textBox15;
	private: System::Windows::Forms::TextBox^ textBox16;
	private: System::Windows::Forms::TextBox^ textBox12;
	private: System::Windows::Forms::TextBox^ textBox11;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::Label^ label27;
	private: System::Windows::Forms::Label^ label26;
	private: System::Windows::Forms::Label^ label25;
	private: System::Windows::Forms::Label^ label24;
	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::Label^ label30;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::Label^ label29;
	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::Label^ label28;
	private: System::Windows::Forms::Label^ label31;
	private: System::Windows::Forms::Label^ label32;
	private: System::Windows::Forms::Label^ label33;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label34;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox17;
	private: System::Windows::Forms::TextBox^ textBox18;
	private: System::Windows::Forms::Label^ label35;
	private: System::Windows::Forms::Label^ label36;
	private: System::Windows::Forms::Label^ label37;
	private: System::Windows::Forms::TextBox^ textBox19;
	private: System::IO::Ports::SerialPort^ serialPort1;



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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->radioButton7 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton8 = (gcnew System::Windows::Forms::RadioButton());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->radioButton9 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton10 = (gcnew System::Windows::Forms::RadioButton());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->radioButton11 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton12 = (gcnew System::Windows::Forms::RadioButton());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->radioButton13 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton14 = (gcnew System::Windows::Forms::RadioButton());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->radioButton15 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton16 = (gcnew System::Windows::Forms::RadioButton());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox17 = (gcnew System::Windows::Forms::TextBox());
			this->textBox18 = (gcnew System::Windows::Forms::TextBox());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->textBox19 = (gcnew System::Windows::Forms::TextBox());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->SuspendLayout();
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
			this->groupBox1->Controls->Add(this->textBox5);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Location = System::Drawing::Point(12, 28);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(584, 114);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Sensor Value";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(495, 38);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(58, 22);
			this->textBox5->TabIndex = 11;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(382, 41);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(106, 16);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Water Temp (°C)";
			this->label6->Click += gcnew System::EventHandler(this, &MainForm::label6_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(299, 76);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(58, 22);
			this->textBox4->TabIndex = 9;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(299, 38);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(58, 22);
			this->textBox3->TabIndex = 8;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(206, 44);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(26, 16);
			this->label5->TabIndex = 7;
			this->label5->Text = L"PH";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(131, 77);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(58, 22);
			this->textBox2->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(206, 83);
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
			this->label3->Location = System::Drawing::Point(6, 82);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(113, 16);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Water Tank Level";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label21);
			this->groupBox2->Controls->Add(this->label11);
			this->groupBox2->Controls->Add(this->label12);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Controls->Add(this->button4);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->button3);
			this->groupBox2->Controls->Add(this->textBox8);
			this->groupBox2->Controls->Add(this->textBox7);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->textBox6);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox2->Location = System::Drawing::Point(615, 28);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(343, 221);
			this->groupBox2->TabIndex = 12;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"PLC Connection Setup";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(273, 65);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(52, 22);
			this->textBox8->TabIndex = 17;
			this->textBox8->Text = L"1";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(175, 65);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(52, 22);
			this->textBox7->TabIndex = 16;
			this->textBox7->Text = L"0";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(237, 68);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(33, 16);
			this->label8->TabIndex = 15;
			this->label8->Text = L"Slot:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(133, 68);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(42, 16);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Rack:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 68);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(22, 16);
			this->label1->TabIndex = 12;
			this->label1->Text = L"IP:";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(29, 65);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(91, 22);
			this->textBox6->TabIndex = 12;
			this->textBox6->Text = L"192.168.10.1";
			this->textBox6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(125, 100);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(90, 31);
			this->button3->TabIndex = 18;
			this->button3->Text = L"Connect";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(6, 107);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(105, 16);
			this->label9->TabIndex = 12;
			this->label9->Text = L"PLC Connection:";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(235, 100);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(90, 31);
			this->button4->TabIndex = 19;
			this->button4->Text = L"Disconnect";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(6, 34);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(75, 16);
			this->label10->TabIndex = 12;
			this->label10->Text = L"CPU Status";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(6, 150);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(106, 16);
			this->label12->TabIndex = 21;
			this->label12->Text = L"Connection state";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->radioButton9);
			this->groupBox3->Controls->Add(this->radioButton10);
			this->groupBox3->Controls->Add(this->label17);
			this->groupBox3->Controls->Add(this->radioButton11);
			this->groupBox3->Controls->Add(this->radioButton12);
			this->groupBox3->Controls->Add(this->label18);
			this->groupBox3->Controls->Add(this->radioButton13);
			this->groupBox3->Controls->Add(this->radioButton14);
			this->groupBox3->Controls->Add(this->label19);
			this->groupBox3->Controls->Add(this->radioButton15);
			this->groupBox3->Controls->Add(this->radioButton16);
			this->groupBox3->Controls->Add(this->label20);
			this->groupBox3->Controls->Add(this->radioButton7);
			this->groupBox3->Controls->Add(this->radioButton8);
			this->groupBox3->Controls->Add(this->label16);
			this->groupBox3->Controls->Add(this->radioButton5);
			this->groupBox3->Controls->Add(this->radioButton6);
			this->groupBox3->Controls->Add(this->label15);
			this->groupBox3->Controls->Add(this->radioButton3);
			this->groupBox3->Controls->Add(this->radioButton4);
			this->groupBox3->Controls->Add(this->label14);
			this->groupBox3->Controls->Add(this->radioButton2);
			this->groupBox3->Controls->Add(this->radioButton1);
			this->groupBox3->Controls->Add(this->label13);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox3->Location = System::Drawing::Point(12, 364);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(584, 187);
			this->groupBox3->TabIndex = 22;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Manual Control";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label13->Location = System::Drawing::Point(26, 38);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(81, 16);
			this->label13->TabIndex = 12;
			this->label13->Text = L"Water Pump";
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(147, 36);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(48, 20);
			this->radioButton1->TabIndex = 13;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"ON";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(210, 36);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(54, 20);
			this->radioButton2->TabIndex = 14;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"OFF";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(210, 71);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(54, 20);
			this->radioButton3->TabIndex = 17;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"OFF";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(147, 71);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(48, 20);
			this->radioButton4->TabIndex = 16;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"ON";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label14->Location = System::Drawing::Point(26, 73);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(30, 16);
			this->label14->TabIndex = 15;
			this->label14->Text = L"Fan";
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Location = System::Drawing::Point(210, 108);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(54, 20);
			this->radioButton5->TabIndex = 20;
			this->radioButton5->TabStop = true;
			this->radioButton5->Text = L"OFF";
			this->radioButton5->UseVisualStyleBackColor = true;
			// 
			// radioButton6
			// 
			this->radioButton6->AutoSize = true;
			this->radioButton6->Location = System::Drawing::Point(147, 108);
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->Size = System::Drawing::Size(48, 20);
			this->radioButton6->TabIndex = 19;
			this->radioButton6->TabStop = true;
			this->radioButton6->Text = L"ON";
			this->radioButton6->UseVisualStyleBackColor = true;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label15->Location = System::Drawing::Point(26, 110);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(106, 16);
			this->label15->TabIndex = 18;
			this->label15->Text = L"Base (PH Down)";
			// 
			// radioButton7
			// 
			this->radioButton7->AutoSize = true;
			this->radioButton7->Location = System::Drawing::Point(210, 144);
			this->radioButton7->Name = L"radioButton7";
			this->radioButton7->Size = System::Drawing::Size(54, 20);
			this->radioButton7->TabIndex = 23;
			this->radioButton7->TabStop = true;
			this->radioButton7->Text = L"OFF";
			this->radioButton7->UseVisualStyleBackColor = true;
			// 
			// radioButton8
			// 
			this->radioButton8->AutoSize = true;
			this->radioButton8->Location = System::Drawing::Point(147, 144);
			this->radioButton8->Name = L"radioButton8";
			this->radioButton8->Size = System::Drawing::Size(48, 20);
			this->radioButton8->TabIndex = 22;
			this->radioButton8->TabStop = true;
			this->radioButton8->Text = L"ON";
			this->radioButton8->UseVisualStyleBackColor = true;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label16->Location = System::Drawing::Point(26, 146);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(35, 16);
			this->label16->TabIndex = 21;
			this->label16->Text = L"Light";
			// 
			// radioButton9
			// 
			this->radioButton9->AutoSize = true;
			this->radioButton9->Location = System::Drawing::Point(497, 144);
			this->radioButton9->Name = L"radioButton9";
			this->radioButton9->Size = System::Drawing::Size(54, 20);
			this->radioButton9->TabIndex = 35;
			this->radioButton9->TabStop = true;
			this->radioButton9->Text = L"OFF";
			this->radioButton9->UseVisualStyleBackColor = true;
			// 
			// radioButton10
			// 
			this->radioButton10->AutoSize = true;
			this->radioButton10->Location = System::Drawing::Point(434, 144);
			this->radioButton10->Name = L"radioButton10";
			this->radioButton10->Size = System::Drawing::Size(48, 20);
			this->radioButton10->TabIndex = 34;
			this->radioButton10->TabStop = true;
			this->radioButton10->Text = L"ON";
			this->radioButton10->UseVisualStyleBackColor = true;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label17->Location = System::Drawing::Point(313, 146);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(74, 16);
			this->label17->TabIndex = 33;
			this->label17->Text = L"Cool Water";
			// 
			// radioButton11
			// 
			this->radioButton11->AutoSize = true;
			this->radioButton11->Location = System::Drawing::Point(497, 108);
			this->radioButton11->Name = L"radioButton11";
			this->radioButton11->Size = System::Drawing::Size(54, 20);
			this->radioButton11->TabIndex = 32;
			this->radioButton11->TabStop = true;
			this->radioButton11->Text = L"OFF";
			this->radioButton11->UseVisualStyleBackColor = true;
			// 
			// radioButton12
			// 
			this->radioButton12->AutoSize = true;
			this->radioButton12->Location = System::Drawing::Point(434, 108);
			this->radioButton12->Name = L"radioButton12";
			this->radioButton12->Size = System::Drawing::Size(48, 20);
			this->radioButton12->TabIndex = 31;
			this->radioButton12->TabStop = true;
			this->radioButton12->Text = L"ON";
			this->radioButton12->UseVisualStyleBackColor = true;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label18->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label18->Location = System::Drawing::Point(313, 110);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(85, 16);
			this->label18->TabIndex = 30;
			this->label18->Text = L"Acid (PH Up)";
			// 
			// radioButton13
			// 
			this->radioButton13->AutoSize = true;
			this->radioButton13->Location = System::Drawing::Point(497, 71);
			this->radioButton13->Name = L"radioButton13";
			this->radioButton13->Size = System::Drawing::Size(54, 20);
			this->radioButton13->TabIndex = 29;
			this->radioButton13->TabStop = true;
			this->radioButton13->Text = L"OFF";
			this->radioButton13->UseVisualStyleBackColor = true;
			// 
			// radioButton14
			// 
			this->radioButton14->AutoSize = true;
			this->radioButton14->Location = System::Drawing::Point(434, 71);
			this->radioButton14->Name = L"radioButton14";
			this->radioButton14->Size = System::Drawing::Size(48, 20);
			this->radioButton14->TabIndex = 28;
			this->radioButton14->TabStop = true;
			this->radioButton14->Text = L"ON";
			this->radioButton14->UseVisualStyleBackColor = true;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label19->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label19->Location = System::Drawing::Point(313, 73);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(89, 16);
			this->label19->TabIndex = 27;
			this->label19->Text = L"Oxi Generator";
			// 
			// radioButton15
			// 
			this->radioButton15->AutoSize = true;
			this->radioButton15->Location = System::Drawing::Point(497, 36);
			this->radioButton15->Name = L"radioButton15";
			this->radioButton15->Size = System::Drawing::Size(54, 20);
			this->radioButton15->TabIndex = 26;
			this->radioButton15->TabStop = true;
			this->radioButton15->Text = L"OFF";
			this->radioButton15->UseVisualStyleBackColor = true;
			// 
			// radioButton16
			// 
			this->radioButton16->AutoSize = true;
			this->radioButton16->Location = System::Drawing::Point(434, 36);
			this->radioButton16->Name = L"radioButton16";
			this->radioButton16->Size = System::Drawing::Size(48, 20);
			this->radioButton16->TabIndex = 25;
			this->radioButton16->TabStop = true;
			this->radioButton16->Text = L"ON";
			this->radioButton16->UseVisualStyleBackColor = true;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label20->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label20->Location = System::Drawing::Point(313, 38);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(79, 16);
			this->label20->TabIndex = 24;
			this->label20->Text = L"Empty Tank";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(122, 150);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(16, 16);
			this->label11->TabIndex = 22;
			this->label11->Text = L"...";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(122, 34);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(16, 16);
			this->label21->TabIndex = 23;
			this->label21->Text = L"...";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->textBox13);
			this->groupBox4->Controls->Add(this->textBox14);
			this->groupBox4->Controls->Add(this->textBox15);
			this->groupBox4->Controls->Add(this->textBox16);
			this->groupBox4->Controls->Add(this->textBox12);
			this->groupBox4->Controls->Add(this->textBox11);
			this->groupBox4->Controls->Add(this->textBox10);
			this->groupBox4->Controls->Add(this->label27);
			this->groupBox4->Controls->Add(this->label26);
			this->groupBox4->Controls->Add(this->label25);
			this->groupBox4->Controls->Add(this->label24);
			this->groupBox4->Controls->Add(this->label23);
			this->groupBox4->Controls->Add(this->label22);
			this->groupBox4->Controls->Add(this->label30);
			this->groupBox4->Controls->Add(this->textBox9);
			this->groupBox4->Controls->Add(this->label29);
			this->groupBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox4->Location = System::Drawing::Point(12, 157);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(584, 192);
			this->groupBox4->TabIndex = 36;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Auto Control";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label29->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label29->Location = System::Drawing::Point(26, 38);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(166, 16);
			this->label29->TabIndex = 12;
			this->label29->Text = L"Upper Ambient Temp Limit";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(222, 32);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(67, 22);
			this->textBox9->TabIndex = 12;
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label30->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label30->Location = System::Drawing::Point(26, 72);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(164, 16);
			this->label30->TabIndex = 34;
			this->label30->Text = L"Lower Ambient Temp Limit";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label22->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label22->Location = System::Drawing::Point(26, 107);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(150, 16);
			this->label22->TabIndex = 35;
			this->label22->Text = L"Upper WaterTemp Limit";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label23->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label23->Location = System::Drawing::Point(26, 142);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(151, 16);
			this->label23->TabIndex = 36;
			this->label23->Text = L"Lower Water Temp Limit";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label24->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label24->Location = System::Drawing::Point(335, 35);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(97, 16);
			this->label24->TabIndex = 37;
			this->label24->Text = L"Upper PH Limit";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label25->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label25->Location = System::Drawing::Point(337, 72);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(95, 16);
			this->label25->TabIndex = 38;
			this->label25->Text = L"Lower PH Limit";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label26->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label26->Location = System::Drawing::Point(335, 107);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(122, 16);
			this->label26->TabIndex = 39;
			this->label26->Text = L"Water Level Desire";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label27->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label27->Location = System::Drawing::Point(337, 140);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(129, 16);
			this->label27->TabIndex = 40;
			this->label27->Text = L"Light Intensity Desire";
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(222, 69);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(67, 22);
			this->textBox10->TabIndex = 41;
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(222, 104);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(67, 22);
			this->textBox11->TabIndex = 42;
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(222, 137);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(67, 22);
			this->textBox12->TabIndex = 43;
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(497, 137);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(67, 22);
			this->textBox13->TabIndex = 47;
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(497, 101);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(67, 22);
			this->textBox14->TabIndex = 46;
			// 
			// textBox15
			// 
			this->textBox15->Location = System::Drawing::Point(497, 66);
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(67, 22);
			this->textBox15->TabIndex = 45;
			// 
			// textBox16
			// 
			this->textBox16->Location = System::Drawing::Point(497, 32);
			this->textBox16->Name = L"textBox16";
			this->textBox16->Size = System::Drawing::Size(67, 22);
			this->textBox16->TabIndex = 44;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->label28);
			this->groupBox5->Controls->Add(this->label31);
			this->groupBox5->Controls->Add(this->label32);
			this->groupBox5->Controls->Add(this->label33);
			this->groupBox5->Controls->Add(this->button1);
			this->groupBox5->Controls->Add(this->label34);
			this->groupBox5->Controls->Add(this->button2);
			this->groupBox5->Controls->Add(this->textBox17);
			this->groupBox5->Controls->Add(this->textBox18);
			this->groupBox5->Controls->Add(this->label35);
			this->groupBox5->Controls->Add(this->label36);
			this->groupBox5->Controls->Add(this->label37);
			this->groupBox5->Controls->Add(this->textBox19);
			this->groupBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox5->Location = System::Drawing::Point(615, 264);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(343, 221);
			this->groupBox5->TabIndex = 24;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Arduino Connection Setup";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(122, 34);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(16, 16);
			this->label28->TabIndex = 23;
			this->label28->Text = L"...";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(122, 150);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(16, 16);
			this->label31->TabIndex = 22;
			this->label31->Text = L"...";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(6, 150);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(106, 16);
			this->label32->TabIndex = 21;
			this->label32->Text = L"Connection state";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(6, 34);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(75, 16);
			this->label33->TabIndex = 12;
			this->label33->Text = L"CPU Status";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(235, 100);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(90, 31);
			this->button1->TabIndex = 19;
			this->button1->Text = L"Disconnect";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(6, 107);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(105, 16);
			this->label34->TabIndex = 12;
			this->label34->Text = L"PLC Connection:";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(125, 100);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(90, 31);
			this->button2->TabIndex = 18;
			this->button2->Text = L"Connect";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// textBox17
			// 
			this->textBox17->Location = System::Drawing::Point(273, 65);
			this->textBox17->Name = L"textBox17";
			this->textBox17->Size = System::Drawing::Size(52, 22);
			this->textBox17->TabIndex = 17;
			this->textBox17->Text = L"1";
			// 
			// textBox18
			// 
			this->textBox18->Location = System::Drawing::Point(175, 65);
			this->textBox18->Name = L"textBox18";
			this->textBox18->Size = System::Drawing::Size(52, 22);
			this->textBox18->TabIndex = 16;
			this->textBox18->Text = L"0";
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(237, 68);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(33, 16);
			this->label35->TabIndex = 15;
			this->label35->Text = L"Slot:";
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(133, 68);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(42, 16);
			this->label36->TabIndex = 14;
			this->label36->Text = L"Rack:";
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(6, 68);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(22, 16);
			this->label37->TabIndex = 12;
			this->label37->Text = L"IP:";
			// 
			// textBox19
			// 
			this->textBox19->Location = System::Drawing::Point(29, 65);
			this->textBox19->Name = L"textBox19";
			this->textBox19->Size = System::Drawing::Size(91, 22);
			this->textBox19->TabIndex = 12;
			this->textBox19->Text = L"192.168.10.1";
			this->textBox19->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(979, 572);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->ResumeLayout(false);

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
		this->timer1->Tick += gcnew System::EventHandler(this, &MainProject::MainForm::OnTick);
		this->timer2->Tick += gcnew System::EventHandler(this, &MainProject::MainForm::OnTick2);
	}
		   void OnTick(System::Object^ sender, System::EventArgs^ e);
		   void OnTick2(System::Object^ sender, System::EventArgs^ e);
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}


	   void test() {
		   while (!TerminateCondition())
		   {
			   if (MyClient->Connected())
			   {
				   PerformDataExchange();
				   sleep(TimeRate); // exchange time interval
			   }
			   else
				   if (MyClient->Connect() != 0) //error
					   MyClient->Disconnect
					   sleep(10); // small wait recovery time
		   }
	   }




private: System::Void bindingSource2_CurrentChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}


void MainProject::MainForm::OnTick(System::Object^ sender, System::EventArgs^ e)
{
	S7Connection();
	MyClient->DBWrite(1, 0, 1, &MyDB1);
	//delete MyClient;
}
void MainProject::MainForm::OnTick2(System::Object^ sender, System::EventArgs^ e)
{
	S7Connection();
	MyClient->DBWrite(1, 0, 1, &MyDB0);
}

 
