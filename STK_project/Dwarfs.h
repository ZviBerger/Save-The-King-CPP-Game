#pragma once
#include "MoveObj.h"

//class Board;

class Dwarfs :public MoveObj
{
public:
	Dwarfs(sf::Texture &texture, sf::Vector2f position, sf::Vector2f size);
	~Dwarfs();
	void goBack();
	virtual void draw(sf::RenderWindow &window);
	virtual void go2(const Direction& direction, Board &brd)override;
	Direction getDirection();



private:
	sf::Vector2f m_origin;
	void setRandomMove();
	Direction m_direction;
	bool isValidMove(std::string) const;
};

