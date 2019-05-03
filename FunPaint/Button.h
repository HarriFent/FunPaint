#pragma once
#include "Component.h"
#include "Shape.h"
#include "Properties.h"

class Button : public Component
{
public:
	Button(Rect r, const wchar_t* img, Shape*(*clickAction)(Shape*), bool fastRun = false);
	~Button();

	void draw(EasyGraphics* g);
	void onClick(int x, int y);

	bool isSelected() { return selected; }
	bool reset() {
		bool result = selected;
		selected = false;
		return result;
	};

	ButtonType getButtonType() { return btnType; };
	void setButtonType(ButtonType type) { btnType = type; }
	void setClickAction(Shape*(*clickAction)(Shape*)) { this->clickAction = clickAction; }

private:
	Properties* p = Properties::getProperties();
	
	bool selected = false;
	bool fastRun;
	ButtonType btnType;
	const wchar_t* img;
	Shape* (*clickAction)(Shape*);
};

