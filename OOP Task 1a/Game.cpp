#include "Game.h"

void Game::set_up()
{
	// set up the holes
	underground.set_hole_no_at_position(0, 4, 3);
	underground.set_hole_no_at_position(1, 15, 10);
	underground.set_hole_no_at_position(2, 7, 15);

	// mouse state already set up in its contructor

	// set up snake
	snake.position_at_random();
	snake.spot_mouse(&mouse);

	// set up Nut
	nut.positionNut();
}

void Game::process_input(int key)
{
	mouse.scamper(key);
	snake.chase_mouse();
	apply_rules();
}

vector<vector<char>> Game::prepare_grid()
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
			if (row == nut.getY() && col == nut.getX())
			{
				line.push_back(nut.get_symbol());
			}
			// is the snake at this position?
			else if (row == snake.getY() && col == snake.getX())
			{
				line.push_back(snake.getSymbol());
			}
			// is the mouse at this position?
			else if (row == mouse.get_y() && col == mouse.get_x())
			{
				line.push_back(mouse.get_symbol());
			}
			else
			{
				// is there a hole at this position?
				const int hole_no = find_hole_number_at_position(col, row);

				if (hole_no != -1)
				{
					line.push_back(underground.get_hole_no(hole_no).get_symbol());
				}
				else
				{
					// none of the above, must be nothing at this position
					line.push_back(FREECELL);
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

void Game::apply_rules()
{
	if (snake.has_caught_mouse())
	{
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
			mouse.escape_into_hole();
		}
	}
}

bool Game::is_running() const
{
	return mouse.is_alive() && !mouse.has_escaped();
}

string Game::get_end_reason() const
{
	if (mouse.has_escaped())
		return "You escaped underground!";

	return "The snake ate you!";
}
