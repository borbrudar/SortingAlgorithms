#include "Quick.h"

void Quick::sortArray(std::vector<int>& vec)
{
	
	if (!isInit) {
		quick.init(temp);
		isInit = true;
	}

	quick.sortTree();
	vec = quick.updateTree();
	//sortingSlowDown();
}
