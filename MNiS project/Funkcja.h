#pragma once
#include<string>
#include<SFML\Graphics.hpp>
#include"MessageBox.h"
#include<cmath>
#include"Snap.h"
#define M_PI 3.14159265358979323846
class Funkcja
{
public:
	Funkcja();
	void set_xk(double xk1);
	void set_xp(double xp1);
	void set_A(double A1);
	void set_B(double B1);
	void set_N(double N1);
	void set_function_choosen(bool function_choosen1);
	void set_compartment(bool compartment1);
	void set_precission(bool precission1);
	void set_factor(bool factor1);
	double get_xp();
	double get_xk();
	double get_A();
	double get_B();
	double get_N();
	bool go();
	double assign(double x, double A, double B, std::string str, int up);
	void run(sf::RenderWindow &win, std::string str);
	std::string x_od_y(std::string str);
	std::string com_string(double var);
private:
	bool function_choosen;
	bool compartment;
	bool precission;
	bool factor;
	//const double N1;
	int snap_C = 0;
	double  xk,
		xp,
		A,
		B,
		N,
		dx,
		s = 0 ,
		x,
		x1,
		y,
		y0=300;
	sf::Font font;


};