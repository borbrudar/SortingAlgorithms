#pragma once
#include <string>
#include "config.h"

class StyleLoader{
public:
    StyleLoader() { conf = config::get();};
    bool loadStyle(std::string path);
private:
    void modifyVal(const std::string &atr, std::string val);
    config * conf;
};