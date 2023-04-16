#pragma once
//settings, color schemes etc
#include <SFML/Graphics.hpp>
#include <vector>

const int SCR_WIDTH = 1080, SCR_HEIGHT = SCR_WIDTH / 16 * 9;
const int maxVectorSize = 1000,minVectorSize = 50; // #of elements in vector
const double maxLengthPercentage = 0.9; // how much of the screen the biggest element takes up

const std::vector<std::string> names = {"Bubble","Selection", "Insertion","Cycle", "Merge","Quick"};

const int colSize = 40;
const std::string usedFont = "font/ColabMed.otf";

const sf::Color arrayCol(255,255,255);
const sf::Color highlightCol(20,255,20);
const sf::Color fadeCol(255,255,255);

const int fade[] = {1,0,0}; // 1 - doesnt fade, 0 -fades

const sf::Color backgroundCol(64,64,64);

const int dStep = 5,dSize = 50,fontSize = 16;
const double outlineThickness = 1.5f;
const sf::Color outlineColor(0,0,0);
const sf::Color fontInner(255,255,255);
const sf::Color buttonColor(128,128,128);

