#pragma once
#include "Global.h"
#include "Shape.h"
#include <list>

class Properties
{
public:

	static Properties* getProperties();
	~Properties();
	int getBackColour() { return backColour; }
	int getPenColour() { return penColour; }
	Point getMousePos() { return prevMousePos; }

	void setBackColour(int backCol) { backColour = backCol; }
	void setPenColour(int penCol) { penColour = penCol; }
	void setMousePos(int x, int y) { prevMousePos = { x,y }; }

	void setAction(Shape*(*clickAction)(Shape*)) { currentAction = clickAction; }
	Shape* runAction(Shape* shp) { return (*currentAction)(shp); }
	bool hasAction() { return currentAction != nullptr; }


private:
	Properties();
	static Properties* prop;

	int backColour = 0xffffff, penColour = 0x000000;

	Point prevMousePos;

	Shape* (*currentAction)(Shape*) = nullptr;
};

