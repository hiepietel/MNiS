#pragma once
#include<SFML\Graphics.hpp>
#include"Funkcja.h"
#include"Calculator.h"
#include"Accuracy.h"
#include"MessageBox.h"
class Menu
{
public:
	Menu(sf::RenderWindow &win);
	~Menu();
	void RunMenu(sf::RenderWindow &window);
protected:
	//enum IntroState { INTRO, MENU, END };
	//IntroState state;
private:
	std::string form;
	sf::Font font;
	Funkcja funkcja;
	
};