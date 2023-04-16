#include "StyleLoader.h"
#include <fstream>
#include <sstream>
#include "config.h"

bool StyleLoader::loadStyle(std::string path){
    std::ifstream file(path);
    if(!file.is_open()) return 0;

    std::string cur;
    while(getline(file,cur)){
        std::stringstream ss(cur);
        std::string attribute,val;
        ss >> attribute >> cur >> val;

        modifyVal(attribute, val);
    }

    file.close();
    return 1;
}

void StyleLoader::modifyVal(const std::string &atr,std::string val){
    if(atr == "styleName") conf->setStyleName(val);
    else if(atr == "usedFont") conf->setUsedFont(val);
    else if(atr == "outlineThickness") conf->setOutlineThickness(std::stod(val));
    else if(atr == "fade") conf->setFade({val[0]-'0',val[2]-'0', val[4]-'0'});
    else {
        // color bash
        sf::Color col;
        std::string cur;
        for(int i = 0, cval = 0; i < val.size();i++){
            if(val[i] == ',') cval++,cur.clear();
            else {
                cur += val[i];
                if(cval == 0) col.r = std::stoi(cur);
                else if(cval == 1) col.g = std::stoi(cur);
                else col.b = std::stoi(cur);
            }
        }
        //bruteforce
        if(atr == "arrayCol")           conf->setArrayCol(col);
        else if(atr == "highlightCol")  conf->setHighlightCol(col);
        else if(atr == "fadeCol")       conf->setFadeCol(col);
        else if(atr == "backgroundCol") conf->setBackgroundCol(col);
        else if(atr == "outlineCol")    conf->setOutlineCol(col);
        else if(atr == "fontCol")       conf->setFontCol(col);
        else if(atr == "buttonCol")     conf->setButtonCol(col);
    }
}
  