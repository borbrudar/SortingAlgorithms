#include "Button.h"

void Button::init(Vector2f pos, Vector2f size, std::string buttonMessage)
{
    buttonRect.setPosition(pos);
    buttonRect.setSize(size);
    buttonRect.setFillColor(Color(128, 128, 128));
    buttonRect.setOutlineColor(Color::Black);
    buttonRect.setOutlineThickness(1.f);
 
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
