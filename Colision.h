#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class Colision
{
public:
	Colision(RectangleShape& objeto);

	void Move(float dx, float dy) { objeto.move(dx, dy); }

	bool CheckColision(Colision& other, float push);
	Vector2f Getposition() { return objeto.getPosition(); }
	Vector2f GetHalfsize() { return objeto.getSize() / 2.0f; }

private:
	RectangleShape& objeto;

};

Colision::Colision(RectangleShape& objeto) : objeto(objeto)
{
}

bool Colision::CheckColision(Colision & other, float push)
{
	Vector2f OtherPosition = other.Getposition();
	Vector2f OtherHalfSize = other.GetHalfsize();
	Vector2f ThisPosition = Getposition();
	Vector2f ThisHalfSize = GetHalfsize();

	float deltax = OtherPosition.x - ThisPosition.x;
	float deltay = OtherPosition.y - ThisPosition.y;
	float intersectX = abs(deltax) - (OtherHalfSize.x + ThisHalfSize.x);
	float intersectY = abs(deltay) - (OtherHalfSize.y + ThisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		push = std::min(std::max(push, 0.0f), 1.0f);

		if (intersectX > intersectY)
		{
			if (deltax > 0.0f)
			{
				Move(intersectX *(1.0f - push), 0.0f);
				other.Move(-intersectX * push, 0.0f);
			}
			else
			{
				Move(-intersectX * (1.0f - push), 0.0f);
				other.Move(intersectX * push, 0.0f);

			}

		}
		else
		{
			if (deltay > 0.0f)
			{
				Move(0.0f, intersectY *(1.0f - push));
				other.Move(0.0f, -intersectY * push);
			}
			else
			{
				Move(0.0f, -intersectY * (1.0f - push));
				other.Move(0.0f, intersectY * push);

			}
		}
		return true;
	}
	return false;
}