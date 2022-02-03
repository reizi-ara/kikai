#pragma once
#include "char.h"


//�R���X�g���N�^
Cursor::Cursor(int WIN_ID) {

	//�摜���[�h--------------------------------------------------
	img = LoadGraph("image\\ArrowDown.png");
	img1 = LoadGraph("image\\UI\\UI.png");

	img_m[0]= LoadGraph("image\\Cube_Speed.png");
	img_m[1] = LoadGraph("image\\Cube_Deffense.png");
	img_m[2] = LoadGraph("image\\Cube_Attack.png");
	img_m[3] = LoadGraph("image\\Cube_Trap.png");

	img_p[0] = LoadGraph("image\\�L�����N�^�[\\Combat.png");
	img_p[1] = LoadGraph("image\\�L�����N�^�[\\Shooting.png");
	img_p[2] = LoadGraph("image\\�L�����N�^�[\\Speed.png");
	img_p[3] = LoadGraph("image\\�L�����N�^�[\\Mecha.png");
	//-------------------------------------------------------------

	//WINDOW���Ƃ̈ʒu��ݒ�
	switch (WIN_ID)
	{
	case P1:
		status.pos.x = IMGSIZE64 ;
		status.pos.y = 0;
		break;
	case P2:
		status.pos.x = IMGSIZE64  + 928 + IMGSIZE64;
		status.pos.y = 0;
		break;
	case P3:
		status.pos.x = IMGSIZE64 ;
		status.pos.y = 508 + IMGSIZE64;
		break;
	case P4:
		status.pos.x = IMGSIZE64 + 928 + IMGSIZE64;
		status.pos.y = 508 + IMGSIZE64;
		break;
	}
	

	status.ID = 1;

	status.WIN_ID = WIN_ID;

	status.FLAG = true;
}

