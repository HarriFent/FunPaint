#include "Application.h"
#include "Global.h"
#include "ButtonFunctions.h"
#include "SelectionBox.h"


Application::Application() {
	this->setImmediateDrawMode(false);
	createHUD();
}

Application::~Application() {}

void Application::onCreate() {
	EasyGraphics::onCreate();
	::SetWindowText(getHWND(), L"OOPaint");
	selectionBox = new SelectionBox(Rect{0,0,0,0});
}

void Application::onDestroy()
{
	for (Component* shp : Canvas) {
		shp->onDelete();
		delete shp;
	}
	for (Component* comp : HUD) {
		delete comp;
	}
	delete currentShape;
	delete selectionBox;
	removeProp();
	EasyGraphics::onDestroy();
}

void Application::createHUD() {
	for (int i = 0; i < 13; i++) {
		int size = 60;
		Rect r = { (i * (size + 1)) + 1,1,size,size };
		Button* btn = nullptr;

		switch (i) {
		case PENCIL: btn = new Button(r, L"imgs/imgPencilButton.bmp", &PencilClick); break;
		case LINE: btn = new Button(r, L"imgs/imgLineButton.bmp", &LineClick); break;
		case RECTANGLE:	btn = new Button(r, L"imgs/imgRectangleButton.bmp", &RectangleClick);	break;
		case CIRCLE: btn = new Button(r, L"imgs/imgCircleButton.bmp", &CircleClick); break;
		case COLOUR: btn = new Button(r, L"imgs/imgColourButton.bmp", &ColourClick, true); break;
		case FILL: btn = new Button(r, L"imgs/imgFillButton.bmp", &FillClick); break;
		case ERASER: btn = new Button(r, L"imgs/imgEraserButton.bmp", &EraserClick); break;
		case TRANSFORM: btn = new Button(r, L"imgs/imgTransformButton.bmp", &TransformClick); break;
		case IMPORTIMAGE: btn = new Button(r, L"imgs/imgImportButton.bmp", &ImportImageClick, true); break;
		case EXPORTIMAGE: btn = new Button(r, L"imgs/imgExportButton.bmp", &ExportImageClick, true); break;
		case SAVE: btn = new Button(r, L"imgs/imgSaveButton.bmp", &SaveClick, true); break;
		case LOAD: btn = new Button(r, L"imgs/imgLoadButton.bmp", &LoadClick, true); break;
		case HELP: btn = new Button(r, L"imgs/imgHelpButton.bmp", &HelpClick, true); break;
		default: break;
		}
		if (btn) {
			btn->setButtonType((ButtonType)i);
			HUD.push_back(btn);
		}
	}
}

void Application::onDraw() {
	this->clrscr(clWhite);
	for (Component* shp : Canvas) 
		shp->draw(this);
	for (Component* comp : HUD) 
		comp->draw(this);
	if(currentShape)
		selectionBox->draw(this);
	EasyGraphics::onDraw();
}


void Application::onLButtonDown(UINT nFlags, int x, int y) {
	p->setMousePos(x, y);
	if (y > 60) {
		Shape* shp = dynamic_cast<Shape*>(findObjFromClick(x, y));

		if (p->hasAction()) {
			shp = p->runAction(shp);
			if (shp) {
				Rect r = { x,y,0,0 };
				switch (shp->getStatus()) {
				case NEW:
					shp->setRect(r);
					Canvas.push_back(shp);
					break;
				case REMOVE:
					Canvas.remove(shp);
					delete shp;
					shp = nullptr;
					break;
				default:
					break;
				}
				
			}
		}
		currentShape = shp;
	}
	else {
		for (it = HUD.begin(); it != HUD.end(); it++) {
			if ((*it)->hitTest(x, y)) {
				if (Button* button = dynamic_cast<Button*>(*it)) {
					if (button != getSelectedButton()) {
						resetButtons();
					}
					button->onClick(x,y);
				}
			}
		}
	}
	onDraw();

}

void Application::onLButtonUp(UINT nFlags, int x, int y)
{
	if(currentShape)
		currentShape = nullptr;
}

void Application::onMouseMove(UINT nFlags, int x, int y)
{
	if (currentShape) {
		switch (currentShape->getStatus()) {
		case NEW:
			if (ShapePencil* shp = dynamic_cast<ShapePencil*>(currentShape)) {
				shp->addPoint(x, y);
			}
			else {
				currentShape->updateShape(x,y);
			}
			break;
		case MOVE:
			Point old = p->getMousePos();
			currentShape->movePos(x - old.x, y - old.y);
			break;
		}
		
		dynamic_cast<SelectionBox*>(selectionBox)->update(currentShape);
		onDraw();
		p->setMousePos(x, y);
	}
}


void Application::onRButtonDown(UINT nFlags, int x, int y)
{
	for (it = HUD.begin(); it != HUD.end(); it++) {
		if ((*it)->hitTest(x, y)) {
			if (Button* button = dynamic_cast<Button*>(*it)) {
				if (button->getButtonType() == COLOUR) {
					if (button != getSelectedButton()) {
						resetButtons();
					}
					button->setClickAction(&ColourRClick);
					button->onClick(x, y);
					button->setClickAction(&ColourClick);
					onDraw();
				}
			}
		}
	}
}



Button* Application::getSelectedButton() {
	std::list<Component*>::iterator select;
	for (select = HUD.begin(); select != HUD.end(); select++)
		if (Button* object = dynamic_cast<Button*>(*select))
			if (object->isSelected())
				return object;
	return nullptr;
}


void Application::resetButtons() {
	std::list<Component*>::iterator reset;
	for (reset = HUD.begin(); reset != HUD.end(); reset++)
		if (Button* object = dynamic_cast<Button*>(*reset))
			object->reset();
}

Component* Application::findObjFromClick(int x, int y) {
	std::list<Component*>::iterator shpit;
	Component* c = nullptr;
	for (shpit = Canvas.begin(); shpit != Canvas.end(); shpit++) {
		if ((*shpit)->hitTest(x, y)) {
			c = (*shpit);
		}
	}
	return c;
}