#pragma once
//#include <snap7.h>
#include<C:\Users\Admin\Desktop\doAncpp\S7PLCCPPPack\LIB\include\SNAP7\snap7.h>
#include <cstring>
#include <compare>
#include <type_traits>
#include <string>
#include <bitset>
#include <C:\Users\Admin\Desktop\doAncpp\S7PLCCPPPack\LIB\include\SNAP7\s7.h>
#include <C:\Users\Admin\Desktop\doAncpp\S7PLCCPPPack\LIB\include\SNAP7\SerialPort.h>
#include <msclr/marshal_cppstd.h>
#include <sstream>
#include <sstream>
#include <cmath>


namespace MainProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace System::Runtime::InteropServices;
	using namespace msclr::interop;


	
	union FloatBytes {
		float real;
		byte bytes;
	};
	char* PlcConnectionState;
	char* ArduinoConnectionState;
	char* plcStat;
	TS7Client* PlcClient;
	char* addr;
	int rack;
	int slot;
	int PlcIndexColorConnStr; // 0 ok, 1 fail, 2 normal
	int ArduinoIndexColorConnStr; // 0 ok, 1 fail, 2 normal
	int indexColorCpuStr; // 0 Run, 1 Stop
	int indexColorArdStr; // 0 Run, 1 Stop
	static bool isConnectClick, isDisArduino;
	byte DB9_W[1];
	// Arduino
	char output[1];
	char incomingData[MAX_DATA_LENGTH];
	char* port;
	SerialPort* arduino=NULL;
	std::string Prefix = "\\\\.\\";
	std::string  fullComName = "";
	// 
	float ambientTempValue, watertankLvValue, PHValue, LightIntenValue, wtTempValue;
	float ambientUp, watertankLvDesire, ambientLo, waterTempUp, waterTempLo, PhUp, PhLo, LightIntenDesire;
	bool binaryArraySave[8] = { 0 };
	bool  isMotorOn, isBaseOn, isAcidOn, isFanOn, isLightOn, isCoolwtOn;
	bool isAutoMode;
	
	void ArduinoConn(SerialPort* object, char* portName) {
		fullComName = Prefix + portName;
		const char* portConv = fullComName.c_str();
		char* port = const_cast<char*>(portConv);;
	
		
		if (object->isConnected()) {
			System::Threading::Thread::Sleep(100);
			ArduinoConnectionState = "Successful connection!";
			ArduinoIndexColorConnStr = 0;
		}
		else {
			ArduinoConnectionState = "Connection fail!";
			ArduinoIndexColorConnStr = 1;
		}
	}
	static void ArduinoGetData(SerialPort* object) {
		if(object)
		object->readSerialPort(output, MAX_DATA_LENGTH);
	}

	void S7Connection(char* addr, int rack, int slot)
	{
		PlcClient->ConnectTo(addr, rack, slot);
		if (PlcClient->Connect() != 0) // error occur
		{
			System::Threading::Thread::Sleep(100); // small wait recovery time
			PlcConnectionState = "Connection errors!";
			PlcIndexColorConnStr = 1;
			return;
		}
		if (PlcClient->Connected())
		{
			PlcConnectionState = "Successful connection!";
			PlcIndexColorConnStr = 0;
			
		}
	}
	void S7Disconnect(bool isDisconnect) {
		if (isDisconnect) {
			PlcClient->Disconnect(); // Disconnect
		}
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
#pragma region UICODE




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


	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::GroupBox^ groupBox3;


	private: System::Windows::Forms::Label^ label17;


	private: System::Windows::Forms::Label^ label18;


	private: System::Windows::Forms::Label^ label19;


	private: System::Windows::Forms::Label^ label20;


	private: System::Windows::Forms::Label^ label16;


	private: System::Windows::Forms::Label^ label15;


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

	private: System::Windows::Forms::Label^ label31;
	private: System::Windows::Forms::Label^ label32;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label34;
	private: System::Windows::Forms::Button^ button2;

	private: System::Windows::Forms::TextBox^ textBox18;


	private: System::Windows::Forms::Label^ label37;


private: System::Windows::Forms::GroupBox^ groupBox6;
private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
private: System::Windows::Forms::GroupBox^ groupBox10;
private: System::Windows::Forms::RadioButton^ radioButton9;
private: System::Windows::Forms::RadioButton^ radioButton10;
private: System::Windows::Forms::GroupBox^ groupBox9;
private: System::Windows::Forms::RadioButton^ radioButton7;
private: System::Windows::Forms::RadioButton^ radioButton8;
private: System::Windows::Forms::GroupBox^ groupBox11;
private: System::Windows::Forms::RadioButton^ radioButton11;
private: System::Windows::Forms::RadioButton^ radioButton12;
private: System::Windows::Forms::GroupBox^ groupBox8;
private: System::Windows::Forms::RadioButton^ radioButton5;
private: System::Windows::Forms::RadioButton^ radioButton6;
private: System::Windows::Forms::GroupBox^ groupBox12;
private: System::Windows::Forms::RadioButton^ radioButton13;
private: System::Windows::Forms::RadioButton^ radioButton14;
private: System::Windows::Forms::GroupBox^ groupBox7;
private: System::Windows::Forms::RadioButton^ radioButton3;
private: System::Windows::Forms::RadioButton^ radioButton4;
private: System::Windows::Forms::GroupBox^ groupBox13;
private: System::Windows::Forms::RadioButton^ radioButton15;
private: System::Windows::Forms::RadioButton^ radioButton16;
private: System::Windows::Forms::Button^ button6;
private: System::Windows::Forms::Button^ button8;
private: System::Windows::Forms::Button^ button7;
private: System::Windows::Forms::Button^ button9;


#pragma endregion


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
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->groupBox10 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton9 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton10 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton7 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton8 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox11 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton11 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton12 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox12 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton13 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton14 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox13 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton15 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton16 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox18 = (gcnew System::Windows::Forms::TextBox());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox10->SuspendLayout();
			this->groupBox9->SuspendLayout();
			this->groupBox11->SuspendLayout();
			this->groupBox8->SuspendLayout();
			this->groupBox12->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->groupBox13->SuspendLayout();
			this->groupBox6->SuspendLayout();
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
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(58, 22);
			this->textBox5->TabIndex = 11;
			this->textBox5->TabStop = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(402, 41);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(86, 16);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Light Intensity";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(325, 76);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(58, 22);
			this->textBox4->TabIndex = 9;
			this->textBox4->TabStop = false;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(325, 38);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(58, 22);
			this->textBox3->TabIndex = 8;
			this->textBox3->TabStop = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(206, 44);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(113, 16);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Water Tank Level";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(131, 77);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(58, 22);
			this->textBox2->TabIndex = 6;
			this->textBox2->TabStop = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(206, 83);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(106, 16);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Water Temp (°C)";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(131, 41);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(58, 22);
			this->textBox1->TabIndex = 4;
			this->textBox1->TabStop = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 82);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(26, 16);
			this->label3->TabIndex = 3;
			this->label3->Text = L"PH";
			this->label3->Click += gcnew System::EventHandler(this, &MainForm::label3_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label21);
			this->groupBox2->Controls->Add(this->label11);
			this->groupBox2->Controls->Add(this->label12);
			this->groupBox2->Controls->Add(this->label10);
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
			this->groupBox2->Size = System::Drawing::Size(373, 221);
			this->groupBox2->TabIndex = 12;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"PLC Connection Setup";
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
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(122, 150);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(16, 16);
			this->label11->TabIndex = 22;
			this->label11->Text = L"...";
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
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(6, 34);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(75, 16);
			this->label10->TabIndex = 12;
			this->label10->Text = L"CPU Status";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(6, 107);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(87, 16);
			this->label9->TabIndex = 12;
			this->label9->Text = L"PLC Connect:";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(138, 100);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(102, 31);
			this->button3->TabIndex = 18;
			this->button3->Text = L"Connect";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::ConnectClick);
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(324, 65);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(27, 22);
			this->textBox8->TabIndex = 17;
			this->textBox8->TabStop = false;
			this->textBox8->Text = L"1";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(221, 65);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(30, 22);
			this->textBox7->TabIndex = 16;
			this->textBox7->TabStop = false;
			this->textBox7->Text = L"0";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(288, 68);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(33, 16);
			this->label8->TabIndex = 15;
			this->label8->Text = L"Slot:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(179, 68);
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
			this->textBox6->Location = System::Drawing::Point(34, 65);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(117, 22);
			this->textBox6->TabIndex = 12;
			this->textBox6->TabStop = false;
			this->textBox6->Text = L"192.168.0.1";
			this->textBox6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->button6);
			this->groupBox3->Controls->Add(this->groupBox10);
			this->groupBox3->Controls->Add(this->groupBox9);
			this->groupBox3->Controls->Add(this->groupBox11);
			this->groupBox3->Controls->Add(this->groupBox8);
			this->groupBox3->Controls->Add(this->groupBox12);
			this->groupBox3->Controls->Add(this->groupBox7);
			this->groupBox3->Controls->Add(this->groupBox13);
			this->groupBox3->Controls->Add(this->groupBox6);
			this->groupBox3->Controls->Add(this->label17);
			this->groupBox3->Controls->Add(this->label18);
			this->groupBox3->Controls->Add(this->label19);
			this->groupBox3->Controls->Add(this->label20);
			this->groupBox3->Controls->Add(this->label16);
			this->groupBox3->Controls->Add(this->label15);
			this->groupBox3->Controls->Add(this->label14);
			this->groupBox3->Controls->Add(this->label13);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox3->Location = System::Drawing::Point(12, 371);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(584, 236);
			this->groupBox3->TabIndex = 22;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Manual Control";
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(474, 193);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(90, 31);
			this->button6->TabIndex = 24;
			this->button6->Text = L"Set State";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MainForm::SetStateClick);
			// 
			// groupBox10
			// 
			this->groupBox10->Controls->Add(this->radioButton9);
			this->groupBox10->Controls->Add(this->radioButton10);
			this->groupBox10->Location = System::Drawing::Point(424, 141);
			this->groupBox10->Name = L"groupBox10";
			this->groupBox10->Size = System::Drawing::Size(140, 33);
			this->groupBox10->TabIndex = 42;
			this->groupBox10->TabStop = false;
			// 
			// radioButton9
			// 
			this->radioButton9->AutoSize = true;
			this->radioButton9->Location = System::Drawing::Point(82, 9);
			this->radioButton9->Name = L"radioButton9";
			this->radioButton9->Size = System::Drawing::Size(54, 20);
			this->radioButton9->TabIndex = 14;
			this->radioButton9->TabStop = true;
			this->radioButton9->Text = L"OFF";
			this->radioButton9->UseVisualStyleBackColor = true;
			// 
			// radioButton10
			// 
			this->radioButton10->AutoSize = true;
			this->radioButton10->Location = System::Drawing::Point(19, 9);
			this->radioButton10->Name = L"radioButton10";
			this->radioButton10->Size = System::Drawing::Size(48, 20);
			this->radioButton10->TabIndex = 13;
			this->radioButton10->TabStop = true;
			this->radioButton10->Text = L"ON";
			this->radioButton10->UseVisualStyleBackColor = true;
			// 
			// groupBox9
			// 
			this->groupBox9->Controls->Add(this->radioButton7);
			this->groupBox9->Controls->Add(this->radioButton8);
			this->groupBox9->Location = System::Drawing::Point(138, 141);
			this->groupBox9->Name = L"groupBox9";
			this->groupBox9->Size = System::Drawing::Size(140, 33);
			this->groupBox9->TabIndex = 39;
			this->groupBox9->TabStop = false;
			// 
			// radioButton7
			// 
			this->radioButton7->AutoSize = true;
			this->radioButton7->Location = System::Drawing::Point(81, 9);
			this->radioButton7->Name = L"radioButton7";
			this->radioButton7->Size = System::Drawing::Size(54, 20);
			this->radioButton7->TabIndex = 14;
			this->radioButton7->TabStop = true;
			this->radioButton7->Text = L"OFF";
			this->radioButton7->UseVisualStyleBackColor = true;
			// 
			// radioButton8
			// 
			this->radioButton8->AutoSize = true;
			this->radioButton8->Location = System::Drawing::Point(18, 9);
			this->radioButton8->Name = L"radioButton8";
			this->radioButton8->Size = System::Drawing::Size(48, 20);
			this->radioButton8->TabIndex = 13;
			this->radioButton8->TabStop = true;
			this->radioButton8->Text = L"ON";
			this->radioButton8->UseVisualStyleBackColor = true;
			// 
			// groupBox11
			// 
			this->groupBox11->Controls->Add(this->radioButton11);
			this->groupBox11->Controls->Add(this->radioButton12);
			this->groupBox11->Location = System::Drawing::Point(424, 104);
			this->groupBox11->Name = L"groupBox11";
			this->groupBox11->Size = System::Drawing::Size(140, 33);
			this->groupBox11->TabIndex = 43;
			this->groupBox11->TabStop = false;
			// 
			// radioButton11
			// 
			this->radioButton11->AutoSize = true;
			this->radioButton11->Location = System::Drawing::Point(82, 9);
			this->radioButton11->Name = L"radioButton11";
			this->radioButton11->Size = System::Drawing::Size(54, 20);
			this->radioButton11->TabIndex = 14;
			this->radioButton11->TabStop = true;
			this->radioButton11->Text = L"OFF";
			this->radioButton11->UseVisualStyleBackColor = true;
			// 
			// radioButton12
			// 
			this->radioButton12->AutoSize = true;
			this->radioButton12->Location = System::Drawing::Point(19, 9);
			this->radioButton12->Name = L"radioButton12";
			this->radioButton12->Size = System::Drawing::Size(48, 20);
			this->radioButton12->TabIndex = 13;
			this->radioButton12->TabStop = true;
			this->radioButton12->Text = L"ON";
			this->radioButton12->UseVisualStyleBackColor = true;
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->radioButton5);
			this->groupBox8->Controls->Add(this->radioButton6);
			this->groupBox8->Location = System::Drawing::Point(138, 104);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(140, 33);
			this->groupBox8->TabIndex = 39;
			this->groupBox8->TabStop = false;
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Location = System::Drawing::Point(81, 9);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(54, 20);
			this->radioButton5->TabIndex = 14;
			this->radioButton5->TabStop = true;
			this->radioButton5->Text = L"OFF";
			this->radioButton5->UseVisualStyleBackColor = true;
			// 
			// radioButton6
			// 
			this->radioButton6->AutoSize = true;
			this->radioButton6->Location = System::Drawing::Point(18, 9);
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->Size = System::Drawing::Size(48, 20);
			this->radioButton6->TabIndex = 13;
			this->radioButton6->TabStop = true;
			this->radioButton6->Text = L"ON";
			this->radioButton6->UseVisualStyleBackColor = true;
			// 
			// groupBox12
			// 
			this->groupBox12->Controls->Add(this->radioButton13);
			this->groupBox12->Controls->Add(this->radioButton14);
			this->groupBox12->Location = System::Drawing::Point(424, 66);
			this->groupBox12->Name = L"groupBox12";
			this->groupBox12->Size = System::Drawing::Size(140, 33);
			this->groupBox12->TabIndex = 41;
			this->groupBox12->TabStop = false;
			// 
			// radioButton13
			// 
			this->radioButton13->AutoSize = true;
			this->radioButton13->Location = System::Drawing::Point(82, 9);
			this->radioButton13->Name = L"radioButton13";
			this->radioButton13->Size = System::Drawing::Size(54, 20);
			this->radioButton13->TabIndex = 14;
			this->radioButton13->TabStop = true;
			this->radioButton13->Text = L"OFF";
			this->radioButton13->UseVisualStyleBackColor = true;
			// 
			// radioButton14
			// 
			this->radioButton14->AutoSize = true;
			this->radioButton14->Location = System::Drawing::Point(19, 9);
			this->radioButton14->Name = L"radioButton14";
			this->radioButton14->Size = System::Drawing::Size(48, 20);
			this->radioButton14->TabIndex = 13;
			this->radioButton14->TabStop = true;
			this->radioButton14->Text = L"ON";
			this->radioButton14->UseVisualStyleBackColor = true;
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->radioButton3);
			this->groupBox7->Controls->Add(this->radioButton4);
			this->groupBox7->Location = System::Drawing::Point(138, 66);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(140, 33);
			this->groupBox7->TabIndex = 38;
			this->groupBox7->TabStop = false;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(81, 9);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(54, 20);
			this->radioButton3->TabIndex = 14;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"OFF";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(18, 9);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(48, 20);
			this->radioButton4->TabIndex = 13;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"ON";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// groupBox13
			// 
			this->groupBox13->Controls->Add(this->radioButton15);
			this->groupBox13->Controls->Add(this->radioButton16);
			this->groupBox13->Location = System::Drawing::Point(424, 29);
			this->groupBox13->Name = L"groupBox13";
			this->groupBox13->Size = System::Drawing::Size(140, 33);
			this->groupBox13->TabIndex = 40;
			this->groupBox13->TabStop = false;
			// 
			// radioButton15
			// 
			this->radioButton15->AutoSize = true;
			this->radioButton15->Location = System::Drawing::Point(82, 9);
			this->radioButton15->Name = L"radioButton15";
			this->radioButton15->Size = System::Drawing::Size(54, 20);
			this->radioButton15->TabIndex = 14;
			this->radioButton15->TabStop = true;
			this->radioButton15->Text = L"OFF";
			this->radioButton15->UseVisualStyleBackColor = true;
			// 
			// radioButton16
			// 
			this->radioButton16->AutoSize = true;
			this->radioButton16->Location = System::Drawing::Point(19, 9);
			this->radioButton16->Name = L"radioButton16";
			this->radioButton16->Size = System::Drawing::Size(48, 20);
			this->radioButton16->TabIndex = 13;
			this->radioButton16->TabStop = true;
			this->radioButton16->Text = L"ON";
			this->radioButton16->UseVisualStyleBackColor = true;
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->radioButton2);
			this->groupBox6->Controls->Add(this->radioButton1);
			this->groupBox6->Location = System::Drawing::Point(138, 29);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(140, 33);
			this->groupBox6->TabIndex = 37;
			this->groupBox6->TabStop = false;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(81, 9);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(54, 20);
			this->radioButton2->TabIndex = 14;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"OFF";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(18, 9);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(48, 20);
			this->radioButton1->TabIndex = 13;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"ON";
			this->radioButton1->UseVisualStyleBackColor = true;
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
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label16->Location = System::Drawing::Point(26, 152);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(35, 16);
			this->label16->TabIndex = 21;
			this->label16->Text = L"Light";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label15->Location = System::Drawing::Point(26, 118);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(106, 16);
			this->label15->TabIndex = 18;
			this->label15->Text = L"Base (PH Down)";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label14->Location = System::Drawing::Point(26, 80);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(30, 16);
			this->label14->TabIndex = 15;
			this->label14->Text = L"Fan";
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
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->button9);
			this->groupBox4->Controls->Add(this->button8);
			this->groupBox4->Controls->Add(this->button7);
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
			this->groupBox4->Location = System::Drawing::Point(12, 148);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(584, 217);
			this->groupBox4->TabIndex = 36;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Auto Control";
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(474, 180);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(90, 31);
			this->button9->TabIndex = 49;
			this->button9->Text = L"Set Data";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MainForm::button9_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(474, 11);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(90, 31);
			this->button8->TabIndex = 48;
			this->button8->Text = L"Stop Auto";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MainForm::button8_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(367, 11);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(90, 31);
			this->button7->TabIndex = 44;
			this->button7->Text = L"Start Auto";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MainForm::button7_Click);
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(497, 153);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(67, 22);
			this->textBox13->TabIndex = 47;
			this->textBox13->TabStop = false;
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(497, 117);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(67, 22);
			this->textBox14->TabIndex = 46;
			this->textBox14->TabStop = false;
			// 
			// textBox15
			// 
			this->textBox15->Location = System::Drawing::Point(497, 82);
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(67, 22);
			this->textBox15->TabIndex = 45;
			this->textBox15->TabStop = false;
			// 
			// textBox16
			// 
			this->textBox16->Location = System::Drawing::Point(497, 48);
			this->textBox16->Name = L"textBox16";
			this->textBox16->Size = System::Drawing::Size(67, 22);
			this->textBox16->TabIndex = 44;
			this->textBox16->TabStop = false;
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(222, 153);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(67, 22);
			this->textBox12->TabIndex = 43;
			this->textBox12->TabStop = false;
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(222, 120);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(67, 22);
			this->textBox11->TabIndex = 42;
			this->textBox11->TabStop = false;
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(222, 85);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(67, 22);
			this->textBox10->TabIndex = 41;
			this->textBox10->TabStop = false;
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label27->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label27->Location = System::Drawing::Point(337, 156);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(129, 16);
			this->label27->TabIndex = 40;
			this->label27->Text = L"Light Intensity Desire";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label26->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label26->Location = System::Drawing::Point(335, 123);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(122, 16);
			this->label26->TabIndex = 39;
			this->label26->Text = L"Water Level Desire";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label25->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label25->Location = System::Drawing::Point(337, 88);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(95, 16);
			this->label25->TabIndex = 38;
			this->label25->Text = L"Lower PH Limit";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label24->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label24->Location = System::Drawing::Point(335, 51);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(97, 16);
			this->label24->TabIndex = 37;
			this->label24->Text = L"Upper PH Limit";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label23->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label23->Location = System::Drawing::Point(26, 158);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(151, 16);
			this->label23->TabIndex = 36;
			this->label23->Text = L"Lower Water Temp Limit";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label22->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label22->Location = System::Drawing::Point(26, 123);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(150, 16);
			this->label22->TabIndex = 35;
			this->label22->Text = L"Upper WaterTemp Limit";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label30->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label30->Location = System::Drawing::Point(26, 88);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(164, 16);
			this->label30->TabIndex = 34;
			this->label30->Text = L"Lower Ambient Temp Limit";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(222, 48);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(67, 22);
			this->textBox9->TabIndex = 12;
			this->textBox9->TabStop = false;
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label29->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label29->Location = System::Drawing::Point(26, 54);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(166, 16);
			this->label29->TabIndex = 12;
			this->label29->Text = L"Upper Ambient Temp Limit";
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->label31);
			this->groupBox5->Controls->Add(this->label32);
			this->groupBox5->Controls->Add(this->button1);
			this->groupBox5->Controls->Add(this->label34);
			this->groupBox5->Controls->Add(this->button2);
			this->groupBox5->Controls->Add(this->textBox18);
			this->groupBox5->Controls->Add(this->label37);
			this->groupBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox5->Location = System::Drawing::Point(615, 264);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(373, 165);
			this->groupBox5->TabIndex = 24;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Arduino Connection Setup";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(122, 115);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(16, 16);
			this->label31->TabIndex = 22;
			this->label31->Text = L"...";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(6, 115);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(106, 16);
			this->label32->TabIndex = 21;
			this->label32->Text = L"Connection state";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(249, 65);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(102, 31);
			this->button1->TabIndex = 19;
			this->button1->Text = L"Disconnect";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(6, 72);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(108, 16);
			this->label34->TabIndex = 12;
			this->label34->Text = L"Arduino Connect:";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(138, 65);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(102, 31);
			this->button2->TabIndex = 18;
			this->button2->Text = L"Connect";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// textBox18
			// 
			this->textBox18->Location = System::Drawing::Point(93, 30);
			this->textBox18->Name = L"textBox18";
			this->textBox18->Size = System::Drawing::Size(52, 22);
			this->textBox18->TabIndex = 16;
			this->textBox18->TabStop = false;
			this->textBox18->Text = L"COM3";
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(6, 33);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(81, 16);
			this->label37->TabIndex = 12;
			this->label37->Text = L"COM PORT:";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1012, 610);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1030, 657);
			this->MinimumSize = System::Drawing::Size(1030, 657);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"System Monitor";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox10->ResumeLayout(false);
			this->groupBox10->PerformLayout();
			this->groupBox9->ResumeLayout(false);
			this->groupBox9->PerformLayout();
			this->groupBox11->ResumeLayout(false);
			this->groupBox11->PerformLayout();
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			this->groupBox12->ResumeLayout(false);
			this->groupBox12->PerformLayout();
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			this->groupBox13->ResumeLayout(false);
			this->groupBox13->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
		
		this->timer1->Interval = 1000;
		this->timer1->Start();
		this->timer2->Interval = 1500;
		this->timer2->Start();
		this->timer1->Tick += gcnew System::EventHandler(this, &MainProject::MainForm::OnTick);
		this->timer2->Tick += gcnew System::EventHandler(this, &MainProject::MainForm::OnTick2);
		this->radioButton1->Checked = false;
		this->radioButton2->Checked = true;
		this->radioButton3->Checked = true;
		this->radioButton4->Checked = false;
		this->radioButton5->Checked = true;
		this->radioButton6->Checked = false;
		this->radioButton7->Checked = true;
		this->radioButton8->Checked = false;
		this->radioButton9->Checked = true;
		this->radioButton10->Checked = false;
		this->radioButton11->Checked = true;
		this->radioButton12->Checked = false;
		this->radioButton13->Checked = true;
		this->radioButton14->Checked = false;
		this->radioButton15->Checked = true;
		this->radioButton16->Checked = false;
	}
		   void OnTick(System::Object^ sender, System::EventArgs^ e);
		   void OnTick2(System::Object^ sender, System::EventArgs^ e);

	//Connecttion PLC Click
	private: System::Void ConnectClick(System::Object^ sender, System::EventArgs^ e)
	{
		while (arduino&& arduino->isConnected())
		{
			ArduinoDisConnectAction();
		}
		RelayConnectPLC();
		FirstReadDataSettingFrPLC();
		RelayConnectArd();
	}
		   
