#pragma once

#include"char.h"


Block::Block()
{
	pri = 90;
	status.ID = BLOCK;

	GetMap(map);
}

int Block::Action(list<unique_ptr<Base>>& base)
{
	ScrollSet(scroll, p_pos, base);

	Getimg(base, p_img);
	for (auto i = base.begin(); i != base.end(); i++)
	{
		if ((*i)->status.FLAG == false && (*i)->status.ID == ITEMBOX)
		{
			Item_time_flag = true;
			for (int z = 0; z < 10; z++)
			{
				if (Item_pos[z].x == 0.0f && Item_pos[z].y == 0.0f)
				{
					Item_pos[z].x = (*i)->status.pos.x;
					Item_pos[z].y = (*i)->status.pos.y;
					break;
				}
			}
			
		}
	}

	if (Item_time_flag == true)
	{
		Item_time++;
		if (Item_time > 600)
		{
			for (int z = 0; z < 10; z++)
			{
				if (Item_pos[z].x > 0.0f && Item_pos[z].y > 0.0f)
				{
					base.emplace_back((unique_ptr<Base>)new Itembox(Item_pos[z].x, Item_pos[z].y));
					SetMap(Item_pos[z].x/IMGSIZE64, Item_pos[z].y/IMGSIZE64, 2);
				}
				else
				{
					Item_time = 0;
					Item_time_flag = false;
					break;
				}
			}
		}
	}

	return 0;
}

