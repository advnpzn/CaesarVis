#pragma once

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Caesar
{
private:
    sf::Texture initTexture;
    sf::Texture finalTexture;
    sf::Image image;
    sf::Font font;
    int shift;
    

public:

    sf::Text title;
    sf::Text before;
    sf::Text after;
    sf::Text hotkeys;
    sf::Text shiftText;

    sf::Sprite initial;
    sf::Sprite final;

    Caesar(std::string, sf::Vector2f);
    void encrypt();
    void shiftChange(bool);
    sf::Color setPixelColor(sf::Color);
};