#pragma once
#include <SFML\Graphics.hpp>
#include "Colision.h"
using namespace sf;

class Objeto
{
public:
	Objeto(Texture * textura, Vector2f size, Vector2f position);

	void Draw(RenderWindow& window);
	Colision GetCol() { return Colision(objeto); }

private:
	RectangleShape objeto;
};


void Objeto::Draw(RenderWindow& window)
{
	window.draw(objeto);
}

Objeto::Objeto(Texture* textura, Vector2f size, Vector2f position)
{
	objeto.setSize(size);
	objeto.setTexture(textura);
	objeto.setOrigin(size / 2.0f);
	objeto.setPosition(position);

}