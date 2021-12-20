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
				Skill[P1] = (*i)->status.skill_cooldown;
				Kill[P1] = ((Player*)(*i).get())->kill;
				break;
			case P2:
				HP[P2] = (*i)->status.hp;
				WEPON[P2] = (*i)->status.wepon_num;
				Skill[P2] = (*i)->status.skill_cooldown;
				Kill[P2] = ((Player*)(*i).get())->kill;
				break;
			case P3:
				HP[P3] = (*i)->status.hp;
				WEPON[P3] = (*i)->status.wepon_num;
				Skill[P3] = (*i)->status.skill_cooldown;
				Kill[P3] = ((Player*)(*i).get())->kill;
				break;
			case P4:
				HP[P4] = (*i)->status.hp;
				WEPON[P4] = (*i)->status.wepon_num;
				Skill[P4] = (*i)->status.skill_cooldown;
				Kill[P4] = ((Player*)(*i).get())->kill;
				break;
			}
		}
	}
	return 0;
}

void UI::Draw() 
{
	//（Blockめり込み対策）UI表示
	DrawGraph(0, 0, status.img, TRUE);
	SetFontSize(32);
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
			for (int i = 1; i <= Skill[P1] / 25; i++)
			{
				DrawGraph(0, 508 - i * 4, img_Skill, TRUE);
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
			DrawFormatString(0, 508, GetColor(255, 255, 255), "↑キル数：%d", Kill[P1]);
			break;
		case P2:
			DrawGraph(WINDOW_WIDTH - IMGSIZE64*2, 0, img_Item_UI, TRUE);
			DrawGraph(928 + IMGSIZE64, 0, img_HP_UI, TRUE);
			DrawGraph(WINDOW_WIDTH - IMGSIZE64, 508 - IMGSIZE64, img_Skill_UI, TRUE);
			for (int i = 1; i < HP[P2] / 4; i++)
			{
				DrawGraph(928 + 2 + IMGSIZE64 + i * 4, 0 + 1, img_HP, TRUE);
			}
			for (int i = 1; i <= Skill[P2] / 25; i++)
			{
				DrawGraph(WINDOW_WIDTH - IMGSIZE64, 508 - i * 4 - 4, img_Skill, TRUE);
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
			DrawFormatString(908 + IMGSIZE64, 508, GetColor(255, 255, 255), "↑キル数：%d", Kill[P2]);
			break;
		case P3:
			DrawGraph(928 - IMGSIZE64 * 2, 508 + IMGSIZE64, img_Item_UI, TRUE);
			DrawGraph(0, 508 + IMGSIZE64, img_HP_UI, TRUE);
			DrawGraph(0, WINDOW_HEIGHT - IMGSIZE64, img_Skill_UI, TRUE);
			for (int i = 1; i < HP[P3] / 4; i++)
			{
				DrawGraph(2 + i * 4-4, 508 + IMGSIZE64 + 1, img_HP, TRUE);
			}
			for (int i = 1; i <= Skill[P3] / 25; i++)
			{
				DrawGraph(0, WINDOW_HEIGHT - i * 4, img_Skill, TRUE);
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
			DrawFormatString(0, 508 + 32, GetColor(255, 255, 255), "↓キル数：%d", Kill[P3]);
			break;
		case P4:
			DrawGraph(WINDOW_WIDTH - IMGSIZE64*2, 508 + IMGSIZE64, img_Item_UI, TRUE);
			DrawGraph(928 + IMGSIZE64, 508 + IMGSIZE64, img_HP_UI, TRUE);
			DrawGraph(WINDOW_WIDTH - IMGSIZE64, WINDOW_HEIGHT - IMGSIZE64, img_Skill_UI, TRUE);
			for (int i = 1; i < HP[P4] / 4; i++)
			{
				DrawGraph(2 + 928 + IMGSIZE64 + i * 4, 508 + IMGSIZE64 + 1, img_HP, TRUE);
			}
			for (int i = 1; i <= Skill[P4] / 25; i++)
			{
				DrawGraph(WINDOW_WIDTH - IMGSIZE64, WINDOW_HEIGHT - i * 4 - 4, img_Skill, TRUE);
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
			DrawFormatString(908 + IMGSIZE64, 508+32, GetColor(255, 255, 255), "↓キル数：%d", Kill[P4]);
			break;
		}
		
	}

}