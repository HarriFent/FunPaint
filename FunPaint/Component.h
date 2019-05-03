#pragma once
#include "EasyGraphics.h"
#include "Global.h"
//#include "Properties.h"

class Component
{
public:
	Component(Rect r) : rectangle(r) {};
	~Component();

	virtual void draw(EasyGraphics* g) = 0;

	boolean hitTest(int x, int y);

protected:
	Rect rectangle;

private:
	Rect getRect();
};

