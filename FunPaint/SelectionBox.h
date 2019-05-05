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

	void setRect(Rect r) { rectangle = r; }

private:
	std::vector<ShapeRectangle*> btns;
};