void Block::Draw()
{
	for (int y = 0; y < MAP_SIZE_Y; y++)
	{
		for (int x = 0; x < MAP_SIZE_X; x++)
		{
			for (int i = 0; i < 4; i++)
			{
				switch (BlockDraw(scroll, p_pos, i, x, y))
				{
				case -99:
					Draw_flag = false;
					break;
				case 0:
					status.img = img_green;
					Draw_flag = true;
					break;
				case 1:
					status.img = img;
					Draw_flag = true;
					break;
				}
				if (Draw_flag == true)
				{
					if (i == P1)
					{
						DrawGraph((x * IMGSIZE64) + (-scroll[i].x), (y * IMGSIZE64) + (-scroll[i].y), status.img, TRUE);
					}
					if (i == P2)
					{
						DrawGraph((x * IMGSIZE64) + (-scroll[i].x) + 928 + IMGSIZE64, (y * IMGSIZE64) + (-scroll[i].y), status.img, TRUE);
					}
					if (i == P3)
					{
						DrawGraph((x * IMGSIZE64) + (-scroll[i].x), (y * IMGSIZE64) + (-scroll[i].y) + 508 + IMGSIZE64, status.img, TRUE);
					}
					if (i == P4)
					{
						DrawGraph((x * IMGSIZE64) + (-scroll[i].x) + 928 + IMGSIZE64, (y * IMGSIZE64) + (-scroll[i].y) + 508 + IMGSIZE64, status.img, TRUE);
					}
				}
			}
		}
	}


	
//WINDOWごとの敵プレイヤーを表示
	//(player.cppに移動するかも)
	for (int z = 0; z < 4; z++)
	{
		if (z != P1)
		{
			if (p_pos[z].x - scroll[z].x >= -IMGSIZE64 &&
				p_pos[z].x + IMGSIZE64 - scroll[z].x <= 992 &&
				p_pos[z].y - scroll[z].y >= -IMGSIZE64 &&
				p_pos[z].y + IMGSIZE64 - scroll[z].y <= 508 + IMGSIZE64)
			{
				if (p_pos[z].x + IMGSIZE64 - scroll[P1].x <= 992 &&
					p_pos[z].x - scroll[P1].x >= -IMGSIZE64 &&
					p_pos[z].y - scroll[P1].y >= -IMGSIZE64 &&
					p_pos[z].y + IMGSIZE64 - scroll[P1].y <= 572)
				{
					switch (z)
					{
					case P2:
						DrawGraph(p_pos[z].x - scroll[P1].x, p_pos[z].y - scroll[P1].y, p_img[P2], TRUE);
						break;
					case P3:
						DrawGraph(p_pos[z].x - scroll[P1].x, p_pos[z].y - scroll[P1].y, p_img[P3], TRUE);
						break;
					case P4:
						DrawGraph(p_pos[z].x - scroll[P1].x, p_pos[z].y - scroll[P1].y, p_img[P4], TRUE);
						break;
					}
				}
			}
		}
		if (z != P2)
		{
			if (p_pos[z].x - scroll[z].x >= -IMGSIZE64 &&
				p_pos[z].x + IMGSIZE64 - scroll[z].x <= 992 &&
				p_pos[z].y - scroll[z].y >= -IMGSIZE64 &&
				p_pos[z].y + IMGSIZE64 - scroll[z].y <= 508 + IMGSIZE64)
			{
				if (p_pos[z].x + IMGSIZE64 - scroll[P2].x + 992 <= WINDOW_WIDTH + IMGSIZE64 &&
					p_pos[z].x - scroll[P2].x + 992 >= 928 &&
					p_pos[z].y - scroll[P2].y >= -IMGSIZE64 &&
					p_pos[z].y + IMGSIZE64 - scroll[P2].y <= 572)
				{
					switch (z)
					{
					case P1:
						DrawGraph(p_pos[z].x + 992.0f - scroll[P2].x, p_pos[z].y - scroll[P2].y, p_img[P1], TRUE);
						break;
					case P3:
						DrawGraph(p_pos[z].x + 992.0f - scroll[P2].x, p_pos[z].y - scroll[P2].y, p_img[P3], TRUE);
						break;
					case P4:
						DrawGraph(p_pos[z].x + 992.0f - scroll[P2].x, p_pos[z].y - scroll[P2].y, p_img[P4], TRUE);
						break;
					}
				}

			}
		}
		if (z != P3)
		{
			if (p_pos[z].x - scroll[z].x >= -IMGSIZE64 &&
				p_pos[z].x + IMGSIZE64 - scroll[z].x <= 992 &&
				p_pos[z].y - scroll[z].y >= -IMGSIZE64 &&
				p_pos[z].y + IMGSIZE64 - scroll[z].y <= 508 + IMGSIZE64)
			{
				if (p_pos[z].x + IMGSIZE64 - scroll[P3].x <= 992 &&
					p_pos[z].x - scroll[P3].x >= -IMGSIZE64 &&
					p_pos[z].y - scroll[P3].y + 572 >= 572 - IMGSIZE64 &&
					p_pos[z].y + IMGSIZE64 - scroll[P3].y + 572 <= WINDOW_HEIGHT + IMGSIZE64)
				{
					switch (z)
					{
					case P1:
						DrawGraph(p_pos[z].x - scroll[P3].x, p_pos[z].y + 572.0f - scroll[P3].y, p_img[P1], TRUE);
						break;
					case P2:
						DrawGraph(p_pos[z].x - scroll[P3].x, p_pos[z].y + 572.0f - scroll[P3].y, p_img[P2], TRUE);
						break;
					case P4:
						DrawGraph(p_pos[z].x - scroll[P3].x, p_pos[z].y + 572.0f - scroll[P3].y, p_img[P4], TRUE);
						break;
					}
				}

			}
		}
		if (z != P4)
		{
			if (p_pos[z].x - scroll[z].x >= -IMGSIZE64 &&
				p_pos[z].x + IMGSIZE64 - scroll[z].x <= 992 &&
				p_pos[z].y - scroll[z].y >= -IMGSIZE64 &&
				p_pos[z].y + IMGSIZE64 - scroll[z].y <= 508 + IMGSIZE64)
			{
				if (p_pos[z].x + IMGSIZE64 - scroll[P4].x + 992 <= WINDOW_WIDTH + IMGSIZE64 &&
					p_pos[z].x - scroll[P4].x + 992 >= 928 &&
					p_pos[z].y - scroll[P4].y + 572 >= 572 - IMGSIZE64 &&
					p_pos[z].y + IMGSIZE64 - scroll[P4].y + 572 <= WINDOW_HEIGHT + IMGSIZE64)
				{
					switch (z)
					{
					case P1:
						DrawGraph(p_pos[z].x + 992.0f - scroll[P4].x, p_pos[z].y + 572.0f - scroll[P4].y, p_img[P1], TRUE);
						break;
					case P2:
						DrawGraph(p_pos[z].x + 992.0f - scroll[P4].x, p_pos[z].y + 572.0f - scroll[P4].y, p_img[P2], TRUE);
						break;
					case P3:
						DrawGraph(p_pos[z].x + 992.0f - scroll[P4].x, p_pos[z].y + 572.0f - scroll[P4].y, p_img[P3], TRUE);
						break;
					}
				}

			}
		}
	}
	//（Blockめり込み対策）UI表示
	DrawGraph(0, 0, img_back, TRUE);
}