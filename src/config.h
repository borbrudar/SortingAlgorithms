#pragma once
//settings, color schemes etc
#include <SFML/Graphics.hpp>
#include <vector>

const int SCR_WIDTH = 1080, SCR_HEIGHT = SCR_WIDTH / 16 * 9;
const int maxVectorSize = 1000,minVectorSize = 50; // #of elements in vector
const double maxLengthPercentage = 0.9; // how much of the screen the biggest element takes up
const int dStep = 5,dSize = 50,fontSize = 16; // user control
const std::vector<std::string> names = {"Bubble","Selection", "Insertion","Cycle", "Merge","Quick"}; // algos used
const int colSize = 40; // #of colored blocks
const std::string stylesDir = "styles/";

// styles, controlled with a config file, this is a fallback
static std::string syleName = "Default";
static std::string usedFont = "fonts/ColabMed.otf"; // font used for everything

static sf::Color arrayCol(255,255,255); // regular array color
static sf::Color highlightCol(20,255,20); // last element swapped
static sf::Color fadeCol(255,255,255); // color of the fade
static int fade[] = {1,0,0}; // 1 - doesnt fade, 0 -fades

static sf::Color backgroundCol(64,64,64); 
static double outlineThickness = 1.5f; // applies to all outlines

static sf::Color outlineColor(0,0,0); 
static sf::Color fontInner(255,255,255); // inner color of the text
static sf::Color buttonColor(128,128,128);

