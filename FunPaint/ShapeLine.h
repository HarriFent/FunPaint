#pragma once
#include "Shape.h"

class ShapeLine : public Shape
{
public:
	ShapeLine(int penCol, int backCol);
	~ShapeLine();
	virtual void draw(EasyGraphics* g);
	virtual void updateShape(int x, int y);
	void setRect(Rect r);
	Rect getResetRect();
	Rect getRect();

	Point getPoint1() { return Point{ x1,y1 }; }
	Point getPoint2() { return Point{ x2,y2 }; }

	virtual boolean hitTest(int x, int y);
	virtual void movePos(int dx, int dy);

	void scale(int dx, int dy, CornerPos pos);

private:
	double findDistance(int m, int n, int x1, int y1, int x2, int y2);

	int x1, y1, x2, y2;
};

