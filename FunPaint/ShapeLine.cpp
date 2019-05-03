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
	g->setPenColour(this->penColour, 3);
	g->drawLine(r.x, r.y, r.x + r.w, r.y + r.h);

}

