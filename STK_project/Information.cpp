#include "Information.h"
#include<sstream>
#include <string.h>



Information::Information(sf::Texture &texture, sf::Vector2f position, sf::Vector2f size, int level, int moves, sf::Time time)
	:GameObject(texture, position, size)
{
	std::string fontFileName = getWinDirName() + "/fonts/arial.ttf";
	m_font.loadFromFile(fontFileName);
	movements = 0;
	m_level = level;
	m_movements = moves;
	m_time = time;
}
//==============================================================

Information::~Information()
{
}
//==============================================================

void Information::moved()
{
	m_countdMoves++;
}
//==============================================================

void Information::setLevel(int level)
{
	m_level = level;
}
//==============================================================

void Information::setTimer(sf::Time time)
{
	m_time = time;
}
//==============================================================
void Information::setMoves(int moves)
{
	m_movements += moves;
}
//==============================================================

void Information::draw(sf::RenderWindow & window)
{
	nexTime();
	
	
	m_movements = movements;

	std::string hour = (m_hour < 10) ? "0"+std::to_string(m_hour) : std::to_string(m_hour);
	std::string minute = (m_minute < 10) ? "0" + std::to_string(m_minute) : std::to_string(m_minute);
	std::string sec = (m_seconds < 10) ? "0" + std::to_string(m_seconds) : std::to_string(m_seconds);

	std::string str = "                             Level: " + std::to_string(m_level)
	+"        " 	+ "Time: " +  hour + ": " + minute+ ": " +sec
	+ "        " + " Movements: " + std::to_string(m_movements);


	sf::Text txt(str, m_font, 30);
	txt.setFillColor(sf::Color::White);
	window.draw(txt);
}
//==============================================================
bool Information::isTimeOver() const
{
	if (m_time.asSeconds() > 0)
		return m_countdTimer.getElapsedTime().asSeconds() <= m_time.asSeconds();
	return true;
}
//==============================================================
bool Information::isMovesOver() const
{
	if (m_movements > 0)
		return movements <= m_movements;
	return true;
}
//==============================================================
void Information::nexTime()
{
	m_seconds = m_countdTimer.getElapsedTime().asSeconds();
	if (m_seconds >= 60)
	{
		m_countdTimer.restart();
		m_seconds = 0;
		m_minute++;
		if (m_minute >= 60)
		{
			m_hour++;
			m_minute = 0;
		}
	}
}
//==============================================================
std::string Information::getWinDirName()
{
	size_t envSize;
	std::string winDirName(1, ' ');
	auto ret = getenv_s(&envSize, &winDirName[0], winDirName.size(), "WINDIR");
	winDirName.resize(envSize);
	ret = getenv_s(&envSize, &winDirName[0], winDirName.size(), "WINDIR");
	winDirName.resize(envSize - 1); // remove the null-terminator
	return winDirName;
}

