#pragma once
#include "char.h"

Bullet::Bullet(float vx, float vy, float px, float py)
{
	img = LoadGraph("image\\square.png");

	Charcter.pos.x = px;
	Charcter.pos.y = py;

	Charcter.speed.x = vx;
	Charcter.speed.y = vy;

	Charcter.FLAG = true;

}

int Bullet::Action(list<unique_ptr<Bace>>& bace)
{
	float r = 0.0f;
	r = Charcter.speed.x * Charcter.speed.x + Charcter.speed.y * Charcter.speed.y;
	r = sqrt(r);

	if (r == 0.0f)
	{
		;
	}
	else
	{
		Charcter.speed.x = 5.0f / r * Charcter.speed.x;
		Charcter.speed.y = 5.0f / r * Charcter.speed.y;
	}

	Charcter.pos.x += Charcter.speed.x;
	Charcter.pos.y += Charcter.speed.y;

	//âÊñ äOÇ…èoÇΩÇÁçÌèú
	if (Charcter.pos.x < 0 || Charcter.pos.y < 0 || Charcter.pos.x>800 - 32 || Charcter.pos.y>600 - 32) {
		for (auto i = bace.begin(); i != bace.end(); i++)
		{
			Charcter.FLAG = false;
		}
	}

	return 0;
}

void Bullet::Draw() {
	DrawGraphF(Charcter.pos.x, Charcter.pos.y, img, TRUE);
}