#pragma once

#include <list>
#include "EasyGraphics.h"
#include "Component.h"
#include "Button.h"
#include "Shape.h"

class Application : public EasyGraphics {
public:
	Application();
	~Application();
private:
	virtual void onDraw();
	virtual void onCreate();
	virtual void onDestroy();
	virtual void onLButtonDown(UINT nFlags, int x, int y);
	virtual void onLButtonUp(UINT nFlags, int x, int y);
	virtual void onRButtonDown(UINT nFlags, int x, int y);
	virtual void onMouseMove(UINT nFlags, int x, int y);

	void createHUD();
	Button* getSelectedButton();
	void resetButtons();
	Component* findObjFromClick(int x, int y);

	std::list<Component*> HUD;
	std::list<Component*> Canvas;
	std::list<Component*>::iterator it;

	Properties* p = Properties::getProperties();

	Shape* currentShape;
};
