#pragma once

#include "MainForm.h"

namespace CityBuilderApplication {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class LoadProjectForm : public System::Windows::Forms::Form
	{
	public:
		LoadProjectForm(MainForm^ parent)
		{
			InitializeComponent();
			parentForm = parent;
		}

	protected:
		~LoadProjectForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button1;


	private: MainForm^ parentForm;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(12, 409);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(360, 40);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Open";
			this->button1->Click += gcnew System::EventHandler(this, &LoadProjectForm::button1_Click);
			// 
			// listBox1
			// 
			this->listBox1->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawVariable;
			this->listBox1->Location = System::Drawing::Point(12, 12);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(360, 381);
			this->listBox1->TabIndex = 2;
			this->listBox1->DrawItem += gcnew System::Windows::Forms::DrawItemEventHandler(this, &LoadProjectForm::listBox1_DrawItem);
			this->listBox1->MeasureItem += gcnew System::Windows::Forms::MeasureItemEventHandler(this, &LoadProjectForm::listBox1_MeasureItem);
			// 
			// LoadProjectForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(384, 461);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"LoadProjectForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"LoadProject";
			this->Load += gcnew System::EventHandler(this, &LoadProjectForm::LoadProjectForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
		
	private: System::Void LoadProjectForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void FillListBox(String^ path);
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void listBox1_MeasureItem(System::Object^ sender, System::Windows::Forms::MeasureItemEventArgs^ e);
	private: System::Void listBox1_DrawItem(System::Object^ sender, System::Windows::Forms::DrawItemEventArgs^ e);
	};
}
