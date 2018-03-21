#include "Board.h"



Board::Board()
{
}

Board::Board(sf::Vector2f size,std::string level)
	:m_size{size}
{
	m_theFile.open(level);
	for (int i = 0; i < 11; i++)
	{
		m_textures[i].loadFromFile(m_path[i]);
	}
	setBrdVec();
}


Board::~Board()
{
}

//====================================================
//draw the board
void Board::draw(sf::RenderWindow & window)
{
	//draw static objects
	for (size_t i = 0; i < m_rowsNum; i++)
	{
		for (size_t j = 0; j < m_colsNum; j++)
		{
			if (m_boarVec[i][j])
				m_boarVec[i][j]->draw(window);
		}
	}
	//draw dwarfs
	for (auto& d : m_dwarfs)
		d->draw(window);
	//draw player objects
	for (auto& p : m_playObj)
		p->draw(window);
}

//=================================================================
//moves player objects according to direction
void Board::movePlayer(const Direction &direction)
{
	for (auto& p : m_playObj)
		p->go2(direction, *this);
	
}

//====================================================================
//moves all dwarfs
void Board::moveDwarfs()
{
	for (auto& d : m_dwarfs)
		d->go2(d->getDirection() ,*this);
	
}

//====================================================================
//sets the object that the player is using
void Board::chooseObj(sf::Vector2f location)
{
	for (auto& p : m_playObj)
		if (p->doesContain(location))
		{
			turnOffObj();
			p->setPlayarOb(true);
		}
}

//================================================================================
//gets the string of board and size, calls function that sets board
void Board::setTheBoard(sf::Vector2f size, std::string level)
{
	m_size = size;
	m_theFile.open(level);
	setBrdVec();
}

//====================================================================
//sets the vectors of all objects
void Board::setBrdVec()
{
	
	m_boarVec.clear();
	m_playObj.clear();
	m_dwarfs.clear();
	std::string line;
	if (m_theFile.is_open())
	{
		getline(m_theFile, line);	//Read a line.
		m_rowsNum = atoi(line.c_str());//reads the number of rows
		
		getline(m_theFile, line);
		m_colsNum = atoi(line.c_str());  //reads the number of columns


		m_iconSize = { m_size.x / m_colsNum,(m_size.y - 60) / m_rowsNum };

		std::vector <std::unique_ptr<StaticObj>> oneLine;
		for (int i = 0; i < m_rowsNum; i++)
		{
			for (int j = 0; j < m_colsNum; j++)
			{
				
				bool wasSet = false;
				switch (m_theFile.get())
				{
					case ('='): 
					{
						oneLine.push_back(std::make_unique<Wall>(m_textures[1], sf::Vector2f{ (m_iconSize.x)*j, (m_iconSize.y)*i + 60 }, m_iconSize));
						wasSet = true;
						break;
					}
					case ('*'):
					{
						oneLine.push_back(std::make_unique<Fire>(m_textures[2], sf::Vector2f{ (m_iconSize.x)*j, (m_iconSize.y)*i + 60 }, m_iconSize));
						wasSet = true;
						break;
					}
					case ('F'):
					{
						oneLine.push_back(std::make_unique<GateKey>(m_textures[3], sf::Vector2f{ (m_iconSize.x)*j, (m_iconSize.y)*i + 60 }, m_iconSize));
						wasSet = true;
						break;
					}
					case ('@'):
					{
						oneLine.push_back(std::make_unique<Throne>(m_textures[4], sf::Vector2f{ (m_iconSize.x)*j, (m_iconSize.y)*i + 60 }, m_iconSize));
						wasSet = true;
						break;
					}
					case ('#'):
					{
						oneLine.push_back(std::make_unique<Gate>(m_textures[5], sf::Vector2f{ (m_iconSize.x)*j, (m_iconSize.y)*i + 60 }, m_iconSize));
						wasSet = true;
						break;
					}
					case ('K'):
					{
						m_playObj.push_back(std::make_unique<King>(m_textures[6], sf::Vector2f{ (m_iconSize.x)*j, (m_iconSize.y)*i + 60 }, m_iconSize));
						break;
					}
					case ('G'):
					{
						m_playObj.push_back(std::make_unique<Giant>(m_textures[7], sf::Vector2f{ (m_iconSize.x)*j, (m_iconSize.y)*i + 60 }, m_iconSize));
						break;
					}
					case ('T'):
					{
						m_playObj.push_back(std::make_unique<Thief>(m_textures[8], sf::Vector2f{ (m_iconSize.x)*j, (m_iconSize.y)*i + 60 }, m_iconSize));
						break;
					}
					case ('M'):
					{
						m_playObj.push_back(std::make_unique<Mage>(m_textures[9], sf::Vector2f{ (m_iconSize.x)*j, (m_iconSize.y)*i + 60 }, m_iconSize));
						break;
					}
					case ('^'):
					{
						m_dwarfs.push_back(std::make_unique<Dwarfs>(m_textures[10], sf::Vector2f{ (m_iconSize.x)*j, (m_iconSize.y)*i + 60 }, m_iconSize));
						break;
					}
					default:
						break;
				}
				if(!wasSet)
					oneLine.push_back(nullptr);
			}
			m_boarVec.push_back(std::move(oneLine));
			m_theFile.get();
		}
	}
}

//==============================================================
//sets location and returns the name of object on location
std::string Board::objectNameOnPlace(sf::Vector2f location)
{
	bool found = false, onKey = false;
	std::string objectName;
	int row = (int)((location.y - 60) / m_iconSize.y);
	int col = (int)(location.x / m_iconSize.x);
	if (m_boarVec[row][col])
	{
		objectName = typeid(*m_boarVec[row][col]).name();
		found = true;
		if (objectName == typeid(GateKey).name())
			onKey = true;
	}
	if(!found || onKey)
	{
		found = false;
		for (auto& p : m_playObj)
			if (p->doesContain(location))
			{
				objectName = typeid(*p).name();
				found = true;
				break;
			}
		if (!found)
			for (auto& d : m_dwarfs)
				if (d->doesContain(location))
				{
					objectName = typeid(Dwarfs).name();
					found = true;
					break;
				}
	}

	if (!found && !onKey)
	{
		objectName = "EMPTY";
	}
	return objectName;
}

//===================================================================
//returns true if location is bounders
bool Board::isInBoundeOfBoard(sf::Vector2f location)
{
	return (location.x >= 0 && location.x <= m_size.x && location.y >=60 && location.y <= m_size.y);
}

//===================================================================
//gets location and object name and removes from vector
void Board::removeCellfromBoard(sf::Vector2f place, std::string name)
{
	std::string objectName;
	int row = (int)((place.y-60) / m_iconSize.y);
	int col = (int)(place.x / m_iconSize.x);
	if ((m_boarVec[row][col]) && name == typeid(*m_boarVec[row][col]).name())
		m_boarVec[row][col].reset();
		
}

//==================================================================================
//returns dwarf to first place
void Board::sendBackDwarf(sf::Vector2f location)
{
	for (auto& d : m_dwarfs)
		if (d->doesContain(location))
		{
			d->goBack();
			break;
		}
	
}

//==============================================================
//sets all player objects not selected
void Board::turnOffObj()
{
	for (size_t i = 0; i < m_playObj.size(); i++)
	{
		m_playObj[i]->setPlayarOb(false);
	}
}
