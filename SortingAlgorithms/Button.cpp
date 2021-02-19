#include "Button.h"

void Button::init(Vector2f pos, Vector2f size, std::string buttonMessage)
{
    buttonRect.setPosition(pos);
    buttonRect.setSize(size);
    buttonRect.setFillColor(Color(128, 128, 128));
    buttonRect.setOutlineColor(Color::Black);
    buttonRect.setOutlineThickness(1.f);
    
    arial.loadFromFile("font/arial.ttf");

    buttonText.setFont(arial);
    buttonText.setCharacterSize(16);
    buttonText.setFillColor(Color::White);
    buttonText.setOutlineColor(Color::Black);
    buttonText.setOutlineThickness(1.5f);
    buttonText.setString(buttonMessage);

    buttonText.setPosition(Vector2f(pos.x + size.x / 20, pos.y + size.y / 20));
}

void Button::drawButton(RenderWindow& window)
{
    window.draw(buttonRect);
    window.draw(buttonText);
}

bool Button::isPressed(RenderWindow& window,Mouse mouse)
{
    Vector2i mousePos = mouse.getPosition(window);

    //check if mouse is pressing the button AABB collision
    if (mouse.isButtonPressed(Mouse::Left) &&
        mousePos.x > buttonRect.getGlobalBounds().left &&
        mousePos.x < (buttonRect.getGlobalBounds().left + buttonRect.getGlobalBounds().width) &&
        mousePos.y > buttonRect.getGlobalBounds().top &&
        mousePos.y < (buttonRect.getGlobalBounds().top + buttonRect.getGlobalBounds().height)) 
        return true;
    return false;
}
