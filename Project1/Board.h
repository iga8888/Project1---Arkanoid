#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Board
{
public:
	unsigned int window_size_x;
	unsigned int window_size_y;
	Board();
	~Board() = default;
	Board(unsigned int x, unsigned int y);
};



