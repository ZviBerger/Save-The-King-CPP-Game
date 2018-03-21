#include "Mage.h"
#include "Board.h"
#include "Information.h"

//int Information::movements;

//===============================================================
//move mage
void Mage::go2(const Direction & direction, Board & brd)
{
	if (!isSelected())
		return;
	sf::Vector2f movingPlace = transferDirecToVec(direction);
	sf::Vector2f first = getPosition(), second = getSize();
	conversTwoSides(first, second, direction);
	if (!brd.isInBoundeOfBoard(first))
		return;

	if (isValidPlace(brd.objectNameOnPlace(first)) && isValidPlace(brd.objectNameOnPlace(second)))
	{
		setPosition(movingPlace);
		Information::movements++;
	}
	else if ((isValidPlace(brd.objectNameOnPlace(first)) || brd.objectNameOnPlace(first) == typeid(Fire).name())
		&& (isValidPlace(brd.objectNameOnPlace(second)) || brd.objectNameOnPlace(second) == typeid(Fire).name()))
	{
		setPosition(movingPlace);
		Information::movements++;
		brd.removeCellfromBoard(first, typeid(Fire).name());
		brd.removeCellfromBoard(second, typeid(Fire).name());
	}
}
