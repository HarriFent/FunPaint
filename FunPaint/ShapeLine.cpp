#include "ShapeLine.h"
#include <math.h>


ShapeLine::ShapeLine(int penCol, int backCol) : Shape( penCol, backCol)
{

}


ShapeLine::~ShapeLine()
{
}

void ShapeLine::draw(EasyGraphics * g)
{
	g->setPenColour(this->penColour, PEN_WIDTH);
	g->drawLine(x1, y1, x2, y2);
}

void ShapeLine::updateShape(int x, int y)
{
	x2 = x;
	y2 = y;
	rectangle = this->getResetRect();
}

void ShapeLine::setRect(Rect r)
{
	x1 = r.x;
	y1 = r.y;
	x2 = r.w == 0 ? r.x : r.w;
	y2 = r.h == 0 ? r.y : r.h;
	rectangle = this->getResetRect();
}

Rect ShapeLine::getResetRect()
{
	int x, y, w, h;
	x = x1 < x2 ? x1 : x2;
	y = y1 < y2 ? y1 : y2;
	w = x1 < x2 ? x2 - x1 : x1 - x2;
	h = y1 < y2 ? y2 - y1 : y1 - y2;
	return Rect{x,y,w,h};
}

Rect ShapeLine::getRect()
{
	Rect r;
	r.x = x1;
	r.y = y1;
	r.w = x2;
	r.h = y2;
	return r;
}

boolean ShapeLine::hitTest(int x, int y)
{
	double distance = findDistance(x,y,x1,y1,x2,y2);
	Rect r = getResetRect();
	return (x >= r.x && x <= r.x + r.w && y >= r.y && y <= r.y + r.h && distance < 10);
}

void ShapeLine::movePos(int dx, int dy) {
	x1 += dx;
	x2 += dx;
	y1 += dy;
	y2 += dy;
	rectangle = this->getResetRect();
}

void ShapeLine::scale(int dx, int dy, CornerPos pos)
{
	if (pos == TOP_RIGHT) {
		x1 += dx;
		y1 += dy;
	}
	else {
		x2 += dx;
		y2 += dy;
	}
	rectangle = this->getResetRect();
}

double ShapeLine::findDistance(int m, int n, int x1, int y1, int x2, int y2)
{
	//  (y-y1) m(x - x1)
	// m = (y2-y1)/(x2-x1)
	// c = y-mx
	double A, B, C;
	A = y1 - y2;
	B = x2 - x1;
	C = (x1 - x2) * y1 + (y2 - y1) * x1;
	return abs((A * m) + (B * n) + C) / (sqrt(pow(A, 2) + pow(B, 2)));
}
