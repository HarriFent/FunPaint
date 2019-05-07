#include "Properties.h"
#include <cstdlib> 
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
	root->SetAttribute("BGColor", this->bgColour);

	for (Component* comp : Canvas) {
		Shape* shp = dynamic_cast<Shape*>(comp);
		TiXmlElement* shape;
		shape = new TiXmlElement("Shape");
		root->LinkEndChild(shape);
		if (ShapeLine* line = dynamic_cast<ShapeLine*>(shp)) {
			shape->SetAttribute("type", "Line");
		}
		else if (ShapeRectangle* r = dynamic_cast<ShapeRectangle*>(shp)) {
			shape->SetAttribute("type", "Rectangle");
		}
		else if (ShapeCircle* c = dynamic_cast<ShapeCircle*>(shp)) {
			shape->SetAttribute("type", "Circle");
		}
		shape->SetAttribute("x", shp->getRect().x);
		shape->SetAttribute("y", shp->getRect().y);
		shape->SetAttribute("w", shp->getRect().w);
		shape->SetAttribute("h", shp->getRect().h);
		shape->SetAttribute("PenColour", shp->getPenColour());
		shape->SetAttribute("BackColour", shp->getBackColour());
	}

	doc.SaveFile("Save1.xml");
}

void Properties::LoadCanvas()
{
	Canvas.clear();
	TiXmlDocument doc("Save1.xml");
	bool loaded = doc.LoadFile();
	if (loaded) {
		TiXmlHandle docHandle(&doc);
		TiXmlElement* can = docHandle.FirstChild("Shapes").ToElement();
		int bgColor = EasyGraphics::clWhite;
		can->QueryIntAttribute("BGColor", &bgColor);
		this->setBGColour(bgColor);
		TiXmlElement* shp = docHandle.FirstChild("Shapes").Child("Shape", 0).ToElement();

		for (shp; shp; shp = shp->NextSiblingElement())
		{
			int penCol, backCol;
			shp->QueryIntAttribute("PenColour", &penCol);
			shp->QueryIntAttribute("BackColour", &backCol);

			if (strcmp(shp->Attribute("type"), "Rectangle") == 0) {
				Shape* newShp = new ShapeRectangle(penCol, backCol);
				newShp->setRect(getRectFromNode(shp));
				Canvas.push_back(newShp);
			} else if (strcmp(shp->Attribute("type"), "Circle") == 0) {
				Shape* newShp = new ShapeCircle(penCol, backCol);
				newShp->setRect(getRectFromNode(shp));
				Canvas.push_back(newShp);
			} else if (strcmp(shp->Attribute("type"), "Line") == 0) {
				Shape* newShp = new ShapeLine(penCol, backCol);
				newShp->setRect(getRectFromNode(shp));
				Canvas.push_back(newShp);
			}
		}
	}
	else {
		OutputDebugStringA("Could not find saved file.\n");
	}
}

Rect Properties::getRectFromNode(TiXmlElement* shp)
{
	int x, y, w, h;
	shp->QueryIntAttribute("x", &x); // If this fails, original value is left as-is
	shp->QueryIntAttribute("y", &y);
	shp->QueryIntAttribute("w", &w);
	shp->QueryIntAttribute("h", &h);
	return Rect{ x,y,w,h };
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