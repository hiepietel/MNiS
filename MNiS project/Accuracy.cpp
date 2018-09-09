#include"Accuracy.h"
Accuracy::Accuracy()
{
	if (!font.loadFromFile("font/arial-black.ttf"))
	{
		//essageBox(NULL, "Font not found!", "ERROR", NULL);
		//return;
	}
	value = 0;
	//pi_enabled = false;
	run();
}
Accuracy::~Accuracy()
{
}
void Accuracy::run()
{
	sf::RenderWindow accu(sf::VideoMode(320, 240), "calc", sf::Style::Close);
	const int ile = 8;
	sf::Text tekst[ile];
	std::string str[] = { "+1", "+10", "+100", "-1", "-10", "-100","RESET","OK" };
	for (int i = 0; i < 3; i++)
	{
		tekst[i].setFont(font);
		tekst[i].setCharacterSize(30);

		tekst[i].setString(str[i]);
		tekst[i].setPosition(320 / 4 * (i + 1) - tekst[i].getGlobalBounds().width / 2, 80);
	}
	for (int i = 3; i < 6; i++)
	{
		tekst[i].setFont(font);
		tekst[i].setCharacterSize(30);

		tekst[i].setString(str[i]);
		tekst[i].setPosition(320 / 4 * (i - 2) - tekst[i].getGlobalBounds().width / 2, 140);
	}
	for (int i = 6; i < ile; i++)
	{
		tekst[i].setFont(font);
		tekst[i].setCharacterSize(30);

		tekst[i].setString(str[i]);
		tekst[i].setPosition(320 / 3 * (i - 5) - tekst[i].getGlobalBounds().width / 2, 200);
	}
	sf::VertexArray mon(sf::LinesStrip, 5);
	mon[0].position = sf::Vector2f(10, 10);
	mon[1].position = sf::Vector2f(320 - 10, 10);
	mon[2].position = sf::Vector2f(320 - 10, 50);
	mon[3].position = sf::Vector2f(10, 50);
	mon[4].position = sf::Vector2f(10, 10);
	for (int i = 0; i < 5; i++) mon[i].color = sf::Color::Cyan;
	bool open = true;
	sf::Text tvalue("", font, 30);
	tvalue.setStyle(sf::Text::Bold);
	tvalue.setPosition(20, 10);
	while (open == true)
	{
		sf::Event event;
		sf::Vector2f mysz(sf::Mouse::getPosition(accu));
		while (accu.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed &&
				event.key.code == sf::Keyboard::Escape)
				open = false;
			else if (tekst[0].getGlobalBounds().contains(mysz) &&
				event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				value++;
				//svalue = "";
			}
			else if (tekst[1].getGlobalBounds().contains(mysz) &&
				event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				value += 10;
				//svalue = "";
			}
			else if (tekst[2].getGlobalBounds().contains(mysz) &&
				event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				value += 100;
			}
			else if (tekst[3].getGlobalBounds().contains(mysz) &&
				event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				value -= 1;
				//svalue = "";
			}
			else if (tekst[4].getGlobalBounds().contains(mysz) &&
				event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				value -= 10;
				//svalue = "";
			}
			else if (tekst[5].getGlobalBounds().contains(mysz) &&
				event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				value -=100;
				//svalue = "";
			}
			else if (tekst[6].getGlobalBounds().contains(mysz) &&
				event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				//przycisk reset
				value = 0;
				//svalue = "";
			}
			else if (tekst[7].getGlobalBounds().contains(mysz) &&
				event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				//przycisk ok
				open = false;
			}
		}
		for (int i = 0; i < ile; i++)
		{
			if (tekst[i].getGlobalBounds().contains(mysz))
				tekst[i].setFillColor(sf::Color::Cyan);

			else tekst[i].setFillColor(sf::Color::White);
		}
		//std::string sval = std::to_string(value);
		value = round(value * 10) / 10;
		svalue = std::to_string(value);
		tvalue.setString(svalue);
		accu.clear();
		accu.draw(tvalue);
		accu.draw(mon);
		for (int i = 0; i<ile; i++)
			accu.draw(tekst[i]);
		//calc.clear();
		//calc.draw();
		accu.display();
	}
}
double Accuracy::get_value()
{
	return value;
}