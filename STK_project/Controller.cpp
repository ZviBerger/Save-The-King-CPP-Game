#include "Controller.h"
#include <fstream>
#include "King.h"

int Information::movements;
bool King::m_cameToThrone;

Controller::Controller()
{
}


Controller::~Controller()
{
}

//====================================================================
//gets names of levels, creates each level
//====================================================================
void Controller::letsPlay(std::string levelPathFile)
{
	setLevel(levelPathFile);

	m_window.create(sf::VideoMode(1200, 600), "Save The King");
	m_size = { 1200, 600 };
	m_texture.loadFromFile("gamepng/manu.png");
	m_backgraund.setSize(m_size);

	while (m_window.isOpen())
	{

		Menu menu{ m_texture, sf::Vector2f{0,0}, m_size ,m_window};
		
		if(menu.newGame()) //for any level call runLevel function
		for (unsigned int level = 0; level < m_level.size()&& m_window.isOpen(); level++)
		{
			runLevel(level); // run the current level
			menu.nextLevel(); // show the next level choice window

		}
	}	
}

//====================================================================
// etLevel- Read from Levels.txt the other files names
//====================================================================
void Controller::setLevel(std::string levelsPathFile)
{
	std::ifstream stream(levelsPathFile);
	std::string level;
	while (getline(stream, level))
	{
		m_level.push_back(level);
	}
}

//====================================================================
//gets number of level, sets in board and runs the game
//====================================================================
bool Controller::runLevel(const unsigned int  & Mylevel)
{
	if (Mylevel >= m_level.size())
		return false;
	sf::Texture backText;
	backText.loadFromFile("gamepng/backgraund.png");
	m_backgraund.setTexture(&backText);
	
	
	m_window.clear();

	
	//Initialize the current board level
	m_board = std::make_unique<Board>(m_size, m_level[Mylevel]);
	
	m_info = std::make_unique<Information>(m_texture, sf::Vector2f{ 0,0 }, sf::Vector2f{ m_size.x, 60 }, (int)Mylevel +1, 0, sf::Time{});
	//int Information::movements = 0;
	m_window.draw(m_backgraund);
	

	
	m_dwTimeDwn = sf::seconds(0.0001); //timer for moving dwarfs
	m_dwarfTime.restart();			 //clock to move dwarfs



	//Print board and status for the first time
	m_board->draw(m_window);
	m_window.display();
	

	//The core of the game Level:
	while (m_window.isOpen() && !onThrone()) 
	{
		eventManeger();
		
		//if timer == clock, move dwarfs
		if (m_dwarfTime.getElapsedTime().asSeconds() >= m_dwTimeDwn.asSeconds())
		{

			m_board->moveDwarfs();
			//reset clock
			m_dwarfTime.restart();
		}

		m_window.clear();
		m_window.draw(m_backgraund);
		
		m_board->draw(m_window);
		m_info->draw(m_window);
		m_window.display();

	} 

	m_board.reset();
	m_info.reset();
	//m_statusPlay.reset();
	return  true;
}

//============================================================================
//gets events from user and calls board according to that
void Controller::eventManeger()
{

	for (sf::Event event; m_window.pollEvent(event); )
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;

			case sf::Event::MouseButtonPressed:
			{
				auto mp = sf::Vector2f{ float(event.mouseButton.x) , float(event.mouseButton.y ) };
				m_board->chooseObj(mp);
				break;
			}
			case sf::Event::KeyPressed:
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					m_board->movePlayer(Direction::UP);
					break;				
				case sf::Keyboard::Right:
					m_board->movePlayer(Direction::RIGHT);
					break;
				case sf::Keyboard::Left:
					m_board->movePlayer(Direction::LEFT);
					break;
				case sf::Keyboard::Down:
					m_board->movePlayer(Direction::DOWN);
					break;
				case sf::Keyboard::Escape:
					m_window.close();
					break;
				default:
					break;
				}
			}
			default:
				break;
			}
			return;
		}
}
