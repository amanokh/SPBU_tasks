#include "MyForm.h"
#include "gsl/gsl_sf_trig.h"

using namespace System;
using namespace System::Windows::Forms;

const int POINTS_NUM = 800;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project1::MyForm form;
	Application::Run(%form);
}


Void Project1::MyForm::xInput_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	if (double::TryParse(xInput->Text, x)) {
		errorText->Visible = false;
		fOutput->Text = gsl_sf_sin(x).ToString();
	} else {
		errorText->Visible = true;
	}
}

Void Project1::MyForm::drawFunc(System::Drawing::Graphics^ g) {
	g->Clear(Color::White);

	double axisX = graphBox->Width / (xRightDouble - xLeftDouble) * (-xLeftDouble);

	if (xLeftDouble < 0 && xRightDouble > 0) g->DrawLine(pen, axisX, 0, axisX, graphBox->Height);
	g->DrawLine(pen, 0, graphBox->Height / 2, graphBox->Width, graphBox->Height / 2);

	if (xLeftDouble > xRightDouble) { return; }

	float x1 = xLeftDouble;
	float y1 = gsl_sf_sin(x1) * 50 * (-1);

	float step = (float) Math::Abs(xRightDouble - xLeftDouble) / POINTS_NUM;
	float width_step = (float) graphBox->Width / POINTS_NUM;
	float height_step = graphBox->Height / 2;

	for (int i = 0; i < POINTS_NUM; ++i)
	{
		float x2 = x1 + step;
		float y2 = gsl_sf_sin(x2) * 50 * (-1);
		g->DrawLine(cPen, i * width_step, y1 + height_step, (i + 1) * width_step, y2 + height_step);
		x1 = x2;
		y1 = y2;
	}
}

Void Project1::MyForm::graphBox_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) 
{
	drawFunc(e->Graphics);
}

Void Project1::MyForm::boundsChanged() {
	if (float::TryParse(xLeft->Text, xLeftDouble) && float::TryParse(xRight->Text, xRightDouble)) {
		errorText1->Visible = false;

		graphBox->Invalidate();
		graphBox->Update();
		graphBox->Refresh();
	} else {
		errorText1->Visible = true;
	}
}

Void Project1::MyForm::xLeft_TextChanged(System::Object^  sender, System::EventArgs^  e) { boundsChanged(); }
Void Project1::MyForm::xRight_TextChanged(System::Object^  sender, System::EventArgs^  e) { boundsChanged(); }


Void Project1::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	pen = gcnew Pen(Color::Black, 1);
	cPen = gcnew Pen(Color::Red, 1);

	boundsChanged();
}



