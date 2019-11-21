#include "Game.h"
Game::Game() : nut(10, 5)
{

}
Game::Game(string name) : nut(10, 5), player(name)
{
}
void Game::setup()
{
	// set up the holes
	underground.set_hole_no_at_position(0, 4, 3);
	underground.set_hole_no_at_position(1, 15, 10);
	underground.set_hole_no_at_position(2, 7, 15);

	// mouse state already set up in its contructor
	setPosition();
	// set up snake
	snake.spot_mouse(&mouse);
}
void Game::setPosition()
{
	mouse.randomisePosition();
	while (mouse.is_at_position(snake.getSnake().at(0).getX(), snake.getSnake().at(0).getY())
		|| mouse.is_at_position(nut.getX(), nut.getY())){
			mouse.randomisePosition();
	}
	while (nut.is_at_position(underground.get_hole_no(0).getX(), underground.get_hole_no(0).getY()) ||
		nut.is_at_position(underground.get_hole_no(1).getX(), underground.get_hole_no(1).getY()) ||
		nut.is_at_position(underground.get_hole_no(2).getX(), underground.get_hole_no(2).getY()) ||
		nut.is_at_position(snake.getSnake().at(0).getX(), snake.getSnake().at(0).getY()) ||
		nut.getX() >= 18 || nut.getX() <= 2 || nut.getY() >= 18 || nut.getY() <= 2)
	{
		nut.randomisePosition();
	}
}

void Game::resetGame() {
	mouse.respawn();
	nut.respawn();
	nut.randomisePosition();
	snake.resetSnake();
	snake.position_at_random();
	snake.spot_mouse(&mouse);
	player.resetCheat();
	setPosition();
}

void Game::processInput(int key)
{
	mouse.scamper(key);
	snake.chase_mouse();
	apply_rules();
}

vector<vector<char>> Game::prepareGrid()
{
	// create the 2D grid
	vector<vector<char>> grid;

	// for each row
	for (int row = 1; row <= SIZE; ++row)
	{
		// create a row to add to the 2D grid
		vector<char> line;

		// for each column
		for (int col = 1; col <= SIZE; ++col)
		{
			bool tailFound = false;
			int count = 0;
			for (MoveableGridItem snakePart : snake.getSnake())
			{
				if (row == snakePart.getY() && col == snakePart.getX() && count > 0)
				{
					line.push_back(snakePart.getSymbol());
					tailFound = true;
				}
				count++;
			}
			if (!tailFound)
			{
				// is the nut at this position?
				if (row == nut.getY() && col == nut.getX() && !nut.has_been_collected())
				{
					line.push_back(nut.getSymbol());
				}
				// is the snake at this position?
				else if (row == snake.getSnake().at(0).getY() && col == snake.getSnake().at(0).getX())
				{
					line.push_back(snake.getSnake().at(0).getSymbol());
				}
				// is the mouse at this position?
				else if (row == mouse.getY() && col == mouse.getX())
				{
					line.push_back(mouse.getSymbol());
				}
				else
				{
					// is there a hole at this position?
					const int hole_no = find_hole_number_at_position(col, row);

					if (hole_no != -1)
					{
						line.push_back(underground.get_hole_no(hole_no).getSymbol());
					}
					else
					{
						// none of the above, must be nothing at this position
						line.push_back(FREECELL);
					}
				}
			}
		}

		// now that the row is full, add it to the 2D grid
		grid.push_back(line);
	}

	return grid;
}

int Game::find_hole_number_at_position(int x, int y) const
{
	for (size_t h_no = 0; h_no < underground.getHoles().size(); ++h_no)
	{
		if (underground.get_hole_no(h_no).is_at_position(x, y))
		{
			return h_no;
		}
	}

	return -1; // not a hole
}

void Game::cheatMode() {
	snake.toggleImmbolise();
	player.toggleCheat();
}

bool Game::isCheatModeActive() const
{
	if (player.isCheating()) {
		return true;
	}
	else {
		return false;
	}
}

void Game::apply_rules()
{
	if (!player.isCheating() && snake.has_caught_mouse())
	{
		if (!player.isCheating()) {
			player.updateScore(player.getScore() - 1);
		}
		mouse.die();
	}
	else
	{
		if (mouse.has_reached_nut(nut))
		{
			nut.update_position(mouse.getDirectionX(), mouse.getDirectionY());
		}
		if (underground.hasNutReachedHole(nut))
		{
			nut.disappear();
		}
		if (mouse.has_reached_a_hole(underground) && nut.has_been_collected() == true)
		{
			if (!player.hasCheated()) {
				player.updateScore(player.getScore() + 1);
			}
			mouse.escape_into_hole();
		}
		if (mouse.has_reached_a_hole(underground) && nut.has_been_collected() == false)
		{
			//move mouse to another hole
			RandomNumberGenerator rng;
			int hole = rng.get_random_value(3) - 1;
			while (mouse.getX() == underground.get_hole_no(hole).getX() && mouse.getY() == underground.get_hole_no(hole).getY())
			{
				hole = rng.get_random_value(3) - 1;
			}
			mouse.SetX(underground.getHoles().at(hole).getX());
			mouse.SetY(underground.getHoles().at(hole).getY());

		}
	}
}

bool Game::isRunning() const
{
	return mouse.is_alive() && !mouse.has_escaped();
}

string Game::get_end_reason() const
{
	if (mouse.has_escaped())
		return "You escaped underground!";

	return "The snake ate you!";
}

string Game::getPlayerName() const {
	return player.getName();
}

Mouse& Game::getMouse()
{
	return mouse;
}

Snake& Game::getSnake()
{
	return snake;
}

Nut& Game::getNut()
{
	return nut;
}

Player& Game::getPlayer()
{
	return player;
}

int Game::getPlayerScore() const {
	return player.getScore();
}
//TODO
// does mouse have nut?
//
ostream& operator<<(ostream& os, Game& game)
{
	os << game.getPlayer(); // save player
	os << game.getMouse(); //save mouse
	if (game.getMouse().is_alive())
	{
		os << game.getNut(); //save nut
		os << game.getSnake(); //save snake
	}
	return os;
}
istream& operator>>(istream& is, Game& game)
{
	int playerScore; string playerName;
	is >> playerName;
	is >> playerScore;
	game.getPlayer().setName(playerName);
	game.getPlayer().updateScore(playerScore);
	string mouseAlive;
	is >> mouseAlive;

	if (mouseAlive == "mouse_alive")
	{
		int mouseX, mouseY;
		is >> mouseX;
		is >> mouseY;
		game.getMouse().SetX(mouseX);
		game.getMouse().SetY(mouseY);

		string nutCollected;
		is >> nutCollected;
		if (nutCollected == "nut_not_collected")
		{
			int nutX, nutY;
			is >> nutX;
			is >> nutY;
			game.getNut().SetX(nutX);
			game.getNut().SetY(nutY);
		}
		int snakeSize;
		is >> snakeSize;
		for (int x = 0; x < snakeSize; x++)
		{
			int snakeX, snakeY;
			is >> snakeX;
			is >> snakeY;
			game.getSnake().getSnake().at(x).SetX(snakeX);
			game.getSnake().getSnake().at(x).SetY(snakeY);
		}
	}


	return is;
}

