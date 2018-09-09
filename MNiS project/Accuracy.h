#pragma once
#include<SFML\Graphics.hpp>
#include<cmath>
#include <string>
class Accuracy
{
public:
	Accuracy();
	~Accuracy();
	void run();
	double get_value();
private:
	double value;
	std::string svalue;
	sf::Font font;

};