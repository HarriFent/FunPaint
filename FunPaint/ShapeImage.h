#pragma once
#include "Shape.h"
class ShapeImage :	public Shape
{
public:
	ShapeImage(const wchar_t* img) : image(img), Shape(0,0) {};
	~ShapeImage();
	virtual void draw(EasyGraphics* g);

private:
	const wchar_t* image;
};

