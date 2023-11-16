#pragma once

#include <chrono>
#include <string>
#include <vcclr.h>
#include <vector>
#include "cpp_lib.h"
#include "asm_lib.h"

namespace PhotoEditorBlurCPPASMx64 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Podsumowanie informacji o userGUI
	/// </summary>
	public ref class userGUI : public System::Windows::Forms::Form
	{
	public:

		Bitmap^ bmpLoadedIMG;

		int blur_rate, weight_one, weight_two, weight_three, weight_four, weight_five, weight_six, weight_seven,
			weight_eight, weight_nine;

		bool dll_lib_choice;

	private: System::Windows::Forms::ToolStripMenuItem^ setDLLBlurLibraryToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ assemblyX64ToolStripMenuItem;
	private: System::Windows::Forms::ProgressBar^ progressBar;
	public:
	private: System::Windows::Forms::ToolStripMenuItem^ cToolStripMenuItem;

	public:



	public:

	public:

		userGUI(void)
		{
			InitializeComponent();
			this->blur_rate = 10;
			this->weight_one = 1;
			this->weight_two = 1;
			this->weight_three = 1;
			this->weight_four = 1;
			this->weight_five = 1;
			this->weight_six = 1;
			this->weight_seven = 1;
			this->weight_eight = 1;
			this->weight_nine = 1;
			this->dll_lib_choice = true;
		}

	protected:		~userGUI()
		{

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
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
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
			this->setDLLBlurLibraryToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->assemblyX64ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->progressBar = (gcnew System::Windows::Forms::ProgressBar());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(144, 637);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(34, 22);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &userGUI::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(184, 637);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(34, 22);
			this->textBox2->TabIndex = 1;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &userGUI::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(224, 637);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(34, 22);
			this->textBox3->TabIndex = 2;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &userGUI::textBox3_TextChanged);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(144, 665);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(34, 22);
			this->textBox4->TabIndex = 3;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &userGUI::textBox4_TextChanged);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(184, 665);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(34, 22);
			this->textBox5->TabIndex = 4;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &userGUI::textBox5_TextChanged);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(224, 665);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(34, 22);
			this->textBox6->TabIndex = 5;
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &userGUI::textBox6_TextChanged);
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(224, 693);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(34, 22);
			this->textBox7->TabIndex = 8;
			this->textBox7->TextChanged += gcnew System::EventHandler(this, &userGUI::textBox7_TextChanged);
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(184, 693);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(34, 22);
			this->textBox8->TabIndex = 7;
			this->textBox8->TextChanged += gcnew System::EventHandler(this, &userGUI::textBox8_TextChanged);
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(144, 693);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(34, 22);
			this->textBox9->TabIndex = 6;
			this->textBox9->TextChanged += gcnew System::EventHandler(this, &userGUI::textBox9_TextChanged);
			// 
			// labelSetAVG
			// 
			this->labelSetAVG->AutoSize = true;
			this->labelSetAVG->Font = (gcnew System::Drawing::Font(L"Arial", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelSetAVG->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->labelSetAVG->Location = System::Drawing::Point(31, 601);
			this->labelSetAVG->Name = L"labelSetAVG";
			this->labelSetAVG->Size = System::Drawing::Size(351, 21);
			this->labelSetAVG->TabIndex = 9;
			this->labelSetAVG->Text = L"Set values of weighted pixel average  :";
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
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
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
			this->menuToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->importImageToolStripMenuItem,
					this->setDLLBlurLibraryToolStripMenuItem, this->clearToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->menuToolStripMenuItem->Name = L"menuToolStripMenuItem";
			this->menuToolStripMenuItem->Size = System::Drawing::Size(60, 24);
			this->menuToolStripMenuItem->Text = L"Menu";
			// 
			// importImageToolStripMenuItem
			// 
			this->importImageToolStripMenuItem->Name = L"importImageToolStripMenuItem";
			this->importImageToolStripMenuItem->Size = System::Drawing::Size(221, 26);
			this->importImageToolStripMenuItem->Text = L"Import image";
			this->importImageToolStripMenuItem->Click += gcnew System::EventHandler(this, &userGUI::importImageToolStripMenuItem_Click);
			// 
			// setDLLBlurLibraryToolStripMenuItem
			// 
			this->setDLLBlurLibraryToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->cToolStripMenuItem,
					this->assemblyX64ToolStripMenuItem
			});
			this->setDLLBlurLibraryToolStripMenuItem->Name = L"setDLLBlurLibraryToolStripMenuItem";
			this->setDLLBlurLibraryToolStripMenuItem->Size = System::Drawing::Size(221, 26);
			this->setDLLBlurLibraryToolStripMenuItem->Text = L"Set DLL Blur Library";
			this->setDLLBlurLibraryToolStripMenuItem->Click += gcnew System::EventHandler(this, &userGUI::setDLLBlurLibraryToolStripMenuItem_Click);
			// 
			// cToolStripMenuItem
			// 
			this->cToolStripMenuItem->Name = L"cToolStripMenuItem";
			this->cToolStripMenuItem->Size = System::Drawing::Size(182, 26);
			this->cToolStripMenuItem->Text = L"C++";
			this->cToolStripMenuItem->Click += gcnew System::EventHandler(this, &userGUI::cToolStripMenuItem_Click);
			// 
			// assemblyX64ToolStripMenuItem
			// 
			this->assemblyX64ToolStripMenuItem->Name = L"assemblyX64ToolStripMenuItem";
			this->assemblyX64ToolStripMenuItem->Size = System::Drawing::Size(182, 26);
			this->assemblyX64ToolStripMenuItem->Text = L"Assembly x64";
			this->assemblyX64ToolStripMenuItem->Click += gcnew System::EventHandler(this, &userGUI::assemblyX64ToolStripMenuItem_Click);
			// 
			// clearToolStripMenuItem
			// 
			this->clearToolStripMenuItem->Name = L"clearToolStripMenuItem";
			this->clearToolStripMenuItem->Size = System::Drawing::Size(221, 26);
			this->clearToolStripMenuItem->Text = L"Clear";
			this->clearToolStripMenuItem->Click += gcnew System::EventHandler(this, &userGUI::clearToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(221, 26);
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
			this->radioButton1->Checked = true;
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
			this->radioButton3->Text = L"high Blur";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &userGUI::radioButton3_CheckedChanged);
			// 
			// progressBar
			// 
			this->progressBar->Location = System::Drawing::Point(423, 240);
			this->progressBar->Name = L"progressBar";
			this->progressBar->Size = System::Drawing::Size(438, 86);
			this->progressBar->Step = 1;
			this->progressBar->TabIndex = 22;
			this->progressBar->Visible = false;
			// 
			// userGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1281, 732);
			this->Controls->Add(this->progressBar);
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
			this->KeyPreview = true;
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
		pictureBox1->Image = this->bmpLoadedIMG;
		labelCppTime->Text = "C++: ";
		labelAssemblyTime->Text = "Assembly x64: ";
	}
	private: void cpp_blur_algorithm() {
		Bitmap^ bmpCopyProcessedIMG = dynamic_cast<Bitmap^>(this->bmpLoadedIMG->Clone());
		// Uzyskaj dane obiektu BitmapData do modyfikacji pikseli
		Rectangle rect = Rectangle(0, 0, bmpCopyProcessedIMG->Width, bmpCopyProcessedIMG->Height);
		System::Drawing::Imaging::BitmapData^ bmpData = bmpCopyProcessedIMG->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, bmpCopyProcessedIMG->PixelFormat);

		IntPtr ptr = IntPtr(bmpData->Scan0.ToPointer());
		List<IntPtr>^ avg_matrix = gcnew List<IntPtr>(9);
		for (int i = 0; i < 9; ++i) {
			avg_matrix->Add(ptr);
		}

		for (int i = 0; i < this->blur_rate; ++i) {
			for (int y = 1; y < bmpData->Height - 1; y++)
			{
				for (int x = 1; x < bmpData->Width - 1; x++)
				{
					//Wype³nienie macierzy pikseli do obliczenia œredniej
					avg_matrix[0] = IntPtr(ptr.ToInt64() + (y - 1) * bmpData->Stride + (x - 1) * 3);
					avg_matrix[1] = IntPtr(ptr.ToInt64() + (y - 1) * bmpData->Stride + x * 3);
					avg_matrix[2] = IntPtr(ptr.ToInt64() + (y - 1) * bmpData->Stride + (x + 1) * 3);
					avg_matrix[3] = IntPtr(ptr.ToInt64() + y * bmpData->Stride + (x - 1) * 3);
					avg_matrix[4] = IntPtr(ptr.ToInt64() + y * bmpData->Stride + x * 3);// Center
					avg_matrix[5] = IntPtr(ptr.ToInt64() + y * bmpData->Stride + (x + 1) * 3);
					avg_matrix[6] = IntPtr(ptr.ToInt64() + (y + 1) * bmpData->Stride + (x - 1) * 3);
					avg_matrix[7] = IntPtr(ptr.ToInt64() + (y + 1) * bmpData->Stride + x * 3);
					avg_matrix[8] = IntPtr(ptr.ToInt64() + (y + 1) * bmpData->Stride + (x + 1) * 3);

					// Modyfikacja wartoœci piksela
					Byte* pixel1 = reinterpret_cast<Byte*>(avg_matrix[0].ToPointer());
					Byte* pixel2 = reinterpret_cast<Byte*>(avg_matrix[1].ToPointer());
					Byte* pixel3 = reinterpret_cast<Byte*>(avg_matrix[2].ToPointer());
					Byte* pixel4 = reinterpret_cast<Byte*>(avg_matrix[3].ToPointer());
					Byte* pixel5 = reinterpret_cast<Byte*>(avg_matrix[4].ToPointer());//Center
					Byte* pixel6 = reinterpret_cast<Byte*>(avg_matrix[5].ToPointer());
					Byte* pixel7 = reinterpret_cast<Byte*>(avg_matrix[6].ToPointer());
					Byte* pixel8 = reinterpret_cast<Byte*>(avg_matrix[7].ToPointer());
					Byte* pixel9 = reinterpret_cast<Byte*>(avg_matrix[8].ToPointer());

					pixel5[0] = wavg_calc_cpp(pixel1[0], pixel2[0], pixel3[0], pixel4[0], pixel5[0],
						pixel6[0], pixel7[0], pixel8[0], pixel9[0], this->weight_one,
						this->weight_two, this->weight_three, this->weight_four,
						this->weight_five, this->weight_six, this->weight_seven,
						this->weight_eight, this->weight_nine);
					pixel5[1] = wavg_calc_cpp(pixel1[1], pixel2[1], pixel3[1], pixel4[1], pixel5[1],
						pixel6[1], pixel7[1], pixel8[1], pixel9[1], this->weight_one,
						this->weight_two, this->weight_three, this->weight_four,
						this->weight_five, this->weight_six, this->weight_seven,
						this->weight_eight, this->weight_nine);
					pixel5[2] = wavg_calc_cpp(pixel1[2], pixel2[2], pixel3[2], pixel4[2], pixel5[2],
						pixel6[2], pixel7[2], pixel8[2], pixel9[2], this->weight_one,
						this->weight_two, this->weight_three, this->weight_four,
						this->weight_five, this->weight_six, this->weight_seven,
						this->weight_eight, this->weight_nine);
				}
			}
			this->progressBar->Value = i;
		}
		// Odblokuj obiekt BitmapData po modyfikacji
		bmpCopyProcessedIMG->UnlockBits(bmpData);
		//Zapis wyniku i wyœwietlenie
		this->pictureBox1->Image = bmpCopyProcessedIMG;
	}
	private: void assembly_blur_algorithm() {
		Bitmap^ bmpCopyProcessedIMG = dynamic_cast<Bitmap^>(this->bmpLoadedIMG->Clone());
		// Uzyskaj dane obiektu BitmapData do modyfikacji pikseli
		Rectangle rect = Rectangle(0, 0, bmpCopyProcessedIMG->Width, bmpCopyProcessedIMG->Height);
		System::Drawing::Imaging::BitmapData^ bmpData = bmpCopyProcessedIMG->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, bmpCopyProcessedIMG->PixelFormat);

		IntPtr ptr = IntPtr(bmpData->Scan0.ToPointer());
		List<IntPtr>^ avg_matrix = gcnew List<IntPtr>(9);
		for (int i = 0; i < 9; ++i) {
			avg_matrix->Add(ptr);
		}

		for (int i = 0; i < this->blur_rate; ++i) {
			for (int y = 1; y < bmpData->Height - 1; y++)
			{
				for (int x = 1; x < bmpData->Width - 1; x++)
				{
					//Wype³nienie macierzy pikseli do obliczenia œredniej
					avg_matrix[0] = IntPtr(ptr.ToInt64() + (y - 1) * bmpData->Stride + (x - 1) * 3);
					avg_matrix[1] = IntPtr(ptr.ToInt64() + (y - 1) * bmpData->Stride + x * 3);
					avg_matrix[2] = IntPtr(ptr.ToInt64() + (y - 1) * bmpData->Stride + (x + 1) * 3);
					avg_matrix[3] = IntPtr(ptr.ToInt64() + y * bmpData->Stride + (x - 1) * 3);
					avg_matrix[4] = IntPtr(ptr.ToInt64() + y * bmpData->Stride + x * 3);// Center
					avg_matrix[5] = IntPtr(ptr.ToInt64() + y * bmpData->Stride + (x + 1) * 3);
					avg_matrix[6] = IntPtr(ptr.ToInt64() + (y + 1) * bmpData->Stride + (x - 1) * 3);
					avg_matrix[7] = IntPtr(ptr.ToInt64() + (y + 1) * bmpData->Stride + x * 3);
					avg_matrix[8] = IntPtr(ptr.ToInt64() + (y + 1) * bmpData->Stride + (x + 1) * 3);

					// Modyfikacja wartoœci piksela
					Byte* pixel1 = reinterpret_cast<Byte*>(avg_matrix[0].ToPointer());
					Byte* pixel2 = reinterpret_cast<Byte*>(avg_matrix[1].ToPointer());
					Byte* pixel3 = reinterpret_cast<Byte*>(avg_matrix[2].ToPointer());
					Byte* pixel4 = reinterpret_cast<Byte*>(avg_matrix[3].ToPointer());
					Byte* pixel5 = reinterpret_cast<Byte*>(avg_matrix[4].ToPointer());//Center
					Byte* pixel6 = reinterpret_cast<Byte*>(avg_matrix[5].ToPointer());
					Byte* pixel7 = reinterpret_cast<Byte*>(avg_matrix[6].ToPointer());
					Byte* pixel8 = reinterpret_cast<Byte*>(avg_matrix[7].ToPointer());
					Byte* pixel9 = reinterpret_cast<Byte*>(avg_matrix[8].ToPointer());

					pixel5[0] = wavg_calc_asm(pixel1[0], pixel2[0], pixel3[0], pixel4[0], pixel5[0],
						pixel6[0], pixel7[0], pixel8[0], pixel9[0], this->weight_one,
						this->weight_two, this->weight_three, this->weight_four,
						this->weight_five, this->weight_six, this->weight_seven,
						this->weight_eight, this->weight_nine);
					pixel5[1] = wavg_calc_asm(pixel1[1], pixel2[1], pixel3[1], pixel4[1], pixel5[1],
						pixel6[1], pixel7[1], pixel8[1], pixel9[1], this->weight_one,
						this->weight_two, this->weight_three, this->weight_four,
						this->weight_five, this->weight_six, this->weight_seven,
						this->weight_eight, this->weight_nine);
					pixel5[2] = wavg_calc_asm(pixel1[2], pixel2[2], pixel3[2], pixel4[2], pixel5[2],
						pixel6[2], pixel7[2], pixel8[2], pixel9[2], this->weight_one,
						this->weight_two, this->weight_three, this->weight_four,
						this->weight_five, this->weight_six, this->weight_seven,
						this->weight_eight, this->weight_nine);
				}
			}
			this->progressBar->Value = i;
		}
		// Odblokuj obiekt BitmapData po modyfikacji
		bmpCopyProcessedIMG->UnlockBits(bmpData);
		//Zapis wyniku i wyœwietlenie
		this->pictureBox1->Image = bmpCopyProcessedIMG;
	}
	private: System::Void process_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->bmpLoadedIMG == nullptr) {
			return;
		}
		this->progressBar->Visible = true;
		//TODO main app logic here
		if (this->dll_lib_choice) {
			std::chrono::steady_clock::time_point cpp_time_start = std::chrono::high_resolution_clock::now();
			//TODO C++ dll
			cpp_blur_algorithm();

			std::chrono::steady_clock::time_point cpp_time_end = std::chrono::high_resolution_clock::now();
			auto cpp_time = cpp_time_end - cpp_time_start;

			labelCppTime->Text = "C++: " + cpp_time / std::chrono::milliseconds(1) + " ms";
		}
		else {
			std::chrono::steady_clock::time_point assembly_time_start = std::chrono::high_resolution_clock::now();
			//TODO assembly dll
			assembly_blur_algorithm();

			std::chrono::steady_clock::time_point assembly_time_end = std::chrono::high_resolution_clock::now();
			auto assembly_time = assembly_time_end - assembly_time_start;
			labelAssemblyTime->Text = "Assembly x64: " + assembly_time / std::chrono::milliseconds(1) + " ms";
		}
		this->progressBar->Visible = false;
		this->progressBar->Value = 0;
	}
	private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		this->blur_rate = 10;
		this->progressBar->Maximum = 10;
	}
	private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		this->blur_rate = 25;
		this->progressBar->Maximum = 25;
	}
	private: System::Void radioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		this->blur_rate = 50;
		this->progressBar->Maximum = 50;
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (!Int32::TryParse(dynamic_cast<TextBox^>(sender)->Text, this->weight_one)) {
			this->weight_one = 1;
		}
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (!Int32::TryParse(dynamic_cast<TextBox^>(sender)->Text, this->weight_two)) {
			this->weight_two = 1;
		}
	}
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (!Int32::TryParse(dynamic_cast<TextBox^>(sender)->Text, this->weight_three)) {
			this->weight_three = 1;
		}
	}
	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (!Int32::TryParse(dynamic_cast<TextBox^>(sender)->Text, this->weight_four)) {
			this->weight_four = 1;
		}
	}
	private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (!Int32::TryParse(dynamic_cast<TextBox^>(sender)->Text, this->weight_five)) {
			this->weight_five = 1;
		}
	}
	private: System::Void textBox6_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (!Int32::TryParse(dynamic_cast<TextBox^>(sender)->Text, this->weight_six)) {
			this->weight_six = 1;
		}
	}
	private: System::Void textBox9_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (!Int32::TryParse(dynamic_cast<TextBox^>(sender)->Text, this->weight_seven)) {
			this->weight_seven = 1;
		}
	}
	private: System::Void textBox8_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (!Int32::TryParse(dynamic_cast<TextBox^>(sender)->Text, this->weight_eight)) {
			this->weight_eight = 1;
		}
	}
	private: System::Void textBox7_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (!Int32::TryParse(dynamic_cast<TextBox^>(sender)->Text, this->weight_nine)) {
			this->weight_nine = 1;
		}
	}
	private: System::Void setDLLBlurLibraryToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void cToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		this->dll_lib_choice = true;
	}
	private: System::Void assemblyX64ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		this->dll_lib_choice = false;
	}
};
}
