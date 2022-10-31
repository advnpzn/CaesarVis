#include "caesar.hpp"

Caesar::Caesar(std::string loc, sf::Vector2f coords)
{

    shift = 1;

    if (!font.loadFromFile("raleway-m.ttf"))
    {
        std::cout << "Error loading font :(\n";
    }

    title.setString("Caesar Cipher");
    title.setPosition(sf::Vector2f(coords.x / 2 - 100.f, 10.f));
    title.setFont(font);

    shiftText.setString("Shift = " + std::to_string(shift));
    shiftText.setPosition(sf::Vector2f(coords.x / 2 - 50.f, coords.y - 50.f));
    shiftText.setFont(font);

    before.setString("Before");
    before.setPosition(sf::Vector2f(coords.x / 4 - 50.f, coords.y - 100.f));
    before.setFont(font);

    after.setString("After");
    after.setPosition(sf::Vector2f(3 * (coords.x/4), coords.y - 100.f));
    after.setFont(font);

    hotkeys.setString("F5 - Run");
    hotkeys.setPosition(sf::Vector2f(coords.x / 2 - 50.f, coords.y - 100.f));
    hotkeys.setFont(font);



    if (!initTexture.loadFromFile(loc))
    {
        std::cout << "Error loading texture :(\n";
    }
    if (!finalTexture.loadFromFile(loc))
    {
        std::cout << "Error loading texture :(\n";
    }

    initial.setTexture(initTexture);
    initial.setPosition(sf::Vector2f(90.f, 100.f));
    initial.setScale(sf::Vector2f(0.5f, 0.5f));

    final.setPosition(sf::Vector2f(coords.x/2 + 100.f, 100.f));
    final.setScale(sf::Vector2f(0.5f, 0.5f));

    image = finalTexture.copyToImage();

}

void Caesar::encrypt()
{
    int width = image.getSize().x;
    int height = image.getSize().y;
    //std::cout << "Image size px = " << width << ", " << height << "\n";


    for (int i = 0; i <= width; i++)
    {
        for (int j = 0; j <= height; j++)
        {
            sf::Color imgColor = image.getPixel(i, j);
            //std::cout << "Before\n(RGBA) = (" << int(imgColor.r) << ", " << int(imgColor.g) << ", " << int(imgColor.b) << ", " << int(imgColor.a) << ")\n";
            image.setPixel(i, j, setPixelColor(imgColor));
        }
    }

    finalTexture.loadFromImage(image);
    final.setTexture(finalTexture);

}

sf::Color Caesar::setPixelColor(sf::Color color)
{

    color.r = (int(color.r) + shift) % 255;
    color.g = (int(color.g) + shift) % 255;
    color.b = (int(color.b) + shift) % 255;
    color.a = (color.a + shift) % 255;
    //std::cout << "After\n(RGBA) = (" << int(color.r) << ", " << int(color.g) << ", " << int(color.b) << ", " << int(color.a) << ")\n";
    

    return color;
}

void Caesar::shiftChange(bool right)
{
    if (right == true)
    {
        shift += 1;
    }
    else
    {
        if (shift == 0)
        {
            shift = 0;
        }
        else
        {
            shift -=1;
        }
    }
    //std::cout << shift << "\n";
    shiftText.setString("Shift = " + std::to_string(shift));
}