#include "Global.h"
#include <Windows.h>
#include <string>
#include <shlobj.h>
#include <iostream>
#include <sstream>

int getColourDialog(int col) {
	CHOOSECOLOR color;//the struct for the dialog
	COLORREF ccref[16];//custom colors

	memset(&color, 0, sizeof(color));
	color.lStructSize = sizeof(CHOOSECOLOR);
	//color.hwndOwner = this->getHWND();
	color.lpCustColors = ccref;
	color.rgbResult = col;
	color.Flags = CC_RGBINIT;

	if (ChooseColor(&color))
	{
		return color.rgbResult;
	}
	return 0;
};


static int CALLBACK BrowseCallbackProc(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData)
{

	if (uMsg == BFFM_INITIALIZED)
	{
		std::string tmp = (const char*)lpData;
		std::cout << "path: " << tmp << std::endl;
		SendMessage(hwnd, BFFM_SETSELECTION, TRUE, lpData);
	}

	return 0;
};

std::wstring BrowseFolder(std::string saved_path)
{
	TCHAR path[MAX_PATH];

	std::wstring wsaved_path(saved_path.begin(), saved_path.end());
	const wchar_t* path_param = wsaved_path.c_str();

	BROWSEINFO bi = { 0 };
	bi.lpszTitle = (L"Browse for img...");
	bi.ulFlags = BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE;
	bi.lpfn = BrowseCallbackProc;
	bi.lParam = (LPARAM)path_param;

	LPITEMIDLIST pidl = SHBrowseForFolder(&bi);

	if (pidl != 0)
	{
		//get the name of the folder and put it in path
		SHGetPathFromIDList(pidl, path);

		//free memory used
		IMalloc* imalloc = 0;
		if (SUCCEEDED(SHGetMalloc(&imalloc)))
		{
			imalloc->Free(pidl);
			imalloc->Release();
		}

		return path;
	}

	return L"";
};