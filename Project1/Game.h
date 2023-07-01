#pragma once

#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Clock.hpp>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Ball.h"
#include "Paddle.h"
#include "Block.h"
#include "Board.h"
#include "Game.h"
#include <windows.h>
#include "Collision.h"
#include "GameOver.h"
#include "MENU.h"
using namespace sf;
using namespace std;
//Jedna glowna klasa gry
//Dziedziczenie
class Game : public GameOver, public MENU
{
public:
	void run(int n);
};


