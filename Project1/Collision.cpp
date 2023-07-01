#include "Collision.h"
using namespace sf;
using namespace std;
//klasa generyczna
template <class T1, class T2> bool Collision::isintersecting(T1& A, T2& B)
{
    return A.right() >= B.left() && A.left() <= B.right()
        && A.bottom() <= B.top() && A.top() >= B.bottom();
}
bool Collision::collisionTest(Paddle& paddle, Ball& ball)
{
    if (!isintersecting(paddle, ball)) return false;

    if (ball.velocity.x != 0 && ball.velocity.y != 0)
    {
        ball.moveUp();
        if (ball.getPosition().x > paddle.getPosition().x)
        {
            ball.moveLeft();
        }
        else if (ball.getPosition().x < paddle.getPosition().x)
        {
            ball.moveRight();
        }
    }
    else
    {
        if (Keyboard::isKeyPressed(Keyboard::Key::Up))
        {
            ball.velocity.x = ball.ballVelocity;
            ball.velocity.y = ball.ballVelocity;
        }
    }
}
bool Collision::collisionTest(Block& block, Ball& ball)
{
    if (!isintersecting(block, ball)) return false;
    block.destroy();
    float overLapLeft = ball.right() - block.left();
    float overLapRight = block.right() - ball.left();
    float overLapTop = ball.bottom() - block.top();
    float overLapBottom = block.bottom() - ball.top();

    bool ballFrameLeft(abs(overLapLeft) > abs(overLapRight));
    bool ballFrameTop(abs(overLapTop) > abs(overLapBottom));

    float minOverLapX{ ballFrameLeft ? overLapLeft : overLapRight };
    float minOverLapY{ ballFrameTop ? overLapTop : overLapBottom };

    if (abs(minOverLapX) < abs(minOverLapY))
    {
        ballFrameLeft ? ball.moveLeft() : ball.moveRight();
    }
    else
    {
        ballFrameTop ? ball.moveUp() : ball.moveDown();
    }
}