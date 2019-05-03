#pragma once
#include "Shape.h"

class ShapeCircle : public Shape
{
public:
	ShapeCircle( int penCol, int backCol);
	~ShapeCircle();

	virtual void draw(EasyGraphics* g);
};

