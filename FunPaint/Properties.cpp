#include "Properties.h"
#include <cstdlib> 
#include "tinyxml.h"
#include "ShapeLine.h"
#include "ShapeRectangle.h"
#include "ShapeCircle.h"

void Properties::drawCanvas(EasyGraphics* g)
{
	for (Component* shp : Canvas)
		shp->draw(g);
}

void Properties::deleteShape(Shape* shp)
{
	std::vector<Component*>::iterator it;
	for (it = Canvas.begin(); it != Canvas.end(); it++)
		if ((*it) == shp) {
			Canvas.erase(it);
			break;
		}
}

void Properties::SaveCanvas()
{
	TiXmlDocument doc;
	TiXmlDeclaration* decl = new TiXmlDeclaration("1.0", "", "");
	doc.LinkEndChild(decl);

	TiXmlElement* root = new TiXmlElement("Shapes");
	doc.LinkEndChild(root);

	for (Component* comp : Canvas) {
		Shape* shp = dynamic_cast<Shape*>(comp);
		TiXmlElement* shape;
		shape = new TiXmlElement("Shape");
		root->LinkEndChild(shape);
		if (ShapeLine* line = dynamic_cast<ShapeLine*>(shp)) {
			shape->SetAttribute("type", "Line");
			shape->SetAttribute("x1", line->getPoint1().x);
			shape->SetAttribute("y1", line->getPoint1().y);
			shape->SetAttribute("x2", line->getPoint2().x);
			shape->SetAttribute("y2", line->getPoint2().y);
		}
		else if (ShapeRectangle* r = dynamic_cast<ShapeRectangle*>(shp)) {
			shape->SetAttribute("type", "Rectangle");
			shape->SetAttribute("x", r->getRect().x);
			shape->SetAttribute("y", r->getRect().y);
			shape->SetAttribute("w", r->getRect().w);
			shape->SetAttribute("h", r->getRect().h);
		}
		else if (ShapeCircle* c = dynamic_cast<ShapeCircle*>(shp)) {
			shape->SetAttribute("type", "Circle");
			shape->SetAttribute("x", c->getRect().x);
			shape->SetAttribute("y", c->getRect().y);
			shape->SetAttribute("w", c->getRect().w);
			shape->SetAttribute("h", c->getRect().h);
		}
		shape->SetAttribute("PenColour", shp->getPenColour());
		shape->SetAttribute("BackColour", shp->getBackColour());
	}

	doc.SaveFile("Save1.xml");
}

void Properties::LoadCanvas()
{
	TiXmlDocument doc("Save1.xml");
	bool loaded = doc.LoadFile();
	if (loaded) {

	}
	else {
		OutputDebugStringA("Could not find saved file.\n");
	}
}

Properties::Properties()
{
}


Properties * Properties::getProperties()
{
	if (!prop)
		prop = new Properties();
	return prop;
}

Properties::~Properties()
{
	for (Component* shp : Canvas) {
		delete shp;
	}
}

Properties* Properties::prop = nullptr;