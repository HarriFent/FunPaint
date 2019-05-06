#pragma once
#include "Global.h"
#include "Shape.h"

class Properties
{
public:

	static Properties* getProperties();
	

	~Properties();
	bool getActive() { return active; }
	int getBackColour() { return backColour; }
	int getPenColour() { return penColour; }
	Point getMousePos() { return prevMousePos; }
	std::vector<Component*>::iterator getCanvasBegin() { return Canvas.begin(); }
	std::vector<Component*>::iterator getCanvasEnd() { return Canvas.end(); }

	void setActive(bool act) { active = act; }
	void setBackColour(int backCol) { backColour = backCol; }
	void setPenColour(int penCol) { penColour = penCol; }
	void setMousePos(int x, int y) { prevMousePos = { x,y }; }
	void addShape(Shape* shp) { Canvas.push_back(shp); }
	void deleteShape(Shape* shp);
	void drawCanvas(EasyGraphics* g);

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

	std::vector<Component*> Canvas;
};

