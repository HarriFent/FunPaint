#include "SelectionBox.h"



SelectionBox::SelectionBox(Rect r) : Component(r)
{
	for (int i = 0; i < 4; i++)
		btns.push_back(new ShapeRectangle(EasyGraphics::clBlack, EasyGraphics::clWhite));
}


SelectionBox::~SelectionBox()
{
	for (ShapeRectangle* btn : btns)
		delete btn;
}

void SelectionBox::onClick(int x, int y)
{
	for (int i = 0; i < 4; i++) {
		ShapeRectangle* btn = btns.at(i);
		if (btn->hitTest(x, y)) {
			dynamic_cast<Shape*>(comp)->setStatus(SCALE);
			position = CornerPos(i);
		}
	}
	
}

void SelectionBox::draw(EasyGraphics* g)
{
	Rect r = this->getResetRect();
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
	if (shp) {
		comp = shp;
		Rect r = shp->getResetRect();
		r += 5;
		this->setRect(r);
		for (int i = 0; i < 4; i++) {
			ShapeRectangle* btn = btns.at(i);
			switch (i) {
			case 0:	btn->setRect({ r.x,r.y,10,10 }); break;
			case 1:	btn->setRect({ r.x, r.y + r.h - 10,10,10 }); break;
			case 2:	btn->setRect({ r.x + r.w - 10,r.y,10,10 }); break;
			case 3:	btn->setRect({ r.x + r.w - 10,r.y + r.h - 10,10,10 }); break;
			}
		}
	}
}
