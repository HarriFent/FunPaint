#pragma once
#include "Shape.h"

class ShapeRectangle : public Shape
{
public:
	ShapeRectangle(int penCol, int backCol);
	~ShapeRectangle();
	virtual void draw(EasyGraphics* g);

	
};

