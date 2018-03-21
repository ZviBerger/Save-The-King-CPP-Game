#pragma once
#include <stdlib.h>     

#include <SFML/Graphics.hpp>

enum class Direction
{
	UP, RIGHT, DOWN, LEFT
};

/*enum class WallColor
{
	BLUE, GREEN, BROWN
};*/
int random(int);

sf::Vector2f transferDirecToVec(const Direction &direction);

void conversTwoSides(sf::Vector2f &first, sf::Vector2f &second, const Direction direction);