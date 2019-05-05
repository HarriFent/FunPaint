#include "SelectionBox.h"



SelectionBox::SelectionBox(Rect r) : Component(r)
{
	for (int i = 0; i < 4; i++)
		btns.push_back(new ShapeRectangle(EasyGraphics::clBlack, EasyGraphics::clWhite));
}


SelectionBox::~SelectionBox()
{
}

void SelectionBox::onClick(int x, int y)
{
	
}

void SelectionBox::draw(EasyGraphics* g)
{
	Rect r = this->getRect();
	r += 5;
	r.transform(-1, -1);
	g->setDotColour(g->clBlack, 1);
	g->drawLine(r.x, r.y, r.x + r.w, r.y);
	g->drawLine(r.x, r.y, r.x, r.y + r.h);
	g->drawLine(r.x + r.w, r.y, r.x + r.w, r.y + r.h);
	g->drawLine(r.x, r.y + r.h, r.x + r.w, r.y + r.h);
	for (ShapeRectangle* btn : btns) {
		btn->draw(g);
	}
}

void SelectionBox::update(Component* shp)
{
	Rect r = shp->getRect();
	this->setRect(r);
	for (int i = 0; i < 4; i++) {
		ShapeRectangle* btn = btns.at(i);
		switch (i) {
		case 0:
			btn->setRect({ r.x-5,r.y-5,10,10 });
			break;
		case 1:
			btn->setRect({ r.x-5, r.y + r.h - 5,10,10 });
			break;
		case 2:
			btn->setRect({ r.x + r.w - 5,r.y-5,10,10 });
			break;
		case 3:
			btn->setRect({ r.x + r.w - 5,r.y + r.h - 5,10,10 });
			break;
		}
	}
}
