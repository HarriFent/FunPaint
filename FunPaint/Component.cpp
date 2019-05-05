#include "Component.h"


Component::~Component()
{
}

boolean Component::hitTest(int x, int y) {
	Rect r = this->getResetRect();
	if (x >= r.x && x <= r.x + r.w && y >= r.y && y <= r.y + r.h) {
		return true;
	}
	return false;
}


Rect Component::getRect() {
	return rectangle;
}

Rect Component::getResetRect() {
	Rect r = rectangle;
	int x1 = r.x;
	int y1 = r.y;
	int x2 = r.x + r.w;
	int y2 = r.y + r.h;
	r.x = x1 < x2 ? x1 : x2;
	r.y = y1 < y2 ? y1 : y2;
	r.w = x1 > x2 ? x1 - x2 : x2 - x1;
	r.h = y1 > y2 ? y1 - y2 : y2 - y1;
	return r;
}
