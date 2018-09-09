#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
class Snap
{
private:
	sf::Texture tex;
	int count = 0;
	std::string t_snap = "snap";
	//tex.create(1280, 720);
public:
	Snap(sf::RenderWindow &win, int snap);
	~Snap();
	void makeSnap(sf::RenderWindow &window);
};