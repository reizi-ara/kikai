#pragma once
#include "char.h"

//�R���X�g���N�^
Player::Player(float _x, float _y,int type_num,int pilot)
{
	/*img1 = LoadGraph("image\\Arrow.png");
	img2 = LoadGraph("image\\ArrowDown.png");
	img3 = LoadGraph("image\\ArrowRight.png");
	img4 = LoadGraph("image\\ArrowLeft.png");*/
	img1 = LoadGraph("image\\square64.png");

	//�L�����N�^�[������--------------------------------------------------------------
	Charcter.pos.x = _x;
	Charcter.pos.y = _y;

	Charcter.ID = type_num;
	Charcter.Pilot = pilot;

	Charcter.hp = default_HP;
	Charcter.sp = default_SP;
	Charcter.f_atk = default_F_ATK;
	Charcter.s_atk = default_S_ATK;
	Charcter.def = default_DEF;
	Charcter.skill_cooldown = default_CD;
	Charcter.speed.x = default_SPD_X;
	Charcter.speed.y = default_SPD_Y;
	
	SetMachine(&Charcter, type_num, pilot);//�@�̏��A�p�C���b�g���}��

	Charcter.FLAG = true;

	
	//-------------------------------------------------------------------------------
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


	for (auto i = bace.begin(); i != bace.end(); i++)
	{
		if ((*i)->Charcter.ID == ITEMBOX) {
			Item = ((Itembox*)(*i).get())->Charcter.pos;
			if (Item.x < Charcter.pos.x + 64 && Item.x + 64 > Charcter.pos.x && Item.y < Charcter.pos.y + 64 && Item.y + 64 > Charcter.pos.y)
			{
				if (wepon_num == -1)
					weponget_flag = true;

				((Itembox*)(*i).get())->Charcter.FLAG = false;
			}
		}

		

	}

	

	if (weponget_flag == true) {
		wepon_num = rand() % 2;
		weponget_flag = false;
	}
	

	

	/*if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B) == 0)
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
	}*/

	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B) == 0)
	{
		ShotFlag = true;
	}
	else
	{
		if (ShotFlag == true)
		{
			/*auto B = (unique_ptr<Bace>)new Bullet(BulletSave_vx, BulletSave_vy, Charcter.pos.x, Charcter.pos.y);
			bace.emplace_back(move(B));*/

			bace.emplace_back((unique_ptr<Bace>)new wepon(500.0f, 100.0f, 0));

			ShotFlag = false;
		}
	}
	
	
	return 0;
}

// �`��
void Player::Draw() {

	/*if (img_Vec == 3) {
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
	}*/
	DrawGraph(Charcter.pos.x, Charcter.pos.y, img1, TRUE);
	
}