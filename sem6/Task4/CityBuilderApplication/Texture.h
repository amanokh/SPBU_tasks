#pragma once

public ref struct Texture
{
public:
	System::Drawing::Bitmap^ texture;
	System::Drawing::Point point;
	System::String^ name;

	Texture(System::String^ objName, System::Drawing::Bitmap^ image, System::Drawing::Point coordinates) {
		name = objName;
		texture = image;
		point = coordinates;
	}

public:
	bool _ActiveTexture(System::Drawing::Point point) {
		return (point.X >= this->point.X - this->texture->Width / 2 && point.X <= this->point.X + this->texture->Width / 2 &&
				point.Y >= this->point.Y - this->texture->Height / 2 && point.Y <= this->point.Y + this->texture->Height / 2);
	}
};