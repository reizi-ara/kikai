#pragma once
#include "char.h"

//コンストラクタ
Player::Player(float _x, float _y,int type_num,int pilot,int player_num, int window_num, Point Pos)
{
	/*img1 = LoadGraph("image\\Arrow.png");
	img2 = LoadGraph("image\\ArrowDown.png");
	img3 = LoadGraph("image\\ArrowRight.png");
	img4 = LoadGraph("image\\ArrowLeft.png");*/
	img1 = LoadGraph("image\\Cube_Speed.png");
	img2 = LoadGraph("image\\Cube_Deffense.png");
	img3 = LoadGraph("image\\Cube_Attack.png");
	img4 = LoadGraph("image\\Cube_Trap.png");

	status.WIN_ID = window_num;

	//キャラクター初期化--------------------------------------------------------------
	status.pos.x = Pos.x;
	status.pos.y = Pos.y;

	switch (type_num)
	{
	case SPEED_PLAYER:
		status.img = img1;
		break;
	case DEFFENSE_PLAYER:
		status.img = img2;
		break;
	case TRAP_PLAYER:
		status.img = img4;
		break;
	case ATTACK_PLAYER:
		status.img = img3;
		break;
	}

	img = img1;

	

	status.ID = type_num;
	status.Pilot = pilot;
	status.P_ID = player_num;

	status.hp = default_HP;
	status.sp = default_SP;
	status.f_atk = default_F_ATK;
	status.s_atk = default_S_ATK;
	status.def = default_DEF;
	status.skill_cooldown = default_CD;
	status.speed.x = default_SPD_X;
	status.speed.y = default_SPD_Y;
	
	SetMachine(&status, type_num, pilot);//機体情報、パイロット情報挿入

	pri = 999;

	
	//-------------------------------------------------------------------------------
}

int Player::Action(list<unique_ptr<Base>>& base)
{
	status.speed.x = 0.0f; status.speed.y = 0.0f;
	static int vx, vy;

	//移動方向入力
	switch (status.WIN_ID)
	{
	case P1:
		GetJoypadAnalogInput(&vx, &vy, (DX_INPUT_PAD1));
		break;
	case P2:
		GetJoypadAnalogInput(&vx, &vy, (DX_INPUT_PAD2));
		break;
	case P3:
		GetJoypadAnalogInput(&vx, &vy, (DX_INPUT_PAD3));
		break;
	case P4:
		GetJoypadAnalogInput(&vx, &vy, (DX_INPUT_PAD4));
		break;
	}
	

	status.speed.x = vx / 250.0f;
	status.speed.y = vy / 250.0f;

	status.pos.x += status.speed.x;
	status.pos.y += status.speed.y;

	//画像用の保存変数
	if (vx != 0 || vy != 0)
	{
		rotate_vx = vx;
		rotate_vy = vy;
	}

	//弾用の保存変数
	if (vx != 0 || vy != 0)
	{
		BulletSave_vx = status.speed.x;
		BulletSave_vy = status.speed.y;
	}


	if (rotate_vx > 0)
	{
		img_Vec = 3;
	}
	if (rotate_vx < 0)
	{
		img_Vec = 4;
	}
	if (rotate_vy > 0)
	{
		img_Vec = 2;
	}
	if (rotate_vy < 0)
	{
		img_Vec = 1;
	}


	for (auto i = base.begin(); i != base.end(); i++)
	{
		if ((*i)->status.ID == ITEMBOX) {
			Item = ((Itembox*)(*i).get())->status.pos;
			if (Item.x < status.pos.x + 64 && Item.x + 64 > status.pos.x && Item.y < status.pos.y + 64 && Item.y + 64 > status.pos.y)
			{
				if (wepon_num == -1)
					weponget_flag = true;

				
			}
		}
		switch ((*i)->status.WIN_ID)
		{
		case P1:
			id[P1] = (*i)->status.ID;
			break;
		case P2:
			id[P2] = (*i)->status.ID;
			break;
		case P3:
			id[P3] = (*i)->status.ID;
			break;
		case P4:
			id[P4] = (*i)->status.ID;
			break;
		}
	}

	

	if (weponget_flag == true) {
		wepon_num = rand() % 2;
		weponget_flag = false;
	}
	

	//wepon_num = 0;


	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B) == 0 && wepon_cd >= 60)
	{
		ShotFlag = true;
	}
	else
	{
		if (ShotFlag == true)
		{
			/*auto B = (unique_ptr<Bace>)new Bullet(BulletSave_vx, BulletSave_vy, Charcter.pos.x, Charcter.pos.y);
			bace.emplace_back(move(B));*/
			wepon_summary(base, status.pos.x, status.pos.y, wepon_num, status.P_ID);

			if (wepon_num == 0) {
				w_img = LoadGraph("image\\刀身.png");
			}

			ShotFlag = false;
			wepon_cd = 0;
			wepon_num = -1;
		}
	}

	if (ShotFlag == false)
	{
		wepon_cd++;
	}

	if (wepon_cd < 60)
	{
		DrawGraphF(status.pos.x + 64, status.pos.y, w_img, TRUE);
	}

	GetScroll(&status.pos, &scroll, status.WIN_ID);
	BlockHit(&h_player, &status.pos, &status.speed);
	ScrollSet(e_scroll, e_pos, base);

	return 0;
}

// 描画
void Player::Draw() {

	switch (status.WIN_ID)
	{
	case P1:
		DrawGraph(status.pos.x - scroll.x, status.pos.y - scroll.y, status.img, TRUE);
		break;
	case P2:
		DrawGraph(status.pos.x - scroll.x + 992.0f, status.pos.y - scroll.y, status.img, TRUE);
		break;
	case P3:
		DrawGraph(status.pos.x - scroll.x, status.pos.y + 572.0f - scroll.y, status.img, TRUE);
		break;
	case P4:
		DrawGraph(status.pos.x + 992.0f - scroll.x, status.pos.y + 572.0f - scroll.y, status.img, TRUE);
		break;
	}
}