#pragma once
#include <iostream>
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
class Collision
{
public:
    template <class T1, class T2> bool isintersecting(T1& A, T2& B);
    //polimorfizm
    bool collisionTest(Paddle& paddle, Ball& ball);
    bool collisionTest(Block& block, Ball& ball);
};


