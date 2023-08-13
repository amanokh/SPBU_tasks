#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Painter::MainForm form;
	Application::Run(% form);
}

System::Void Painter::MainForm::paintBox_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
{
	if (isPicker) {
		Bitmap^ bm = gcnew Bitmap(paintBox->Image);
		brush->Color = bm->GetPixel(e->X, e->Y);
		isPicker = false;
		return;
	}

	isDraw = true;
	point1 = e->Location;
	point1.X = (int)(point1.X / scale_x);
	point1.Y = (int)(point1.Y / scale_y);


	if (e->Button == System::Windows::Forms::MouseButtons::Right) {
			brushMode = 0;
			paintBox->Cursor->Current = Cursors::No;
	}

}

System::Void Painter::MainForm::paintBox_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
{
	if (isDraw) {
		point2 = e->Location;
		point2.X = (int)(point2.X / scale_x);
		point2.Y = (int)(point2.Y / scale_y);
		paintBox->Invalidate();
	}
}

System::Void Painter::MainForm::paintBox_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	switch (brushMode)
	{
	case 2:
		layerGraphics->DrawEllipse(brush, point1.X, point1.Y, point2.X - point1.X, point2.Y - point1.Y);
		break;
	case 3:
		layerGraphics->DrawRectangle(brush, subPoint1.X, subPoint1.Y, subPoint2.X - subPoint1.X, subPoint2.Y - subPoint1.Y);
		break;
	case 4:
		layerGraphics->DrawLine(brush, point1.X, point1.Y, point2.X, point2.Y);
		break;
	}


	if (e->Button == System::Windows::Forms::MouseButtons::Right) {
		paintBox->Cursor->Current = Cursors::Default;
	}

	brushMode = 1;
	circleButton->Enabled = true;
	squareButton->Enabled = true;

	isDraw = false;
	paintBox->Invalidate();
}

System::Void Painter::MainForm::color_Click(System::Object^  sender, System::EventArgs^  e) {
	if (safe_cast<Button^>(sender)->Name == L"red") brushColor = Color::Red;
	if (safe_cast<Button^>(sender)->Name == L"orange") brushColor = Color::Orange;
	if (safe_cast<Button^>(sender)->Name == L"yellow") brushColor = Color::Yellow;
	if (safe_cast<Button^>(sender)->Name == L"green") brushColor = Color::Green;
	if (safe_cast<Button^>(sender)->Name == L"blue") brushColor = Color::Blue;
	if (safe_cast<Button^>(sender)->Name == L"violet") brushColor = Color::Violet;
	if (safe_cast<Button^>(sender)->Name == L"black") brushColor = Color::Black;
	if (safe_cast<Button^>(sender)->Name == L"white") brushColor = Color::White;

	brush->Color = brushColor;
}

System::Void Painter::MainForm::pictureBox1_Click(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	Bitmap^ bm = gcnew Bitmap(palette->Image, palette->Width, palette->Height);
	brush->Color = bm->GetPixel(e->X, e->Y);
}

System::Void Painter::MainForm::button8_Click(System::Object^  sender, System::EventArgs^  e) {
	isPicker = true;
}


System::Void Painter::MainForm::paintBox_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{
	Graphics^ graphics = e->Graphics;
	graphics->ScaleTransform((float)scale_x, (float)scale_y);

	if (isDraw) {
		switch (brushMode)
		{
		case 0:
			layerGraphics->DrawLine(erase, point1, point2);
			point1 = point2;
			break;
		case 1:
			layerGraphics->DrawLine(brush, point1, point2);
			point1 = point2;
			break;
		case 2:
			graphics->DrawEllipse(brush, point1.X, point1.Y, point2.X - point1.X, point2.Y - point1.Y);
			break;
		case 3:
			subPoint1 = Point(Math::Min(point1.X, point2.X), Math::Min(point1.Y, point2.Y));
			subPoint2 = Point(Math::Max(point1.X, point2.X), Math::Max(point1.Y, point2.Y));
			graphics->DrawRectangle(brush, subPoint1.X, subPoint1.Y, subPoint2.X - subPoint1.X, subPoint2.Y - subPoint1.Y);
			break;
		}
	}
}

System::Void Painter::MainForm::paintBox_MouseWheel(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
{
	if (brushSize > 0 && brushSize <= 20) {
		if (e->Delta > 0) {
			brushSize = brushSize + 1;
		}
		else {
			brushSize = brushSize - 1;
		}
		brush->Width = (float)brushSize;
	}
	else {
		if (brushSize == 0) {
			MessageBox::Show("Min brush exceeded");
			brushSize = 1;
		}
		else {
			MessageBox::Show("Max brush exceeded");
			brushSize = 20;
		}
	}
}

System::Void Painter::MainForm::circleButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (brushMode == 2) brushMode = 1;
	else brushMode = 2;

	circleButton->Enabled = false;

}

System::Void Painter::MainForm::squareButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (brushMode == 3) brushMode = 1;
	else brushMode = 3;

	squareButton->Enabled = false;

}

System::Void Painter::MainForm::clearButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	Bitmap^ bm = gcnew Bitmap(paintBox->Width, paintBox->Height);
	layerGraphics = Graphics::FromImage(bm);
	layerGraphics->Clear(Color::White);
	paintBox->Image = bm;
	paintBox_SizeChanged(paintBox, e);
}


System::Void Painter::MainForm::paintBox_SizeChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (paintBox->Image) {
		scale_x = (double) paintBox->Width / paintBox->Image->Width;
		scale_y = (double) paintBox->Height / paintBox->Image->Height;
	}
}

System::Void Painter::MainForm::MainForm_Load(System::Object^ sender, System::EventArgs^ e) 
{
	scale_x = 1.;
	scale_y = 1.;

	brushMode = 1;
	brushSize = 5;
	brushColor = Color::Black;
	brush = gcnew Pen(brushColor, (float)brushSize);
	erase = gcnew Pen(Color::White, 10);
	isDraw = false;
	isPicker = false;

	Bitmap^ bm = gcnew Bitmap(paintBox->Width, paintBox->Height);
	layerGraphics = Graphics::FromImage(bm);
	layerGraphics->Clear(Color::White);
	paintBox->Image = bm;
}

System::Void Painter::MainForm::saveBtn_click(System::Object^ sender, System::EventArgs^ e)
{
	SaveFileDialog^ sfd = gcnew SaveFileDialog();
	sfd->Filter = "Image(*.png)|*.png|All files (*.*)|*.*";
	if (sfd->ShowDialog() == ::DialogResult::OK) {
		Bitmap^ btm = gcnew Bitmap(paintBox->Image);
		btm->Save(sfd->FileName);
	}
}

System::Void Painter::MainForm::loadBtn_click(System::Object^ sender, System::EventArgs^ e)
{
	OpenFileDialog^ ofd = gcnew OpenFileDialog();
	ofd->Filter = "Image(*.png)|*.png|All files (*.*)|*.*";
	if (ofd->ShowDialog() == ::DialogResult::OK) {
		background = gcnew Bitmap(ofd->FileName);
		layerGraphics = Graphics::FromImage(background);
		paintBox->Image = background;
		paintBox_SizeChanged(paintBox, e);
	}
}

System::Void Painter::MainForm::aboutBtn_click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Use scroll for changing brush size.\n\nUse right-click for erase.");
}