//����
int Cursor::Action(list<unique_ptr<Base>>& base) 
{
	//�Z���N�g���I����Ă��Ȃ���Ύ��s
	if (complete_select == false)
	{
		//�J�[�\���ړ�����
		if ((GetJoypadInputState(Con[status.WIN_ID]) & PAD_INPUT_RIGHT) != 0 && key_flag == false)
		{
			if (x_count < 3)
			{
				x_count++;
			}

			key_flag = true;
		}
		//�J�[�\���ړ�����
		if ((GetJoypadInputState(Con[status.WIN_ID]) & PAD_INPUT_LEFT) != 0 && key_flag == false)
		{
			if (x_count > 0)
			{
				x_count--;
			}

			key_flag = true;
		}
		//�{�^���̑��d�����h������
		if ((GetJoypadInputState(Con[status.WIN_ID]) & PAD_INPUT_LEFT) == 0 && (GetJoypadInputState(Con[status.WIN_ID]) & PAD_INPUT_RIGHT) == 0)
		{
			key_flag = false;
		}

		//����{�^���������ƃZ���N�g����
		if ((GetJoypadInputState(Con[status.WIN_ID]) & PAD_INPUT_B) != 0 && button_flag == false)
		{
			//�@�̃Z���N�g
			if (select_mode == 1)
			{
				switch (x_count)
				{
				case SPEED_PLAYER:
					get_select[select_mode][status.WIN_ID] = SPEED_PLAYER;
					complete_select = true;
					break;
				case DEFFENSE_PLAYER:
					get_select[select_mode][status.WIN_ID] = DEFFENSE_PLAYER;
					complete_select = true;
					break;
				case ATTACK_PLAYER:
					get_select[select_mode][status.WIN_ID] = ATTACK_PLAYER;
					complete_select = true;
					break;
				case TRAP_PLAYER:
					get_select[select_mode][status.WIN_ID] = TRAP_PLAYER;
					complete_select = true;
					break;
				}
			}
			//�p�C���b�g�Z���N�g
			if (select_mode == 0)
			{
				switch (x_count)
				{
				case COMBAT:
					get_select[select_mode][status.WIN_ID] = COMBAT;
					y_count = 1;
					select_mode = 1;
					break;
				case SHOOT:
					get_select[select_mode][status.WIN_ID] = SHOOT;
					y_count = 1;
					select_mode = 1;
					break;
				case RUN:
					get_select[select_mode][status.WIN_ID] = RUN;
					y_count = 1;
					select_mode = 1;
					break;
				case MECHANIC:
					get_select[select_mode][status.WIN_ID] = MECHANIC;
					y_count = 1;
					select_mode = 1;
					break;
				}
			}


			button_flag = true;
		}

		//�{�^�����d�����h������
		if ((GetJoypadInputState(Con[status.WIN_ID]) & PAD_INPUT_B) == 0)
			button_flag = false;
	}
	else
	{
		if ((GetJoypadInputState(Con[status.WIN_ID]) & PAD_INPUT_A) != 0)
		{
			complete_select = false;
			y_count = 0;
			select_mode = 0;
			get_select[0][status.WIN_ID] = -1;
			get_select[1][status.WIN_ID] = -1;
		}
	}

	return 0;
}
//�`��
void Cursor::Draw() 
{
	//�J�[�\���`��
	DrawGraphF(status.pos.x + x_count * 256, status.pos.y + y_count * 256 , img, TRUE);

	//�L�����N�^�[�\��
	for (int i = 0; i < 4; i++)
	{
		DrawGraphF(status.pos.x + i * 256-IMGSIZE64/4, status.pos.y + IMGSIZE64, img_m[i], TRUE);
		DrawGraphF(status.pos.x + i * 256 - IMGSIZE64 / 4, status.pos.y + 256 + IMGSIZE64, img_p[i], TRUE);
	}
	SetFontSize(IMGSIZE64 / 2);
	//�Z���N�g�����@�̂�\��
	switch (get_select[0][status.WIN_ID])
	{
	case -1:
		break;
	case SPEED_PLAYER:
		DrawFormatString(status.pos.x + 256 - IMGSIZE64 / 4, status.pos.y + IMGSIZE64 + IMGSIZE64, GetColor(255, 255, 255), "�X�s�[�h�^");
		break;
	case DEFFENSE_PLAYER:
		DrawFormatString(status.pos.x + 256 - IMGSIZE64 / 4, status.pos.y + IMGSIZE64 + IMGSIZE64, GetColor(255, 255, 255), "�f�B�t�F���X�^");
		break;
	case ATTACK_PLAYER:
		DrawFormatString(status.pos.x + 256 - IMGSIZE64 / 4, status.pos.y + IMGSIZE64 + IMGSIZE64, GetColor(255, 255, 255), "�L���m���^");
		break;
	case TRAP_PLAYER:
		DrawFormatString(status.pos.x + 256 - IMGSIZE64 / 4, status.pos.y + IMGSIZE64 + IMGSIZE64, GetColor(255, 255, 255), "�g���b�v�^");
		break;
	}
	switch (get_select[1][status.WIN_ID])
	{
	case -1:
		break;
	case COMBAT:
		DrawFormatString(status.pos.x + 256 - IMGSIZE64 / 4, status.pos.y + IMGSIZE64 + IMGSIZE64 + 256, GetColor(255, 255, 255), "�ߐڌ^");
		break;
	case SHOOT:
		DrawFormatString(status.pos.x + 256 - IMGSIZE64 / 4, status.pos.y + IMGSIZE64 + IMGSIZE64 + 256, GetColor(255, 255, 255), "�ˌ��^");
		break;
	case RUN:
		DrawFormatString(status.pos.x + 256 - IMGSIZE64 / 4, status.pos.y + IMGSIZE64 + IMGSIZE64 + 256, GetColor(255, 255, 255), "���@���^");
		break;
	case MECHANIC:
		DrawFormatString(status.pos.x + 256 - IMGSIZE64 / 4, status.pos.y + IMGSIZE64 + IMGSIZE64 + 256, GetColor(255, 255, 255), "�����񕜌^");
		break;
	}


	//UI�\��
	DrawGraphF(0, 0, img1, TRUE);
	SetFontSize(IMGSIZE64);

	//�Z���N�g������
	if (complete_select == true)
	{
		DrawFormatString(status.pos.x, status.pos.y, GetColor(255, 255, 255), "%dP SELECT COMPLETE", status.WIN_ID + 1);
	}
}