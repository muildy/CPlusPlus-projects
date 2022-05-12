#pragma once

#include "raylib.h"

class Application
{
public:

	Application();
	~Application();

	void Run();

private:

	void Load();
	void Unload();

	void Update(float deltaTime);
	void Draw();

	Color GetTileColor(int tileValue);

private:

	int m_windowWidth = 800;
	int m_windowHeight = 800;

	static const int ROWS = 40;//40 squares
	static const int COLS = 40;//by 40 squares

	int m_tiles[ROWS * COLS];

	int m_tileWidth = 20;//size of each one
	int m_tileHeight = 20;
};