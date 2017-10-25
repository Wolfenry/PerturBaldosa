#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
using namespace std;


class Animation
{
public:

	Animation(Texture* textura, Vector2u imageCount, float switchtime, int SpriteSheet = 1);

	~Animation();

	void Update(float deltatime, int row = 0);



public:
	IntRect uvRect;



private:
	Vector2u imageCount;
	Vector2u currentImage;
	int SpriteSheet;

	float totaltime;
	float switchtime;
};


///DECLARACION CONSTRUCTOR

Animation::Animation(Texture* textura, Vector2u imageCount, float switchtime, int SpriteSheet)
{
	this->imageCount = imageCount;
	this->switchtime = switchtime;
	this->SpriteSheet = SpriteSheet;

	totaltime = 0.0f;
	currentImage.x = 0;
	uvRect.width = textura->getSize().x / float(imageCount.x);
	uvRect.height = textura->getSize().y / float(imageCount.y);

}

Animation::~Animation()
{

}

void Animation::Update(float deltatime, int row)
{


	switch (SpriteSheet)
	{
	case 1:

		currentImage.y = row;
		totaltime += deltatime;

		if (totaltime >= switchtime)
		{
			totaltime -= switchtime;
			currentImage.x++;

			if (currentImage.x >= imageCount.x)
			{
				currentImage.x = 0;
			}
		}



		uvRect.left = currentImage.x * uvRect.width;
		uvRect.top = currentImage.y * uvRect.height;
		/////////////////////SEPARADOR/////////////////////////////////
		break;
	case 2:

		totaltime += deltatime;

		if (totaltime >= switchtime)
		{
			totaltime -= switchtime;
			currentImage.x++;

			if (currentImage.x >= imageCount.x)
			{
				currentImage.y++;
				if (currentImage.y == imageCount.y)
				{
					currentImage.y = 0;
				}
				currentImage.x = 0;
			}
		}



		uvRect.left = currentImage.x * uvRect.width;
		uvRect.top = currentImage.y * uvRect.height;
		break;
		/////////////////////SEPARADOR/////////////////////////////////
	case 3:

		break;

	}



}