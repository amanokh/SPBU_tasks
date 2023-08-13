#pragma once

namespace Painter {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^ instrumentPanel;

	private: System::Windows::Forms::Button^ clearButton;
	private: System::Windows::Forms::Button^ squareButton;
	private: System::Windows::Forms::Button^ circleButton;
	private: System::Windows::Forms::PictureBox^ paintBox;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  loadBtn;

	private: System::Windows::Forms::ToolStripMenuItem^  saveBtn;

	private: System::Windows::Forms::ToolStripMenuItem^  about;
	private: System::Windows::Forms::Button^  red;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::PictureBox^  palette;
	private: System::Windows::Forms::Button^  picker;





	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->instrumentPanel = (gcnew System::Windows::Forms::Panel());
			this->picker = (gcnew System::Windows::Forms::Button());
			this->palette = (gcnew System::Windows::Forms::PictureBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->red = (gcnew System::Windows::Forms::Button());
			this->clearButton = (gcnew System::Windows::Forms::Button());
			this->squareButton = (gcnew System::Windows::Forms::Button());
			this->circleButton = (gcnew System::Windows::Forms::Button());
			this->paintBox = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->loadBtn = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveBtn = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->about = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->instrumentPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->palette))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->paintBox))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// instrumentPanel
			// 
			this->instrumentPanel->BackColor = System::Drawing::Color::WhiteSmoke;
			this->instrumentPanel->Controls->Add(this->picker);
			this->instrumentPanel->Controls->Add(this->palette);
			this->instrumentPanel->Controls->Add(this->button7);
			this->instrumentPanel->Controls->Add(this->button6);
			this->instrumentPanel->Controls->Add(this->button5);
			this->instrumentPanel->Controls->Add(this->button4);
			this->instrumentPanel->Controls->Add(this->button3);
			this->instrumentPanel->Controls->Add(this->button2);
			this->instrumentPanel->Controls->Add(this->button1);
			this->instrumentPanel->Controls->Add(this->red);
			this->instrumentPanel->Controls->Add(this->clearButton);
			this->instrumentPanel->Controls->Add(this->squareButton);
			this->instrumentPanel->Controls->Add(this->circleButton);
			this->instrumentPanel->Dock = System::Windows::Forms::DockStyle::Left;
			this->instrumentPanel->Location = System::Drawing::Point(0, 24);
			this->instrumentPanel->Name = L"instrumentPanel";
			this->instrumentPanel->Size = System::Drawing::Size(173, 587);
			this->instrumentPanel->TabIndex = 0;
			// 
			// picker
			// 
			this->picker->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"picker.Image")));
			this->picker->Location = System::Drawing::Point(124, 219);
			this->picker->Name = L"picker";
			this->picker->Size = System::Drawing::Size(36, 39);
			this->picker->TabIndex = 16;
			this->picker->TabStop = false;
			this->picker->UseVisualStyleBackColor = true;
			this->picker->Click += gcnew System::EventHandler(this, &MainForm::button8_Click);
			// 
			// palette
			// 
			this->palette->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"palette.Image")));
			this->palette->Location = System::Drawing::Point(15, 284);
			this->palette->Margin = System::Windows::Forms::Padding(2);
			this->palette->Name = L"palette";
			this->palette->Size = System::Drawing::Size(145, 156);
			this->palette->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->palette->TabIndex = 15;
			this->palette->TabStop = false;
			this->palette->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox1_Click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::White;
			this->button7->Location = System::Drawing::Point(57, 219);
			this->button7->Margin = System::Windows::Forms::Padding(2);
			this->button7->Name = L"white";
			this->button7->Size = System::Drawing::Size(36, 39);
			this->button7->TabIndex = 14;
			this->button7->TabStop = false;
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &MainForm::color_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::Black;
			this->button6->Location = System::Drawing::Point(15, 219);
			this->button6->Margin = System::Windows::Forms::Padding(2);
			this->button6->Name = L"black";
			this->button6->Size = System::Drawing::Size(36, 39);
			this->button6->TabIndex = 13;
			this->button6->TabStop = false;
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &MainForm::color_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::Violet;
			this->button5->Location = System::Drawing::Point(57, 176);
			this->button5->Margin = System::Windows::Forms::Padding(2);
			this->button5->Name = L"violet";
			this->button5->Size = System::Drawing::Size(36, 39);
			this->button5->TabIndex = 12;
			this->button5->TabStop = false;
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MainForm::color_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Blue;
			this->button4->Location = System::Drawing::Point(15, 176);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"blue";
			this->button4->Size = System::Drawing::Size(36, 39);
			this->button4->TabIndex = 11;
			this->button4->TabStop = false;
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MainForm::color_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Green;
			this->button3->Location = System::Drawing::Point(57, 132);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"green";
			this->button3->Size = System::Drawing::Size(36, 39);
			this->button3->TabIndex = 10;
			this->button3->TabStop = false;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::color_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Yellow;
			this->button2->Location = System::Drawing::Point(15, 132);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"yellow";
			this->button2->Size = System::Drawing::Size(36, 39);
			this->button2->TabIndex = 9;
			this->button2->TabStop = false;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::color_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::DarkOrange;
			this->button1->Location = System::Drawing::Point(57, 88);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"orange";
			this->button1->Size = System::Drawing::Size(36, 39);
			this->button1->TabIndex = 8;
			this->button1->TabStop = false;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::color_Click);
			// 
			// red
			// 
			this->red->BackColor = System::Drawing::Color::Red;
			this->red->Location = System::Drawing::Point(15, 88);
			this->red->Margin = System::Windows::Forms::Padding(2);
			this->red->Name = L"red";
			this->red->Size = System::Drawing::Size(36, 39);
			this->red->TabIndex = 7;
			this->red->TabStop = false;
			this->red->UseVisualStyleBackColor = false;
			this->red->Click += gcnew System::EventHandler(this, &MainForm::color_Click);
			// 
			// clearButton
			// 
			this->clearButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->clearButton->ForeColor = System::Drawing::Color::Black;
			this->clearButton->Location = System::Drawing::Point(0, 557);
			this->clearButton->Name = L"clearButton";
			this->clearButton->Size = System::Drawing::Size(106, 30);
			this->clearButton->TabIndex = 6;
			this->clearButton->Text = L"Clear";
			this->clearButton->UseVisualStyleBackColor = true;
			this->clearButton->Click += gcnew System::EventHandler(this, &MainForm::clearButton_Click);
			// 
			// squareButton
			// 
			this->squareButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"squareButton.Image")));
			this->squareButton->Location = System::Drawing::Point(57, 15);
			this->squareButton->Name = L"squareButton";
			this->squareButton->Size = System::Drawing::Size(36, 39);
			this->squareButton->TabIndex = 5;
			this->squareButton->TabStop = false;
			this->squareButton->UseVisualStyleBackColor = true;
			this->squareButton->Click += gcnew System::EventHandler(this, &MainForm::squareButton_Click);
			// 
			// circleButton
			// 
			this->circleButton->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->circleButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"circleButton.Image")));
			this->circleButton->Location = System::Drawing::Point(15, 15);
			this->circleButton->Name = L"circleButton";
			this->circleButton->Size = System::Drawing::Size(36, 39);
			this->circleButton->TabIndex = 4;
			this->circleButton->TabStop = false;
			this->circleButton->UseVisualStyleBackColor = true;
			this->circleButton->Click += gcnew System::EventHandler(this, &MainForm::circleButton_Click);
			// 
			// paintBox
			// 
			this->paintBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->paintBox->Location = System::Drawing::Point(173, 24);
			this->paintBox->Name = L"paintBox";
			this->paintBox->Size = System::Drawing::Size(790, 587);
			this->paintBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->paintBox->TabIndex = 1;
			this->paintBox->TabStop = false;
			this->paintBox->SizeChanged += gcnew System::EventHandler(this, &MainForm::paintBox_SizeChanged);
			this->paintBox->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::paintBox_Paint);
			this->paintBox->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::paintBox_MouseDown);
			this->paintBox->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::paintBox_MouseMove);
			this->paintBox->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::paintBox_MouseUp);
			this->paintBox->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::paintBox_MouseWheel);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->loadBtn, this->saveBtn, 
				this->about});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(963, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// loadBtn
			// 
			this->loadBtn->Name = L"loadBtn";
			this->loadBtn->Size = System::Drawing::Size(48, 20);
			this->loadBtn->Text = L"Open";
			this->loadBtn->Click += gcnew System::EventHandler(this, &MainForm::loadBtn_click);
			// 
			// saveBtn
			// 
			this->saveBtn->Name = L"saveBtn";
			this->saveBtn->Size = System::Drawing::Size(43, 20);
			this->saveBtn->Text = L"Save";
			this->saveBtn->Click += gcnew System::EventHandler(this, &MainForm::saveBtn_click);
			// 
			// about
			// 
			this->about->Name = L"about";
			this->about->Size = System::Drawing::Size(44, 20);
			this->about->Text = L"Help";
			this->about->Click += gcnew System::EventHandler(this, &MainForm::aboutBtn_click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(963, 611);
			this->Controls->Add(this->paintBox);
			this->Controls->Add(this->instrumentPanel);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Painter";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->instrumentPanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->palette))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->paintBox))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: Graphics^ layerGraphics;
	private: Bitmap^ background;
	private: Pen^ brush, ^erase;
	private: Color brushColor;
	private: Point point1, point2;
	private: Point subPoint1, subPoint2;
	private: System::Drawing::Size^ initialSize1;

	private: int brushSize, brushMode;
	private: bool isDraw, isPicker;
	private: double scale_x, scale_y;

	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void saveBtn_click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void paintBox_MouseWheel(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e); 
	private: System::Void paintBox_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void paintBox_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void paintBox_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void paintBox_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);
	private: System::Void circleButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void squareButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void clearButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void paintBox_SizeChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void loadBtn_click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void aboutBtn_click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void color_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void pictureBox1_Click(System::Object^  sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e);
};
}
