#pragma once
#include<SFML\Graphics.hpp>
#include<cmath>
#include <string>
#define M_PI 3.14159265358979323846
class Calculator
{
public:
	Calculator();
	~Calculator();
	void run();
	double get_value();
	private:
		double value;
		std::string svalue="";
		sf::Font font;
		bool pi_enabled;
};