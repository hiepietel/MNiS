#include "Intro.h"

sf::RenderWindow window(sf::VideoMode(1280, 720), "MNiS project", sf::Style::Close);

Intro::Intro()
{
	state = END;
	if (!font.loadFromFile("font/arial-black.ttf"))
	{
		//essageBox(NULL, "Font not found!", "ERROR", NULL);
		//return;
	}
	state = INTRO;
}
Intro::~Intro()
{

}
void Intro::run_intro()
{
	sf::Text title("MNiS project", font, 100);
	title.setStyle(sf::Text::Bold);
	sf::Text start("START", font, 100);
	start.setStyle(sf::Text::Bold);
	sf::Text content("3B: calkowanie metoda  trapezow", font, 60);
	start.setStyle(sf::Text::Bold);

	title.setPosition(1280 / 2 - title.getGlobalBounds().width / 2, 20);
	start.setPosition(1280 / 2 - start.getGlobalBounds().width / 2, 720 / 2 - start.getGlobalBounds().height / 2);
	content.setPosition(1280 / 2 - content.getGlobalBounds().width / 2, 140);
	
	const int ile = 3;
	sf::Text dane[ile];

	std::string str[] = { "Jan Pietrzak","gr A4p", "127 128" };
	for (int i = 0; i < ile; i++)
	{
		dane[i].setFont(font);
		dane[i].setCharacterSize(30);

		dane[i].setString(str[i]);
		dane[i].setPosition(1000, 540 + i * 40);
	}

	while (state == INTRO)
	{
		sf::Vector2f mouse(sf::Mouse::getPosition(window));
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				state = END;
			else if (start.getGlobalBounds().contains(mouse) && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
				state = MENU;
			else if (event.key.code == sf::Keyboard::Space && event.type == sf::Event::KeyPressed)
				state = MENU;
		}
		if (start.getGlobalBounds().contains(mouse))
			start.setFillColor(sf::Color::Cyan);

		else start.setFillColor(sf::Color::White);
		
		window.clear();
		window.draw(content);
		for (int i = 0; i<ile; i++)
			window.draw(dane[i]);
		window.draw(title);
		window.draw(start);
		window.display();
	}
	if (state == MENU)
	{
		Menu menu(window);
		state = END;
	}
}