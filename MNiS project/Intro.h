#pragma once

#include<SFML\Graphics.hpp>
#include<string>
#include "Menu.h"


class Intro
{
public:
	Intro();
	~Intro();
	void run_intro();
	//void menu();
protected:
	enum IntroState { INTRO, MENU, END };
	IntroState state;
private:
	sf::Font font;
};