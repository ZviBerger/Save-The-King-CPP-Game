#include "Menu.h"




Menu::Menu(sf::Texture &texture, sf::Vector2f position, sf::Vector2f size, sf::RenderWindow &myWindow)
	:GameObject(texture, position, size), m_window(myWindow)
{
	m_background.setTexture(&texture);


	for (int index = 0; index < m_buttNum; index++)
	{
	
		sf::RectangleShape rec(sf::Vector2f{ 470.27f,64.35f });
		rec.setFillColor(sf::Color::Color(1, 1, 1, 0));
		m_buttons.push_back(rec);

	}

	m_buttons[0].setPosition(sf::Vector2f{ 365.5,202 });
	m_buttons[1].setPosition(sf::Vector2f{ 365.5,292 });
	m_buttons[2].setPosition(sf::Vector2f{ 365.5,378 });

}

/////////////////////////////////////////////////////////////////
//  newGame
/////////////////////////////////////////////////////////////////
bool Menu::newGame()
{
	m_window.setFramerateLimit(40);
	m_window.setSize(sf::Vector2u(unsigned int(m_windowSize.x), unsigned int(m_windowSize.y)));

	while (m_window.isOpen())
	{
		m_timer += 0.05;

		if (handleEvent())
		{
			m_window.setFramerateLimit(20);	
			return true;
		}
		for (int i = 0; i < 3; i++)
		{
			if (i == m_buttIndex)
				m_buttons[i].setFillColor(sf::Color::Color(215, 48, 39, (abs(sin(m_timer))) * 140));
			else
				m_buttons[i].setFillColor(sf::Color::Color(0, 0, 0, 0));
		}
		m_window.clear();
		GameObject::draw(m_window);
		m_window.draw(m_background);
		m_window.draw(m_buttons[m_buttIndex]);
		m_window.display();

	}

	
	return false;
}
/////////////////////////////////////////////////////////////////
//  show an other window
/////////////////////////////////////////////////////////////////
void Menu::showOtherWindow(const WindowButton &button, std::string path2image,const sf::Vector2f &winSize)
{
	sf::Texture texture;
	sf::RectangleShape winButton(button._size);
	sf::RectangleShape background(winSize);
	sf::Color defColor(sf::Color::Color(0, 0, 0, 0));
	bool onTheButton = false;
	texture.loadFromFile(path2image);
	background.setTexture(&texture);
	winButton.setFillColor(defColor);
	winButton.setPosition(button._position);

	while (m_window.isOpen())
	{
		for (sf::Event event; m_window.pollEvent(event);)
		{
			switch (event.type)
			{
			case sf::Event::MouseMoved:
				if (winButton.getGlobalBounds().contains(sf::Vector2f{ float(event.mouseMove.x),float(event.mouseMove.y) }))
				{
					onTheButton = true;
					winButton.setFillColor(button._presetColor);
				}
				else
				{
					winButton.setFillColor(defColor);
					onTheButton = false;
				}
				break;
			case sf::Event::MouseButtonPressed:
				if (onTheButton)
					return;
				break;
			default:
				break;
			}
		}
		m_window.clear();
		GameObject::draw(m_window);
		m_window.draw(background);
		m_window.draw(winButton);
		m_window.display();
	}
}
/////////////////////////////////////////////////////////////////
//  handle Event
/////////////////////////////////////////////////////////////////
bool Menu::handleEvent()
{
	for (sf::Event event; m_window.pollEvent(event);)
	{
		sf::Vector2f crds{ float(event.mouseMove.x),float(event.mouseMove.y) };
		switch (event.type)
		{
		case sf::Event::MouseMoved:
		{
			for (int i = 0; i < m_buttNum; i++)
				if (m_buttons[i].getGlobalBounds().contains(crds)&& m_buttIndex  != i)
				{
					m_buttIndex = i;
					m_timer = 0;
				}
			break;

		}

		case sf::Event::MouseButtonPressed:
		{
			if (buttenPreset())  return true;

		}
		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				if (m_buttIndex > 0)  m_buttIndex--, m_timer=0;
				break;
			case sf::Keyboard::Down:
				if (m_buttIndex < m_buttNum - 1)  m_buttIndex++, m_timer=0;
				break;
			case sf::Keyboard::Return:
				if (buttenPreset())  return true;
				break;
			default:
				break;
			}
		default:
			break;
		}

	}

	return false;
}
/////////////////////////////////////////////////////////////////
//  buttenPreset
/////////////////////////////////////////////////////////////////
bool Menu::buttenPreset()
{
	switch (m_buttIndex)
	{
	case 0:
		return true;  //the NEW GAME button  pressed
	case 1:
		showHelp();
		break;
	case 2:
		m_window.close();
		break;

	}
	return false;
}
/////////////////////////////////////////////////////////////////
//  showHelp
/////////////////////////////////////////////////////////////////
void Menu::showHelp()
{
	
	WindowButton butten;
	butten._position =sf::Vector2f{ 28,19 };
	butten._size = sf::Vector2f{ 178, 60 };
	butten._presetColor = sf::Color::Color(215, 48, 39, 50);
	
	showOtherWindow(butten, "gamepng/help.png", m_windowSize);
	m_timer = 0;
}

////////////////////////////////////////////////////////////////
// next level
/////////////////////////////////////////////////////////////////
void Menu::nextLevel()
{
	WindowButton butten;
	butten._position = sf::Vector2f{ 365.5,378 };
	butten._size = sf::Vector2f{ 470.27f,64.35f };
	butten._presetColor = sf::Color::Color(215, 48, 39, 50);

	showOtherWindow(butten, "gamepng/next.png", m_windowSize);

}