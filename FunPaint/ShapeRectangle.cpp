#include "ShapeRectangle.h"


ShapeRectangle::ShapeRectangle( int penCol, int backCol) : Shape( penCol,backCol){}

ShapeRectangle::~ShapeRectangle(){}


void ShapeRectangle::draw(EasyGraphics* g) {
	Rect r = this->rectangle;
	g->setPenColour(this->penColour, 3);
	g->selectBackColour(this->backColour);
	g->drawRectangle(r.x, r.y, r.w, r.h, true);
}