
#pragma once
#include "char.h"


//コンストラクタ
Cursor::Cursor(int WIN_ID) {

	img = LoadGraph("image\\ArrowDown.png");
	img1 = LoadGraph("image\\UI\\UI.png");

	img_m[0]= LoadGraph("image\\Cube_Speed.png");
	img_m[1] = LoadGraph("image\\Cube_Deffense.png");
	img_m[2] = LoadGraph("image\\Cube_Attack.png");
	img_m[3] = LoadGraph("image\\Cube_Trap.png");

	img_p[0] = LoadGraph("image\\キャラクター\\Combat.png");
	img_p[1] = LoadGraph("image\\キャラクター\\Shooting.png");
	img_p[2] = LoadGraph("image\\キャラクター\\Speed.png");
	img_p[3] = LoadGraph("image\\キャラクター\\Mecha.png");

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

//処理
int Cursor::Action(list<unique_ptr<Base>>& base) 
{
	
		if ((GetJoypadInputState(Con[status.WIN_ID]) & PAD_INPUT_RIGHT) != 0 && key_flag == false)
		{
			if (x_count < 3)
			{
				x_count++;
			}

			key_flag = true;
		}
		if ((GetJoypadInputState(Con[status.WIN_ID]) & PAD_INPUT_LEFT) != 0 && key_flag == false)
		{
			if (x_count > 0)
			{
				x_count--;
			}

			key_flag = true;
		}

		if ((GetJoypadInputState(Con[status.WIN_ID]) & PAD_INPUT_LEFT) == 0 && (GetJoypadInputState(Con[status.WIN_ID]) & PAD_INPUT_RIGHT) == 0)
		{
			key_flag = false;
		}


		if ((GetJoypadInputState(Con[status.WIN_ID]) & PAD_INPUT_B) != 0 && button_flag == false)
		{
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

		if ((GetJoypadInputState(Con[status.WIN_ID]) & PAD_INPUT_B) == 0)
			button_flag = false;
	

	return 0;
}
//描画
void Cursor::Draw() {
	DrawGraphF(status.pos.x + x_count * 256, status.pos.y + y_count * 256 , img, TRUE);

	for (int i = 0; i < 4; i++)
	{
		DrawGraphF(status.pos.x + i * 256, status.pos.y, img_m[i], TRUE);
		DrawGraphF(status.pos.x + i * 256, status.pos.y + 256, img_p[i], TRUE);
	}
		

	DrawGraphF(0, 0, img1, TRUE);
	SetFontSize(IMGSIZE64);
	if (complete_select == true)
	{
		DrawFormatString(status.pos.x, status.pos.y, GetColor(255, 255, 255), "%dP SELECT COMPLETE", status.WIN_ID + 1);
	}
}