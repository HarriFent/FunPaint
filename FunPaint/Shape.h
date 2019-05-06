#pragma once
#include "Component.h"
#include "EasyGraphics.h"
#include "Global.h"

class Shape : public Component
{
public:
	Shape(int penCol, int backCol) : Component(Rect{0,0,0,0}), penColour(penCol), backColour(backCol), status(NEW) {};
	~Shape() {};

	/*int getBackColour() { return backColour; }
	int getPenColour() { return penColour; }*/

	void setBackColour(int backCol) { backColour = backCol; }
	void setPenColour(int penCol) { penColour = penCol; }

	void setStatus(ShapeStatus stat) { status = stat; }
	ShapeStatus getStatus() { return status; }

	virtual void updateShape(int x, int y) {
		Rect r = getRect();
		r.w = x - r.x;
		r.h = y - r.y;
		setRect(r);
	};

	virtual void movePos(int dx, int dy) { rectangle.x += dx; rectangle.y += dy; };
	virtual void scale(int dx, int dy, CornerPos pos) {
		Rect r = rectangle;
		switch (pos) {
		case TOP_RIGHT:
			r = { r.x += dx, r.y += dy, r.w -= dx, r.h -= dy };
			break;
		case BOTTOM_LEFT:
			r = { r.x += dx, r.y, r.w -= dx, r.h += dy };
			break;
		case BOTTOM_RIGHT:
			r = { r.x, r.y, r.w += dx, r.h += dy };
			break;
		case TOP_LEFT:
			r = { r.x, r.y += dy, r.w += dx, r.h -= dy };
		}
		rectangle = r;
	};

protected:
	int penColour;
	int backColour;
	ShapeStatus status;
};

