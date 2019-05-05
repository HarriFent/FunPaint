#pragma once
#include "EasyGraphics.h"
#include "Global.h"

class Component
{
public:
	Component(Rect r) : rectangle(r) {};
	~Component();

	virtual void draw(EasyGraphics* g) = 0;
	virtual void onDelete() {};

	boolean hitTest(int x, int y);
	Rect getRect();
	virtual void setRect(Rect r) { rectangle = r; };

protected:
	Rect rectangle;
};

