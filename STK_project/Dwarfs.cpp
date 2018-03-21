#include "Dwarfs.h"
#include "Board.h"


Dwarfs::Dwarfs(sf::Texture &texture, sf::Vector2f position, sf::Vector2f size)
	:MoveObj(texture, position, size)
{
	m_origin = position;
}


Dwarfs::~Dwarfs()
{
}

//===============================================================
//returns dwarf to origin place
void Dwarfs::goBack()
{
	setBackOrigin(m_origin);
}

//====================================================================
//draws dwarf
void Dwarfs::draw(sf::RenderWindow & window)
{
	MoveObj::draw(window);
}

//===============================================================
//moves dwarf to new place
void Dwarfs::go2(const Direction& direction, Board &brd)
{
	sf::Vector2f movingPlace = transferDirecToVec(direction);
	sf::Vector2f first = getPosition(), second = getSize();
	conversTwoSides(first, second, direction);
	if (!brd.isInBoundeOfBoard(first))
		return;
	
	int changeSide = random(13);
	if (!(isValidPlace(brd.objectNameOnPlace(first)) && isValidPlace(brd.objectNameOnPlace(second))) || changeSide == 5)
	{
		setRandomMove();
	}
	else
	{
		setPosition(movingPlace);
	}

	
	
}


//===============================================================
//returns last direction of dwarf
Direction Dwarfs::getDirection()
{
	return m_direction;
}



//===============================================================
//sets a random direction for dwarf
void Dwarfs::setRandomMove()
{
	
	int side = random(4);
		switch (side)
		{
		case 0:
			m_direction = Direction::UP;
			break;
		case 1:
			m_direction = Direction::RIGHT;
			break;
		case 2:
			m_direction = Direction::DOWN;
			break;
		case 3:
			m_direction = Direction::LEFT;
			break;
		default:
			m_direction = Direction::UP;
			break;
		}
}

bool Dwarfs::isValidMove(std::string objectName) const
{
	return (typeid(nullptr).name()== objectName);
}
