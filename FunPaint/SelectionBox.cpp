#include "SelectionBox.h"



SelectionBox::SelectionBox(Rect r) : Component(r)
{
}


SelectionBox::~SelectionBox()
{
}

void SelectionBox::onClick(int x, int y)
{
	
}

void SelectionBox::draw(EasyGraphics* g)
{

}

void SelectionBox::update(Component* shp)
{
	this->setRect(shp->getRect());
}
