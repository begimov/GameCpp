#include "Block.h";
#include <assert.h>

void Block::Init(int inX, int inY)
{
	assert(initialized == false);
	x = inX;
	y = inY;
	initialized = true;
}

void Block::Draw(Graphics& gfx) const
{
	assert(initialized == true);

	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			gfx.PutPixel(x + j - 10, y + i - 10, Colors::Red);
		}
	}
}

bool Block::isCollidingWithBall(int inX, int inY)
{
	assert(initialized == true);

	if (inX > x - 15 && inX < x + 15
		&& inY > y - 15 && inY < y + 15)
	{
		return true;
	}
	return false;
}
