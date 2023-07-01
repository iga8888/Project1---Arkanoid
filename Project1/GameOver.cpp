
#include "GameOver.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Clock.hpp>
using namespace std;
using namespace sf;
void GameOver::win(sf::RenderWindow& window, sf::RenderWindow& window1, sf::Event& event)
{
    while (!Keyboard::isKeyPressed(Keyboard::Key::Enter) && !(event.type == Event::Closed))
    {
        window.close();
        window1.clear(Color::Red);
        window1.pollEvent(event);
        auto texture = std::make_unique<sf::Texture>();
        string wyjatek = "Failed to load a picture";
        try
        {
            if (!texture->loadFromFile("win.jpg"))
            {
                throw wyjatek;
            }
            sf::Sprite sprite;
            sprite.setTexture(*texture);
            sprite.setScale(2.1, 2.5);
            sprite.setPosition(-20, 0);
            window1.draw(sprite);
            window1.display();
        }
        catch (string arg)
        {
            cout << wyjatek << endl;
        }
        catch (...)
        {

        }
    }
}
void GameOver::lose(sf::RenderWindow& window, sf::RenderWindow& window1, sf::Event& event)
{
    while (!Keyboard::isKeyPressed(Keyboard::Key::Enter) && !(event.type == Event::Closed))
    {
        window.close();
        window1.clear(Color::Red);
        window1.pollEvent(event);
        auto texture = std::make_unique<sf::Texture>();
        string wyjatek = "Failed to load a picture";
        try
        {
            if (!texture->loadFromFile("gameover.jpg"))
            {
                throw wyjatek;
            }
            sf::Sprite sprite;
            sprite.setTexture(*texture);
            sprite.setScale(1.5, 1.5);
            sprite.setPosition(-20, 0);
            window1.draw(sprite);
            window1.display();
        }
        catch (string arg)
        {
            cout << "Nastapil wyjatek: " << wyjatek << endl;
            break;
        }
        catch (...)
        {

        }
    }
}