//relay control
		   void RelayConnectPLC() {
			   isConnectClick = true;
			   // get connect param 
			   addr = (char*)(void*)Marshal::StringToHGlobalAnsi(this->textBox6->Text); // String^ to char*
			   rack = Int32::Parse(this->textBox7->Text);
			   slot = Int32::Parse(this->textBox8->Text);
			   // create client
			   PlcConnectAction(); // conect PLC
			  
 }
		   //Connect Action
	private: System::Void PlcConnectAction()
	{
		
		PlcClient = new TS7Client();
		S7Connection(addr, rack, slot); // start connect
		
		String^ connectStateString = gcnew String(PlcConnectionState);// Convert char* to String^
		this->label11->Text = connectStateString;
		if (PlcIndexColorConnStr == 0)
			this->label11->ForeColor = System::Drawing::Color::DarkGreen;
		else if (PlcIndexColorConnStr == 1)
			this->label11->ForeColor = System::Drawing::Color::Red;
		else if (PlcIndexColorConnStr == 2)
			this->label11->ForeColor = System::Drawing::Color::Black;
		GetPLCState();
		
	}
		   //Get PLC Status
		   void GetPLCState()
		   {
			   if (PlcClient->Connected())
			   {
				   if (PlcClient->PlcStatus() == 0x00) {
					   indexColorCpuStr = 2;
					   plcStat = "The CPU status is unknown.";
				   }
					  
				   else if (PlcClient->PlcStatus() == 0x08) {
					   indexColorCpuStr = 0;
					   plcStat = "The CPU is running.";
				   }
					  
				   else if (PlcClient->PlcStatus() == 0x04) {
					   indexColorCpuStr = 1;
					   plcStat = "The CPU is stopped.";
				   }
					   
				   String^ cpuStateString = gcnew String(plcStat);// Convert char* to String^
				   this->label21->Text = cpuStateString;
				   if (indexColorCpuStr == 0)
					   this->label21->ForeColor = System::Drawing::Color::DarkGreen;
				   else if (indexColorCpuStr == 1)
					   this->label21->ForeColor = System::Drawing::Color::Red;
				   else if (indexColorCpuStr == 2)
					   this->label21->ForeColor = System::Drawing::Color::Black;
			   }
			  
		   }


		   //Disconnect PLC
	private: System::Void Dis_Click(System::Object^ sender, System::EventArgs^ e)
	{
		while (arduino && arduino->isConnected())
		{
			ArduinoDisConnectAction();
		}
		PlcClient -> Disconnect();
		/*PlcDisConnectAction(true);*/
	}
		   void PlcDisConnectAction(bool isDis) {
			   if (PlcClient) {
				   isConnectClick = false;
				   S7Disconnect(isDis);
				   if (!PlcClient->Connected()) {
					   PlcConnectionState = "Idle!";
					   PlcIndexColorConnStr = 2;
					   String^ connectStateString = gcnew String(PlcConnectionState);// Convert char* to String^
					   this->label11->Text = connectStateString;
					   if (PlcIndexColorConnStr == 0)
						   this->label11->ForeColor = System::Drawing::Color::DarkGreen;
					   else if (PlcIndexColorConnStr == 1)
						   this->label11->ForeColor = System::Drawing::Color::Red;
					   else if (PlcIndexColorConnStr == 2)
						   this->label11->ForeColor = System::Drawing::Color::Black;
				   }
			   }
		   }
	private: System::Void Res_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		PlcDisConnectAction(true);
	}
