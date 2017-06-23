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
	gfx(wnd),
	rng(rd()),
	xDist(50,750),
	yDist(50,550)
{
	for (size_t i = 0; i < numOfBoxes; i++)
	{
		boxes[i].Init(xDist(rng), yDist(rng));
	}
	for (size_t i = 0; i < numOfBlocks; i++)
	{
		blocks[i].Init(xDist(rng), yDist(rng));
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
	const float dTime = frameTimer.Mark();

	for (size_t i = 0; i < numOfBoxes; i++)
	{
		if (boxes[i].isCollidingWithBall(ball.GetX(), ball.GetY()))
		{
			scoreMeter.Increment();
			ball.InvertSpeed();
		}
	}

	for (size_t i = 0; i < numOfBlocks; i++)
	{
		if (blocks[i].isCollidingWithBall(ball.GetX(), ball.GetY()))
		{
			scoreMeter.Decrement();
			ball.InvertSpeed();
		}
	}

	ball.Move(wnd, dTime);
}

void Game::ComposeFrame()
{
	scoreMeter.Draw(gfx);

	for (size_t i = 0; i < numOfBoxes; i++)
	{
		boxes[i].Draw(gfx);
	}

	for (size_t i = 0; i < numOfBlocks; i++)
	{
		blocks[i].Draw(gfx);
	}

	ball.Draw(gfx);
}
