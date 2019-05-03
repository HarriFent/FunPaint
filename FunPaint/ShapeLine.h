#pragma once
#include "Shape.h"

class ShapeLine : public Shape
{
public:
	ShapeLine(int penCol, int backCol);
	~ShapeLine();
	virtual void draw(EasyGraphics* g);
};