unsigned char BinaryArrayToByte(const bool binaryArray[], int size) {
	unsigned char byte = 0;

	for (int i = 0; i < size; i++) {
		byte |= (binaryArray[i] << (size - 1 - i));
	}
	return byte;
}
void ByteToBinaryArray(unsigned char byte, bool binaryArray[], int size) {
	for (int i = 0; i < size; i++) {
		binaryArray[size - 1 - i] = ((byte >> i) & 1);
	}
}

private: System::Void SetStateClick(System::Object^ sender, System::EventArgs^ e) {
	while (arduino  && arduino->isConnected())
	{
		ArduinoDisConnectAction();
	}
	RelayConnectPLC();
	if (PlcClient && PlcClient->Connected()) {
	bool binaryArray[8] = { 0 };
	//Motor
	if (this->radioButton1->Checked)
		binaryArray[7] = 1;
	//Motor Empty
	if (this->radioButton16->Checked)
		binaryArray[6] = 1;
	////Base on
	if (this->radioButton6->Checked)
		binaryArray[5] = 1;
	////Acid
	if (this->radioButton12->Checked)
		binaryArray[4] = 1;
	// Fan
	if (this->radioButton4->Checked)
		binaryArray[3] = 1;
	//// Oxi
	if (this->radioButton14->Checked)
		binaryArray[2] = 1;
	////Light
	if (this->radioButton8->Checked)
		binaryArray[1] = 1;
	//// Cool wt
	if (this->radioButton10->Checked)
		binaryArray[0] = 1;
		unsigned char byte = BinaryArrayToByte(binaryArray, 8);
		DB9_W[0] = static_cast<int>(byte);
		PlcClient->DBWrite(9, 0, 1, &DB9_W);
	}
	PlcDisConnectAction(true);
	RelayConnectArd();
}
	   
	   float bytesToFloat(const unsigned char* bytes)
	   {
		   float result;
		   std::memcpy(&result, bytes, sizeof(float));
		   return result;
	   }
	   void BackupDataSetting() {
		   if (PlcClient) {
			   const int elementNum = 8;
			   float numberConvert[elementNum];
			   byte DataPush[32];
			   cli::array<String^>^ stringGetfrTextBox = gcnew cli::array<String^>(elementNum);
			   stringGetfrTextBox[0] = this->textBox9->Text;
			   stringGetfrTextBox[1] = this->textBox10->Text;
			   stringGetfrTextBox[2] = this->textBox11->Text;
			   stringGetfrTextBox[3] = this->textBox12->Text;
			   stringGetfrTextBox[4] = this->textBox13->Text;
			   stringGetfrTextBox[5] = this->textBox14->Text;
			   stringGetfrTextBox[6] = this->textBox15->Text;
			   stringGetfrTextBox[7] = this->textBox16->Text;
			   int j = 0;
			   for (int i = 0;i < elementNum;i++) {
				   numberConvert[i] = float::Parse(stringGetfrTextBox[i]);
			   }
			   for (int i = 0; i < elementNum; i++)
			   {
				   S7_SetRealAt(&DataPush[i], 0, numberConvert[i]);
				   PlcClient->DBWrite(i + 1, 0, 4, &DataPush[i]);
			   }
		   }
		   
	  }
	   float roundToDigit(float number, int decimalPlaces) {
		   float power = std::pow(10, decimalPlaces);
		   return std::round(number * power) / power;
	   }
	   String^ floatToString(float number) {
		   return Single(number).ToString();
	   }
	   void FirstReadDataSettingFrPLC()
	   {
		   const int elementNum = 8;
		   byte DataGet[32]; // 
		   float result[elementNum];
		   cli::array<String^>^ stringRes = gcnew cli::array<String^>(elementNum);
		  
		   for (int i = 0; i < elementNum;i++) {
			   PlcClient->DBRead(i+1, 0, 4, &DataGet[i]);
			   result[i] = S7_GetRealAt(&DataGet[i], 0); // pos : pos in DB
			   stringRes[i] = floatToString(roundToDigit(result[i], 2));
			  
		   }
		   this->textBox9->Text = stringRes[0];
		   this->textBox10->Text = stringRes[1];
		   this->textBox11->Text = stringRes[2];
		   this->textBox12->Text = stringRes[3];
		   this->textBox13->Text = stringRes[4];
		   this->textBox14->Text = stringRes[5];
		   this->textBox15->Text = stringRes[6];
		   this->textBox16->Text = stringRes[7];
	   }
