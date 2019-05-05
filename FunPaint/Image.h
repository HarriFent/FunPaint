#pragma once
#include "Shape.h"
class Image : public Shape
{
public:
	Image(wchar_t* img);
	~Image();

	void draw(EasyGraphics* g);

private:

	const wchar_t* img;
};

