#pragma once
#include "GameObject.h"

//Information::movements = 0;

class Information :public GameObject
{
public:
	//Information();
	Information(sf::Texture &texture, sf::Vector2f position, sf::Vector2f size, int level, int moves, sf::Time time);
	~Information();
	void moved();
	void setLevel(int level);
	void setTimer(sf::Time time);
	void setMoves(int moves);
	virtual void draw(sf::RenderWindow &window);
	bool isTimeOver()const;
	bool isMovesOver()const;
	void nexTime();
	std::string getWinDirName();
	static int movements ;
private:
	int m_level;
	int m_movements;
	int m_countdMoves = 0;
	int m_hour = 0;
	int m_minute = 0;
	int m_seconds = 0;
	sf::Font m_font;
	sf::Time m_time;
	sf::Clock m_countdTimer;
	
};

