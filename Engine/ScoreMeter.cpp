#include "ScoreMeter.h"

void ScoreMeter::Draw(Graphics& gfx) const
{
	for (int i = 0; i < length; i++)
	{
		gfx.PutPixel(i, 10, Colors::Magenta);
	}
}

void ScoreMeter::Increment()
{
	int screenWidth = Graphics::ScreenWidth;
	if (length + screenWidth / maxScore < screenWidth)
	{
		length += screenWidth / maxScore;
	}
}

void ScoreMeter::Decrement()
{
	int screenWidth = Graphics::ScreenWidth;
	if (length - screenWidth / maxScore >= 0)
	{
		length -= screenWidth / maxScore;
	}
}
