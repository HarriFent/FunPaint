#pragma once
#include "Global.h"
#include "Shape.h"
#include "tinyxml.h"

class Properties
{
public:

	static Properties* getProperties();
	

	~Properties();
	bool getActive() { return active; }
	int getBackColour() { return backColour; }
	int getPenColour() { return penColour; }
	int getBGColour() { return bgColour; }
	Point getMousePos() { return prevMousePos; }
	std::vector<Component*>::iterator getCanvasBegin() { return Canvas.begin(); }
	std::vector<Component*>::iterator getCanvasEnd() { return Canvas.end(); }

	void setActive(bool act) { active = act; }
	void setBackColour(int backCol) { backColour = backCol; }
	void setPenColour(int penCol) { penColour = penCol; }
	void setBGColour(int bg) { bgColour = bg; }
	void setMousePos(int x, int y) { prevMousePos = { x,y }; }
	void addShape(Shape* shp) { Canvas.push_back(shp); }
	void deleteShape(Shape* shp);
	void drawCanvas(EasyGraphics* g);

	void setAction(Shape*(*clickAction)(Shape*)) { currentAction = clickAction; }
	Shape* runAction(Shape* shp) { return (*currentAction)(shp); }
	bool hasAction() { return currentAction != nullptr; }

	void SaveCanvas();
	void LoadCanvas();
	Rect getRectFromNode(TiXmlElement*);

private:
	Properties();
	static Properties* prop;

	int backColour = 0x00ffffff, penColour = 0x00000000;
	int bgColour = EasyGraphics::clWhite;

	Point prevMousePos = {0,0};

	bool active = true;

	Shape* (*currentAction)(Shape*) = nullptr;

	std::vector<Component*> Canvas;
};

