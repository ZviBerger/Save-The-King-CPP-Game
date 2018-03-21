#pragma once
#include "PlayersObj.h"

//bool King::m_cameToThrone ;

class King :public PlayersObj
{
public:
	King(sf::Texture &texture, sf::Vector2f position, sf::Vector2f size);
	~King();
	
	virtual void go2(const Direction& direction, Board &brd) override;
	bool notAloud(std::string objName);
	static bool m_cameToThrone;

private:
	
};
bool onThrone();
