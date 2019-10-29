#include "raylib.h"
#include "Game.h"

int main()
{
	InitWindow(900, 600, "OOP Assignment 1");
	SetTargetFPS(60);

	Game game;
	game.set_up();

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(DARKGRAY);

		if (game.is_running())
		{
			if (IsKeyPressed(KEY_RIGHT))  game.process_input(KEY_RIGHT);
			if (IsKeyPressed(KEY_LEFT))   game.process_input(KEY_LEFT);
			if (IsKeyPressed(KEY_UP))     game.process_input(KEY_UP);
			if (IsKeyPressed(KEY_DOWN))   game.process_input(KEY_DOWN);
		}
		else
		{
			DrawText(game.get_end_reason().c_str(), 610, 10, 20, LIGHTGRAY);
		}

		const int cellSize = (int)((float)GetScreenHeight() / (float)(SIZE));

		const auto grid = game.prepare_grid();

		for (int x = 0; x < SIZE; x++)
		{
			for (int y = 0; y < SIZE; y++)
			{
				int xPosition = x * cellSize;
				int yPosition = y * cellSize;

				switch (grid[y][x])
				{
					case HOLE:       DrawRectangle(xPosition, yPosition, cellSize, cellSize, BLACK);     break;
					case SNAKEHEAD:  DrawRectangle(xPosition, yPosition, cellSize, cellSize, RED);       break;
					case MOUSE:      DrawRectangle(xPosition, yPosition, cellSize, cellSize, GREEN);     break;
					case FREECELL:   DrawRectangle(xPosition, yPosition, cellSize, cellSize, DARKGREEN); break;
					default:         assert(false); // if this assert triggers there's an unrecognised tile on the grid!
				}

				// draw lines around each tile, remove this if you don't like it!
				DrawRectangleLines(x * cellSize, y * cellSize, cellSize, cellSize, DARKGRAY);
			}
		}

		EndDrawing();
	}

	CloseWindow();
	return 0;
}