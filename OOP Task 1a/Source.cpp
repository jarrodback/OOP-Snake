#include "raylib.h"
#include "Game.h"

string getName() {
	string name;
	cout << "Enter your name: ";
	cin >> name;
	return name;
}
void saveFile(Game& game)
{
	ofstream fout;
	fout.open("Game.txt");
	if (fout.fail()) cout << "\nError saving game.";
	else fout << game; // operator << for Game instances
	fout.close();
}
void loadFile(Game& game)
{
	ifstream fin;
	fin.open("Game.txt");
	if (fin.fail()) cout << "\nError loading game.";
	else fin >> game;   // operator >> for Game instances
	fin.close();
}
int main()
{
	int count = 0;
	bool cont = true;
	Game game;
	game.setup();
	char answer;
	do {
		cout << "Would you like to load the previous save?(Y/N): " << endl;
		cin >> answer;
	} while (toupper(answer) != 'Y' && toupper(answer) != 'N');
	if (toupper(answer) == 'Y')
	{
		loadFile(game);
	}
	else
	{
		game.getPlayer().setName(getName());
	}
	InitWindow(900, 600, "OOP Assignment 1");
	SetTargetFPS(60);
	while (cont)
	{
		BeginDrawing();
		ClearBackground(DARKGRAY);
		DrawText(("Player Name: " + game.getPlayerName()).c_str(), 610, 10, 20, LIGHTGRAY);
		DrawText(("Score: " + to_string(game.getPlayerScore())).c_str(), 610, 40, 20, LIGHTGRAY);
		DrawText("Controls", 610, 140, 20, LIGHTGRAY);
		DrawText("Press 'C' to cheat", 610, 160, 20, LIGHTGRAY);
		DrawText("Press 'Q' to quit", 610, 180, 20, LIGHTGRAY);
		DrawText("Press 'U' to undo last move", 610, 200, 20, LIGHTGRAY);
		if (game.isRunning())
		{
			if (IsKeyPressed(KEY_RIGHT))  game.processInput(KEY_RIGHT);
			if (IsKeyPressed(KEY_LEFT))   game.processInput(KEY_LEFT);
			if (IsKeyPressed(KEY_UP))     game.processInput(KEY_UP);
			if (IsKeyPressed(KEY_DOWN))   game.processInput(KEY_DOWN);
			if (IsKeyPressed(KEY_Q)) cont = false;
			if (IsKeyPressed(KEY_C)) game.cheatMode();
			if (IsKeyPressed(KEY_U)) game.undo();
		}
		else
		{
			DrawText(game.get_end_reason().c_str(), 610, 70, 20, LIGHTGRAY);
			DrawText("Press 'Y' to continue", 610, 90, 20, LIGHTGRAY);
			if (IsKeyPressed(KEY_Y)) {
				game.resetGame();
			}
			if (IsKeyPressed(KEY_Q)) cont = false;
		}

		if (game.isCheatModeActive()) 	DrawText("*CHEAT MODE*", 610, 220, 20, RED);
		else  DrawText("", 610, 220, 20, LIGHTGRAY);

		const int cellSize = (int)((float)GetScreenHeight() / (float)(SIZE));

		const auto grid = game.prepareGrid();

		for (int x = 0; x < SIZE; x++)
		{
			for (int y = 0; y < SIZE; y++)
			{
				int xPosition = x * cellSize;
				int yPosition = y * cellSize;
				switch (grid[y][x])
				{
				case HOLE:       DrawRectangle(xPosition, yPosition, cellSize, cellSize, BLACK);     break;
				case NUT:        DrawRectangle(xPosition, yPosition, cellSize, cellSize, BROWN);     break;
				case SNAKETAIL:  DrawRectangle(xPosition, yPosition, cellSize, cellSize, PURPLE);    break;
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
	saveFile(game);
	CloseWindow();
	return 0;
}