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

private:
	int x1, y1, x2, y2;
};

