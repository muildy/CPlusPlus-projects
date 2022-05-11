#include "Application.h"
#include "raylib.h"
#include <stdlib.h>

#include <cstdlib>
#include <iostream>

Application::Application()
{
	
}

Application::~Application()
{

}

void Application::Run()
{
	InitWindow(m_windowWidth, m_windowHeight, "Simple Tilemap");
	SetTargetFPS(60);

	Load();

	while (!WindowShouldClose())
	{
		Update(GetFrameTime());
		Draw();
	}

	Unload();
}

void Application::Load()
{
	// Task1:
	// Initialise all values in m_tiles array to a random
	// value between 0 and 5 exclusive;
	// -----------------------------------------------------
	
	// write your code here
	srand(time(NULL));


	for (int i = 0; i < ROWS * COLS; i += 20) {

		m_tiles[i] = rand() % 5 + 1;
		//std::cout << m_tiles[i];
	}
	// -----------------------------------------------------
}

void Application::Unload()
{

}

void Application::Update(float deltaTime)
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		Vector2 mousePos = GetMousePosition();

		// Task 3:
		// TODO: Calculate row and col index based on the mouse positon
		int rowIndex = mousePos.x/20; 
		int colIndex = mousePos.y/20;
		std::cout << "mous x " << rowIndex << "mouse pos y " << colIndex << std::endl;

		// TODO: calculate the index of the tile clicked on based on the row/col index
		int tileIndex = colIndex + (rowIndex * ROWS);
		if (tileIndex < ROWS * COLS) {
			std::cout << "mouse check pass" << std::endl;
			m_tiles[tileIndex] += 1;
			if (m_tiles[tileIndex] >= 5)
				m_tiles[tileIndex] = 0;
		}
	}
}

void Application::Draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);

	// Task2:
	// use a nested loop to iterate over rows and columns
	// Use raylib's DrawRect method to draw each tile in the array.
	// 	   use the row and col index multipled by m_tileHeight/m_tileWidth
	// 	   to calculate the x and y position for each rectangle.
	// 
	// change the color of the rect drawn based on the value of the tile.
	// 	   We have created a helper function you can use "GetTileColor"
	// --------------------------------------------------------------------
	// write your code here
	float xPos = 0;
	float yPos = 0;



	for (int rowIndex = 0; rowIndex < ROWS; rowIndex += m_tileWidth)
	{
		for (int colIndex = 0; colIndex < COLS; colIndex += m_tileHeight)
		{
			Color color = GetTileColor(m_tiles[colIndex + (rowIndex * ROWS)]); // pass in the tilevalue
			DrawRectangle(rowIndex, colIndex, m_tileWidth, m_tileHeight, color);
			std::cout << colIndex + (rowIndex * ROWS) << std::endl;
		}
		std::cout << std::endl;
	}
	// --------------------------------------------------------------------

	EndDrawing();
}

Color Application::GetTileColor(int tileValue)
{
	switch (tileValue)
	{
	case 0: return WHITE;
	case 1: return RED;
	case 2: return GREEN;
	case 3: return BLUE;
	case 4: return YELLOW;
	}
	
	return BLACK;
}