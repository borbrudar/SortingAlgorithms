#pragma once
#include "SortingAlgorithm.h"

class Selection : public SortingAlgorithm {
public:
	Selection() {
		algorithmName = "Selection";
	}
	void sortArray(std::vector<int> &vec);
private:
	void parseThroughArray(std::vector<int>& vec);
	void updateIterator(std::vector<int>& vec);

	long currentMinimum = 1000000;
	long currentLowestIndex = -1;
	int iterator = 0;
	int checkArrayFrom = 0;
	bool isParsing = 1;
};