#pragma once
#include "char.h"

//�R���X�g���N�^
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

	//�L�����N�^�[������--------------------------------------------------------------
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
	
	SetMachine(&status, type_num, pilot);//�@�̏��A�p�C���b�g���}��

	pri = 990;

	
	//-------------------------------------------------------------------------------
}

int Player::Action(list<unique_ptr<Base>>& base)
{
	status.speed.x = 0.0f; status.speed.y = 0.0f;
	static int vx, vy;

	//�ړ���������
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

	//�摜�p�̕ۑ��ϐ�
	if (vx != 0 || vy != 0)
	{
		rotate_vx = vx;
		rotate_vy = vy;
	}

	//�e�p�̕ۑ��ϐ�
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
	}

	if (weponget_flag == true) {
		wepon_num = rand() % 2;
		weponget_flag = false;
	}

	if (wepon_num >= 0)
	{
		if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B) == 0 && wepon_cd >= 60)
		{
			ShotFlag = true;
		}
		else
		{
			if (ShotFlag == true)
			{
				//�u���b�N�ɐڐG���Ă���ƒe�𔭎˂ł��Ȃ����߉����p�i���j
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

				base.emplace_back((unique_ptr<Base>)new Bullet(BulletSave_vx, BulletSave_vy, status.pos.x + IMGSIZE64 / 2 + bullet.x, status.pos.y + IMGSIZE64 / 2 + bullet.y));
				//wepon_summary(base, status.pos.x, status.pos.y, wepon_num, status.P_ID);

				/*	if (wepon_num == 0) {
						w_img = LoadGraph("image\\���g.png");
					}*/

				ShotFlag = false;
				wepon_cd = 0;
				wepon_num = -1;
			}
		}
	}
	
	if (ShotFlag == false)
	{
		wepon_cd++;
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

// �`��
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