#include "AlgoDraw.h"

void AlgoDraw::draw(RenderWindow &window){
    for(int i = 0;i < vec.size();i++){
        block.setSize(Vector2f(unitWidth,unitLength * vec[i]));
        block.setPosition(Vector2f(i * unitWidth,SCR_HEIGHT - block.getSize().y));

        int color = -1;
        for(int j = 0; j < colorInd.size();j++) if(colorInd[j] == i) color = j;

        if(color != -1){
            if(color == colorInd.size()-1) block.setFillColor(Color::Green);
            else {
                double temp = (double) colorInd.size()/ (color+1) * 255;
                block.setFillColor(Color(255,temp,temp));  
            }
        }

        window.draw(block);
        if(color != -1) block.setFillColor(Color(255,255,255));
    }
}

void AlgoDraw::setup(std::vector<int> &&vec, std::vector<std::pair<int,int>> &&swaps)
{
    colorInd.clear();
    this->vec.clear(),this->swaps.clear();
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
        colorInd.push_back(swaps[swapPos].first);
        if(colorInd.size() > colSize) colorInd.pop_front();
        swapPos++;
    }else if(colorInd.size()) colorInd.pop_back();
}
