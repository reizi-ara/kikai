#pragma once
#include "char.h"
#define b_speedx 5.0f
#define b_speedy 5.0f

Bullet::Bullet(float vx, float vy, float px, float py)
{
	img = LoadGraph("image\\square.png");

	status.pos.x = px;
	status.pos.y = py;

	status.speed.x = vx;
	status.speed.y = vy;
}

int Bullet::Action(list<unique_ptr<Base>>& base)
{
	float r = NONE;
	r = status.speed.x * status.speed.x + status.speed.y * status.speed.y;
	r = sqrt(r);

	if (r == NONE)
	{
		;
	}
	else
	{
		status.speed.x =  b_speedx / r * status.speed.x;
		status.speed.y =  b_speedy / r * status.speed.y;
	}

	status.pos.x += status.speed.x;
	status.pos.y += status.speed.y;

	//‰æ–ÊŠO‚Éo‚½‚çíœ
	if (status.pos.x < NONE || status.pos.y < NONE || status.pos.x>WINDOW_WIDTH - 32 || status.pos.y>WINDOW_HEIGHT - 32) {
		status.FLAG = false;
	}

	return 0;
}

void Bullet::Draw() {
	DrawGraphF(status.pos.x, status.pos.y, img, TRUE);
}