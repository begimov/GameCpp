/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <random>

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd)
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> xDist(20, 780);
	std::uniform_int_distribution<int> yDist(20, 580);
	for (size_t i = 0; i < 5; i++)
	{
		boxes[i].x = xDist(rng);
		boxes[i].y = yDist(rng);
	}
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	ball.BordersCollisionTest();
	ObjectCollisionTest(ball.x, ball.y);
	BallControl();
}

void Game::ComposeFrame()
{
	for (size_t i = 0; i < 5; i++)
	{
		if (boxes[i].isVisible == true) {
			DrawBox(boxes[i].x, boxes[i].y, boxes[i].boxColor);
		}
	}
	DrawBall(ball.x, ball.y, ball.color);
}

void Game::ObjectCollisionTest(int x, int y)
{
	int collidingBox = ObjectsCollideTest(x, y);

	if (collidingBox >= 0) {
		ball.dx = -ball.dx;
		ball.dy = -ball.dy;
		ball.isBoxMode = true;
		boxes[collidingBox].isVisible = false;
	}
	else
	{
		ball.isBoxMode = false;
	}
}

int Game::ObjectsCollideTest(int x, int y)
{
	for (size_t i = 0; i < 5; i++)
	{
		if (boxes[i].isVisible == true) {
			if (x > boxes[i].x - 15 && x < boxes[i].x + 15
				&& y > boxes[i].y - 15 && y < boxes[i].y + 15) {
				return i;
			}
		}
	}
	return -1;
}

void Game::BallControl()
{
	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		ball.dx = 0;
		ball.dy = 0;
	}

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		ball.dy = (ball.dy > -ball.speedLimit) ? ball.dy - 1 : ball.dy;
	}
	else if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		ball.dy = (ball.dy < ball.speedLimit) ? ball.dy + 1 : ball.dy;
	}
	else if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		ball.dx = (ball.dx > -ball.speedLimit) ? ball.dx - 1 : ball.dx;
	}
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		ball.dx = (ball.dx < ball.speedLimit) ? ball.dx + 1 : ball.dx;
	}
}

void Game::DrawBox(int x, int y, int color)
{
	for (int i = 0; i < 21; i++)
	{
		gfx.PutPixel(-10 + x + i, y - 10, color);
		gfx.PutPixel(-10 + x + i, y + 10, color);
		gfx.PutPixel(x - 10, -10 + y + i, color);
		gfx.PutPixel(x + 10, -10 + y + i, color);
	}
}

void Game::DrawBall(int x, int y, int color)
{
	if (ball.isBoxMode) {
		for (int i = 0; i < 11; i++)
		{
			gfx.PutPixel(-5 + x + i, y - 5, color);
			gfx.PutPixel(-5 + x + i, y + 5, color);
			gfx.PutPixel(x - 5, -5 + y + i, color);
			gfx.PutPixel(x + 5, -5 + y + i, color);
		}
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			gfx.PutPixel(-5 + x + i, y, color);
			gfx.PutPixel(3 + x + i, y, color);
			gfx.PutPixel(x, -5 + y + i, color);
			gfx.PutPixel(x, 3 + y + i, color);
		}
	}
}
