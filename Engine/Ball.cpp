#include "Ball.h";
#include "Graphics.h"

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

bool Ball::IsCollidingBorder(char axis) {
	if (axis == 'x')
	{
		return !((x >= 20 && x <= Graphics::ScreenWidth - 20)
			|| (x < 20 && dx >= 0)
			|| (x > Graphics::ScreenWidth - 20 && dx <= 0));
	}
	else if (axis = 'y')
	{
		return !((y >= 20 && y <= Graphics::ScreenHeight - 20)
			|| (y < 20 && dy >= 0)
			|| (y > Graphics::ScreenHeight - 20 && dy <= 0));
	}
}