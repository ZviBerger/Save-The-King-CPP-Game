#include "Giant.h"
#include "Board.h"
#include "Information.h"

//int Information::movements;

void Giant::go2(const Direction & direction, Board & brd)
{
	if (!isSelected())
		return;
	sf::Vector2f movingPlace = transferDirecToVec(direction);
	sf::Vector2f first = getPosition(), second = getSize();
	sf::Vector2f check = first;
	//movingPlace = { first.x + movingPlace.x, first.y + movingPlace.y };
	conversTwoSides(first, second, direction);
	if (!brd.isInBoundeOfBoard(first))
		return;

	if (!notAloud(brd.objectNameOnPlace(first)) && !notAloud(brd.objectNameOnPlace(second)))
	{
		if (brd.objectNameOnPlace(first) == typeid(Dwarfs).name())
			brd.sendBackDwarf(first);
		if(brd.objectNameOnPlace(second) == typeid(Dwarfs).name())
			brd.sendBackDwarf(second);
		setPosition(movingPlace);
		Information::movements++;
	}

}

//==========================================================================
//checks if place not aloud
bool Giant::notAloud(std::string objName)
{
	if (notValidForAll(objName) ||  objName == typeid(Gate).name()
		|| objName == typeid(Fire).name() || objName == typeid(Throne).name())
		return true;
	return false;
}
