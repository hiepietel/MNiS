#include"MessageBox.h"
MessageBox::MessageBox(std::string info1)
{
	info = info1;
	if (!font.loadFromFile("font/arial-black.ttf"))
	{
		//essageBox(NULL, "Font not found!", "ERROR", NULL);
		//return;
	}
	if (!tekstura.loadFromFile("img/warn.png"))
	{
		// error...
	}
	show();
}
MessageBox::~MessageBox()
{

}
void MessageBox::show()
{
	sf::RenderWindow warn(sf::VideoMode(300, 300), "Error", sf::Style::Close);
	sprite.setTexture(tekstura);
	sprite.setPosition(sf::Vector2f((320/2-(sprite.getGlobalBounds().width/2)), 0));
	//sprite.setScale(sf::Vector2f(5.0f, 5.0f));
	sf::Text OK("OK", font, 30);
	OK.setStyle(sf::Text::Bold);
	OK.setPosition(sf::Vector2f(320 / 2 - OK.getGlobalBounds().width / 2, 300-40));
	OK.setFillColor(sf::Color::Red);
	sf::Text Info(info, font, 20);
	Info.setPosition(320 / 2 - Info.getGlobalBounds().width / 2, 180);
	bool open = true;
	while (open == true)
	{
		sf::Event event;
		sf::Vector2f mysz(sf::Mouse::getPosition(warn));
		while (warn.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed &&
				event.key.code == sf::Keyboard::Escape)
				open = false;
			else if (OK.getGlobalBounds().contains(mysz) &&
				event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				open = false;
				//svalue = "";
			}
		}

		warn.clear();
		warn.draw(Info);
		warn.draw(OK);
		warn.draw(sprite);
		warn.display();
	}
}