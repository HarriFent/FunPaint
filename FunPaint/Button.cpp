#include "Button.h"

Button::Button(Rect r, const wchar_t* img, Shape*(*clickAction)(Shape*), bool fastRun) : Component(r), img(img), clickAction(clickAction), fastRun(fastRun)
{};

void Button::draw(EasyGraphics* g) {
	Rect r = this->rectangle;
	g->drawBitmap(img, r.x, r.y, r.w, r.h);

	
	if (btnType == COLOUR) {
		g->setPenColour(g->clWhite, 1);
		g->selectBackColour(p->getPenColour());
		g->drawRectangle(r.x + 4, r.y + 45, 24, 11, true);
		g->selectBackColour(p->getBackColour());
		g->drawRectangle(r.x + 32, r.y + 45, 24, 11, true);
	}

	if (selected) {
		g->setPenColour(g->clRed, 3);
		g->drawRectangle(r.x, r.y, r.w, r.h, false);
		if (btnType == HELP) 
			g->drawBitmap(L"imgs/help.bmp", 40, 80, 820, 352);
	}
}

void Button::onClick(int x, int y)
{
	selected = !selected; 
	if (selected) {
		if (fastRun) {
			(*clickAction)(nullptr);
			selected = false;
		}
		else {
			p->setAction(clickAction);
		}
	}
	else {
		p->setAction(nullptr);
	}
}

Button::~Button()
{
	delete img;
	delete p;
}
