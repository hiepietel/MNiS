#include"Calculator.h"

//sf::RenderWindow calc(sf::VideoMode(320, 480), "calc", sf::Style::Default);
Calculator::Calculator()
{
	if (!font.loadFromFile("font/arial-black.ttf"))
	{
		//essageBox(NULL, "Font not found!", "ERROR", NULL);
		//return;
	}
	value = 0;
	pi_enabled = false;
	run();
}
Calculator::~Calculator()
{

}
void Calculator::run()
{
	sf::RenderWindow calc(sf::VideoMode(320, 240), "calc", sf::Style::Close);
	const int ile = 8;
	sf::Text tekst[ile];
	std::string str[] = { "+1", "+0,1", "M_PI", "-1", "-0,1", "+/-","RESET","OK" };
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
	mon[1].position = sf::Vector2f(320 - 60, 10);
	mon[2].position = sf::Vector2f(320 - 60, 50);
	mon[3].position = sf::Vector2f(10, 50);
	mon[4].position = sf::Vector2f(10, 10);
	for (int i = 0; i < 5; i++) mon[i].color = sf::Color::Cyan;
	bool open = true;
	sf::Text tvalue("", font, 30);
	tvalue.setStyle(sf::Text::Bold);
	tvalue.setPosition(20, 10);

	sf::Text tpi("*pi", font, 30);
	tpi.setStyle(sf::Text::Bold);
	tpi.setPosition(320-50, 10);
	//tvalue.setPosition(320 / 2 - tvalue.getGlobalBounds().width / 2, 10);

	while (open == true)
	{
		sf::Event event;
		sf::Vector2f mysz(sf::Mouse::getPosition(calc));
		while (calc.pollEvent(event))
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
				value += 0.1;
				//svalue = "";
			}
			else if (tekst[2].getGlobalBounds().contains(mysz) &&
				event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{				
				if (pi_enabled == true)
					pi_enabled = false;
			else if (pi_enabled == false)
					pi_enabled = true;
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
				value -= 0.1;
				//svalue = "";
			}
			else if (tekst[5].getGlobalBounds().contains(mysz) &&
				event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				value =-value;
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
		calc.clear();
		if (pi_enabled == true)
			calc.draw(tpi);
		calc.draw(tvalue);
		calc.draw(mon);
		for (int i = 0; i<ile; i++)
			calc.draw(tekst[i]);
		//calc.clear();
		//calc.draw();
		calc.display();
	}
}
double Calculator::get_value()
{
	if (pi_enabled)
		return value*M_PI;
	else
		return value;
}