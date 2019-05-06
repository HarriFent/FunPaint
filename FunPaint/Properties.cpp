#include "Properties.h"
#include <cstdlib> 
#include "tinyxml.h"

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
	TiXmlElement* msg;
	TiXmlDeclaration* decl = new TiXmlDeclaration("1.0", "", "");
	doc.LinkEndChild(decl);

	TiXmlElement* root = new TiXmlElement("MyApp");
	doc.LinkEndChild(root);

	TiXmlComment* comment = new TiXmlComment();
	comment->SetValue(" Settings for MyApp ");
	root->LinkEndChild(comment);

	TiXmlElement* msgs = new TiXmlElement("Messages");
	root->LinkEndChild(msgs);

	msg = new TiXmlElement("Welcome");
	msg->LinkEndChild(new TiXmlText("Welcome to MyApp"));
	msgs->LinkEndChild(msg);

	msg = new TiXmlElement("Farewell");
	msg->LinkEndChild(new TiXmlText("Thank you for using MyApp"));
	msgs->LinkEndChild(msg);

	TiXmlElement* windows = new TiXmlElement("Windows");
	root->LinkEndChild(windows);

	TiXmlElement* window;
	window = new TiXmlElement("Window");
	windows->LinkEndChild(window);
	window->SetAttribute("name", "MainFrame");
	window->SetAttribute("x", 5);
	window->SetAttribute("y", 15);
	window->SetAttribute("w", 400);
	window->SetAttribute("h", 250);

	TiXmlElement* cxn = new TiXmlElement("Connection");
	root->LinkEndChild(cxn);
	cxn->SetAttribute("ip", "192.168.0.1");
	cxn->SetDoubleAttribute("timeout", 123.456); // floating point attrib

	//dump_to_stdout(&doc);
	doc.SaveFile("appsettings.xml");
}

void Properties::LoadCanvas()
{

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