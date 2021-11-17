#pragma once
#include "char.h"

//�R���X�g���N�^
Player::Player(float _x, float _y,int type_num)
{
	img1 = LoadGraph("image\\Arrow.png");
	img2 = LoadGraph("image\\ArrowDown.png");
	img3 = LoadGraph("image\\ArrowRight.png");
	img4 = LoadGraph("image\\ArrowLeft.png");

	Charcter.pos.x = _x;
	Charcter.pos.y = _y;

	if (type_num == SPEED_PLAYER)
	{
		Charcter.ID = SPEED_PLAYER;

		HP = default_HP;
		SP = default_SP;
		ATK = default_ATK;
		DEF = default_DEF;
		CD = default_CD;
		SPD_X = default_SPD_X;
		SPD_Y = default_SPD_Y;
	} 

	if (type_num == DEFENSE_PLAYER)
	{
		Charcter.ID = DEFENSE_PLAYER;

		HP = default_HP;
		SP = default_SP;
		ATK = default_ATK;
		DEF = default_DEF * 1.2;
		CD = default_CD;
		SPD_X = default_SPD_X * 0.1;
		SPD_Y = default_SPD_Y * 0.1;
	}

	if (type_num == SHOOTING_PLAYER)
	{
		Charcter.ID = SHOOTING_PLAYER;

		HP = default_HP;
		SP = default_SP;
		ATK = default_ATK;
		DEF = default_DEF;
		CD = default_CD;
		SPD_X = default_SPD_X;
		SPD_Y = default_SPD_Y;
	}

	if (type_num == TRAP_PLAYER)
	{
		Charcter.ID = TRAP_PLAYER;

		HP = default_HP;
		SP = default_SP;
		ATK = default_ATK;
		DEF = default_DEF;
		CD = default_CD;
		SPD_X = default_SPD_X;
		SPD_Y = default_SPD_Y;
	}

	

	Charcter.FLAG = true;
}

int Player::Action(list<unique_ptr<Bace>>& bace)
{
	Charcter.speed.x = 0.0f; Charcter.speed.y = 0.0f;
	static int vx, vy;

	//�ړ���������
	GetJoypadAnalogInput(&vx, &vy, (DX_INPUT_PAD1));

	Charcter.speed.x = vx / 250.0f;
	Charcter.speed.y = vy / 250.0f;

	Charcter.pos.x += Charcter.speed.x;
	Charcter.pos.y += Charcter.speed.y;

	//�摜�p�̕ۑ��ϐ�
	if (vx != 0 || vy != 0)
	{
		rotate_vx = vx;
		rotate_vy = vy;
	}

	//�e�p�̕ۑ��ϐ�
	if (vx != 0 || vy != 0)
	{
		BulletSave_vx = Charcter.speed.x;
		BulletSave_vy = Charcter.speed.y;
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

	

	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B) == 0)
	{
		ShotFlag = true;
	}
	else
	{
		if (ShotFlag == true)
		{
			auto B = (unique_ptr<Bace>)new Bullet(BulletSave_vx, BulletSave_vy, Charcter.pos.x, Charcter.pos.y);
			bace.emplace_back(move(B));

			ShotFlag = false;
		}
	}
	
	return 0;
}

// �`��
void Player::Draw() {

	if (img_Vec == 3) {
		DrawGraph(Charcter.pos.x, Charcter.pos.y, img3, TRUE);
		
	}
	if (img_Vec == 4) {
		DrawGraph(Charcter.pos.x, Charcter.pos.y, img4, TRUE);
	}
	if (img_Vec == 2) {
		DrawGraph(Charcter.pos.x, Charcter.pos.y, img2, TRUE);
	}
	if (img_Vec == 1) {
		DrawGraph(Charcter.pos.x, Charcter.pos.y, img1, TRUE);
	}

	
}