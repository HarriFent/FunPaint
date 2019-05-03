#include "ShapeCircle.h"



ShapeCircle::ShapeCircle( int penCol, int backCol) : Shape(penCol,backCol)
{
}


ShapeCircle::~ShapeCircle()
{
}

void ShapeCircle::draw(EasyGraphics* g) {
	Rect r = this->rectangle;
	g->setPenColour(this->penColour, 3);
	g->selectBackColour(this->backColour);
	g->drawEllipse(r.x, r.y, r.w, r.h, true);
}