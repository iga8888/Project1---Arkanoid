#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Block : public Drawable
{
public:
	Block() = delete;
	~Block() = default;
	Block(float t_X, float t_Y, float t_Width, float t_Height);
	void update();
	Vector2f getPosition();
	float left();
	float right();
	float top();
	float bottom();
	bool isDistroyed();
	void destroy();
	Vector2f getSize();
	void moveDown();
private:
	virtual void draw(RenderTarget& target, RenderStates state) const override;
	RectangleShape shape;
	bool destroyed = false;

};


