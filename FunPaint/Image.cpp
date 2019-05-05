#include "Image.h"



Image::Image(wchar_t* img) : Shape(0,0), img(img)
{
}


Image::~Image()
{
}

void Image::draw(EasyGraphics* g)
{
	Rect r = this->rectangle;
	g->drawBitmap(img, r.x, r.y, r.w, r.h);
}
