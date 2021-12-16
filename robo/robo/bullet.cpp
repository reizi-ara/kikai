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

	pri = 99;
}

int Bullet::Action(list<unique_ptr<Base>>& base)
{
	ScrollSet(scroll, p_pos, base);
	BlockHit(&h_bullet, &status.pos, &status.speed, IMGSIZE64 / 2);
	if (h_bullet.UP == true || h_bullet.DOWN == true || h_bullet.LEFT == true || h_bullet.RIGHT == true)
	{
		status.FLAG = false;
	}

	delete_time++;
	if (delete_time > 120)
	{
		status.FLAG = false;
	}

	//Hit_Player(status.pos, scroll, base, IMGSIZE64 / 2, &status.FLAG);

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

	return 0;
}

void Bullet::Draw() 
{
	if (status.FLAG != false)
	{
		for (int i = 0; i < 4; i++)
		{
			switch (i)
			{
				//WINDOW 1
			case P1:
				if (status.pos.x - scroll[P1].x >= -IMGSIZE64 &&
					status.pos.x + IMGSIZE64 / 2 - scroll[P1].x <= 992 &&
					status.pos.y - scroll[P1].y >= 0 - IMGSIZE64 &&
					status.pos.y + IMGSIZE64 / 2 - scroll[P1].y <= 508 + IMGSIZE64)
				{
					DrawGraph(status.pos.x + (-scroll[i].x), status.pos.y + (-scroll[i].y), img, TRUE);
				}
				break;
				//WINDOW 2
			case P2:
				if (status.pos.x - scroll[P2].x + 992 >= 928 &&
					status.pos.x + IMGSIZE64 / 2 - scroll[P2].x + 992 <= WINDOW_WIDTH + IMGSIZE64 &&
					status.pos.y - scroll[P2].y >= 0 - IMGSIZE64 &&
					status.pos.y + IMGSIZE64 / 2 - scroll[P2].y <= 508 + IMGSIZE64)
				{
					DrawGraph(status.pos.x + (-scroll[i].x) + 928 + IMGSIZE64, status.pos.y + (-scroll[i].y), img, TRUE);
				}
				break;
				//WINDOW 3
			case P3:
				if (status.pos.x - scroll[P3].x >= -IMGSIZE64 &&
					status.pos.x + IMGSIZE64 / 2 - scroll[P3].x <= 928 + IMGSIZE64 &&
					status.pos.y - scroll[P3].y + 572 >= 572 - IMGSIZE64 &&
					status.pos.y + IMGSIZE64 / 2 - scroll[P3].y + 572 <= WINDOW_HEIGHT + IMGSIZE64)
				{
					DrawGraph(status.pos.x + (-scroll[i].x), status.pos.y + (-scroll[i].y) + 508 + IMGSIZE64, img, TRUE);
				}
				break;
				//WINDOW 4
			case P4:
				if (status.pos.x - scroll[P4].x + 992 >= 992 - IMGSIZE64 &&
					status.pos.x + IMGSIZE64 / 2 - scroll[P4].x + 992 <= WINDOW_WIDTH + IMGSIZE64 &&
					status.pos.y - scroll[P4].y + 572 >= 572 - IMGSIZE64 &&
					status.pos.y + IMGSIZE64 / 2 - scroll[P4].y + 572 <= WINDOW_HEIGHT + IMGSIZE64)
				{
					DrawGraph(status.pos.x + (-scroll[i].x) + 928 + IMGSIZE64, status.pos.y + (-scroll[i].y) + 508 + IMGSIZE64, img, TRUE);
				}
				break;
			}
		}
	}
	
}