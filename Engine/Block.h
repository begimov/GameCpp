#pragma once
#include "Graphics.h"

class Block
{
public:
	void Init(int inX, int inY);
	void Draw(Graphics& gfx) const;
	bool isCollidingWithBall(int x, int y);
private:
	int x;
	int y;
	bool initialized = false;
};