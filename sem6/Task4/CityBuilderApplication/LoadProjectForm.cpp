#include "LoadProjectForm.h"
#include "Texture.h"

using namespace System;
using System::Collections::Generic::IEnumerable;

System::Void CityBuilderApplication::LoadProjectForm::LoadProjectForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	String^ path = Application::StartupPath;
	FillListBox(path + "\\Save\\");
}

System::Void CityBuilderApplication::LoadProjectForm::FillListBox(String^ path) {
	for each (String^ file in System::IO::Directory::GetFiles(path))
	{
		file = file->Replace(path, "");
		array<String^>^ nameAndFormat = file->Split('.');
		if (nameAndFormat[1] == "bmp") {
			listBox1->Items->Add(nameAndFormat[0]);
		}
	}
}

System::Void CityBuilderApplication::LoadProjectForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ selectedProject = Convert::ToString(listBox1->SelectedItem);
	
	if (selectedProject == "") {
		MessageBox::Show("Select project at first");
		return System::Void();
	}
	
	Data::Value = selectedProject;

	this->Close();
}


System::Void CityBuilderApplication::LoadProjectForm::listBox1_MeasureItem(System::Object^ sender, System::Windows::Forms::MeasureItemEventArgs^ e)
{
	e->ItemHeight = 50;
}

System::Void CityBuilderApplication::LoadProjectForm::listBox1_DrawItem(System::Object^ sender, System::Windows::Forms::DrawItemEventArgs^ e)
{
	ListBox^ list = (ListBox^)sender;
	if (e->Index > -1)
	{
		if ((e->State & DrawItemState::Selected) == DrawItemState::Selected)
			e = gcnew DrawItemEventArgs(e->Graphics,
				e->Font,
				e->Bounds,
				e->Index,
				e->State ^ DrawItemState::Selected,
				e->ForeColor,
				Color::Black);
		e->DrawBackground();
		e->DrawFocusRectangle();
		Object^ item = list->Items[e->Index];
		Brush^ brush = gcnew SolidBrush(e->ForeColor);
		Pen^ brushs = gcnew Pen(e->ForeColor, 1);
		SizeF size = e->Graphics->MeasureString(item->ToString(), e->Font);
		e->Graphics->DrawString(item->ToString(), e->Font, brush, e->Bounds.Left + (e->Bounds.Width / 2 - size.Width / 2), e->Bounds.Top + (e->Bounds.Height / 2 - size.Height / 2));
	}
}
