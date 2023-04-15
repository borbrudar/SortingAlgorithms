#pragma once
//settings, color schemes etc

const int SCR_WIDTH = 1080, SCR_HEIGHT = SCR_WIDTH / 16 * 9;
const int vectorSize = 100,maxVectorSize = 1000,minVectorSize = 50; // #of elements in vector
const double maxLengthPercentage = 0.9; // how much of the screen the biggest element takes up
const int delay = 0; // delay in ms

const std::vector<std::string> names = {"Bubble","Selection", "Insertion","Cycle", "Merge","Quick"};