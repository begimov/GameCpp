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

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd)
{
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
	CollisionTests(x, y, xBox, yBox);
	BallControl();
}

void Game::ComposeFrame()
{
	DrawBox(xBox, yBox, boxColor);
	DrawBall(x, y, color);
}

void Game::CollisionTests(int x1, int y1, int x2, int y2)
{
	if (ObjectsCollideTest(x1, y1, x2, y2)) {
		dx = -dx;
		dy = -dy;
		isBoxMode = true;
	}
	else
	{
		isBoxMode = false;
	}

	if (BordersCollideTest(x1, y1, 'x'))
	{
		x += dx;
	}
	else
	{
		dx = -dx;
	}

	if (BordersCollideTest(x1, y1, 'y'))
	{
		y += dy;
	}
	else
	{
		dy = -dy;
	}
}

bool Game::ObjectsCollideTest(int x1, int y1, int x2, int y2)
{
	return (x1 > x2 - 15 && x1 < x2 + 15
		&& y1 > y2 - 15 && y1 < y2 + 15);
}

bool Game::BordersCollideTest(int x, int y, char axis)
{
	if (axis == 'x') 
	{
		return (x >= 20 && x <= gfx.ScreenWidth - 20)
			|| (x < 20 && dx >= 0)
			|| (x > gfx.ScreenWidth - 20 && dx <= 0);
	}
	else if (axis = 'y')
	{
		return (y >= 20 && y <= gfx.ScreenHeight - 20)
			|| (y < 20 && dy >= 0)
			|| (y > gfx.ScreenHeight - 20 && dy <= 0);
	}
}

void Game::BallControl()
{
	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		dx = 0;
		dy = 0;
	}

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		dy = (dy > -speedLimit) ? dy - 1 : dy;
	}
	else if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		dy = (dy < speedLimit) ? dy + 1 : dy;
	}
	else if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		dx = (dx > -speedLimit) ? dx - 1 : dx;
	}
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		dx = (dx < speedLimit) ? dx + 1 : dx;
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
	if (isBoxMode) {
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
