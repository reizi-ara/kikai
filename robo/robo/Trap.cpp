#pragma once
#include "char.h"
#define b_speedx 10.0f
#define b_speedy 10.0f

//コンストラクタ
Trap::Trap(float vx, float vy, float px, float py, int WIN_ID, int IMGSIZE)
{
	img = LoadGraph("image\\Trap_bom.png");

	//初期化--------------------------------
	img_size = IMGSIZE;

	status.pos.x = px;
	status.pos.y = py;

	status.WIN_ID = WIN_ID;

	status.ID = BULLET;
	status.speed.x = vx;
	status.speed.y = vy;
	//-------------------------------------

	//描画順番号
	pri = 99;
}

//処理実行
int Trap::Action(list<unique_ptr<Base>>& base)
{
	//プレイヤーを探し、ID情報を取得する
	for (auto i = base.begin(); i != base.end(); i++)
	{
		if ((*i)->status.WIN_ID >= 0 && (*i)->status.ID != BULLET)
		{
			switch ((*i)->status.WIN_ID)
			{
			case P1:
				ID[P1] = (*i)->status.ID;
				break;
			case P2:
				ID[P2] = (*i)->status.ID;
				break;
			case P3:
				ID[P3] = (*i)->status.ID;
				break;
			case P4:
				ID[P4] = (*i)->status.ID;
				break;
			}
		}
	}

	//スクロール情報セッティング
	ScrollSet(scroll, p_pos, base);
	//プレイヤーとの当たり判定実行
	hit_player = Hit_Player(status.pos, scroll, base, IMGSIZE64, &status.FLAG, status.WIN_ID);

	//hit_player に数値がある場合　ダメージ処理実行
	if (hit_player >= 0 && hit_player <= 3)
	{
		for (auto i = base.begin(); i != base.end(); i++)
		{
			if ((*i)->status.WIN_ID == hit_player && ((Player*)(*i).get())->r_flag == false)
			{
				//基本ダメージにステータス情報を入れ、ダメージを増減させる
				(*i)->status.hp -= 200.0f * (*i)->status.s_atk - (50.0f * (*i)->status.s_atk * (*i)->status.def);
				//当たったプレイヤーのHPが０の時 kill_flag を true　にする
				if ((*i)->status.hp <= 0)
				{
					kill_flag = true;
				}
			}
		}
	}
	//キル数カウント処理
	for (auto i = base.begin(); i != base.end(); i++)
	{
		if (kill_flag == true && (*i)->status.WIN_ID == status.WIN_ID && (*i)->status.ID != BULLET)
		{
			((Player*)(*i).get())->kill++;
		}
	}

	//時間でオブジェクト削除----------------------
	delete_time++;
	if (delete_time > 6000)
	{
		status.FLAG = false;
	}
	//-------------------------------------------
	if (status.FLAG == false)
	{
		PlaySoundMem(SE_damege, DX_PLAYTYPE_BACK);
	}
	return 0;
}

