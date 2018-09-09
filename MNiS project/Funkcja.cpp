#include"Funkcja.h"
#include<cmath>
#include<iostream>
#include<queue>
Funkcja::Funkcja()
{
	if (!font.loadFromFile("font/arial-black.ttf"))
	{
		//essageBox(NULL, "Font not found!", "ERROR", NULL);
		//return;
	}
}
void Funkcja::set_xk(double xk1)
{
	xk = xk1;
}
void Funkcja::set_xp(double xp1)
{
	xp = xp1;
}
void Funkcja::set_A(double A1)
{
	A = A1;
}
void Funkcja::set_B(double B1)
{
	B = B1;
}
void Funkcja::set_N(double N1)
{
	N = N1;
}
double Funkcja::get_xk()
{
	return xk;
}
double Funkcja::get_xp()
{
	return xp;
}
double Funkcja::get_A()
{
	return A;
}
double Funkcja::get_B()
{
	return B;
}
double Funkcja::get_N()
{
	return N;
}
void Funkcja::set_function_choosen(bool function_choosen1)
{
	function_choosen = function_choosen1;
}
void Funkcja::set_compartment(bool compartment1)
{
	compartment = compartment1;
}
void Funkcja::set_precission(bool precission1)
{
	precission = precission1;
}
void Funkcja::set_factor(bool factor1)
{
	factor = factor1;
}
bool Funkcja::go()
{
	if (factor == true && precission == true && compartment == true && function_choosen == true)
		return true;
	else return false;
}
double Funkcja::assign(double x, double A, double B, std::string str, int up)
{
	if (str == "sinx")
	{
		return up*A*sin(B*x);
	}
	if (str == "par")
	{
		return up*A*x*x+up*B;
	}
	if (str == "pol")
	{
		return up*A*x*x*x + up*B*x;
	}
}
std::string Funkcja::x_od_y(std::string str)
{
	if (str == "sinx")
	{
		std::string strA = std::to_string(A);
		strA.erase(strA.size() - 5, 5);
		std::string strB = std::to_string(B);
		strB.erase(strB.size() - 5, 5);
		return "f(x)=" + strA + "sin(" + strB + "x)";
	}
	if (str == "par")
	{
		std::string strA = std::to_string(A);
		strA.erase(strA.size() - 5, 5);
		std::string strB = std::to_string(B);
		strB.erase(strB.size() - 5, 5);
		return "f(x) = "+strA+"x^2+"+strB;
	}
	if (str == "pol")
	{
		std::string strA = std::to_string(A);
		strA.erase(strA.size() - 5, 5);
		std::string strB = std::to_string(B);
		strB.erase(strB.size() - 5, 5);
		return "f(x) =" + strA + "x^3+" + strB +"x";
	}
}
std::string Funkcja::com_string(double var)
{
	std::string str = std::to_string(var);
	str.erase(str.size() - 3, 3);
	return str;
}
void Funkcja::run(sf::RenderWindow &window, std::string str)
{
	dx = (xk - xp) / N;
	x = xp;
	s = 0;

	//rysowanie czarnych prostkoatow
		sf::ConvexShape convex1;
	convex1.setPointCount(4);
	convex1.setPoint(0, sf::Vector2f(60, 0));
	convex1.setPoint(1, sf::Vector2f(60, 59));
	convex1.setPoint(2, sf::Vector2f(860, 59));
	convex1.setPoint(3, sf::Vector2f(860, 0));
	convex1.setFillColor(sf::Color::Black);
	sf::ConvexShape convex2;
	convex2.setPointCount(4);
	convex2.setPoint(0, sf::Vector2f(60, 0+661));
	convex2.setPoint(1, sf::Vector2f(60, 59+661));
	convex2.setPoint(2, sf::Vector2f(860, 59+661));
	convex2.setPoint(3, sf::Vector2f(860, 0+661));
	convex2.setFillColor(sf::Color::Black);
	//rysowanie tekstu info
	sf::Text info("INFO", font, 60);
	info.setStyle(sf::Text::Bold);
	info.setPosition(420 / 2 - info.getGlobalBounds().width / 2 + 860, 20);

	//rysowanie tekstu xk i xp
	sf::Text xp_text("xp", font, 15);
	xp_text.setPosition(0 + 60 + 2 - xp_text.getGlobalBounds().width / 2, 600 + 60);
	sf::Text xk_text("xk", font, 15);
	xk_text.setPosition(800 + 60 - 2 - xk_text.getGlobalBounds().width / 2, 600 + 60);

	//rysowanie tekst f(x)
	std::string f_od_x = x_od_y(str);
	sf::Text f_text(f_od_x, font, 40);
	f_text.setPosition(420 / 2 - f_text.getGlobalBounds().width / 2 + 860, 100);

	//rysoywanie tekstu przedzialu
	std::string com_str = "xE<" + com_string(xp) + ";" + com_string(xk) + ">";
	sf::Text com_text(com_str, font, 40);
	com_text.setPosition(420 / 2 - com_text.getGlobalBounds().width / 2 + 860, 160);
	
	//rysowanie tekst powrot
	sf::Text powrot("POWROT", font, 40);
	info.setStyle(sf::Text::Bold);
	powrot.setPosition(420 / 2 -powrot.getGlobalBounds().width / 2 + 860, 600);

	//rysowanie linii
	sf::VertexArray x_line(sf::Lines, 2);
	sf::VertexArray y_line(sf::Lines, 2);
	x_line[0].position = sf::Vector2f(0 + 60, 300 + 60);
	x_line[1].position = sf::Vector2f(800 + 60, 300 + 60);
	double odl_y = (fabs(xp)*800)/(fabs(xk) + fabs(xp));
	std::cout << odl_y << std::endl;
	y_line[0].position = sf::Vector2f(odl_y +60, 0 + 60);
	y_line[1].position = sf::Vector2f(odl_y + 60, 600 + 60);

	//rysowanie granic przedzia³u
	sf::VertexArray xp_line(sf::Lines, 2);
	sf::VertexArray xk_line(sf::Lines, 2);
	xp_line[0].position = sf::Vector2f(0 + 60 + 2, 0 + 60);
	xp_line[1].position = sf::Vector2f(0 + 60 + 2, 600 + 60);
	xk_line[0].position = sf::Vector2f(800 + 60 - 2, 0 + 60);
	xk_line[1].position = sf::Vector2f(800 + 60 - 2, 600 + 60);
	for (int i = 0; i < 2; i++) xk_line[i].color = sf::Color::Yellow;
	for (int i = 0; i < 2; i++) xp_line[i].color = sf::Color::Yellow;

	//rysowanie obwody wykresu
	sf::VertexArray mon(sf::LinesStrip, 5);
	mon[0].position = sf::Vector2f(60, 60);
	mon[1].position = sf::Vector2f(60 + 800, 60);
	mon[2].position = sf::Vector2f(60 + 800, 60 + 600);
	mon[3].position = sf::Vector2f(60, 60 + 600);
	mon[4].position = sf::Vector2f(60, 60);
	for (int i = 0; i < 5; i++) mon[i].color = sf::Color::Cyan;

	//twoerzenie strzalek
	sf::VertexArray x_arrow(sf::Lines, 4);
	sf::VertexArray y_arrow(sf::Lines, 4);
	int arrow_size = 10;
	int y_arrow_tab[][2] = { { odl_y + 60,0 + 60 },{ odl_y + arrow_size + 60, 0 + arrow_size + 60 },
	{ odl_y + 60,0 + 60 },{ odl_y - arrow_size + 60, 0 + arrow_size + 60 } };
	int x_arrow_tab[][2] = { { 800 + 60,300 + 60 }, { 800 - arrow_size + 60, 300 - arrow_size + 60 },
	{ 800 + 60,300 + 60 }, { 800 - arrow_size + 60, 300 + arrow_size + 60 } };

	//ustawiajnie pozycji strzalek
	for (int i = 0; i < 4; i++)
	{
		x_arrow[i].position = sf::Vector2f(x_arrow_tab[i][0], x_arrow_tab[i][1]);
	}
	for (int i = 0; i < 4; i++)
	{
		y_arrow[i].position = sf::Vector2f(y_arrow_tab[i][0], y_arrow_tab[i][1]);
	}

	//rysowanie funkcji
	sf::VertexArray point(sf::LinesStrip, 800);
	for (double i = 0; i < 800; i++)
	{
		y = -assign(x, A, B, str, 20) + y0;
		if (y >= 600) y = 800;
		else if (y <= 0) y = -800;
		point[i].position = sf::Vector2f(i + 60, y + 60);
		point[i].color = sf::Color::Red;
		x += (xk - xp) / 800;
		//std::cout << "x: " << x << " y: " << y << std::endl;
	}
	x = xp;
	s = 0;
	dx = (xk - xp) / N;

	//liczenie calki
	int n = static_cast<int>(N);
	double *s_queue = new double[n];
	double *s1_queue = new double[n];
	double sn=0;

	std::string str_s;
	std::string str_sn;

	for (int i = 1; i < N; i++)
	{
		s += assign(xp + i*dx, A, B, str, 1);

	}
	s = (s + (y = assign(xp, A, B, str, 1) + assign(xk, A, B, str, 1)) / 2) * dx;
	s = fabs(s);
	//liczenie wartosci funkcji
	for (int i = 0; i < N+1; i++)
	{
		s1_queue[i] = (assign(xp + i*dx, A, B, str, 20));
		std::cout << s1_queue[i] << "  " << s << std::endl;

	}
	//liczneie pola pojedycznego trapezu
	for (int i = 0; i < N; i++)
	{
		s_queue[i] = (assign(xp + i*dx, A, B, str, 1)*dx + assign(xp + (i + 1)*dx, A, B, str, 1)*dx) / 2;
	}

	//s = (s + (y = assign(xp, A, B, str, 1) + assign(xk, A, B, str, 1)) / 2) * dx;


	//rysowanie tekstu aktualnej wartosci S
	sf::Text s1_text("S", font, 40);
	s1_text.setPosition(420 / 2 - s1_text.getGlobalBounds().width / 2 + 860, 220);

	//rysowanie tekstu sumy S
	sf::Text sn_text("ES", font, 40);
	sn_text.setPosition(420 / 2 - sn_text.getGlobalBounds().width / 2 + 860, 280);

	//rysowanie tekstu wartosci calki
	std::string s_str = "S=" + std::to_string(s);
	sf::Text s_text(s_str, font, 40);
	s_text.setPosition(420 / 2 - s_text.getGlobalBounds().width / 2 + 860, 400);

	std::string arrow_str[] = { "<<<",">>>" };
	sf::Text arrow_text[2];

	//tworzenie trpazow na ekranie
	sf::VertexArray quad(sf::Quads, 4);
	double pdx = 800 / N;

	for (int i = 0; i < 2; i++)
	{
		arrow_text[i].setFont(font);
		arrow_text[i].setCharacterSize(40);

		arrow_text[i].setString(arrow_str[i]);
		arrow_text[i].setPosition(420 / 3 * (i + 1) - arrow_text[i].getGlobalBounds().width / 2 + 860, 340);
	}
		bool open = true;
		n = 1;
		while (open == true) {
			sf::Vector2f mouse(sf::Mouse::getPosition(window));
			sf::Event event;
			while (window.pollEvent(event)) {

				if (event.type == sf::Event::Closed)
					open = false;
				else if (powrot.getGlobalBounds().contains(mouse) && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
				{
					open = false;
				}
				else if (arrow_text[0].getGlobalBounds().contains(mouse) && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left ||event.key.code == sf::Keyboard::A && event.type == sf::Event::KeyPressed)
				{
					sn = 0;
					n--;
					if (n < 1) n = 1;
					for (int i = 0; i < n; i++)
					{
						sn += s_queue[i];
					}
					str_s = "S"+ std::to_string(n) + "="+std::to_string(s_queue[n-1]);
					s1_text.setString(str_s);
					s1_text.setPosition(420 / 2 - s1_text.getGlobalBounds().width / 2 + 860, 220);
					str_sn = "ES"+std::to_string(n)+"="+std::to_string(sn);
					sn_text.setString(str_sn);
					sn_text.setPosition(420 / 2 - sn_text.getGlobalBounds().width / 2 + 860, 280);
				}
				else if (arrow_text[1].getGlobalBounds().contains(mouse) && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left || event.key.code == sf::Keyboard::D && event.type == sf::Event::KeyPressed)
				{
					sn = 0;
					n++;
					if (n >static_cast<int>(N)) n = static_cast<int>(N);;
					for (int i = 0; i < n; i++)
					{
						sn += s_queue[i];
					}
					str_s = "S" + std::to_string(n) + "=" + std::to_string(s_queue[n-1]);
					s1_text.setString(str_s);
					s1_text.setPosition(420 / 2 - s1_text.getGlobalBounds().width / 2 + 860, 220);
					str_sn = "ES" + std::to_string(n) + "=" + std::to_string(sn);
					sn_text.setString(str_sn);
					sn_text.setPosition(420 / 2 - sn_text.getGlobalBounds().width / 2 + 860, 280);

				}
				else if (event.key.code == sf::Keyboard::Space && event.type == sf::Event::KeyPressed)
				{
					Snap snap(window, snap_C);
					snap_C+=1;
				}
			}			
			double h1 = -s1_queue[n] + 360;
			double h2 = -s1_queue[n - 1] + 360;
			if (h1 >= 660) h1 = 659;
			if (h2 >= 660) h2 = 659;
			if (h2 <= 60) h2 = 61;
			if (h1 <= 60) h1 = 61;
			quad[0].position = sf::Vector2f(pdx*(n-1)+60,360 );
			quad[1].position = sf::Vector2f(pdx*(n)+60, 360);
			quad[2].position = sf::Vector2f(pdx*(n) + 60, h1);
			quad[3].position = sf::Vector2f(pdx*(n-1) + 60, h2);

			quad[0].color = sf::Color::White;
			quad[1].color = sf::Color::White;
			quad[2].color = sf::Color::Red;
			quad[3].color = sf::Color::Red;;

			for (int i = 0; i < 2; i++) {
				if (arrow_text[i].getGlobalBounds().contains(mouse))
					arrow_text[i].setFillColor(sf::Color::Cyan);
				else arrow_text[i].setFillColor(sf::Color::White);
			}
			if (powrot.getGlobalBounds().contains(mouse))
				powrot.setFillColor(sf::Color::Red);
			else powrot.setFillColor(sf::Color::White);
			window.clear();
			window.draw(info);
			window.draw(mon);
			window.draw(com_text);
			window.draw(x_line);
			if (xk*xp < 0)
			{
				window.draw(y_line);
				window.draw(y_arrow);
			}
			
			window.draw(x_arrow);
			window.draw(point);
			window.draw(xp_line);
			window.draw(xk_line);
			window.draw(f_text);
			window.draw(s_text);
			window.draw(s1_text);
			window.draw(sn_text);
			window.draw(powrot);
			window.draw(quad);
			window.draw(convex1);
			window.draw(convex2);
			window.draw(xp_text);
			window.draw(xk_text);
			for (int i = 0; i < 2; i++) window.draw(arrow_text[i]);
			window.display();
			//MessageBox box("|ASdasd"); 
			//window.display();

		}
	}
