#include "ShapeLine.h"



ShapeLine::ShapeLine(int penCol, int backCol) : Shape( penCol, backCol)
{

}


ShapeLine::~ShapeLine()
{
}

void ShapeLine::draw(EasyGraphics * g)
{
	Rect r = this->rectangle;
	g->setPenColour(this->penColour, PEN_WIDTH);
	g->drawLine(x1, y1, x2, y2);

}

void ShapeLine::updateShape(int x, int y)
{
	x2 = x;
	y2 = y;
}

void ShapeLine::setRect(Rect r)
{
	x1 = r.x;
	x2 = r.x;
	y1 = r.y;
	y2 = r.y;
}
