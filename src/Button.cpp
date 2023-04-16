#include "Button.h"

void Button::init(Vector2f pos, Vector2f size, std::string buttonMessage)
{
    conf = config::get();
    buttonRect.setPosition(pos);
    buttonRect.setSize(size);
    setStyle();

    buttonText.setMessage(buttonMessage);
    buttonText.setPosition(Vector2f(pos.x + 5,pos.y));
}

void Button::drawButton(RenderWindow& window)
{
    window.draw(buttonRect);
    buttonText.drawString(window);
}

bool Button::isPressed(RenderWindow& window,Mouse mouse, Event event)
{
    if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left &&
        buttonRect.getGlobalBounds().contains(Vector2f(mouse.getPosition(window))))
        return true;
    return false;
}

void Button::setStyle(){
    buttonRect.setFillColor(conf->getButtonCol());
    buttonRect.setOutlineColor(conf->getOutlineCol());
    buttonRect.setOutlineThickness(conf->getOutlineThickness());
}