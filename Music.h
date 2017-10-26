#pragma once
#include <SFML\Audio.hpp>

using namespace sf;

class MusiCarga
{
public:
	MusiCarga(char* cadena);

	void Play(bool cuando);
	

private:
	Music music;
};
	
MusiCarga::MusiCarga(char* cadena)
{
	music.openFromFile(cadena);
	music.play();
}

void MusiCarga::Play(bool cuando)
{
	if (cuando == true)
	{
		music.play();
	}

	else music.stop();
}