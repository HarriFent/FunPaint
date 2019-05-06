#pragma once
#include "Global.h"
#include "Shape.h"
#include <list>

class Properties
{
public:

	static Properties* getProperties();
	
	void removeProperties() { delete prop; };

	~Properties();
	bool getActive() { return active; }
	int getBackColour() { return backColour; }
	int getPenColour() { return penColour; }
	Point getMousePos() { return prevMousePos; }

	void setActive(bool act) { active = act; }
	void setBackColour(int backCol) { backColour = backCol; }
	void setPenColour(int penCol) { penColour = penCol; }
	void setMousePos(int x, int y) { prevMousePos = { x,y }; }

	void setAction(Shape*(*clickAction)(Shape*)) { currentAction = clickAction; }
	Shape* runAction(Shape* shp) { return (*currentAction)(shp); }
	bool hasAction() { return currentAction != nullptr; }

	void SaveCanvas();
	void LoadCanvas();

private:
	Properties();
	static Properties* prop;

	int backColour = 0xffffff, penColour = 0x000000;

	Point prevMousePos = {0,0};

	bool active = true;

	Shape* (*currentAction)(Shape*) = nullptr;
};

