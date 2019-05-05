#pragma once
#include "Component.h"
#include "EasyGraphics.h"

class SelectionBox : public Component
{
public:
	SelectionBox(Rect r);
	~SelectionBox();

	void onClick(int x, int y);
	void draw(EasyGraphics* g);
};

