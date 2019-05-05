#include "ShapePencil.h"

ShapePencil::~ShapePencil()
{
}

void ShapePencil::draw(EasyGraphics* g) {
	if (line.size() > 0) {
		g->setPenColour(this->penColour, 3);
		Point lastP = cood_to_point(line.front().x, line.front().y);
		for (it_line = line.begin(); it_line != line.end(); it_line++) {
			g->drawLine(lastP.x, lastP.y, (*it_line).x, (*it_line).y);
			lastP = *it_line;
		}
		Rect r = this->rectangle;
		g->setPenColour(g->clRed, 2);
		g->drawRectangle(r.x, r.y, r.w, r.h, false);
	}
}

void ShapePencil::onDelete()
{
	line.empty();
}

void ShapePencil::resetRect() {
	for (it_line = line.begin(); it_line != line.end(); it_line++) {
		rectangle.x = (*it_line).x < rectangle.x ?  (*it_line).x : rectangle.x;
		rectangle.y = (*it_line).y < rectangle.y ? (*it_line).y : rectangle.y;
		rectangle.w = (*it_line).x > rectangle.x + rectangle.w ? (*it_line).x - rectangle.x : rectangle.w;
		rectangle.h = (*it_line).y > rectangle.y + rectangle.h ? (*it_line).y - rectangle.y : rectangle.h;
	}
}

void ShapePencil::addPoint(int x, int y)
{
	for (it_line = line.begin(); it_line != line.end(); it_line++)
		if ((*it_line).x == x && (*it_line).y == y)
			return;
	line.push_back(cood_to_point(x, y));
	resetRect();
}

void ShapePencil::movePos(int dx, int dy)
{
	rectangle.x += dx;
	rectangle.y += dy;
	for (it_line = line.begin(); it_line != line.end(); it_line++) {
		(*it_line).x += dx;
		(*it_line).y += dy;
	}
}

Point ShapePencil::cood_to_point(int x, int y)
{
	Point p = Point{x,y};
	return p;
}

