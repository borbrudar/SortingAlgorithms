#include "AlgoDraw.h"

void AlgoDraw::draw(RenderWindow &window){
    for(int i = 0;i < vec.size();i++){
        block.setSize(Vector2f(unitWidth,unitLength * vec[i]));
        block.setPosition(Vector2f(i * unitWidth,SCR_HEIGHT - block.getSize().y));
        window.draw(block);
    }
}

void AlgoDraw::setup(std::vector<int> &&vec, std::vector<std::pair<int,int>> &&swaps)
{
    this->vec = std::move(vec);
    this->swaps = std::move(swaps);
    swapPos = 0;
    unitLength = (double)SCR_HEIGHT / this->vec.size() * maxLengthPercentage; 
    unitWidth = (double)SCR_WIDTH / this->vec.size();
    block.setFillColor(Color(255,255,255));
}

void AlgoDraw::update()
{
    if(swapPos < swaps.size()){
        vec[swaps[swapPos].first] = swaps[swapPos].second;
        swapPos++;
    }
}
