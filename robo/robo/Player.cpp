#pragma once
#include "char.h"

//コンストラクタ
Player::Player(float _x, float _y,int type_num,int pilot,int player_num, int window_num, Point Pos)
{
	switch (type_num)
	{
	case SPEED_PLAYER:
		img_player[0] = LoadGraph("image\\Cube_Speed.png");
		img_player[1] = LoadGraph("image\\Cube_Speed_LEFT.png");
		img_player[2] = LoadGraph("image\\Cube_Speed_BACK.png");
		img_player[3] = LoadGraph("image\\Cube_Speed_RIGHT.png");
		break;
	case DEFFENSE_PLAYER:
		img_player[0] = LoadGraph("image\\Cube_Deffense.png");
		img_player[1] = LoadGraph("image\\Cube_Deffense_LEFT.png");
		img_player[2] = LoadGraph("image\\Cube_Deffense_BACK.png");
		img_player[3] = LoadGraph("image\\Cube_Deffense_RIGHT.png");
		break;
	case TRAP_PLAYER:
		img_player[0] = LoadGraph("image\\Cube_Trap.png");
		img_player[1] = LoadGraph("image\\Cube_Trap_LEFT.png");
		img_player[2] = LoadGraph("image\\Cube_Trap_BACK.png");
		img_player[3] = LoadGraph("image\\Cube_Trap_RIGHT.png");
		break;
	case ATTACK_PLAYER:
		img_player[0] = LoadGraph("image\\Cube_Attack.png");
		img_player[1] = LoadGraph("image\\Cube_Attack_LEFT.png");
		img_player[2] = LoadGraph("image\\Cube_Attack_BACK.png");
		img_player[3] = LoadGraph("image\\Cube_Attack_RIGHT.png");
		break;
	}

	status.WIN_ID = window_num;

	//キャラクター初期化--------------------------------------------------------------
	status.pos.x = Pos.x;
	status.pos.y = Pos.y;

	for (int i = 0; i < 4; i++)
	{
		switch (type_num)
		{
		case SPEED_PLAYER:
			status.p_img[i] = img_player[i];
			break;
		case DEFFENSE_PLAYER:
			status.p_img[i] = img_player[i];
			break;
		case TRAP_PLAYER:
			status.p_img[i] = img_player[i];
			break;
		case ATTACK_PLAYER:
			status.p_img[i] = img_player[i];
			break;
		}
	}

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

	pri = 990;

	
	//-------------------------------------------------------------------------------
}

int Player::Action(list<unique_ptr<Base>>& base)
{
	static int vx, vy;

	GetJoypadAnalogInput(&vx, &vy, (Con[status.WIN_ID]));

	if (vx > 0)
	{
		status.pos.x += status.speed.x;
	}
	if (vx < 0)
	{
		status.pos.x -= status.speed.x;
	}
	if (vy > 0)
	{
		status.pos.y += status.speed.y;
	}
	if (vy < 0)
	{
		status.pos.y -= status.speed.y;
	}

	//画像用の保存変数
	if (vx != 0 || vy != 0)
	{
		rotate_vx = vx;
		rotate_vy = vy;
	}

	//弾用の保存変数
	if (vx != 0 || vy != 0)
	{
		BulletSave_vx = vx / 250.0f;
		BulletSave_vy = vy / 250.0f;
	}


	if (rotate_vx > 0)
	{
		img_Vec = 3;
	}
	if (rotate_vx < 0)
	{
		img_Vec = 1;
	}
	if (rotate_vy > 0)
	{
		img_Vec = 0;
	}
	if (rotate_vy < 0)
	{
		img_Vec = 2;
	}

	//アイテムボックス取得処理
	for (auto i = base.begin(); i != base.end(); i++)
	{
		if ((*i)->status.ID == ITEMBOX) {
			Item = ((Itembox*)(*i).get())->status.pos;
			if (Item.x < status.pos.x + 64 && Item.x + 64 > status.pos.x && Item.y < status.pos.y + 64 && Item.y + 64 > status.pos.y)
			{
				if (status.wepon_num == -1)
					weponget_flag = true;
			}
		}
	}

	if (weponget_flag == true) {
		status.wepon_num = rand() % 2;
		weponget_flag = false;
	}

	//ライフル処理
	if (status.wepon_num == 0)
	{
		if ((GetJoypadInputState(Con[status.WIN_ID]) & PAD_INPUT_B) == 0 && wepon_cd == 0)
		{
			ShotFlag = true;
		}
		else
		{
			if (ShotFlag == true && wepon_cd == 0)
			{
				ShotFlag = false;
			}
		}
		if (ShotFlag == false)
		{
			wepon_cd++;
			if (wepon_cd % 20== 0)
			{
				//ブロックに接触していると弾を発射できないため解決用（仮）
				if (h_player.LEFT == true)
				{
					bullet.x = IMGSIZE64 / 8;
				}
				if (h_player.RIGHT == true)
				{
					bullet.x = -IMGSIZE64 / 4;
				}
				if (h_player.DOWN == true)
				{
					bullet.y = -IMGSIZE64 / 2;
				}
				if (h_player.UP == true)
				{
					bullet.y = IMGSIZE64 / 8;
				}
				base.emplace_back((unique_ptr<Base>)new Bullet(BulletSave_vx, BulletSave_vy, status.pos.x + IMGSIZE64 / 2 + bullet.x, status.pos.y + IMGSIZE64 / 2 + bullet.y, status.WIN_ID));
			}
				
			if (wepon_cd > 60)
			{
				wepon_cd = 0;
				status.wepon_num = -1;
			}
		}
	}
	
	if (CheckHitKey(KEY_INPUT_Y))
	{
		wepon_cd = 0;
		status.wepon_num = -1;
	}

	if (wepon_cd < 60)
	{
		//DrawGraphF(status.pos.x + 64, status.pos.y, w_img, TRUE);
	}

	GetScroll(&status.pos, &scroll, status.WIN_ID);
	BlockHit(&h_player, &status.pos, &status.speed, IMGSIZE64);
	ScrollSet(e_scroll, e_pos, base);

	return 0;
}

// 描画
void Player::Draw() {

	switch (status.WIN_ID)
	{
	case P1:
		DrawGraph(status.pos.x - scroll.x, status.pos.y - scroll.y, status.p_img[img_Vec], TRUE);
		break;
	case P2:
		DrawGraph(status.pos.x - scroll.x + 992.0f, status.pos.y - scroll.y, status.p_img[img_Vec], TRUE);
		break;
	case P3:
		DrawGraph(status.pos.x - scroll.x, status.pos.y + 572.0f - scroll.y, status.p_img[img_Vec], TRUE);
		break;
	case P4:
		DrawGraph(status.pos.x + 992.0f - scroll.x, status.pos.y + 572.0f - scroll.y, status.p_img[img_Vec], TRUE);
		break;
	}
}