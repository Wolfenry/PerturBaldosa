#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;


class Baldosa
{
public:
	Baldosa(Vector2f size, Texture* textura, float posX, float posY);
	~Baldosa();

	void SetPosition(Vector2f pos);
	Vector2f GetPosition();
	float GetX();
	float GetY();
	void recuadropantalla();
	void draw(RenderWindow &window);
	void SetTextureRect(IntRect &rect);

private:
	RectangleShape baldosa;
};



Baldosa::Baldosa(Vector2f size, Texture* textura, float posX, float posY)
{
	baldosa.setPosition(posX, posY);
	baldosa.setSize(size);
	baldosa.setTexture(textura);
}


Baldosa::~Baldosa()
{
}

void Baldosa::SetPosition(Vector2f pos)
{
	baldosa.setPosition(pos);
}

Vector2f Baldosa::GetPosition()
{
	return baldosa.getPosition();
}

float Baldosa::GetX()
{
	return baldosa.getPosition().x;
}

float Baldosa::GetY()
{
	return baldosa.getPosition().y;
}

void Baldosa::recuadropantalla()
{

}

void Baldosa::draw(RenderWindow &window)
{
	window.draw(baldosa);
}

void Baldosa::SetTextureRect(IntRect &rect)
{
	baldosa.setTextureRect(rect);
}





