#include"Snap.h"
Snap::Snap(sf::RenderWindow &win, int snap)
{
	count = snap;
	//tex.create(1280, 720);
	makeSnap(win);
}
Snap::~Snap()
{
	
}
void Snap::makeSnap(sf::RenderWindow &window)
{
	tex.create(1280, 720);
	tex.update(window);
	t_snap += std::to_string(count)+".png";
	sf::Image img = tex.copyToImage();
	img.saveToFile(t_snap);
	std::cout << t_snap << std::endl;

}