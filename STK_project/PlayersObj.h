#pragma once
#include"MoveObj.h"

class PlayersObj :public MoveObj
{
public:
	PlayersObj(sf::Texture &texture, sf::Vector2f position, sf::Vector2f size);
	~PlayersObj();

	virtual void draw(sf::RenderWindow &window);
	void setPlayarOb(bool selected);
	bool isSelected();


private:
	bool m_isSelectOb;
};

