#pragma once
#include <vector>
#include "Global.h"
#include "Shape.h"
#include "ShapeRectangle.h"
#include "ShapeLine.h"
#include "ShapeCircle.h"
#include "ShapePencil.h"
#include "ShapeImage.h"


Properties* p = Properties::getProperties();

void removeProp() {
	delete p;
}

Shape* PencilClick(Shape* shp) {
	return new ShapePencil(p->getPenColour(), p->getBackColour());
}
Shape* LineClick(Shape* shp) {
	shp = new ShapeLine(p->getPenColour(), p->getBackColour());
	p->addShape(shp);
	Point cood = p->getMousePos();
	shp->setRect({ cood.x,cood.y,cood.x,cood.y });
	return shp;
}
Shape* RectangleClick(Shape* shp) {
	shp = new ShapeRectangle(p->getPenColour(), p->getBackColour());
	p->addShape(shp);
	Point cood = p->getMousePos();
	shp->setRect({ cood.x,cood.y,0,0 });
	return shp;
}
Shape* CircleClick(Shape* shp) {
	shp = new ShapeCircle(p->getPenColour(), p->getBackColour());
	p->addShape(shp);
	Point cood = p->getMousePos();
	shp->setRect({cood.x,cood.y,0,0});
	return shp;
}
Shape* ColourClick(Shape* shp) {
	//OutputDebugStringA("COLOUR\n");
	p->setActive(false);
	p->setPenColour(getColourDialog(p->getPenColour()));
	p->setActive(true);
	return shp;
}
Shape* ColourRClick(Shape* shp) {
	//OutputDebugStringA("COLOUR\n");
	p->setActive(false);
	p->setBackColour(getColourDialog(p->getBackColour()));
	p->setActive(true);
	return shp;
}
Shape* FillClick(Shape* shp) {
	//OutputDebugStringA("FILL\n");
	if (shp) {
		shp->setBackColour(p->getBackColour());
		shp->setPenColour(p->getPenColour());
		shp->setStatus(DEFAULT);
	}
	return shp;
}
Shape* EraserClick(Shape* shp) {
	if (shp) {
		p->deleteShape(shp);
		delete shp;
		shp = nullptr;
	}
	return shp;
}
Shape* TransformClick(Shape* shp) {
	if (shp) shp->setStatus(MOVE);
	return shp;
}

Shape* PickerClick(Shape* shp) {
	p->setBackColour(shp->getBackColour());
	p->setPenColour(shp->getPenColour());
	shp->setStatus(DEFAULT);
	return shp;
}
Shape* SaveClick(Shape* shp) {
	p->SaveCanvas();
	return shp;
}
Shape* LoadClick(Shape* shp) {
	p->LoadCanvas();
	return shp;
}
Shape* HelpClick(Shape* shp) {
	OutputDebugStringA("HELP\n");
	ShapeImage* img = new ShapeImage(L"imgs/help.bmp");
	img->setRect({ 40,80,820,440 });
	p->addShape(img);
	return shp;
}