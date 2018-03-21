#include "Utilities.h"

//==================================================================
//gets a limit and returns a random number between 0-limit
int random(int limit)
{
	int v = rand() % limit;
	return (v);
}

//==================================================================
//returns movement by pixel according to direction
sf::Vector2f transferDirecToVec(const Direction & direction)
{
	sf::Vector2f transferd = { 0,0 };
	switch (direction)
	{
	case Direction::UP:
		transferd = { 0, -5};
		break;
	case Direction::RIGHT:
		transferd = {7,0 };
		break;
	case Direction::DOWN:
		transferd = { 0,5 };
		break;
	case Direction::LEFT:
		transferd = { -7,0 };
		break;
	default:
		break;
	}
	return transferd;
}

//=============================================================================
//gets location and size by reference and returns them as two points to check
void conversTwoSides(sf::Vector2f & first, sf::Vector2f & second, const Direction direction)
{
	sf::Vector2f toAdd = transferDirecToVec(direction);
	first = { first.x + toAdd.x, first.y + toAdd.y };
	switch (direction)
	{
	case Direction::UP:
	{
		first = { first.x + 5, first.y +4};
		second = { first.x + second.x-10, first.y };
		break;
	}
	case Direction::RIGHT:
	{
		first = { first.x + second.x-6, first.y +5 };
		second = { first.x , first.y+second.y-10 };
		break;
	}
	case Direction::DOWN:
	{
		first = { first.x+5, first.y + second.y -4};
		second = { first.x + second.x-10, first.y };
		break;
	}
	case Direction::LEFT:
	{
		first = { first.x+6,first.y +5 };
		second = { first.x , first.y + second.y-10 };
		break;
	}
	default:
		break;
	}
	
	//second = { second.x + toAdd.x,second.y + toAdd.y };
}
