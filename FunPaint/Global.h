#pragma once
#define _CRTDBG_MAP_ALLOC

#include<iostream>

#include <crtdbg.h>

#ifdef _DEBUG

#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)

#define new DEBUG_NEW

#endif


int getColourDialog(int col);

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
	IMPORTIMAGE,
	EXPORTIMAGE,
	SAVE,
	LOAD,
	HELP,
	NONE
};

enum ShapeStatus {
	DEFAULT,
	NEW,
	REMOVE,
	MOVE,
	SCALE
};
