#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected: 
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;

	private: System::Windows::Forms::Label^  label2;

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Label^  xLabel;
	private: System::Windows::Forms::TextBox^  xInput;


	private: System::Windows::Forms::Label^  fLabel;
	private: System::Windows::Forms::Label^  fOutput;


	private: System::Windows::Forms::Label^  errorText;
	private: System::Windows::Forms::TextBox^  xRight;
	private: System::Windows::Forms::TextBox^  xLeft;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  errorText1;
	private: System::Windows::Forms::PictureBox^ graphBox;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->errorText = (gcnew System::Windows::Forms::Label());
			this->fOutput = (gcnew System::Windows::Forms::Label());
			this->fLabel = (gcnew System::Windows::Forms::Label());
			this->xInput = (gcnew System::Windows::Forms::TextBox());
			this->xLabel = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->errorText1 = (gcnew System::Windows::Forms::Label());
			this->xRight = (gcnew System::Windows::Forms::TextBox());
			this->xLeft = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->graphBox = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->graphBox))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(860, 402);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->errorText);
			this->tabPage1->Controls->Add(this->fOutput);
			this->tabPage1->Controls->Add(this->fLabel);
			this->tabPage1->Controls->Add(this->xInput);
			this->tabPage1->Controls->Add(this->xLabel);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(852, 364);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Значение функции";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// errorText
			// 
			this->errorText->AutoSize = true;
			this->errorText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->errorText->ForeColor = System::Drawing::Color::Brown;
			this->errorText->Location = System::Drawing::Point(10, 93);
			this->errorText->Name = L"errorText";
			this->errorText->Size = System::Drawing::Size(723, 20);
			this->errorText->TabIndex = 4;
			this->errorText->Text = L"Неверный формат. Введите число с дробной частью через запятую, например: 1,48";
			this->errorText->Visible = false;
			// 
			// fOutput
			// 
			this->fOutput->AutoSize = true;
			this->fOutput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->fOutput->Location = System::Drawing::Point(148, 48);
			this->fOutput->Name = L"fOutput";
			this->fOutput->Size = System::Drawing::Size(0, 29);
			this->fOutput->TabIndex = 3;
			// 
			// fLabel
			// 
			this->fLabel->AutoSize = true;
			this->fLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->fLabel->Location = System::Drawing::Point(9, 48);
			this->fLabel->Name = L"fLabel";
			this->fLabel->Size = System::Drawing::Size(140, 29);
			this->fLabel->TabIndex = 2;
			this->fLabel->Text = L"sin(x) = ";
			// 
			// xInput
			// 
			this->xInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->xInput->Location = System::Drawing::Point(56, 7);
			this->xInput->Name = L"xInput";
			this->xInput->Size = System::Drawing::Size(100, 30);
			this->xInput->TabIndex = 1;
			this->xInput->TextChanged += gcnew System::EventHandler(this, &MyForm::xInput_TextChanged);
			// 
			// xLabel
			// 
			this->xLabel->AutoSize = true;
			this->xLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->xLabel->Location = System::Drawing::Point(9, 7);
			this->xLabel->Name = L"xLabel";
			this->xLabel->Size = System::Drawing::Size(50, 29);
			this->xLabel->TabIndex = 0;
			this->xLabel->Text = L"x = ";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->errorText1);
			this->tabPage2->Controls->Add(this->xRight);
			this->tabPage2->Controls->Add(this->xLeft);
			this->tabPage2->Controls->Add(this->label3);
			this->tabPage2->Controls->Add(this->label1);
			this->tabPage2->Controls->Add(this->graphBox);
			this->tabPage2->Controls->Add(this->label2);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(852, 373);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"График функции";
			this->tabPage2->UseVisualStyleBackColor = true;

			// 
			// errorText1
			// 
			this->errorText1->AutoSize = true;
			this->errorText1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->errorText1->ForeColor = System::Drawing::Color::Brown;
			this->errorText1->Location = System::Drawing::Point(285, 328);
			this->errorText1->Name = L"errorText1";
			this->errorText1->Size = System::Drawing::Size(395, 40);
			this->errorText1->TabIndex = 5;
			this->errorText1->Text = L"Неверный формат. Введите число с дробной\r\nчастью через запятую, например: 1,48";
			this->errorText1->Visible = false;
			// 
			// xRight
			// 
			this->xRight->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->xRight->Location = System::Drawing::Point(163, 333);
			this->xRight->Name = L"xRight";
			this->xRight->Size = System::Drawing::Size(100, 26);
			this->xRight->TabIndex = 4;
			this->xRight->Text = L"10";
			this->xRight->TextChanged += gcnew System::EventHandler(this, &MyForm::xRight_TextChanged);
			// 
			// xLeft
			// 
			this->xLeft->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->xLeft->Location = System::Drawing::Point(53, 333);
			this->xLeft->Name = L"xLeft";
			this->xLeft->Size = System::Drawing::Size(100, 26);
			this->xLeft->TabIndex = 3;
			this->xLeft->Text = L"-10";
			this->xLeft->TextChanged += gcnew System::EventHandler(this, &MyForm::xLeft_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label3->Location = System::Drawing::Point(261, 332);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(18, 25);
			this->label3->TabIndex = 2;
			this->label3->Text = L"]";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label1->Location = System::Drawing::Point(150, 334);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(18, 25);
			this->label1->TabIndex = 1;
			this->label1->Text = L";";
			// 
			// graphBox
			// 
			this->graphBox->BackColor = System::Drawing::Color::White;
			this->graphBox->Dock = System::Windows::Forms::DockStyle::Top;
			this->graphBox->Location = System::Drawing::Point(3, 3);
			this->graphBox->Name = L"graphBox";
			this->graphBox->Size = System::Drawing::Size(846, 316);
			this->graphBox->TabIndex = 0;
			this->graphBox->TabStop = false;
			this->graphBox->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::graphBox_Paint);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label2->Location = System::Drawing::Point(6, 332);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 25);
			this->label2->TabIndex = 0;
			this->label2->Text = L"x = [";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(860, 402);
			this->Controls->Add(this->tabControl1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->graphBox))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: double x, f;
	private: Pen^ pen, ^cPen;

	private: System::Void xInput_TextChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Project1::MyForm::boundsChanged();

	private: float xLeftDouble, xRightDouble;

	private: System::Void xLeft_TextChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void xRight_TextChanged(System::Object^  sender, System::EventArgs^  e);

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e);

	private: System::Void drawFunc(System::Drawing::Graphics^ g); 
	private: System::Void graphBox_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);
};
}
