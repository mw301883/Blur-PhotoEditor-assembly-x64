#pragma once

#include <chrono>
#include <string>

namespace PhotoEditorBlurCPPASMx64 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o userGUI
	/// </summary>
	public ref class userGUI : public System::Windows::Forms::Form
	{
	public:

		Bitmap^ bmpLoadedIMG;
		Bitmap^ bmpCopyProcessedIMG;

		int blur_rate;

		userGUI(void)
		{
			InitializeComponent();
			this->blur_rate = 0;
		}

	protected:
		/// <summary>
		/// Wyczy�� wszystkie u�ywane zasoby.
		/// </summary>
		~userGUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::Label^ labelSetAVG;

	private: System::Windows::Forms::Label^ labelSetThreads;

	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::Button^ process;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ timeComp;


	private: System::Windows::Forms::Label^ labelCppTime;
	private: System::Windows::Forms::Label^ labelAssemblyTime;


	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ menuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ importImageToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ clearToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton3;









	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs�ugi projektanta � nie nale�y modyfikowa�
		/// jej zawarto�ci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->labelSetAVG = (gcnew System::Windows::Forms::Label());
			this->labelSetThreads = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->process = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->timeComp = (gcnew System::Windows::Forms::Label());
			this->labelCppTime = (gcnew System::Windows::Forms::Label());
			this->labelAssemblyTime = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->importImageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(79, 639);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(34, 22);
			this->textBox1->TabIndex = 0;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(119, 639);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(34, 22);
			this->textBox2->TabIndex = 1;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(159, 639);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(34, 22);
			this->textBox3->TabIndex = 2;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(79, 667);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(34, 22);
			this->textBox4->TabIndex = 3;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(119, 667);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(34, 22);
			this->textBox5->TabIndex = 4;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(159, 667);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(34, 22);
			this->textBox6->TabIndex = 5;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(159, 695);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(34, 22);
			this->textBox7->TabIndex = 8;
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(119, 695);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(34, 22);
			this->textBox8->TabIndex = 7;
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(79, 695);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(34, 22);
			this->textBox9->TabIndex = 6;
			// 
			// labelSetAVG
			// 
			this->labelSetAVG->AutoSize = true;
			this->labelSetAVG->Font = (gcnew System::Drawing::Font(L"Arial", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelSetAVG->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->labelSetAVG->Location = System::Drawing::Point(31, 601);
			this->labelSetAVG->Name = L"labelSetAVG";
			this->labelSetAVG->Size = System::Drawing::Size(303, 21);
			this->labelSetAVG->TabIndex = 9;
			this->labelSetAVG->Text = L"Set values of weighted average  :";
			this->labelSetAVG->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->labelSetAVG->Click += gcnew System::EventHandler(this, &userGUI::label1_Click);
			// 
			// labelSetThreads
			// 
			this->labelSetThreads->AutoSize = true;
			this->labelSetThreads->Font = (gcnew System::Drawing::Font(L"Arial", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelSetThreads->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->labelSetThreads->Location = System::Drawing::Point(402, 601);
			this->labelSetThreads->Name = L"labelSetThreads";
			this->labelSetThreads->Size = System::Drawing::Size(182, 21);
			this->labelSetThreads->TabIndex = 10;
			this->labelSetThreads->Text = L"Set threads amout :";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(599, 601);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 64, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 22);
			this->numericUpDown1->TabIndex = 11;
			// 
			// process
			// 
			this->process->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->process->Font = (gcnew System::Drawing::Font(L"Arial", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->process->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->process->Location = System::Drawing::Point(406, 653);
			this->process->Name = L"process";
			this->process->Size = System::Drawing::Size(313, 64);
			this->process->TabIndex = 12;
			this->process->Text = L"Proccess";
			this->process->UseCompatibleTextRendering = true;
			this->process->UseVisualStyleBackColor = false;
			this->process->Click += gcnew System::EventHandler(this, &userGUI::process_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(53, 40);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1171, 489);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 13;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &userGUI::pictureBox1_Click);
			// 
			// timeComp
			// 
			this->timeComp->AutoSize = true;
			this->timeComp->Font = (gcnew System::Drawing::Font(L"Arial", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->timeComp->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->timeComp->Location = System::Drawing::Point(746, 554);
			this->timeComp->Name = L"timeComp";
			this->timeComp->Size = System::Drawing::Size(464, 27);
			this->timeComp->TabIndex = 15;
			this->timeComp->Text = L"Time comparison of program execution : ";
			this->timeComp->Click += gcnew System::EventHandler(this, &userGUI::label3_Click);
			// 
			// labelCppTime
			// 
			this->labelCppTime->AutoSize = true;
			this->labelCppTime->Font = (gcnew System::Drawing::Font(L"Arial", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelCppTime->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->labelCppTime->Location = System::Drawing::Point(747, 599);
			this->labelCppTime->Name = L"labelCppTime";
			this->labelCppTime->Size = System::Drawing::Size(57, 21);
			this->labelCppTime->TabIndex = 16;
			this->labelCppTime->Text = L"C++ :";
			// 
			// labelAssemblyTime
			// 
			this->labelAssemblyTime->AutoSize = true;
			this->labelAssemblyTime->Font = (gcnew System::Drawing::Font(L"Arial", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelAssemblyTime->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->labelAssemblyTime->Location = System::Drawing::Point(747, 653);
			this->labelAssemblyTime->Name = L"labelAssemblyTime";
			this->labelAssemblyTime->Size = System::Drawing::Size(146, 21);
			this->labelAssemblyTime->TabIndex = 17;
			this->labelAssemblyTime->Text = L"Assembly x64 :";
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::AliceBlue;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->menuToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1281, 28);
			this->menuStrip1->TabIndex = 18;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// menuToolStripMenuItem
			// 
			this->menuToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->importImageToolStripMenuItem,
					this->clearToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->menuToolStripMenuItem->Name = L"menuToolStripMenuItem";
			this->menuToolStripMenuItem->Size = System::Drawing::Size(60, 24);
			this->menuToolStripMenuItem->Text = L"Menu";
			// 
			// importImageToolStripMenuItem
			// 
			this->importImageToolStripMenuItem->Name = L"importImageToolStripMenuItem";
			this->importImageToolStripMenuItem->Size = System::Drawing::Size(183, 26);
			this->importImageToolStripMenuItem->Text = L"Import image";
			this->importImageToolStripMenuItem->Click += gcnew System::EventHandler(this, &userGUI::importImageToolStripMenuItem_Click);
			// 
			// clearToolStripMenuItem
			// 
			this->clearToolStripMenuItem->Name = L"clearToolStripMenuItem";
			this->clearToolStripMenuItem->Size = System::Drawing::Size(183, 26);
			this->clearToolStripMenuItem->Text = L"Clear";
			this->clearToolStripMenuItem->Click += gcnew System::EventHandler(this, &userGUI::clearToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(183, 26);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &userGUI::exitToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"Jpeg|*.jpg|Bitmap|*.bmp|All files|*.*";
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Arial", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->radioButton1->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->radioButton1->Location = System::Drawing::Point(53, 550);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(127, 31);
			this->radioButton1->TabIndex = 19;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"low Blur";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &userGUI::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Arial", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->radioButton2->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->radioButton2->Location = System::Drawing::Point(290, 550);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(174, 31);
			this->radioButton2->TabIndex = 20;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"medium Blur";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &userGUI::radioButton2_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Font = (gcnew System::Drawing::Font(L"Arial", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->radioButton3->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->radioButton3->Location = System::Drawing::Point(520, 550);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(138, 31);
			this->radioButton3->TabIndex = 21;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"high Blur";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &userGUI::radioButton3_CheckedChanged);
			// 
			// userGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1281, 732);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->labelAssemblyTime);
			this->Controls->Add(this->labelCppTime);
			this->Controls->Add(this->timeComp);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->process);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->labelSetThreads);
			this->Controls->Add(this->labelSetAVG);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->menuStrip1);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximumSize = System::Drawing::Size(1299, 779);
			this->MinimumSize = System::Drawing::Size(1299, 779);
			this->Name = L"userGUI";
			this->Text = L"PhotoEditor - Blur ";
			this->Load += gcnew System::EventHandler(this, &userGUI::userGUI_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void userGUI_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void importImageToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (openFileDialog1->ShowDialog(nullptr) == System::Windows::Forms::DialogResult::OK) {
			try {
				bmpLoadedIMG = (Bitmap^)Image::FromFile(openFileDialog1->FileName);
				pictureBox1->Image = bmpLoadedIMG;
			}
			catch(...){
				MessageBox::Show("This file could not be open.");
			}
		}
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void clearToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		pictureBox1->Image = nullptr;
		labelCppTime->Text = "C++: ";
		labelAssemblyTime->Text = "Assembly x64: ";
	}
	private: System::Void process_Click(System::Object^ sender, System::EventArgs^ e) {
		//TODO main app logic here

		std::chrono::steady_clock::time_point cpp_time_start = std::chrono::high_resolution_clock::now();
		//TODO C++ dll
		for (int i = 0; i < 40000000; ++i) {

		}
		std::chrono::steady_clock::time_point cpp_time_end = std::chrono::high_resolution_clock::now();
		auto cpp_time = cpp_time_end - cpp_time_start;
		
		labelCppTime->Text = "C++: " + cpp_time / std::chrono::milliseconds(1) + " ms";
		

		std::chrono::steady_clock::time_point assembly_time_start = std::chrono::high_resolution_clock::now();
		//TODO assembly dll
		for (int i = 0; i < 50000000; ++i) {

		}
		std::chrono::steady_clock::time_point assembly_time_end = std::chrono::high_resolution_clock::now();
		auto assembly_time = assembly_time_end - assembly_time_start;
		labelAssemblyTime->Text = "Assembly x64: " + assembly_time / std::chrono::milliseconds(1) + " ms";
	}
	private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		this->blur_rate = 25;
	}
	private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		this->blur_rate = 75;
	}
	private: System::Void radioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		this->blur_rate = 150;
	}
};
}