private: System::Void MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	
}

	   //Set data seting
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
	
		while(arduino && arduino ->isConnected())
			ArduinoDisConnectAction(); 
		RelayConnectPLC();
		BackupDataSetting();
		FirstReadDataSettingFrPLC();
		PlcDisConnectAction(true);
		RelayConnectArd();
	
	
}
	   //Arduino Connect Click
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	RelayConnectArd();
}
	   void RelayConnectArd() {
		   isDisArduino = false;
		   ArduinoDisConnectAction();
		   ArduinoConnectAction();
	   }
	   void ArduinoConnectAction() {
		   arduino = new SerialPort(port);
		   port = (char*)(void*)Marshal::StringToHGlobalAnsi(this->textBox18->Text);
		   ArduinoConn(arduino, port);
		   String^ connectStateString = gcnew String(ArduinoConnectionState);// Convert char* to String^
		   this->label31->Text = connectStateString;
		   if (ArduinoIndexColorConnStr == 0)
			   this->label31->ForeColor = System::Drawing::Color::DarkGreen;
		   else if (ArduinoIndexColorConnStr == 1)
			   this->label31->ForeColor = System::Drawing::Color::Black;
	   }
	   //Arduino Disconnect Click
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
{
	ArduinoDisConnectAction();
}
	   void ArduinoDisConnectAction() {
		   isDisArduino = true;
		   arduino->~SerialPort();
		   String^ connectStateString = gcnew String(ArduinoConnectionState);// Convert char* to String^
		   this->label31->Text = "Disconnected !";
		   this->label31->ForeColor = System::Drawing::Color::Black;
	   }
	   // Start Auto Mode
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	isAutoMode = true;
	this->radioButton1->Checked = false;
	this->radioButton2->Checked = true;
	this->radioButton3->Checked = true;
	this->radioButton4->Checked = false;
	this->radioButton5->Checked = true;
	this->radioButton6->Checked = false;
	this->radioButton7->Checked = true;
	this->radioButton8->Checked = false;
	this->radioButton9->Checked = true;
	this->radioButton10->Checked = false;
	this->radioButton11->Checked = true;
	this->radioButton12->Checked = false;
	this->radioButton13->Checked = true;
	this->radioButton14->Checked = false;
	this->radioButton15->Checked = true;
	this->radioButton16->Checked = false;
	this->button6->Enabled = false;
}
	   // Stop Automode
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	isAutoMode = false;
	this->radioButton1->Checked = false;
	this->radioButton2->Checked = true;
	this->radioButton3->Checked = true;
	this->radioButton4->Checked = false;
	this->radioButton5->Checked = true;
	this->radioButton6->Checked = false;
	this->radioButton7->Checked = true;
	this->radioButton8->Checked = false;
	this->radioButton9->Checked = true;
	this->radioButton10->Checked = false;
	this->radioButton11->Checked = true;
	this->radioButton12->Checked = false;
	this->radioButton13->Checked = true;
	this->radioButton14->Checked = false;
	this->radioButton15->Checked = true;
	this->radioButton16->Checked = false;
	this->button6->Enabled = true;
	if (PlcClient && arduino) {
		binaryArraySave[0] = 0;
		binaryArraySave[1] = 0;
		binaryArraySave[2] = 0;
		binaryArraySave[3] = 0;
		binaryArraySave[4] = 0;
		binaryArraySave[5] = 0;
		binaryArraySave[6] = 0;
		binaryArraySave[7] = 0;
		/*unsigned char byte = BinaryArrayToByte(binaryArraySave, 8);
		DB9_W[0] = static_cast<int>(byte);
		PlcClient->DBWrite(9, 0, 1, &DB9_W);*/
	}
}
	   void OperationAuto() {
		   //double ambientTempValue, watertankLvValue, PHValue, LightIntenValue, wtTempValue;
		   //double ambientUp, watertankLvDesire, ambientLo, waterTempUp, waterTempLo, PhUp, PhLo, LightIntenDesire;
		   
		   if (PlcClient && arduino && isAutoMode) {
			   //Motor

			   if (watertankLvValue >= watertankLvDesire) {
				   binaryArraySave[7] = 1;
				   isMotorOn = true;
			   }
			   else if (watertankLvValue < watertankLvDesire && isMotorOn) {
				   binaryArraySave[7] = 1;
				   isMotorOn = false;
			   }
			   //Motor Empty (notuse in auto)
			   // 
			   ////Base on

			   if (PHValue >= PhUp) {
				   binaryArraySave[5] = 0;
				   isBaseOn = true;
				   binaryArraySave[4] = 1;
				   isAcidOn = false;
			   }
			   ////Acid
			   if (PHValue <= PhLo) {
				   binaryArraySave[4] = 0;
				   isAcidOn = true;
				   binaryArraySave[5] = 1;
				   isBaseOn = false;
			   }

			   // Fan

			   if (ambientTempValue >= ambientUp) {
				   binaryArraySave[3] = 1;
				   isFanOn = true;
			   }
			   else if (ambientTempValue <= ambientLo && isFanOn) {
				   binaryArraySave[3] = 0;
			   }

			   //// Oxi
			  //
			   ////Light

			   if (LightIntenValue >= LightIntenDesire) {
				   binaryArraySave[1] = 1;
				   isLightOn = true;
			   }
			   else if (LightIntenValue <= LightIntenDesire && isLightOn) {
				   binaryArraySave[1] = 0;
				   isLightOn = false;
			   }

			   //// Cool wt

			   if (wtTempValue >= waterTempUp) {
				   isCoolwtOn = true;
				   binaryArraySave[0] = 1;
			   }
			   else if (wtTempValue <= waterTempUp && isCoolwtOn) {
				   isCoolwtOn = false;
				   binaryArraySave[0] = 0;
			   }
			   while (arduino && arduino->isConnected())
				   ArduinoDisConnectAction();
			   RelayConnectPLC();
			    unsigned char byte = BinaryArrayToByte(binaryArraySave, 8);
				DB9_W[0] = static_cast<int>(byte);
				PlcClient->DBWrite(9, 0, 1, &DB9_W);
				PlcDisConnectAction(true);
				RelayConnectArd();
		   }
	   }
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}


