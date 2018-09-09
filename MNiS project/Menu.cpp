#include"Menu.h"

Menu::Menu(sf::RenderWindow &win)
{
	if (!font.loadFromFile("font/arial-black.ttf"))
	{
		//essageBox(NULL, "Font not found!", "ERROR", NULL);
		//return;
	}

	RunMenu(win);
}
Menu::~Menu()
{
}
void Menu::RunMenu(sf::RenderWindow &window)
{
	sf::Text title("MENU", font, 80);
	title.setStyle(sf::Text::Bold);
	title.setPosition(1280 / 2 - title.getGlobalBounds().width / 2, 20);

	sf::Text choose_funcion("wybierz funkcje:", font, 40);
	choose_funcion.setPosition(50, 100);
	
	sf::Text compartment("okresl przedzial:", font, 40);
	compartment.setPosition(50, 220);

	sf::Text coefficients("okresl wspolczynniki:", font, 40);
	coefficients.setPosition(50, 340);

	sf::Text accuracy("podaj dokladnosc:", font, 40);
	accuracy.setPosition(50, 460);

	sf::Text confirm("POTWIERDZ", font, 40);
	confirm.setStyle(sf::Text::Bold);
	confirm.setPosition(750, 600);

	const int ile = 8;
	sf::Text tekst[ile];
	std::string str[] = { "Asin(Bx)", "Ax^2+B", "Ax^3+Bx", "xp", "xk","A","B", "n" };
	for (int i = 0; i < 3; i++)
	{
		tekst[i].setFont(font);
		tekst[i].setCharacterSize(40);

		tekst[i].setString(str[i]);
		tekst[i].setPosition(1280 / 4 *(i+1) - tekst[i].getGlobalBounds().width / 2,160);
	}
	for (int i = 3; i < 5; i++)
	{
		tekst[i].setFont(font);
		tekst[i].setCharacterSize(40);

		tekst[i].setString(str[i]);
		tekst[i].setPosition(1280 / 3 * (i -2) - tekst[i].getGlobalBounds().width / 2, 280);
	}
	for (int i = 5; i < 7; i++)
	{
		tekst[i].setFont(font);
		tekst[i].setCharacterSize(40);

		tekst[i].setString(str[i]);
		tekst[i].setPosition(1280 / 3 * (i - 4) - tekst[i].getGlobalBounds().width / 2, 400);
	}
	tekst[7].setFont(font);
	tekst[7].setCharacterSize(40);

	tekst[7].setString(str[7]);
	tekst[7].setPosition(1280 / 2 - tekst[7].getGlobalBounds().width / 2, 520);
	/*
	sf::Text sinx("Asin(Bx)", font, 40);
	sinx.setPosition(1280/4 - sinx.getGlobalBounds().width, 150);

	sf::Text par("Ax^2+B", font, 40);
	par.setPosition(1280 / 2 - par.getGlobalBounds().width, 150);

	sf::Text polynomial("Asin(Bx)", font, 40);
	polynomial.setPosition(1280 / 4 *3 - polynomial.getGlobalBounds().width, 150);
	*/

	bool open = true;

	while (open==true)
	{
		sf::Event event;
		sf::Vector2f mysz(sf::Mouse::getPosition(window));
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed &&
				event.key.code == sf::Keyboard::Escape)
				open = false; 
			else if (event.key.code == sf::Keyboard::Num1 && event.type == sf::Event::KeyPressed)
			{
				form = "sinx";
				funkcja.set_xp(-M_PI / 2);
				funkcja.set_xk(M_PI / 2);
				funkcja.set_A(1.0);
				funkcja.set_B(1.0);
				funkcja.set_N(20.0);
				funkcja.run(window, form);
			}
			else if (event.key.code == sf::Keyboard::Num2 && event.type == sf::Event::KeyPressed)
			{
				form = "par";
				funkcja.set_xp(-4);
				funkcja.set_xk(4);
				funkcja.set_A(-4.0);
				funkcja.set_B(10.0);
				funkcja.set_N(20.0);
				funkcja.run(window, form);
			}
			else if (event.key.code == sf::Keyboard::Num3 && event.type == sf::Event::KeyPressed)
			{
				form = "pol";
				funkcja.set_xp(-10);
				funkcja.set_xk(10);
				funkcja.set_A(-4.0);
				funkcja.set_B(10.0);
				funkcja.set_N(80.0);
				funkcja.run(window, form);
			}
			else if (tekst[0].getGlobalBounds().contains(mysz) &&
				event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				form = "sinx"; 
			}
			else if (tekst[1].getGlobalBounds().contains(mysz) &&
				event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				form = "par";
			}
			else if (tekst[2].getGlobalBounds().contains(mysz) &&
				event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				form = "pol";
			}
			else if (tekst[3].getGlobalBounds().contains(mysz) &&
				event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				Calculator calculator;
				funkcja.set_xp(calculator.get_value());
				tekst[3].setString("xp = "+std::to_string(calculator.get_value()));
				tekst[3].setPosition(1280 / 3  - tekst[3].getGlobalBounds().width / 2, 280);

			}
			else if (tekst[4].getGlobalBounds().contains(mysz) &&
				event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				Calculator calculator;
				funkcja.set_xk(calculator.get_value());
				tekst[4].setString("xk = " + std::to_string(calculator.get_value()));
				tekst[4].setPosition(1280 / 3*2 - tekst[3].getGlobalBounds().width / 2, 280);

			}
			else if (tekst[5].getGlobalBounds().contains(mysz) &&
				event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				Calculator calculator;
				funkcja.set_A(calculator.get_value());
				tekst[5].setString("A = " + std::to_string(calculator.get_value()));
				tekst[5].setPosition(1280 / 3 - tekst[3].getGlobalBounds().width / 2, 400);

			}
			else if (tekst[6].getGlobalBounds().contains(mysz) &&
				event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				Calculator calculator;
				funkcja.set_B(calculator.get_value());
				tekst[6].setString("B = " + std::to_string(calculator.get_value()));
				tekst[6].setPosition(1280 / 3 * 2 - tekst[6].getGlobalBounds().width / 2, 400);

			}
			else if (tekst[7].getGlobalBounds().contains(mysz) &&
				event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				Accuracy acc;
				if (acc.get_value() < 1)
				{
					MessageBox box("n musi byc wieksze od 0");
					tekst[7].setString("n");
					tekst[7].setPosition(1280 / 2 - tekst[7].getGlobalBounds().width / 2, 520);
				}
				else {
					funkcja.set_N(acc.get_value());
					tekst[7].setString("n = " + std::to_string(acc.get_value()));
					tekst[7].setPosition(1280 / 2 - tekst[7].getGlobalBounds().width / 2, 520);
				}
			}
			else if (confirm.getGlobalBounds().contains(mysz) &&
				event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				if (funkcja.get_xp() > funkcja.get_xk())
				{
					MessageBox box("xk musi byc wieksze od xp");
					funkcja.set_compartment(false);
				}
				else { funkcja.set_compartment(true); }
				if (form == "") {
					MessageBox box("musisz wybrac funkcje");
					funkcja.set_function_choosen(false);
				}
				else { funkcja.set_function_choosen(true); }
				if (tekst[5].getString() == "A" || tekst[6].getString() == "B") {
					MessageBox box("musisz okreslic A i B");
					funkcja.set_precission(false);
				}
				else { funkcja.set_precission(true); }
				if (funkcja.get_N() < 1)
				{
					MessageBox box("n musi byc wieksze od 0");
					funkcja.set_factor(false);
				}
				else {
					funkcja.set_factor(true);
				}
				if (funkcja.go() == true) {
					//funkcja.set_window(window);
					//MessageBox box("123");
						//funkcja.assign(form);
						funkcja.run(window, form);
				}
			}
		}
		//sf::Text tekst[] = { sinx, par, polynomial };

		for (int i = 0; i < ile; i++)
		{
			if (tekst[i].getGlobalBounds().contains(mysz))
				tekst[i].setFillColor(sf::Color::Cyan);

			else tekst[i].setFillColor(sf::Color::White);
		}
		if(confirm.getGlobalBounds().contains(mysz))
			confirm.setFillColor(sf::Color::Red);
		else {
			confirm.setFillColor(sf::Color::White);
		}
		if (form=="sinx") tekst[0].setFillColor(sf::Color::Red);
		else if (form == "par") tekst[1].setFillColor(sf::Color::Red);
		else if (form == "pol") tekst[2].setFillColor(sf::Color::Red);
		window.clear();
		window.draw(title);
		window.draw(confirm);
		window.draw(choose_funcion);
		window.draw(compartment);
		window.draw(coefficients);
		window.draw(accuracy);
		for (int i = 0; i<ile; i++)
			window.draw(tekst[i]);

		/*window.draw(sinx);
		window.draw(polynomial);
		window.draw(par);*/
		
		window.display();
	}

}