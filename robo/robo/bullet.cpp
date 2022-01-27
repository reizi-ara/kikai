#pragma once
#include "char.h"
#define b_speedx 10.0f
#define b_speedy 10.0f

Bullet::Bullet(float vx, float vy, float px, float py,int WIN_ID,int IMGSIZE)
{
	if (IMGSIZE == IMGSIZE64 / 4)
		img = LoadGraph("image\\square.png");
	if (IMGSIZE == IMGSIZE64)
		img = LoadGraph("image\\square_bullet.png");

	img_size = IMGSIZE;

	status.pos.x = px;
	status.pos.y = py;

	status.WIN_ID = WIN_ID;

	status.ID = BULLET;
	status.speed.x = vx;
	status.speed.y = vy;

	pri = 99;
}

int Bullet::Action(list<unique_ptr<Base>>& base)
{
	ScrollSet(scroll, p_pos, base);
	BlockHit(&h_bullet, &status.pos, &status.speed, img_size);

	if (img_size == IMGSIZE64)
		hit_player = Hit_Player(status.pos, scroll, base, img_size, &status.FLAG, status.WIN_ID);
	else
		hit_player = Hit_Player(status.pos, scroll, base, img_size, &status.FLAG, status.WIN_ID);

	
	if (hit_player >= 0 && hit_player <= 3)
	{
		for (auto i = base.begin(); i != base.end(); i++)
		{
			if ((*i)->status.WIN_ID == hit_player && ((Player*)(*i).get())->r_flag == false)
			{
				if (img_size == IMGSIZE64)
				{
					(*i)->status.hp -= 100.0f * (*i)->status.s_atk - (50.0f * (*i)->status.s_atk * (*i)->status.def);
					if ((*i)->status.hp <= 0)
					{
						kill_flag = true;
					}
				}
				else
				{
					(*i)->status.hp -= 50.0f * (*i)->status.s_atk - (50.0f * (*i)->status.s_atk * (*i)->status.def);
					if ((*i)->status.hp <= 0)
					{
						kill_flag = true;
					}
				}		
			}
		}
	}
	for (auto i = base.begin(); i != base.end(); i++)
	{
		if (kill_flag == true && (*i)->status.WIN_ID == status.WIN_ID && (*i)->status.ID != BULLET)
		{
			((Player*)(*i).get())->kill++;
			kill_flag = false;
		}
	}
	

	if (h_bullet.UP == true || h_bullet.DOWN == true || h_bullet.LEFT == true || h_bullet.RIGHT == true)
	{
		status.FLAG = false;
	}

	delete_time++;
	if (delete_time > 120)
	{
		status.FLAG = false;
	}
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
					status.pos.x + IMGSIZE64 +img_size- scroll[P1].x <= 992 &&
					status.pos.y-IMGSIZE64 - scroll[P1].y >= 0 - IMGSIZE64 &&
					status.pos.y + IMGSIZE64 - IMGSIZE64 + img_size - scroll[P1].y <= 508 + IMGSIZE64)
				{
					DrawRotaGraph(status.pos.x + (-scroll[i].x), status.pos.y + (-scroll[i].y) , 1, delete_time, img, TRUE, FALSE, FALSE);
					//DrawGraph(status.pos.x + (-scroll[i].x), status.pos.y + (-scroll[i].y), img, TRUE);
				}
				break;
				//WINDOW 2
			case P2:
				if (status.pos.x - scroll[P2].x + 992 >= 928 &&
					status.pos.x + IMGSIZE64 + img_size - scroll[P2].x + 992 <= WINDOW_WIDTH + IMGSIZE64 &&
					status.pos.y - IMGSIZE64 - scroll[P2].y >= 0 - IMGSIZE64 &&
					status.pos.y + IMGSIZE64 - IMGSIZE64 + img_size - scroll[P2].y <= 508 + IMGSIZE64)
				{
					DrawRotaGraph(status.pos.x + (-scroll[i].x) + 928 +IMGSIZE64, status.pos.y + (-scroll[i].y), 1, delete_time, img, TRUE, FALSE, FALSE);
					//DrawGraph(status.pos.x + (-scroll[i].x) + 928 + IMGSIZE64, status.pos.y + (-scroll[i].y), img, TRUE);
				}
				break;
				//WINDOW 3
			case P3:
				if (status.pos.x - scroll[P3].x >= -IMGSIZE64 &&
					status.pos.x + IMGSIZE64 + img_size - scroll[P3].x <= 928 + IMGSIZE64 &&
					status.pos.y - IMGSIZE64 - scroll[P3].y + 572 >= 572 - IMGSIZE64 &&
					status.pos.y + IMGSIZE64 - IMGSIZE64 + img_size - scroll[P3].y + 572 <= WINDOW_HEIGHT + IMGSIZE64)
				{
					DrawRotaGraph(status.pos.x + (-scroll[i].x), status.pos.y + (-scroll[i].y) + 508 +IMGSIZE64, 1, delete_time, img, TRUE, FALSE, FALSE);
					//DrawGraph(status.pos.x + (-scroll[i].x), status.pos.y + (-scroll[i].y) + 928 + IMGSIZE64, img, TRUE);
				}
				break;
				//WINDOW 4
			case P4:
				if (status.pos.x - scroll[P4].x + 992 >= 992 - IMGSIZE64 &&
					status.pos.x + IMGSIZE64 +img_size- scroll[P4].x + 992 <= WINDOW_WIDTH + IMGSIZE64 &&
					status.pos.y - IMGSIZE64 - scroll[P4].y + 572 >= 572 - IMGSIZE64 &&
					status.pos.y + IMGSIZE64 - IMGSIZE64 + img_size - scroll[P4].y + 572 <= WINDOW_HEIGHT + IMGSIZE64)
				{
					DrawRotaGraph(status.pos.x + (-scroll[i].x) + 928 + IMGSIZE64, status.pos.y + (-scroll[i].y) + 508+ IMGSIZE64, 1, delete_time, img, TRUE, FALSE, FALSE);
					//DrawGraph(status.pos.x + (-scroll[i].x) + 928 + IMGSIZE64, status.pos.y + (-scroll[i].y) + 508 + IMGSIZE64, img, TRUE);
				}
				break;
			}
		}
	}
	
}