#include "Ball.h"
#include <iostream>
static int life = 3;
//Konstruktor
Ball::Ball(float t_x, float t_y)
{
	lifeisgood = true;
	shape.setPosition(t_x, t_y);
	shape.setRadius(this->ballRadius);
	shape.setFillColor(Color::White);
	shape.setOrigin(this->ballRadius, this->ballRadius);
}
void Ball::change_lifeisgood()
{
	if (lifeisgood)
	{
		lifeisgood = false;
	}
	else
	{
		lifeisgood = true;
	}
}
bool Ball::get_lifeisgood()
{
	return lifeisgood;
}
void Ball::draw(RenderTarget& target, RenderStates state) const 
{
	target.draw(this->shape, state);
}
void Ball::update()
{
	shape.move(this->velocity);
	if (this->left() < 0)
	{
		velocity.x = ballVelocity;
	}
	else if (this->right() > window_size_x) {
		velocity.x = -ballVelocity;
	}
	else if (this->top() > window_size_y) {
		life--;
		if (life > 0)
		{
			velocity.y = 0;
			velocity.x = 0;
			shape.setPosition(window_size_x / 2, window_size_y - 65);
		}
		else
		{
			velocity.y = 0;
			velocity.x = 0;
			shape.setPosition(window_size_x / 2, window_size_y / 2);
			change_lifeisgood();
			life = 3;
		}
	}
	else if (this->bottom() < 0) {
		velocity.y = ballVelocity;
	}
}
float Ball::left()
{
	return this->shape.getPosition().x - shape.getRadius();
}
float Ball::right()
{
	return this->shape.getPosition().x + shape.getRadius();
}
float Ball::top()
{
	return this->shape.getPosition().y + shape.getRadius();
}
float Ball::bottom()
{
	return this->shape.getPosition().y - shape.getRadius();
}

void Ball::moveDown()
{
	this->velocity.y = ballVelocity;
}
void Ball::moveUp()
{
	this->velocity.y = -ballVelocity;
}
void Ball::moveLeft()
{
	this->velocity.x = ballVelocity;
}
void Ball::moveRight()
{
	this->velocity.x = -ballVelocity;
}
Vector2f Ball::getPosition()
{
	return shape.getPosition();
}
