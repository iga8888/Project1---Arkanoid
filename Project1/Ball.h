#pragma once
#include "Board.h"
#include "Ball.h"
//Dziedziczenie z klas w SFML
class Ball : public Drawable, public Board
{
public:
	Ball(float t_x, float t_y);
	Ball() = delete;
	~Ball() = default;
	void change_lifeisgood();
	bool get_lifeisgood();
	void update();
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	Vector2f getPosition();
	float left();
	float right();
	float top();
	float bottom();
	const float ballVelocity = 3.0f;
	Vector2f velocity{ ballVelocity, ballVelocity };
private:
	bool lifeisgood;
	CircleShape shape;
	const float ballRadius = 10.0f;
	void draw(RenderTarget& target, RenderStates state) const override;
};


