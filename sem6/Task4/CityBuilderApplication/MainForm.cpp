#include "MainForm.h"
#include "LoadProjectForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	CityBuilderApplication::MainForm form;
	Application::Run(% form);
}

System::Void CityBuilderApplication::MainForm::TextureButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	objectName = ((Button^)sender)->Name;
	String^ buttonName = objectName->Remove(objectName->Length - 1);
	
	if (buttonName == "textureButton") {
		texture = gcnew Bitmap(((Button^)sender)->BackgroundImage);
		brushMode = 1;
		return System::Void();
	}

	if (buttonName == "surfaceButton") {
		texture = gcnew Bitmap(((Button^)sender)->BackgroundImage);
		brushMode = 2;
		return System::Void();
	}

	if (buttonName == "undoButton") {
		if (objects->Count > 0) {
			objects->RemoveAt(objects->Count - 1);
			pictureBox->Invalidate();
		}
	}

	else {
		objects = gcnew List<Texture^>();
		graphics->Clear(Color::White);
		pictureBox->Invalidate();
	}
}

System::Void CityBuilderApplication::MainForm::MainForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	Bitmap^ btm = gcnew Bitmap(pictureBox->Width, pictureBox->Height);
	graphics = Graphics::FromImage(btm);
	graphics->Clear(Color::White);
	pictureBox->Image = btm;

	for each (System::Object^ item in toolPanel->Controls) {
		if (dynamic_cast<Button^>(item)) {
			((Button^)item)->Click += gcnew System::EventHandler(this, &MainForm::TextureButton_Click);
		}
	}

	isDraw = false;
	isMove = false;

	objects = gcnew List<Texture^>();
	brushMode = 0;
}

System::Void CityBuilderApplication::MainForm::pictureBox_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	if (e->Button == System::Windows::Forms::MouseButtons::Left) {
		point1 = e->Location;
		
		switch (brushMode)
		{
		case 1:
			objects->Add(gcnew Texture(objectName, texture, point1));
			break;
		case 2:
			isDraw = true;
			break;
		}
	}

	if (e->Button == System::Windows::Forms::MouseButtons::Right) {
		isMove = true;
		point1 = e->Location;
	}

	pictureBox->Invalidate();
}

System::Void CityBuilderApplication::MainForm::pictureBox_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	if (isMove || isDraw) {
		point1 = e->Location;
		pictureBox->Invalidate();
	}
}

System::Void CityBuilderApplication::MainForm::pictureBox_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{

	if (e->Button == System::Windows::Forms::MouseButtons::Left) {
		isDraw = false;
	}

	if (e->Button == System::Windows::Forms::MouseButtons::Right) {
		isMove = false;
		selectedObj = nullptr;
	}
}

System::Void CityBuilderApplication::MainForm::pictureBox_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{
	Graphics^ subGraphics = e->Graphics;

	if (isMove) {
		if (selectedObj) {
			selectedObj->point = point1;
		}
		else {
			for (int i = objects->Count - 1; i >= 0; --i) {
				if (objects[i]->_ActiveTexture(point1)) {
					objects[i]->point = point1;
					selectedObj = objects[i];
					break;
				}
			}
		}
	}

	if (isDraw) {
		graphics->FillEllipse(gcnew System::Drawing::TextureBrush(texture), point1.X - 25, point1.Y - 25, 50, 50);
	}

	for each (Texture ^ obj in objects) {
		subGraphics->DrawImage(obj->texture, obj->point.X - obj->texture->Width / 2, obj->point.Y - obj->texture->Height / 2);
	}
}

System::Void CityBuilderApplication::MainForm::saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ path = Application::StartupPath + "\\Save\\";
	String^ fileName = Random().Next() + "";

	if (!System::IO::Directory::Exists(path)) {
		System::IO::Directory::CreateDirectory(path);
	} 
	Bitmap^ btm = gcnew Bitmap(pictureBox->Image);
	btm->Save(path + fileName + ".bmp", System::Drawing::Imaging::ImageFormat::Bmp);

	System::Xml::XmlWriter^ xmlWriter;

	Xml::XmlWriterSettings^ settings = gcnew Xml::XmlWriterSettings();
	settings->Indent = true;
	settings->NewLineOnAttributes = true;
	xmlWriter = Xml::XmlWriter::Create(path + fileName + ".xml", settings);

	xmlWriter->WriteStartDocument();
	xmlWriter->WriteStartElement("CityBuilderApplication");

	for each (Texture ^ obj in objects) {
		xmlWriter->WriteStartElement("Object");
		xmlWriter->WriteAttributeString("ObjectName", obj->name);
		xmlWriter->WriteAttributeString("y", obj->point.Y + "");
		xmlWriter->WriteAttributeString("x", obj->point.X + "");
		xmlWriter->WriteEndElement();
	}

	xmlWriter->WriteEndDocument();
	xmlWriter->Close();

	MessageBox::Show("saved!");
}

System::Void CityBuilderApplication::MainForm::openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{

	LoadProjectForm^ f2 = gcnew LoadProjectForm(this);
	f2->ShowDialog();
	
	if (Data::Value) {
		String^ path = Application::StartupPath + "\\Save\\";
		String^ fileName = Data::Value;
		Data::Value = nullptr;

		try {
			Bitmap^ btm = gcnew Bitmap(path + fileName + ".bmp");
			graphics = Graphics::FromImage(btm);
			pictureBox->Image = btm;
		}
		catch (Exception^ e) {
			MessageBox::Show(e->Message);
			return System::Void();
		}

		objects = gcnew List<Texture^>();

		try {
			System::Xml::XmlReader^ xmlReader;
			xmlReader = Xml::XmlReader::Create(path + fileName + ".xml");

			while (xmlReader->Read()) {
				if ((xmlReader->NodeType == System::Xml::XmlNodeType::Element) && (xmlReader->Name == "Object")) {
					if (xmlReader->HasAttributes) {
						String^ name = xmlReader->GetAttribute("ObjectName");
						int x = Convert::ToInt32(xmlReader->GetAttribute("x"));
						int y = Convert::ToInt32(xmlReader->GetAttribute("y"));
						objects->Add(gcnew Texture(name, gcnew Bitmap(toolPanel->Controls[name]->BackgroundImage), Point(x, y)));
					}
				}
			}
			pictureBox->Invalidate();
		}
		catch (Exception^ e) {
			MessageBox::Show(e->Message);
			return System::Void();
		}
	}
}