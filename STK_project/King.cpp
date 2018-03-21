#include "King.h"
#include "Board.h"
#include "Information.h"

//int Information::movements;

King::King(sf::Texture &texture, sf::Vector2f position, sf::Vector2f size)
	:PlayersObj(texture, position, size)
{
	m_cameToThrone = false;
}


King::~King()
{
}

//bool King::onThrone()
//{
//	return m_cameToThrone;
//}


//=========================================================================
//move king
void King::go2(const Direction & direction, Board & brd)
{
	if (!isSelected())
		return;
	sf::Vector2f movingPlace = transferDirecToVec(direction);
	sf::Vector2f first = getPosition(), second = getSize();
	conversTwoSides(first, second, direction);
	if (!brd.isInBoundeOfBoard(first))
		return;
	
	if (!notAloud(brd.objectNameOnPlace(first)) && !notAloud(brd.objectNameOnPlace(second)))
	{
		setPosition(movingPlace);
		Information::movements++;
		if(brd.objectNameOnPlace(getPosition()) == typeid(Throne).name())
			m_cameToThrone = true;
	}
}

//=========================================================================
//return true if place for moving is not aloud
bool King::notAloud(std::string objName)
{
	if (notValidForAll(objName) || objName == typeid(Gate).name()
		|| objName == typeid(Fire).name() || objName == typeid(Dwarfs).name())
		return true;
	return false;
}

//=========================================================================
//return true if king came to throne
bool onThrone()
{
	return King::m_cameToThrone;
}
