#pragma once

namespace GridView {

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
	private: System::Windows::Forms::DataGridView^ dataGrid;
	private: System::Windows::Forms::Button^ saveButton;
	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->dataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGrid
			// 
			this->dataGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGrid->BackgroundColor = System::Drawing::Color::White;
			this->dataGrid->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGrid->Location = System::Drawing::Point(0, 0);
			this->dataGrid->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->dataGrid->Name = L"dataGrid";
			this->dataGrid->Size = System::Drawing::Size(665, 482);
			this->dataGrid->TabIndex = 0;
			// 
			// saveButton
			// 
			this->saveButton->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->saveButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->saveButton->Location = System::Drawing::Point(0, 439);
			this->saveButton->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(665, 43);
			this->saveButton->TabIndex = 1;
			this->saveButton->Text = L"Save";
			this->saveButton->UseVisualStyleBackColor = true;
			this->saveButton->Click += gcnew System::EventHandler(this, &MainForm::saveButton_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(665, 482);
			this->Controls->Add(this->saveButton);
			this->Controls->Add(this->dataGrid);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"PhoneBook";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGrid))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: String^ filename;
	private: DataTable^ dataTable;
	private: DataSet^ dataSet;

	private: System::IO::FileStream^ stream;
	private: System::Xml::XmlTextWriter^ xmlWriter;
		
	private: System::Void saveButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e);

	};
}
