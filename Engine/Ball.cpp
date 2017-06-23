#include "Ball.h"

void Ball::Move(MainWindow& wnd, float dTime)
{
	BordersCollisionTest(dTime);
	BallControl(wnd);
}

void Ball::Draw(Graphics& gfx) const
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			gfx.PutPixel(int(x) + j - 5, int(y) + i - 5, Colors::Green);
		}
	}
}

void Ball::BordersCollisionTest(float dTime)
{
	if (!IsCollidingBorder('x'))
	{
		x += dx * dTime;
	}
	else
	{
		dx = -dx;
	}

	if (!IsCollidingBorder('y'))
	{
		y += dy * dTime;
	}
	else
	{
		dy = -dy;
	}
}

void Ball::InvertSpeed()
{
	dx = -dx;
	dy = -dy;
}

int Ball::GetX() const
{
	return int(x);
}

int Ball::GetY() const
{
	return int(y);
}

void Ball::BallControl(MainWindow& wnd)
{
	if (wnd.mouse.LeftIsPressed())
	{
		dx = 0;
		dy = 0;
	}

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		dy = (dy > -speedLimit) ? dy - speedChangeStep : dy;
	}
	else if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		dy = (dy < speedLimit) ? dy + speedChangeStep : dy;
	}
	else if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		dx = (dx > -speedLimit) ? dx - speedChangeStep : dx;
	}
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		dx = (dx < speedLimit) ? dx + speedChangeStep : dx;
	}
}

bool Ball::IsCollidingBorder(const char axis) const
{
	if (axis == 'x')
	{
		return !((x >= 20 && x <= Graphics::ScreenWidth - 20)
			|| (x < 20 && dx >= 0)
			|| (x > Graphics::ScreenWidth - 20 && dx <= 0));
	}
	else if (axis == 'y')
	{
		return !((y >= 20 && y <= Graphics::ScreenHeight - 20)
			|| (y < 20 && dy >= 0)
			|| (y > Graphics::ScreenHeight - 20 && dy <= 0));
	}
	return false;
}