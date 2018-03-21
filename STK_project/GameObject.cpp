#include "GameObject.h"




GameObject::GameObject(sf::Texture &texture, sf::Vector2f position, sf::Vector2f size)
	:m_texture{texture}
{
	
	m_rectTexture.setPosition(position);
	m_rectTexture.setSize(size);
	m_rectTexture.setOutlineThickness(0);
	m_rectTexture.setTexture(&m_texture);

	
}


GameObject::~GameObject()
{
}

//=================================================================
//checks if some location is in global bounds of sprite
bool GameObject::doesContain(sf::Vector2f location) const
{
	return m_rectTexture.getGlobalBounds().contains(location);
}

//=================================================================
//draw object
void GameObject::draw(sf::RenderWindow & window)
{
	window.draw(m_rectTexture);
}

//=================================================================
//return position
sf::Vector2f GameObject::getPosition()
{
	return m_rectTexture.getPosition();
}

//=================================================================
//return size
sf::Vector2f GameObject::getSize()
{
	return m_rectTexture.getSize();
}

//=================================================================
//set new position
void GameObject::setPosition(sf::Vector2f toMove)
{
	
	m_rectTexture.move(toMove);
}

//=================================================================
//set fill color for the player
void GameObject::setFillColor(bool turn)
{
	if (turn)
		m_rectTexture.setFillColor(sf::Color::Yellow);
	else
		m_rectTexture.setFillColor(sf::Color::Color(255,255,255,255));
}

//=================================================================
//set color for the wall
void GameObject::setFColor(const sf::Color &color)
{
	m_rectTexture.setFillColor(color);
}

//=================================================================
//set back position to origin
void GameObject::setBackOrigin(sf::Vector2f origin)
{
	m_rectTexture.setPosition(origin);
}
