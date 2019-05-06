#pragma once
#include <vector>
#include "Global.h"
#include "Shape.h"
#include "ShapeRectangle.h"
#include "ShapeLine.h"
#include "ShapeCircle.h"
#include "ShapePencil.h"
#include "InputBox.h"

Properties* p = Properties::getProperties();

void removeProp() {
	delete p;
}

Shape* PencilClick(Shape* shp) {
	return new ShapePencil(p->getPenColour(), p->getBackColour());
}
Shape* LineClick(Shape* shp) {
	return new ShapeLine(p->getPenColour(), p->getBackColour());
}
Shape* RectangleClick(Shape* shp) {
	return new ShapeRectangle(p->getPenColour(), p->getBackColour());
}
Shape* CircleClick(Shape* shp) {
	return new ShapeCircle(p->getPenColour(), p->getBackColour());
}
Shape* ColourClick(Shape* shp) {
	//OutputDebugStringA("COLOUR\n");
	p->setPenColour(getColourDialog(p->getPenColour()));
	return shp;
}
Shape* ColourRClick(Shape* shp) {
	//OutputDebugStringA("COLOUR\n");
	p->setBackColour(getColourDialog(p->getBackColour()));
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
	if (shp)
		shp->setStatus(REMOVE);
	return shp;
}
Shape* TransformClick(Shape* shp) {
	if (shp) shp->setStatus(MOVE);
	return shp;
}
Shape* ImportImageClick(Shape* shp) {

	InputBox input;
//	input.create(hInstance, 900, 600, 40, true);
	BrowseFolder("");
	OutputDebugStringA("IMPORTIMAGE\n");
	return shp;
}
Shape* ExportImageClick(Shape* shp) {
	OutputDebugStringA("EXPORTIMAGE\n");
	return shp;
}
Shape* SaveClick(Shape* shp) {
	OutputDebugStringA("SAVE\n");
	return shp;
}
Shape* LoadClick(Shape* shp) {
	OutputDebugStringA("LOAD\n");
	return shp;
}
Shape* HelpClick(Shape* shp) {
	OutputDebugStringA("HELP\n");
	return shp;
}