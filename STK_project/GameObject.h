#pragma once
#include "Utilities.h"

class GameObject
{
public:
	
	GameObject(sf::Texture &texture, sf::Vector2f position, sf::Vector2f size);
	virtual ~GameObject() = 0;
	bool doesContain(sf::Vector2f) const;
	virtual void draw(sf::RenderWindow &window);
	sf::Vector2f getPosition();
	sf::Vector2f getSize();
	void setPosition(sf::Vector2f toMove);
	void setFillColor(bool turn);

protected:
	void setFColor(const sf::Color& color);
	void setBackOrigin(sf::Vector2f origin);
	
private:
	sf::Texture m_texture;
	sf::RectangleShape m_rectTexture;
	
};

