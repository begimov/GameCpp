#pragma once
#include "Graphics.h"
#include "MainWindow.h"
#include "Box.h"

class Ball
{
public:
	void Move(MainWindow& wnd, float dTime);
	void Draw(Graphics& gfx) const;
	void BallControl(MainWindow& wnd);
	void InvertSpeed();
	int GetX() const;
	int GetY() const;
private:
	void BordersCollisionTest(float dTime);
	bool IsCollidingBorder(const char axis) const;
	float x = 400.0f;
	float y = 300.0f;
	float dx = 0.0f;
	float dy = 0.0f;
	static constexpr int speedLimit = 300;
	static constexpr float speedChangeStep = 30.0f;
};