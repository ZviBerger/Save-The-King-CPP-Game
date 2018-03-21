#pragma once
#include "GameObject.h"
#include "Utilities.h"

class Board;

class MoveObj :public GameObject
{
public:
	using GameObject::GameObject;
	
	
	virtual void go2(const Direction& direction, Board &brd)=0;
	virtual void draw(sf::RenderWindow &window);
	virtual bool isValidPlace(std::string objName);
	bool notValidForAll(std::string objName);

private:
	


};

