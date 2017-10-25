#pragma once
#include <SFML\Graphics.hpp>

void CrearFondo(RenderWindow &window);



void CrearFondo(RenderWindow &window)
{
	Texture fondo;

	fondo.loadFromFile("Images/fondo.PNG");
	
	Sprite sfondo(fondo);
	sfondo.setScale(1280 / sfondo.getLocalBounds().width, 720 / sfondo.getLocalBounds().height);

	window.draw(sfondo);
}

