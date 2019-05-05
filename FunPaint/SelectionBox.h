#pragma once
#include "Component.h"
#include "EasyGraphics.h"
#include "ShapeRectangle.h"




class SelectionBox : public Component
{
public:
	SelectionBox(Rect r);
	~SelectionBox();

	void onClick(int x, int y);
	void draw(EasyGraphics* g);
	void update(Component* shp);

	CornerPos getPosition() { return position; }

	void setRect(Rect r) { rectangle = r; }

private:
	Component* comp;
	std::vector<ShapeRectangle*> btns;

	CornerPos position = NONE;
};