void Trap::Draw()
{
	//FLAGがtrueの時
	if (status.FLAG != false)
	{
		//WINDOWごとに描画
		for (int i = 0; i < 4; i++)
		{
			switch (i)
			{
				//WINDOW 1
			case P1:
				if (status.pos.x - scroll[P1].x >= -IMGSIZE64 &&
					status.pos.x + IMGSIZE64 - scroll[P1].x <= 992 &&
					status.pos.y - scroll[P1].y >= 0 - IMGSIZE64 &&
					status.pos.y + IMGSIZE64 - scroll[P1].y <= 508 + IMGSIZE64 &&
					ID[P1] == TRAP_PLAYER)
				{
					DrawGraph(status.pos.x + (-scroll[i].x), status.pos.y + (-scroll[i].y), img, TRUE);
				}
				break;
				//WINDOW 2
			case P2:
				if (status.pos.x - scroll[P2].x + 992 >= 928 &&
					status.pos.x + IMGSIZE64  - scroll[P2].x + 992 <= WINDOW_WIDTH + IMGSIZE64 &&
					status.pos.y - scroll[P2].y >= 0 - IMGSIZE64 &&
					status.pos.y + IMGSIZE64   - scroll[P2].y <= 508 + IMGSIZE64 &&
					ID[P2] == TRAP_PLAYER)
				{
					DrawGraph(status.pos.x + (-scroll[i].x) + 928 + IMGSIZE64, status.pos.y + (-scroll[i].y), img, TRUE);
				}
				break;
				//WINDOW 3
			case P3:
				if (status.pos.x - scroll[P3].x >= -IMGSIZE64 &&
					status.pos.x + IMGSIZE64  - scroll[P3].x <= 928 + IMGSIZE64 &&
					status.pos.y - scroll[P3].y + 572 >= 572 - IMGSIZE64 &&
					status.pos.y + IMGSIZE64  - scroll[P3].y + 572 <= WINDOW_HEIGHT + IMGSIZE64 &&
					ID[P3] == TRAP_PLAYER)
				{
					DrawGraph(status.pos.x + (-scroll[i].x), status.pos.y + (-scroll[i].y) + 508 + IMGSIZE64, img, TRUE);
				}
				break;
				//WINDOW 4
			case P4:
				if (status.pos.x - scroll[P4].x + 992 >= 992 - IMGSIZE64 &&
					status.pos.x + IMGSIZE64  - scroll[P4].x + 992 <= WINDOW_WIDTH + IMGSIZE64 &&
					status.pos.y - scroll[P4].y + 572 >= 572 - IMGSIZE64 &&
					status.pos.y + IMGSIZE64 - scroll[P4].y + 572 <= WINDOW_HEIGHT + IMGSIZE64 &&
					ID[P4] == TRAP_PLAYER)
				{
					DrawGraph(status.pos.x + (-scroll[i].x) + 928 + IMGSIZE64, status.pos.y + (-scroll[i].y) + 508 + IMGSIZE64, img, TRUE);
				}
				break;
			}
		}
	}
	//トラップ起動時
	else
	{
		//WINDOWごとに描画
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
					DrawGraph(status.pos.x + (-scroll[i].x), status.pos.y + (-scroll[i].y), img_Bom, TRUE);
				}
				break;
				//WINDOW 2
			case P2:
				if (status.pos.x - scroll[P2].x + 992 >= 928 &&
					status.pos.x + IMGSIZE64 - scroll[P2].x + 992 <= WINDOW_WIDTH + IMGSIZE64 &&
					status.pos.y - scroll[P2].y >= 0 - IMGSIZE64 &&
					status.pos.y + IMGSIZE64 - scroll[P2].y <= 508 + IMGSIZE64)
				{
					DrawGraph(status.pos.x + (-scroll[i].x) + 928 + IMGSIZE64, status.pos.y + (-scroll[i].y), img_Bom, TRUE);
				}
				break;
				//WINDOW 3
			case P3:
				if (status.pos.x - scroll[P3].x >= -IMGSIZE64 &&
					status.pos.x + IMGSIZE64 - scroll[P3].x <= 928 + IMGSIZE64 &&
					status.pos.y - scroll[P3].y + 572 >= 572 - IMGSIZE64 &&
					status.pos.y + IMGSIZE64 - scroll[P3].y + 572 <= WINDOW_HEIGHT + IMGSIZE64)
				{
					DrawGraph(status.pos.x + (-scroll[i].x), status.pos.y + (-scroll[i].y) + 508 + IMGSIZE64, img_Bom, TRUE);
				}
				break;
				//WINDOW 4
			case P4:
				if (status.pos.x - scroll[P4].x + 992 >= 992 - IMGSIZE64 &&
					status.pos.x + IMGSIZE64 - scroll[P4].x + 992 <= WINDOW_WIDTH + IMGSIZE64 &&
					status.pos.y - scroll[P4].y + 572 >= 572 - IMGSIZE64 &&
					status.pos.y + IMGSIZE64 - scroll[P4].y + 572 <= WINDOW_HEIGHT + IMGSIZE64)
				{
					DrawGraph(status.pos.x + (-scroll[i].x) + 928 + IMGSIZE64, status.pos.y + (-scroll[i].y) + 508 + IMGSIZE64, img_Bom, TRUE);
				}
				break;
			}
		}
	}

}