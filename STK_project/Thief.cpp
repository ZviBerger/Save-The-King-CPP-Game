#include "Thief.h"
#include "Board.h"
#include "Information.h"

//int Information::movements;

Thief::Thief(sf::Texture &texture, sf::Vector2f position, sf::Vector2f size)
	:PlayersObj(texture, position, size), m_hasAKey(false)
{
}


Thief::~Thief()
{
}

bool Thief::hasAKey()
{
	return m_hasAKey;
}

//========================================================================
//moves the thief with/without a key
void Thief::go2(const Direction & direction, Board & brd)
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
		if (!hasAKey()) 
		{
			if (brd.objectNameOnPlace(first) == typeid(GateKey).name())
			{
				m_hasAKey = true;
				brd.removeCellfromBoard(first, typeid(GateKey).name());
			}
			else if (brd.objectNameOnPlace(second) == typeid(GateKey).name())
			{
				m_hasAKey = true;
				brd.removeCellfromBoard(second, typeid(GateKey).name());
			}
		}
		else if (hasAKey())
		{
			if (brd.objectNameOnPlace(first) == typeid(Gate).name())
			{
				m_hasAKey = false;
				brd.removeCellfromBoard(first, typeid(Gate).name());
			}
			else if (brd.objectNameOnPlace(second) == typeid(Gate).name())
			{
				m_hasAKey = false;
				brd.removeCellfromBoard(second, typeid(Gate).name());
			}
		}
		setPosition(movingPlace);
		Information::movements++;
	}
	
}

//==========================================================================
//checks if place not aloud
bool Thief::notAloud(std::string objName)
{
	if (notValidForAll(objName) || (!hasAKey() && objName == typeid(Gate).name())
		|| objName == typeid(Fire).name() || objName == typeid(Dwarfs).name() || objName == typeid(Throne).name())
		return true;
	return false;
}
