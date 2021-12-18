#pragma once
#include "char.h"

UI::UI()
{
	status.img = LoadGraph("image\\UI\\UI.png");

	pri = 999;
}

int UI::Action(list<unique_ptr<Base>>& base)
{
	for (auto i = base.begin(); i != base.end(); i++)
	{
		if ((*i)->status.WIN_ID >= 0 && (*i)->status.ID != BULLET)
		{
			switch ((*i)->status.WIN_ID)
			{
			case P1:
				HP[P1] = (*i)->status.hp;
				WEPON[P1] = (*i)->status.wepon_num;
				break;
			case P2:
				HP[P2] = (*i)->status.hp;
				WEPON[P2] = (*i)->status.wepon_num;
				break;
			case P3:
				HP[P3] = (*i)->status.hp;
				WEPON[P3] = (*i)->status.wepon_num;
				break;
			case P4:
				HP[P4] = (*i)->status.hp;
				WEPON[P4] = (*i)->status.wepon_num;
				break;
			}
		}
	}
	return 0;
}

void UI::Draw() 
{
	for (int z = 0; z < 4; z++)
	{
		switch (z)
		{
		case P1:
			DrawGraph(928 - IMGSIZE64 * 2, 0, img_Item_UI, TRUE);
			DrawGraph(0, 0, img_HP_UI, TRUE);
			DrawGraph(0, 508 - IMGSIZE64, img_Skill_UI, TRUE);
			for (int i = 1; i < HP[P1] / 4; i++)
			{
				DrawGraph(2 + i * 4-4, 0 + 1, img_HP, TRUE);
			}
			switch (WEPON[P1])
			{
			case 0:
				DrawGraph(928 + IMGSIZE64 / 2 - IMGSIZE64 * 2, 0 + IMGSIZE64 / 2, img_rifle, TRUE);
				break;
			case 1:
				DrawGraph(928 + IMGSIZE64 / 2 - IMGSIZE64 * 2, 0 + IMGSIZE64 / 2, img_katana, TRUE);
				break;
			}
			break;
		case P2:
			DrawGraph(WINDOW_WIDTH - IMGSIZE64*2, 0, img_Item_UI, TRUE);
			DrawGraph(928 + IMGSIZE64, 0, img_HP_UI, TRUE);
			DrawGraph(WINDOW_WIDTH - IMGSIZE64, 508 - IMGSIZE64, img_Skill_UI, TRUE);
			for (int i = 1; i < HP[P2] / 4; i++)
			{
				DrawGraph(928 + 2 + IMGSIZE64 + i * 4-4, 0 + 1, img_HP, TRUE);
			}
			switch (WEPON[P2])
			{
			case 0:
				DrawGraph(WINDOW_WIDTH + IMGSIZE64 / 2 - IMGSIZE64 * 2, 0 + IMGSIZE64 / 2, img_rifle, TRUE);
				break;
			case 1:
				DrawGraph(WINDOW_WIDTH + IMGSIZE64 / 2 - IMGSIZE64 * 2, 0 + IMGSIZE64 / 2, img_katana, TRUE);
				break;
			}
			break;
		case P3:
			DrawGraph(928 - IMGSIZE64 * 2, 508 + IMGSIZE64, img_Item_UI, TRUE);
			DrawGraph(0, 508 + IMGSIZE64, img_HP_UI, TRUE);
			DrawGraph(0, WINDOW_HEIGHT - IMGSIZE64, img_Skill_UI, TRUE);
			for (int i = 1; i < HP[P3] / 4; i++)
			{
				DrawGraph(2 + i * 4-4, 508 + IMGSIZE64 + 1, img_HP, TRUE);
			}
			switch (WEPON[P3])
			{
			case 0:
				DrawGraph(928 + IMGSIZE64 / 2 - IMGSIZE64 * 2, 508 + IMGSIZE64 + IMGSIZE64 / 2, img_rifle, TRUE);
				break;
			case 1:
				DrawGraph(928 + IMGSIZE64 / 2 - IMGSIZE64 * 2, 508 + IMGSIZE64 + IMGSIZE64 / 2, img_katana, TRUE);
				break;
			}
			break;
		case P4:
			DrawGraph(WINDOW_WIDTH - IMGSIZE64*2, 508 + IMGSIZE64, img_Item_UI, TRUE);
			DrawGraph(928 + IMGSIZE64, 508 + IMGSIZE64, img_HP_UI, TRUE);
			DrawGraph(WINDOW_WIDTH - IMGSIZE64, WINDOW_HEIGHT - IMGSIZE64, img_Skill_UI, TRUE);
			for (int i = 1; i < HP[P4] / 4; i++)
			{
				DrawGraph(2 + 928 + IMGSIZE64 + i * 4-4, 508 + IMGSIZE64 + 1, img_HP, TRUE);
			}
			switch (WEPON[P4])
			{
			case 0:
				DrawGraph(WINDOW_WIDTH + IMGSIZE64 / 2 - IMGSIZE64 * 2, 508 + IMGSIZE64 + IMGSIZE64 / 2, img_rifle, TRUE);
				break;
			case 1:
				DrawGraph(WINDOW_WIDTH + IMGSIZE64 / 2 - IMGSIZE64 * 2, 508 + IMGSIZE64 + IMGSIZE64 / 2, img_katana, TRUE);
				break;
			}
			break;
		}
		
	}
	//iBlock‚ß‚èž‚Ý‘ÎôjUI•\Ž¦
	DrawGraph(0, 0, status.img, TRUE);
}