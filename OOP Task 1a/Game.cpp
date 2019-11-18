#include "Game.h"
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
	// set up snake
	snake.position_at_random();
	snake.spot_mouse(&mouse);
}

void Game::resetGame() {
	mouse.respawn();
	nut.respawn();
	snake.resetSnake();
	snake.position_at_random();
	snake.spot_mouse(&mouse);
	player.resetCheat();
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
	if (snake.has_caught_mouse())
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
			nut.disappear();
		}
		if (mouse.has_reached_a_hole(underground) && nut.has_been_collected() == true)
		{
			if (!player.isCheating()) {
				player.updateScore(player.getScore() + 1);
			}
			mouse.escape_into_hole();
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

Mouse Game::getMouse() const
{
	return mouse;
}

Snake Game::getSnake() const
{
	return snake;
}

int Game::getPlayerScore() const {
	return player.getScore();
}

ostream& operator<<(ostream& os, const Game& game)
{
	if (game.getMouse().is_alive())
	{
		os << "alive" <<endl ;
		os << game.getMouse().getX() << "|" << game.getMouse().getY() << endl;
		os << game.getSnake().getSnake().size() << endl;
		for (MoveableGridItem body : game.getSnake().getSnake())
		{
			os << body.getX() << "|" << body.getY() << endl;
		}
	}
	else os << "dead" <<endl;
	os << game.getPlayerName() << "|" << game.getPlayerScore() << endl;
	return os;
}
//ostream& operator>>(ostream& os, Game& game)
//{
//	string alive; 
//	os >> alive;
//
//	if (alive == "false")
//	{
//		
//	}
//	else
//	{
//
//	}
//	return os;
//}