void SplitString(const std::string& input, char delimiter, std::string* output, size_t size) {
	std::istringstream tokenStream(input);
	std::string token;
	size_t index = 0;

	while (std::getline(tokenStream, token, delimiter) && index < size) {
		output[index] = token;
		index++;
	}
}

std::string GetStringUntilCarriageReturn(const std::string& str) {
	size_t pos = str.find('\r');
	if (pos != std::string::npos) {
		return str.substr(0, pos);
	}
	return str;
}

//Timer for GetData
void MainProject::MainForm::OnTick(System::Object^ sender, System::EventArgs^ e)
{
	ArduinoGetData(arduino);
	// Data Display
	if (arduino) {
		char delimiter = ',';
		const size_t arraySize = 5;
		std::string strings[arraySize];
		String^ managedString = marshal_as<String^>(output);
		std::string stringNon = marshal_as<std::string>(managedString);
		std::string getRetString = GetStringUntilCarriageReturn(stringNon);
		SplitString(getRetString, delimiter, strings, arraySize);
		String^ ambientT = marshal_as<String^>(strings[0]);
		String^ waterTankLV = marshal_as<String^>(strings[2]);
		String^ PH = marshal_as<String^>(strings[1]);
		String^ lightInten = marshal_as<String^>(strings[4]);
		String^ waterT = marshal_as<String^>(strings[3]);
		// GetDataPar
		float::TryParse(this->textBox9->Text, ambientUp);
		float::TryParse(this->textBox10->Text, ambientLo);
		float::TryParse(this->textBox11->Text, waterTempUp);
		float::TryParse(this->textBox12->Text, waterTempLo);
		float::TryParse(this->textBox16->Text, PhUp);
		float::TryParse(this->textBox15->Text, PhLo);
		float::TryParse(this->textBox14->Text, watertankLvDesire);
		float::TryParse(this->textBox13->Text, LightIntenDesire);
		// Try Convert data
		
		if(float::TryParse(ambientT, ambientTempValue))
			ambientTempValue = roundToDigit(ambientTempValue,2);
		else 
			ambientTempValue = 0.0;
		
		if (float::TryParse(waterTankLV, watertankLvValue))
			watertankLvValue = roundToDigit(watertankLvValue,2);
		else 
			watertankLvValue = 0.0;
		
		if (float::TryParse(PH, PHValue))
			PHValue = roundToDigit(PHValue,2);
		else 
			PHValue = 0.0;
		
		if (float::TryParse(lightInten, LightIntenValue))
			LightIntenValue = roundToDigit(LightIntenValue,2);
		else 
			LightIntenValue = 0.0;
		
		if (float::TryParse(waterT, wtTempValue))
			wtTempValue = roundToDigit(wtTempValue,2);
		else 
			wtTempValue = 0.0;
		
		this->textBox1->Text = ambientT;
		this->textBox2->Text = PH; //
		this->textBox3->Text = waterTankLV;
		this->textBox4->Text = waterT;
		this->textBox5->Text = lightInten;
	}
	
}

// Timer for recheck connection
void MainProject::MainForm::OnTick2(System::Object^ sender, System::EventArgs^ e)
{
	// Automode Action
	if (isAutoMode)
		OperationAuto();

}


