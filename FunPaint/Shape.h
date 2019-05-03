#pragma once
#include "Component.h"
#include "EasyGraphics.h"
#include "Global.h"

class Shape : public Component
{
public:
	Shape(int penCol, int backCol) : Component(Rect{0,0,0,0}), penColour(penCol), backColour(backCol), status(NEW) {};
	~Shape() {};

	void setRectangle(Rect r) { rectangle = r; };
	Rect getRectangle() { return rectangle; }

	/*int getBackColour() { return backColour; }
	int getPenColour() { return penColour; }*/

	void setBackColour(int backCol) { backColour = backCol; }
	void setPenColour(int penCol) { penColour = penCol; }

	void setStatus(ShapeStatus stat) { status = stat; }
	ShapeStatus getStatus() { return status; }

	void movePos(int dx, int dy) { rectangle.x += dx; rectangle.y += dy; };

protected:
	int penColour;
	int backColour;
	ShapeStatus status;
};

