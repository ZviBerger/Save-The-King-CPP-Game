#pragma once
#include "Dwarfs.h"
//#include "PlayersObj.h"
//#include "StaticObj.h"
#include "Wall.h"
#include "King.h"
#include "Mage.h"
#include "Giant.h"
#include "Thief.h"
#include "Throne.h"
#include "Gate.h"
#include "GateKey.h"
#include "Fire.h"
#include <fstream>
#include <vector>
#include <memory>


class Board
{
public:
	Board();
	Board(sf::Vector2f size, std::string level);
	~Board();
	void draw(sf::RenderWindow &window);
	void movePlayer(const Direction &direction);
	void moveDwarfs();
	void chooseObj(sf::Vector2f location);
	void setTheBoard(sf::Vector2f size, std::string level);
	void setBrdVec();
	std::string objectNameOnPlace(sf::Vector2f location);
	bool isInBoundeOfBoard(sf::Vector2f location);
	void removeCellfromBoard(sf::Vector2f place, std::string name);
	void sendBackDwarf(sf::Vector2f location);

private:
	std::vector<std::vector<std::unique_ptr <StaticObj>>> m_boarVec;
	std::vector<std::unique_ptr<Dwarfs>> m_dwarfs;
	std::vector<std::unique_ptr<PlayersObj>> m_playObj;
	
	sf::Texture m_textures[11];

	std::string m_path[11]{ "gamepng/empty.jfif" ,"gamepng/wall1.png" ,"gamepng/fire.png" ,"gamepng/key.png" ,
		"gamepng/throne.png" ,"gamepng/gate.png" ,"gamepng/king.png" ,"gamepng/giant.png" 
		,"gamepng/thief.png" ,"gamepng/mage.png" ,"gamepng/dwarf.png" };


	std::ifstream m_theFile;  //STK.txt
	sf::Vector2f m_size;
	sf::Vector2f m_iconSize;
	int m_rowsNum;
	int m_colsNum;
	void turnOffObj();
	
};

