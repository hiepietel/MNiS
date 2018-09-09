#pragma once
#include<SFML\Graphics.hpp>
class MessageBox
{
public:
	MessageBox(std::string info1);
	~MessageBox();
	void show();
private:
	sf::Font font;
	sf::Texture tekstura;
	sf::Sprite sprite;
	std::string info;
};