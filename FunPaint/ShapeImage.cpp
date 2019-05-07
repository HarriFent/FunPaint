#include "ShapeImage.h"

ShapeImage::~ShapeImage()
{
}

void ShapeImage::draw(EasyGraphics * g)
{
	Rect r = this->rectangle;
	g->drawBitmap(image, r.x, r.y, r.w, r.h);
}
