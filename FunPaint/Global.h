#pragma once
#define _CRTDBG_MAP_ALLOC

#include<iostream>

#include <crtdbg.h>

#ifdef _DEBUG

#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)

#define new DEBUG_NEW

#endif


int getColourDialog(int col);
std::wstring BrowseFolder(std::string saved_path);

const int PEN_WIDTH = 2;

struct Point { int x; int y; };

struct Rect {
	int x;
	int y;
	int w;
	int h;

	bool operator == (Rect const &obj) {
		if (x == obj.x && y == obj.y && w == obj.w && h == obj.h)
			return true;
		return false;
	}

	void operator += (int i) {
		x -= i;
		y -= i;
		w += i * 2;
		h += i * 2;
	}
	void transform(int dx, int dy) {
		x += dx;
		y += dy;
	}
	void scale(int dx, int dy) {
		x += dx;
		y += dy;
		w -= dx;
		h -= dy;
	}
};

enum CornerPos {
	TOP_RIGHT,
	BOTTOM_LEFT,
	TOP_LEFT,
	BOTTOM_RIGHT,
	NONE
};

enum ButtonType {
	PENCIL,
	LINE,
	RECTANGLE,
	CIRCLE,
	COLOUR,
	FILL,
	ERASER,
	TRANSFORM,
	PICKER,
	SAVE,
	LOAD,
	HELP,
	NOBUTTOM
};

enum ShapeStatus {
	DEFAULT,
	NEW,
	REMOVE,
	MOVE,
	SCALE,
	INVISIBLE
};

