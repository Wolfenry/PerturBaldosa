#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "Animation.h"
#include "Player.h"
#include "FuncionesGenerales.h"
#include "Baldosa.h"
#include "Colision.h"
#include "Objeto.h"
#include "Music.h"


using namespace std;
using namespace sf;



int main()
{
	RenderWindow window(VideoMode(1280, 720), "BaldosasGame 5.0", Style::Close | Style::Titlebar);
	window.setFramerateLimit(60);
	
	Objeto baldosita(nullptr, Vector2f(200, 200), Vector2f(600, 600));

	

	MusiCarga music("Audio/Music/Unstoppable.wav");

	///Gravity Variables:
	const int groundHeight = 700;
	const float gravitySpeed = 21.5;
	bool isJumping = false;
	

	float deltatime = 0.0f;
	Clock clock;
	Texture texturaP1;
	texturaP1.loadFromFile("Images/Hero Animation/Hero.png");
	Animation P1Anima(&texturaP1, Vector2u(8, 2), 0.3f);
	Player P1(Vector2f(100, 100), &texturaP1, 10, 600);

	float speed = 15;
	
	

	while (window.isOpen())
	{

		deltatime = clock.restart().asSeconds() * 5;
		


		///INICIO EVENTO
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;

			case Event::Resized:
				cout << "Nueva Altura: " << event.size.width << " Nueva anchura: " << event.size.height << endl;
				break;


			

			}
			

		}
		///FIN EVENTO
		window.clear();
		CrearFondo(window);

		P1.recuadropantalla();

		baldosita.GetCol().CheckColision(P1.GetCol(), 0.80f);

		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			P1.Move(Vector2f(-speed, 0));
			P1Anima.Update(deltatime, 1);

		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			P1.Move(Vector2f(speed, 0));
			P1Anima.Update(deltatime, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			P1.Move({ 0, -speed });
			isJumping = true;
		}
		
		///Gravedad
		if (P1.GetY() < groundHeight && isJumping == false)
		{
			P1.Move({ 0, gravitySpeed });
		}

		P1.SetTextureRect(P1Anima.uvRect);
		baldosita.Draw(window);
		P1.draw(window);
		window.display();

	}
}