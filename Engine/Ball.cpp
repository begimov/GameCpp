#include "Ball.h"

void Ball::Move(MainWindow& wnd)
{
	BordersCollisionTest();
	BallControl(wnd);
}

void Ball::Draw(Graphics& gfx) const
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			gfx.PutPixel(x + j - 5, y + i - 5, Colors::Green);
		}
	}
}

void Ball::BordersCollisionTest()
{
	if (!IsCollidingBorder('x'))
	{
		x += dx;
	}
	else
	{
		dx = -dx;
	}

	if (!IsCollidingBorder('y'))
	{
		y += dy;
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
	return x;
}

int Ball::GetY() const
{
	return y;
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
		dy = (dy > -speedLimit) ? dy - 1 : dy;
	}
	else if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		dy = (dy < speedLimit) ? dy + 1 : dy;
	}
	else if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		dx = (dx > -speedLimit) ? dx - 1 : dx;
	}
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		dx = (dx < speedLimit) ? dx + 1 : dx;
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