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

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
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

	isBoxMode = wnd.kbd.KeyIsPressed(VK_CONTROL);

	color = 999;

	if (wnd.kbd.KeyIsPressed(VK_SPACE)) 
	{
		color = 888;
	}

	if ((x >= 20 && x <= 780) || (x < 20 && xspeed >= 0) || (x > 780 && xspeed <= 0))
	{
		x += xspeed;
	}

	if ((y >= 20 && y <= 580) || (y < 20 && yspeed >= 0) || (y > 580 && yspeed <= 0))
	{
		y += yspeed;
	}

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		yspeed = (yspeed > -5) ? yspeed - 1 : yspeed;
	}
	else if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		yspeed = (yspeed < 5) ? yspeed + 1 : yspeed;
		
	}
	else if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		xspeed = (xspeed > -5) ? xspeed - 1 : xspeed;
	}
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		xspeed = (xspeed < 5) ? xspeed + 1 : xspeed;
	}
}

void Game::ComposeFrame()
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
