#include "Properties.h"
#include <cstdlib> 

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
}

Properties* Properties::prop = nullptr;