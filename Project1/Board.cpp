#include "Board.h"
Board::Board(unsigned int x, unsigned int y)
{
	window_size_x = x;
	window_size_y = y;
}
Board::Board()
{
	window_size_x = 1200;
	window_size_y = 800;
}

