#pragma once
#include "PlayersObj.h"

class Thief :public PlayersObj
{
public:
	Thief(sf::Texture &texture, sf::Vector2f position, sf::Vector2f size);
	~Thief();
	bool hasAKey();
	virtual void go2(const Direction & direction, Board & brd) override;
	bool notAloud(std::string objName);

private:
	bool m_hasAKey;
};

