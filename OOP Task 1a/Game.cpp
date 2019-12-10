#include "Game.h"
Game::Game()
{
}
Game::Game(string name) : player(name)
{
}
void Game::setup()
{
	underground.populateHoles();
	setPosition();
	snake.spot_mouse(&mouse);
}
void Game::setPosition()
{
	mouse.randomisePosition();
	while (mouse.is_at_position(snake.getX(), snake.getY()) || mouse.is_at_position(nut.getX(), nut.getY()))
		mouse.randomisePosition();
	while (underground.is_hole_at_position(nut.getX(), nut.getY()) || nut.is_at_position(snake.getX(), snake.getY()) || nut.isOutOfBounds())
		nut.randomisePosition();
}

void Game::resetGame() 
{
	mouse.respawn();
	nut.respawn();
	nut.randomisePosition();
	snake.resetSnake();
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
			// is the nut at this position?
			if (row == nut.getY() && col == nut.getX() && !nut.has_been_collected())
				line.push_back(nut.getSymbol());
			// is the snake at this position?
			else if (row == snake.getY() && col == snake.getX())
				line.push_back(snake.getSymbol());
			// is the mouse at this position?
			else if (row == mouse.getY() && col == mouse.getX())
				line.push_back(mouse.getSymbol());
			else
			{
				// is there a hole at this position?
				if (underground.is_hole_at_position(col,row))
				{
					line.push_back(underground.getSymbol());
				}
				else
				{
					bool tailFound = false;
					for (Tail body : snake.getTail())
					{
						if (row == body.getY() && col == body.getX() && tailFound == false)
						{
							line.push_back(body.getSymbol());
							tailFound = true;
						}
					}
					// none of the above, must be nothing at this position
					if (!tailFound)
						line.push_back(FREECELL);
				}
			}
		}

		// now that the row is full, add it to the 2D grid
		grid.push_back(line);
	}

	return grid;
}

void Game::cheatMode()
{
	snake.toggleImmbolise();
	player.toggleCheat();
}

bool Game::isCheatModeActive() const
{
	return player.isCheating();
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
				mouse.teleport(underground);
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

string Game::getPlayerName() const 
{
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

int Game::getPlayerScore() const 
{
	return player.getScore();
}

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
		game.getMouse().setX(mouseX);
		game.getMouse().setY(mouseY);

		string nutCollected;
		is >> nutCollected;
		if (nutCollected == "nut_not_collected")
		{
			int nutX, nutY;
			is >> nutX;
			is >> nutY;
			game.getNut().setX(nutX);
			game.getNut().setY(nutY);
		}
		else
		{
			game.getNut().disappear();
		}
		int snakeSize;
		is >> snakeSize;
		int snakeX, snakeY;
		is >> snakeX;
		is >> snakeY;
		game.getSnake().setX(snakeX);
		game.getSnake().setY(snakeY);
		for (int x = 0; x < snakeSize; x++)
		{
			is >> snakeX;
			is >> snakeY;
			game.getSnake().getTail().at(x).setX(snakeX);
			game.getSnake().getTail().at(x).setY(snakeY);
		}
	}


	return is;
}

void Game::undo()
{
	if (mouse.getDirectionX() != NULL || mouse.getDirectionY() != NULL)
	{
		mouse.setX(mouse.getPrevX());
		mouse.setY(mouse.getPrevY());
	}
	if (nut.getPrevX() != NULL || nut.getPrevY() != NULL)
	{
		if (nut.has_been_collected() == true)
		{
			nut.respawn();
			nut.setX(nut.getPrevX());
			nut.setY(nut.getPrevY());
		}
		else
		{
			nut.setX(nut.getPrevX());
			nut.setY(nut.getPrevY());
		}
	}
	snake.undo();
}

