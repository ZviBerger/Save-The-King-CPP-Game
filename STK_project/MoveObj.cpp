#include "MoveObj.h"
#include "Board.h"

void MoveObj::draw(sf::RenderWindow & window)
{
	GameObject::draw(window);
}

bool MoveObj::isValidPlace(std::string objName)
{
	return (objName == "EMPTY" || objName == typeid(GateKey).name());
}

bool MoveObj::notValidForAll(std::string objName)
{
	return (objName == typeid(Wall).name() || objName == typeid(Giant).name() || objName == typeid(Thief).name()
		|| objName == typeid(King).name() || objName == typeid(Mage).name());
}
