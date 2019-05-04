#include <Windows.h>
#include "Application.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int show) {


	Application app;
	app.create(hInstance, 900, 600, 40, true);

	_CrtDumpMemoryLeaks();
	return 0;
}

