#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Animation.h"
#include "Colision.h"

using namespace sf;
using namespace std;

class Player
{
public:
	Player(Vector2f size, Texture* textura, float posX, float posY);
	
	void SetPosition(Vector2f pos);
	Vector2f GetPosition();
	float GetX();
	float GetY();
	void recuadropantalla();
	void draw(RenderWindow &window);
	void SetTextureRect(IntRect &rect);
	void Move(Vector2f mov);

	Colision GetCol() { return Colision(jugador); }

private:
	int hp=3;
	RectangleShape jugador;
	
	
};

Player::Player(Vector2f size, Texture* textura, float posX, float posY)
{
	jugador.setPosition(posX, posY);
	jugador.setSize(size);
	jugador.setTexture(textura);
	jugador.setOrigin(size / 2.0f);
}



void Player::Move(Vector2f mov)
{
	jugador.move(mov);

}

void Player::recuadropantalla()
{
	if (jugador.getPosition().x <= 0) {
		jugador.setPosition(0, jugador.getPosition().y);	
	}
	if (jugador.getPosition().x >= 1280) {
		jugador.setPosition(1280, jugador.getPosition().y);	
	}
	if (jugador.getPosition().y >= 720) {
		jugador.setPosition(jugador.getPosition().x, 720);		
	}
	if (jugador.getPosition().y <= 0) {
		jugador.setPosition(jugador.getPosition().x, 0);
	}

	
}

void Player::draw(RenderWindow &window)
{
	window.draw(jugador);

}

void Player::SetPosition(Vector2f pos)
{
	jugador.setPosition(pos);
}

Vector2f Player::GetPosition()
{
	return jugador.getPosition();
}

float Player::GetX()
{
	return jugador.getPosition().x;

}
float Player::GetY()
{
	return jugador.getPosition().y;

}

void Player::SetTextureRect(IntRect &rect)
{
	jugador.setTextureRect(rect);

}