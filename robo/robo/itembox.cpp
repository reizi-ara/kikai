#pragma once
#include "char.h"

Itembox::Itembox(float px, float py)
{
	status.pos.x = px;
	status.pos.y = py;

	img = LoadGraph("image\\�P�A�p�P.png");

	status.ID = ITEMBOX;

	pri = 80;

}

int Itembox::Action(list<unique_ptr<Base>>& base)
{
	ScrollSet(scroll,p_pos, base);

	Hit_Player(status.pos,scroll, base, IMGSIZE64, &status.FLAG);
	if (status.FLAG == false)
	{
		SetMap(status.pos.x / IMGSIZE64, status.pos.y / IMGSIZE64, 0);
	}

	return 0;
}

void Itembox::Draw() {
	/*for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case P1:
			DrawGraphF(status.pos.x - scroll[P1].x, status.pos.y - scroll[P1].y, img, TRUE);
			break;
		case P2:
			DrawGraphF(status.pos.x + 928.0f - scroll[P2].x, status.pos.y - scroll[P2].y, img, TRUE);
			break;
		case P3:
			DrawGraphF(status.pos.x - scroll[P3].x, status.pos.y + 508.0f - scroll[P3].y, img, TRUE);
			break;
		case P4:
			DrawGraphF(status.pos.x + 928.0f - scroll[P4].x, status.pos.y + 508.0f - scroll[P4].y, img, TRUE);
			break;
		}
	}*/
	

	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
			//WINDOW 1
		case P1:
			if (status.pos.x - scroll[P1].x >= -IMGSIZE64 &&
				status.pos.x + IMGSIZE64 - scroll[P1].x <= 992 &&
				status.pos.y - scroll[P1].y >= 0 - IMGSIZE64 &&
				status.pos.y + IMGSIZE64 - scroll[P1].y <= 508 + IMGSIZE64)
			{
				DrawGraph(status.pos.x + (-scroll[i].x), status.pos.y + (-scroll[i].y), img, TRUE);
			}
			break;
			//WINDOW 2
		case P2:
			if (status.pos.x - scroll[P2].x + 992 >= 928 &&
				status.pos.x + IMGSIZE64 - scroll[P2].x + 992 <= WINDOW_WIDTH + IMGSIZE64 &&
				status.pos.y - scroll[P2].y >= 0 - IMGSIZE64 &&
				status.pos.y + IMGSIZE64 - scroll[P2].y <= 508 + IMGSIZE64)
			{
				DrawGraph(status.pos.x + (-scroll[i].x) + 928 + IMGSIZE64, status.pos.y + (-scroll[i].y), img, TRUE);
			}
			break;
			//WINDOW 3
		case P3:
			if (status.pos.x - scroll[P3].x >= -IMGSIZE64 &&
				status.pos.x + IMGSIZE64 - scroll[P3].x <= 928 + IMGSIZE64 &&
				status.pos.y - scroll[P3].y + 572 >= 572 - IMGSIZE64 &&
				status.pos.y + IMGSIZE64 - scroll[P3].y + 572 <= WINDOW_HEIGHT + IMGSIZE64)
			{
				DrawGraph(status.pos.x + (-scroll[i].x), status.pos.y + (-scroll[i].y) + 508 + IMGSIZE64, img, TRUE);
			}
			break;
			//WINDOW 4
		case P4:
			if (status.pos.x - scroll[P4].x + 992 >= 992 - IMGSIZE64 &&
				status.pos.x + IMGSIZE64 - scroll[P4].x + 992 <= WINDOW_WIDTH + IMGSIZE64 &&
				status.pos.y - scroll[P4].y + 572 >= 572 - IMGSIZE64 &&
				status.pos.y + IMGSIZE64 - scroll[P4].y + 572 <= WINDOW_HEIGHT + IMGSIZE64)
			{
				DrawGraph(status.pos.x + (-scroll[i].x) + 928 + IMGSIZE64, status.pos.y + (-scroll[i].y) + 508 + IMGSIZE64, img, TRUE);
			}
			break;
		}

	}
}