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
	gfx(wnd) {}

void Game::Go() {
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel() {
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		x0++;
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
		x0--;
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
		y0++;
	if (wnd.kbd.KeyIsPressed(VK_UP))
		y0--;
	if (wnd.mouse.LeftIsPressed()) {
		int x1 = wnd.mouse.GetPosX();
		int y1 = wnd.mouse.GetPosY();
		
		width = x1 - x0;
		height = y1 - y0;
	}
	x0 = ClamScreenX(x0, width);
	y0 = ClamScreenY(y0, height);
}

void Game::ComposeFrame() {
	gfx.DrawRect(x0, y0, width, height, Colors::Cyan);
}

int Game::ClamScreenX(int x, int width) {
	if (x < 0)
		return 0;
	else if (x > Graphics::ScreenWidth - 1)
		return (Graphics::ScreenWidth - 1) - width;
	else
		return x;
}

int Game::ClamScreenY(int y, int height) {
	if (y < 0)
		return 0;
	else if (y > Graphics::ScreenHeight - 1)
		return (Graphics::ScreenHeight - 1) - height;
	else
		return y;
}