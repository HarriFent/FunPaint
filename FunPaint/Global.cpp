#include "Global.h"
#include <Windows.h>

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