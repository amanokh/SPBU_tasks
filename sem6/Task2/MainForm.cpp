#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GridView::MainForm form;
	Application::Run(%form);
}

System::Void GridView::MainForm::saveButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	dataSet->WriteXml(filename);
}

System::Void GridView::MainForm::MainForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	dataSet = gcnew DataSet();
	dataTable = gcnew DataTable();

	filename = System::Windows::Forms::Application::StartupPath + "//data.xml";
	
	if (System::IO::File::Exists(filename)) {
		dataSet->ReadXml(filename);
		String^ xmlString = dataSet->GetXml();
		dataGrid->DataMember = dataSet->Tables[0]->TableName;
		dataGrid->DataSource = dataSet->Tables[0];
		return System::Void();
	}
	dataGrid->DataSource = dataTable;
	dataTable->Columns->Add("Name");
	dataTable->Columns->Add("Phone number");
	dataSet->Tables->Add(dataTable);
	DataRow row = dataSet->Tables[0]->NewRow();


	dataSet->Tables[0]->TableName = "PhoneBook";
}
