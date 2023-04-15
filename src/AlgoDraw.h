#pragma once
#include <SFML/Graphics.hpp>
#include "config.h"

using namespace sf;

class AlgoDraw{
public:
    void draw(RenderWindow &window);
    void setup(std::vector<int> &&vec,std::vector<std::pair<int,int>> &&swaps);
    void update();
private:
    std::vector<int> vec;
    std::vector<std::pair<int,int>> swaps;
    int swapPos=0;
    double unitWidth,unitLength=0;
    RectangleShape block;
};



