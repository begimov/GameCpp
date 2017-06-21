#pragma once
#include "Graphics.h"
#include "MainWindow.h"
#include "Box.h"

class Ball
{
public:
	void Move(MainWindow& wnd);
	void Draw(Graphics& gfx) const;
	void BallControl(MainWindow& wnd);
	void InvertSpeed();
	int GetX() const;
	int GetY() const;
private:
	void BordersCollisionTest();
	bool IsCollidingBorder(const char axis) const;
	int x = 400;
	int y = 300;
	int dx = 0;
	int dy = 0;
	static constexpr int speedLimit = 5;
};