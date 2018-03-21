#include "PlayersObj.h"
#include "Board.h"
#include "Information.h"

PlayersObj::PlayersObj(sf::Texture &texture, sf::Vector2f position, sf::Vector2f size)
	:MoveObj(texture, position, size), m_isSelectOb(false)
{
}


PlayersObj::~PlayersObj()
{
}

//===============================================================
//moves object to new place
//void PlayersObj::go2(const Direction & direction, Board & brd)
//{
//	if (!isSelected())
//		return;
//	sf::Vector2f movingPlace = transferDirecToVec(direction);
//	sf::Vector2f first = getPosition(), second = getSize();
//	conversTwoSides(first, second, direction);
////	movingPlace = { first.x + movingPlace.x, first.y + movingPlace.y };
//	if (!brd.isInBoundeOfBoard( first))
//		return;
//	
//	if (isValidPlace(brd.objectNameOnPlace(first))&& isValidPlace(brd.objectNameOnPlace(second)))
//	{
//		setPosition(movingPlace);
//		movements++;
//	}
//}

void PlayersObj::draw(sf::RenderWindow & window)
{
	MoveObj::draw(window);
}

void PlayersObj::setPlayarOb(bool selected)
{
	m_isSelectOb = selected;
	setFillColor(selected);
}

bool PlayersObj::isSelected()
{
	return m_isSelectOb;
}
