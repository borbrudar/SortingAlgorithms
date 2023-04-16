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


using namespace sf;
class config{
private:
    // styles, controlled with a config file, this is a fallback
    std::string styleName;
    std::string usedFont;
    std::vector<int> fade; 

    Color arrayCol;
    Color highlightCol;
    Color fadeCol;

    sf::Color backgroundCol;
    double outlineThickness; 

    sf::Color outlineCol;
    sf::Color fontCol; 
    sf::Color buttonCol; 


// singleton stuff
    static config* cptr;
    config() {
        styleName = "Default";
        usedFont = "fonts/ColabMed.otf"; // font used for everything
        fade = {1,0,0}; // 1- doesnt fade, 0 - fades

        arrayCol = Color(255,255,255);// regular array color
        highlightCol = Color(20,255,20); // last element swapped
        fadeCol = Color(255,255,255); // color of the fade

        backgroundCol = Color(64,64,64);
        outlineThickness = 1.5f; // applies to all outlines

        outlineCol= Color(0,0,0); 
        fontCol = Color(255,255,255); 
        buttonCol = Color(128,128,128);
    };
public:
    //delete constructors
    config(const config&obj) = delete;
    void operator=(const config&) = delete;

    static config* get();
//getters
    std::string getStyleName() {return styleName;};
    std::string getUsedFont(){return usedFont;}; 
    std::vector<int> getFade() {return fade;};

    Color getArrayCol(){ return arrayCol;}; 
    Color getHighlightCol() {return highlightCol;};
    Color getFadeCol() {return fadeCol;};

    Color getBackgroundCol(){return backgroundCol;};
    double getOutlineThickness() {return outlineThickness;};

    Color getOutlineCol(){return outlineCol;};
    Color getFontCol(){ return fontCol;};
    Color getButtonCol() { return buttonCol;};

//setters
    void setStyleName(std::string s) {styleName = s;};
    void setUsedFont(std::string s){usedFont = s;}; 
    void setFade(std::vector<int> s) {fade = s;};

    void setArrayCol(Color s){ arrayCol = s;}; 
    void setHighlightCol(Color s) { highlightCol = s;};
    void setFadeCol(Color s) { fadeCol = s;};

    void setBackgroundCol(Color s){ backgroundCol = s;};
    void setOutlineThickness(double s) { outlineThickness = s;};

    void setOutlineCol(Color s){outlineCol = s;};
    void setFontCol(Color s){ fontCol = s;};
    void setButtonCol(Color s) { buttonCol = s;};

};
