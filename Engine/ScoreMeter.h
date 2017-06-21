#pragma once
#include "Graphics.h"

class ScoreMeter
{
public:
	void Draw(Graphics& gfx) const;
	void Increment();
	void Decrement();
private:
	static constexpr int maxScore = 3;
	int length = 0;
};