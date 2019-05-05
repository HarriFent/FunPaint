#include <Windows.h>
#include "Application.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int show) {

#ifdef _DEBUG
	_CrtSetBreakAlloc(166);
	_onexit(_CrtDumpMemoryLeaks);
#endif

	Application app;
	app.create(hInstance, 900, 600, 40, true);
	return 0;
}

