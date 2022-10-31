#include "caesar.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Provide location to the image." << std::endl;
        return 0;
    }

    std::string loc = argv[1];

    sf::RenderWindow window(sf::VideoMode(800, 500), L"CaesarPic", sf::Style::Close);


    Caesar caesar(loc, sf::Vector2f(window.getSize().x, window.getSize().y));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::F5)
                {
                    caesar.encrypt();
                }
                else if (event.key.code == sf::Keyboard::Right)
                {
                    caesar.shiftChange(true);
                }
                else if (event.key.code == sf::Keyboard::Left)
                {
                    caesar.shiftChange(false);
                }
                

            default:
                break;
            }
        }

        window.clear();

        window.draw(caesar.after);
        window.draw(caesar.before);
        window.draw(caesar.title);
        window.draw(caesar.hotkeys);
        window.draw(caesar.initial);
        window.draw(caesar.final);
        window.draw(caesar.shiftText);

        window.display();
    }
}