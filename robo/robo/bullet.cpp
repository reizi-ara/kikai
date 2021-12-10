#pragma once
#include "char.h"
#define b_speedx 5.0f
#define b_speedy 5.0f

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
	float r = NONE;
	r = Charcter.speed.x * Charcter.speed.x + Charcter.speed.y * Charcter.speed.y;
	r = sqrt(r);

	if (r == NONE)
	{
		;
	}
	else
	{
		Charcter.speed.x =  b_speedx / r * Charcter.speed.x;
		Charcter.speed.y =  b_speedy / r * Charcter.speed.y;
	}

	Charcter.pos.x += Charcter.speed.x;
	Charcter.pos.y += Charcter.speed.y;

	//âÊñ äOÇ…èoÇΩÇÁçÌèú
	if (Charcter.pos.x < NONE || Charcter.pos.y < NONE || Charcter.pos.x>Window_Size_x - 32 || Charcter.pos.y>Window_Size_y - 32) {
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