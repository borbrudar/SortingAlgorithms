#include "AlgoDraw.h"

void AlgoDraw::draw(RenderWindow &window){
    for(int i = 0;i < vec.size();i++){
        block.setSize(Vector2f(unitWidth,unitLength * vec[i]));
        block.setPosition(Vector2f(i * unitWidth,SCR_HEIGHT - block.getSize().y));

        int color = -1;
        for(int j = 0; j < colorInd.size();j++) if(colorInd[j] == i) color = j;

        if(color != -1){
            if(color == colorInd.size()-1) block.setFillColor(conf->getHighlightCol());
            else {
                double mult = (double) colorInd.size()/ (color+1);
                block.setFillColor(Color(conf->getFadeCol().r * (conf->getFade()[0]? 1 : mult),
                conf->getFadeCol().g * (conf->getFade()[1] ? 1: mult),conf->getFadeCol().b * (conf->getFade()[2] ? 1 : mult)));  
            }
        }else block.setFillColor(conf->getArrayCol());

        window.draw(block);
        if(color != -1) block.setFillColor(conf->getArrayCol());
    }
}

void AlgoDraw::setup(std::vector<int> &&vec, std::vector<std::pair<int,int>> &&swaps)
{
    conf = config::get();
    colorInd.clear();
    this->vec.clear(),this->swaps.clear();
    this->vec = std::move(vec);
    this->swaps = std::move(swaps);
    swapPos = 0;
    unitLength = (double)SCR_HEIGHT / this->vec.size() * maxLengthPercentage; 
    unitWidth = (double)SCR_WIDTH / this->vec.size();
    block.setFillColor(conf->getArrayCol());
}

void AlgoDraw::update()
{
    if(swapPos < swaps.size()){
        vec[swaps[swapPos].first] = swaps[swapPos].second;
        colorInd.push_back(swaps[swapPos].first);
        if(colorInd.size() > colSize) colorInd.pop_front();
        swapPos++;
    }else if(colorInd.size()) colorInd.pop_front();
}
