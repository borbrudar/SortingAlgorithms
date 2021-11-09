#include "Quick.h"
#include <iostream>
void Quick::sortArray()
{
	
	if (!isInit) {
		quick.init(vector);
		isInit = true;
	}

	quick.sortTree();
	vector = quick.updateTree();
	updateColorArray(quick.getColor());
}
