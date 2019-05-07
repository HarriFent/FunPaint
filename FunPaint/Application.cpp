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
	selectionBox = new SelectionBox(Rect{ 0,0,0,0 });
}

void Application::onDestroy()
{
	for (Component* comp : HUD) {
		delete comp;
	}
	if (selectionBox) {
		delete selectionBox;
	}
	removeProp();
	EasyGraphics::onDestroy();
}

void Application::createHUD() {
	for (int i = 0; i < 12; i++) {
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
		case PICKER: btn = new Button(r, L"imgs/imgPickerButton.bmp", &PickerClick); break;
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
	p->drawCanvas(this);
	for (Component* comp : HUD)
		comp->draw(this);
	if (currentShape)
		selectionBox->draw(this);
	EasyGraphics::onDraw();
}


void Application::onLButtonDown(UINT nFlags, int x, int y) {
	p->setMousePos(x, y);
	if (y > 60 && p->getActive()) {
		if (!selectionBox->hitTest(x, y))
			currentShape = nullptr;
		if (selectionBox && currentShape) {
			currentShape = p->runAction(currentShape);
			selectionBox->update(currentShape);
			selectionBox->onClick(x, y);
		}
		else {
			Shape* shp = dynamic_cast<Shape*>(findObjFromClick(x, y));

			if (p->hasAction()) {
				shp = p->runAction(shp);
			}
			currentShape = shp;
			selectionBox->update(currentShape);
		}
	}
	else {
		if (p->getActive()) {
			for (it = HUD.begin(); it != HUD.end(); it++) {
				if ((*it)->hitTest(x, y)) {
					if (Button * button = dynamic_cast<Button*>(*it)) {
						if (button != getSelectedButton()) {
							resetButtons();
						}
						button->onClick(x, y);
					}
				}
			}
		}
	}
	onDraw();
}

void Application::onLButtonUp(UINT nFlags, int x, int y)
{
	if (currentShape && p->getActive())
		switch (currentShape->getStatus()) {
		case NEW:
			if (ShapeLine * shp = dynamic_cast<ShapeLine*>(currentShape)) {}
			else {
				currentShape->setRect(currentShape->getResetRect());
			}
			currentShape = nullptr;
			break;
		case MOVE:
		case SCALE:
			currentShape->setStatus(DEFAULT);
			break;
		default:
			currentShape = nullptr;
		}
}

void Application::onMouseMove(UINT nFlags, int x, int y)
{
	if (currentShape && p->getActive()) {
		Point old = p->getMousePos();
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
			currentShape->movePos(x - old.x, y - old.y);
			break;
		case SCALE:
			if (ShapePencil * shp = dynamic_cast<ShapePencil*>(currentShape)) {}
			else {
				currentShape->scale(x - old.x, y - old.y, selectionBox->getPosition());
			}
			break;
		}
		
		selectionBox->update(currentShape);
		onDraw();
		p->setMousePos(x, y);
	}
}


void Application::onRButtonDown(UINT nFlags, int x, int y)
{
	if (p->getActive()) {
		for (it = HUD.begin(); it != HUD.end(); it++) {
			if ((*it)->hitTest(x, y)) {
				if (Button * button = dynamic_cast<Button*>(*it)) {
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
}



Button* Application::getSelectedButton() {
	std::vector<Component*>::iterator select;
	for (select = HUD.begin(); select != HUD.end(); select++)
		if (Button* object = dynamic_cast<Button*>(*select))
			if (object->isSelected())
				return object;
	return nullptr;
}


void Application::resetButtons() {
	std::vector<Component*>::iterator reset;
	for (reset = HUD.begin(); reset != HUD.end(); reset++)
		if (Button* object = dynamic_cast<Button*>(*reset))
			object->reset();
}

Component* Application::findObjFromClick(int x, int y) {
	std::vector<Component*>::iterator shpit;
	Component* c = nullptr;
	for (shpit = p->getCanvasBegin(); shpit != p->getCanvasEnd(); shpit++) {
		if ((*shpit)->hitTest(x, y)) {
			c = (*shpit);
		}
	}
	return c;
}