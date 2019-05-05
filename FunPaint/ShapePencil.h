#pragma once
#include "Shape.h"
#include <list>

class ShapePencil : public Shape
{
public:
	ShapePencil( int penCol, int backCol) : Shape(penCol, backCol) {};
	~ShapePencil();
	virtual void draw(EasyGraphics* g);
	virtual void onDelete();
	void addPoint(int x, int y);
	void movePos(int dx, int dy);
private:
	std::vector<Point> line;
	std::vector<Point>::iterator it_line;
	void resetRect();
	Point cood_to_point(int x, int y);
};

