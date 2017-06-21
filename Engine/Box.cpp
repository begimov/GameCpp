#include "Box.h";
#include <assert.h>

void Box::Init(int inX, int inY)
{
	assert(initialized == false);
	x = inX;
	y = inY;
	initialized = true;
}

void Box::Draw(Graphics& gfx) const
{
	assert(initialized == true);

	if (isVisible)
	{
		for (int i = 0; i < 21; i++)
		{
			for (int j = 0; j < 21; j++)
			{
				gfx.PutPixel(x + j - 10, y + i - 10, Colors::Cyan);
			}
		}
	}
}

bool Box::isCollidingWithBall(int inX, int inY)
{
	assert(initialized == true);

	if (isVisible)
	{
		if (inX > x - 15 && inX < x + 15
			&& inY > y - 15 && inY < y + 15)
		{
			isVisible = false;
			return true;
		}
		return false;
	}
	return false;
}
