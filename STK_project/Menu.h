#pragma once
#include "GameObject.h"
struct WindowButton
{
	sf::Vector2f _position;
	sf::Vector2f _size;
	sf::Color _presetColor;
};

/////////////////////////////////////////////////////////////////////////////////////////////////
class Menu :public GameObject
{
public:

	Menu(sf::Texture &texture, sf::Vector2f position, sf::Vector2f size, sf::RenderWindow &myWindow);


	bool newGame();
	void nextLevel();

private:
	float m_timer = 1;
	float m_thickness = 1;
	int m_buttIndex = 0;
	int m_buttNum = 3;
	sf::RenderWindow &m_window;
	sf::RectangleShape m_background;
	std::vector<sf::RectangleShape> m_buttons;
	sf::Vector2f m_windowSize{ 1200 , 600 };
	void Menu::showOtherWindow(const WindowButton &button, std::string path2image,const sf::Vector2f &winSize);
	bool handleEvent();
	bool buttenPreset();
	void showHelp();

};
