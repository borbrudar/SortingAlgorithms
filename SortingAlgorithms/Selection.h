#pragma once
#include "SortingAlgorithm.h"

class Selection : public SortingAlgorithm {
public:
	Selection() {
		algorithmName = "Selection";
	}
	void sortArray();
private:
	void parseThroughArray();
	void updateIterator();

	long currentMinimum = 1000000;
	long currentLowestIndex = -1;
	int iterator = 0;
	int checkArrayFrom = 0;
	bool isParsing = 1;
};