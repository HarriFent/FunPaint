#include "ShapeCircle.h"



ShapeCircle::ShapeCircle( int penCol, int backCol) : Shape(penCol,backCol)
{
}


ShapeCircle::~ShapeCircle()
{
}

void ShapeCircle::draw(EasyGraphics* g) {
	Rect r = this->rectangle;
	g->setPenColour(this->penColour, PEN_WIDTH);
	g->selectBackColour(this->backColour);
	g->drawEllipse(r.x, r.y, r.w, r.h, true);
}

boolean ShapeCircle::hitTest(int x, int y)
{
	double rx = 0.5 * rectangle.w;
	double ry = 0.5 * rectangle.h;
	double mx = rectangle.x + rx;
	double my = rectangle.y + ry;
	return ((pow(x - mx,2)/pow(rx,2))+(pow(y - my,2)/pow(ry,2))) < 1;
}
