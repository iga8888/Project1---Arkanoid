#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Clock.hpp>
#include <windows.h>
class GameOver
{
public:
	void win(sf::RenderWindow& window, sf::RenderWindow& window1, sf::Event& event);
	void lose(sf::RenderWindow& window, sf::RenderWindow& window1, sf::Event& event);
};


