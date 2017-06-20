#pragma once

class Ball
{
public:
	void BordersCollisionTest();
	bool IsCollidingBorder(char axis);
	int x = 400;
	int y = 300;
	int dx = 0;
	int dy = 0;
	static constexpr int color = 55456499;
	static constexpr int speedLimit = 5;
	bool isBoxMode = false;
};