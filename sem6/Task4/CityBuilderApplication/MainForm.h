#pragma once

#include "Texture.h"
#include "Data.h"

namespace CityBuilderApplication {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	
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
	private: System::Windows::Forms::Panel^ toolPanel;

	private: System::Windows::Forms::Button^ textureButton3;
	private: System::Windows::Forms::Button^ textureButton2;
	private: System::Windows::Forms::Button^ textureButton1;
	private: System::Windows::Forms::PictureBox^ pictureBox;
	private: System::Windows::Forms::Button^ surfaceButton2;
	private: System::Windows::Forms::Button^ surfaceButton1;
	private: System::Windows::Forms::Button^ textureButton5;
	private: System::Windows::Forms::Button^ textureButton4;
	private: System::Windows::Forms::Button^ undoButton1;
	private: System::Windows::Forms::Button^ clearButton1;
	private: System::Windows::Forms::Button^ surfaceButton3;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->toolPanel = (gcnew System::Windows::Forms::Panel());
			this->surfaceButton3 = (gcnew System::Windows::Forms::Button());
			this->undoButton1 = (gcnew System::Windows::Forms::Button());
			this->clearButton1 = (gcnew System::Windows::Forms::Button());
			this->surfaceButton2 = (gcnew System::Windows::Forms::Button());
			this->surfaceButton1 = (gcnew System::Windows::Forms::Button());
			this->textureButton5 = (gcnew System::Windows::Forms::Button());
			this->textureButton4 = (gcnew System::Windows::Forms::Button());
			this->textureButton3 = (gcnew System::Windows::Forms::Button());
			this->textureButton2 = (gcnew System::Windows::Forms::Button());
			this->textureButton1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// toolPanel
			// 
			this->toolPanel->BackColor = System::Drawing::Color::WhiteSmoke;
			this->toolPanel->Controls->Add(this->surfaceButton3);
			this->toolPanel->Controls->Add(this->undoButton1);
			this->toolPanel->Controls->Add(this->clearButton1);
			this->toolPanel->Controls->Add(this->surfaceButton2);
			this->toolPanel->Controls->Add(this->surfaceButton1);
			this->toolPanel->Controls->Add(this->textureButton5);
			this->toolPanel->Controls->Add(this->textureButton4);
			this->toolPanel->Controls->Add(this->textureButton3);
			this->toolPanel->Controls->Add(this->textureButton2);
			this->toolPanel->Controls->Add(this->textureButton1);
			this->toolPanel->Dock = System::Windows::Forms::DockStyle::Right;
			this->toolPanel->Location = System::Drawing::Point(834, 24);
			this->toolPanel->Name = L"toolPanel";
			this->toolPanel->Size = System::Drawing::Size(150, 537);
			this->toolPanel->TabIndex = 0;
			// 
			// surfaceButton3
			// 
			this->surfaceButton3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"surfaceButton3.BackgroundImage")));
			this->surfaceButton3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->surfaceButton3->Location = System::Drawing::Point(6, 307);
			this->surfaceButton3->Name = L"surfaceButton3";
			this->surfaceButton3->Size = System::Drawing::Size(40, 42);
			this->surfaceButton3->TabIndex = 10;
			// 
			// undoButton1
			// 
			this->undoButton1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"undoButton1.BackgroundImage")));
			this->undoButton1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->undoButton1->Location = System::Drawing::Point(77, 440);
			this->undoButton1->Name = L"undoButton1";
			this->undoButton1->Size = System::Drawing::Size(70, 70);
			this->undoButton1->TabIndex = 9;
			// 
			// clearButton1
			// 
			this->clearButton1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"clearButton1.BackgroundImage")));
			this->clearButton1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->clearButton1->Location = System::Drawing::Point(3, 440);
			this->clearButton1->Name = L"clearButton1";
			this->clearButton1->Size = System::Drawing::Size(70, 70);
			this->clearButton1->TabIndex = 8;
			// 
			// surfaceButton2
			// 
			this->surfaceButton2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"surfaceButton2.BackgroundImage")));
			this->surfaceButton2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->surfaceButton2->Location = System::Drawing::Point(97, 307);
			this->surfaceButton2->Name = L"surfaceButton2";
			this->surfaceButton2->Size = System::Drawing::Size(41, 42);
			this->surfaceButton2->TabIndex = 7;
			// 
			// surfaceButton1
			// 
			this->surfaceButton1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"surfaceButton1.BackgroundImage")));
			this->surfaceButton1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->surfaceButton1->Location = System::Drawing::Point(52, 307);
			this->surfaceButton1->Name = L"surfaceButton1";
			this->surfaceButton1->Size = System::Drawing::Size(39, 42);
			this->surfaceButton1->TabIndex = 6;
			// 
			// textureButton5
			// 
			this->textureButton5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"textureButton5.BackgroundImage")));
			this->textureButton5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->textureButton5->Location = System::Drawing::Point(77, 196);
			this->textureButton5->Name = L"textureButton5";
			this->textureButton5->Size = System::Drawing::Size(70, 70);
			this->textureButton5->TabIndex = 5;
			// 
			// textureButton4
			// 
			this->textureButton4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"textureButton4.BackgroundImage")));
			this->textureButton4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->textureButton4->Location = System::Drawing::Point(3, 196);
			this->textureButton4->Name = L"textureButton4";
			this->textureButton4->Size = System::Drawing::Size(70, 70);
			this->textureButton4->TabIndex = 4;
			// 
			// textureButton3
			// 
			this->textureButton3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"textureButton3.BackgroundImage")));
			this->textureButton3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->textureButton3->Location = System::Drawing::Point(3, 79);
			this->textureButton3->Name = L"textureButton3";
			this->textureButton3->Size = System::Drawing::Size(70, 70);
			this->textureButton3->TabIndex = 3;
			// 
			// textureButton2
			// 
			this->textureButton2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"textureButton2.BackgroundImage")));
			this->textureButton2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->textureButton2->Location = System::Drawing::Point(77, 3);
			this->textureButton2->Name = L"textureButton2";
			this->textureButton2->Size = System::Drawing::Size(70, 70);
			this->textureButton2->TabIndex = 3;
			// 
			// textureButton1
			// 
			this->textureButton1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"textureButton1.BackgroundImage")));
			this->textureButton1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->textureButton1->Location = System::Drawing::Point(3, 3);
			this->textureButton1->Name = L"textureButton1";
			this->textureButton1->Size = System::Drawing::Size(70, 70);
			this->textureButton1->TabIndex = 2;
			// 
			// pictureBox
			// 
			this->pictureBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox->Location = System::Drawing::Point(0, 24);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(834, 537);
			this->pictureBox->TabIndex = 2;
			this->pictureBox->TabStop = false;
			this->pictureBox->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::pictureBox_Paint);
			this->pictureBox->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox_MouseDown);
			this->pictureBox->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox_MouseMove);
			this->pictureBox->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox_MouseUp);
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->openToolStripMenuItem, 
				this->saveToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(984, 24);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(43, 20);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::saveToolStripMenuItem_Click);
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::openToolStripMenuItem_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(984, 561);
			this->Controls->Add(this->pictureBox);
			this->Controls->Add(this->toolPanel);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"CityBuilder";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->toolPanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		Graphics^ graphics;
		Bitmap^ background;
		Bitmap^ texture;
		Point point1, point2;	
		List<Texture^>^ objects;
		Pen^ pen;
		Color color;
		int brushMode;
		bool isDraw, isMove;
		Texture^ selectedObj;
		String^ objectName;
		String^ prName;

	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void TextureButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void pictureBox_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void pictureBox_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void pictureBox_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void pictureBox_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);
	private: System::Void saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	};
}