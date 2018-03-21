#pragma once
#ifdef _DEBUG
#pragma comment(lib, "sfml-main-d.lib")
#pragma comment(lib, "sfml-system-d.lib")
#pragma comment(lib, "sfml-window-d.lib")
#pragma comment(lib, "sfml-graphics-d.lib")
#elif defined(NDEBUG)
#pragma comment(lib, "sfml-main.lib")
#pragma comment(lib, "sfml-system.lib")
#pragma comment(lib, "sfml-window.lib")
#pragma comment(lib, "sfml-graphics.lib")
#else
#error "Unrecognized configuration!"
#endif
#include	"Board.h"
#include	"Information.h"
#include	"Menu.h"
#include	<string>



class Controller
{
public:
	Controller();
	~Controller();
	void letsPlay(std::string levelPathFile);

private:
	std::unique_ptr<Board> m_board;
	std::unique_ptr<Information> m_info;
	sf::Vector2f m_size;
	sf::Clock m_dwarfTime;
	sf::Time m_dwTimeDwn;
	std::vector<std::string> m_level;
	void setLevel(std::string levelsPathFile);
	bool runLevel(const unsigned int  & Mylevel);

	void eventManeger();
	sf::RenderWindow m_window;
	sf::Texture m_texture;
	sf::RectangleShape m_backgraund;

};

