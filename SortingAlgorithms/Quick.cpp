#include "Quick.h"
#include <iostream>
void Quick::sortArray(std::vector<int>& vec)
{
	
	if (!isInit) {
		quick.init(vec);
		isInit = true;
	}

	quick.sortTree();
	vec = quick.updateTree();
	updateColorArray(quick.color);
	sortingSlowDown();
}
