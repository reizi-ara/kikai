#pragma once
#include "char.h"

Bullet::Bullet(float vx, float vy, float px, float py)
{
	img = LoadGraph("image\\square.png");

	pos.x = px;
	pos.y = py;

	vec.x = vx;
	vec.y = vy;

	FLAG = true;

}

int Bullet::Action(list<unique_ptr<Bace>>& bace)
{
	float r = 0.0f;
	r = vec.x * vec.x + vec.y * vec.y;
	r = sqrt(r);

	if (r == 0.0f)
	{
		;
	}
	else
	{
		vec.x = 5.0f / r * vec.x;
		vec.y = 5.0f / r * vec.y;
	}

	pos.x += vec.x;
	pos.y += vec.y;

	//âÊñ äOÇ…èoÇΩÇÁçÌèú
	if (pos.x<0 || pos.y<0 || pos.x>800 - 32 || pos.y>600 - 32) {
		for (auto i = bace.begin(); i != bace.end(); i++)
		{
			FLAG = false;
		}
	}

	return 0;
}

void Bullet::Draw() {
	DrawGraphF(pos.x, pos.y, img, TRUE);
}