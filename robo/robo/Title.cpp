#pragma once
#include "char.h"


//コンストラクタ
Title::Title() 
{
	img_m[0] = LoadGraph("image\\Cube_Speed.png");
	img_m[1] = LoadGraph("image\\Cube_Deffense.png");
	img_m[2] = LoadGraph("image\\Cube_Attack.png");
	img_m[3] = LoadGraph("image\\Cube_Trap.png");

	p_pos[0].x = IMGSIZE64 * 2;
	p_pos[1].x = IMGSIZE64 * 10;
	p_pos[2].x = IMGSIZE64 * 18;
	p_pos[3].x = IMGSIZE64 * 26;
	p_pos[4].x = IMGSIZE64 * 2;
	p_pos[5].x = IMGSIZE64 * 10;
	p_pos[6].x = IMGSIZE64 * 18;
	p_pos[7].x = IMGSIZE64 * 26;
	p_pos[4].y = -WINDOW_HEIGHT / 2;
	p_pos[5].y = -WINDOW_HEIGHT / 2;
	p_pos[6].y = -WINDOW_HEIGHT / 2;
	p_pos[7].y = -WINDOW_HEIGHT / 2;
	//音量調整
	ChangeVolumeSoundMem(150, BGM_Title);
	//タイトルBGM再生
	PlaySoundMem(BGM_Title, DX_PLAYTYPE_LOOP);
	
}

//処理
int Title::Action(list<unique_ptr<Base>>& base)
{
	if (Change_Scene == false)
	{
		for (int i = 0; i < 4; i++)
		{
			if ((GetJoypadInputState(Con[i]) & PAD_INPUT_B) != 0)
			{
				Change_Scene = true;
				status.FLAG = false;
				//BGMを止める
				StopSoundMem(BGM_Title);
			}
		}
	}
	for (int i = 0; i < 8; i++)
	{
		if (p_pos[i].y > WINDOW_HEIGHT)
		{
			p_pos[i].y = -IMGSIZE64;
		}
		p_pos[i].y += 3.0f;
	}
	
	return 0;
}
//描画
void Title::Draw()
{
	SetFontSize(IMGSIZE64);

	for (int i = 0; i < 8; i++)
	{
		if (i < 4)
			DrawGraph(p_pos[i].x, p_pos[i].y, img_m[i], TRUE);
		else
			DrawGraph(p_pos[i].x, p_pos[i].y, img_m[i - 4], TRUE);
	}


	DrawFormatString(WINDOW_WIDTH / 2 - IMGSIZE64 * 2.5, WINDOW_HEIGHT / 2 - IMGSIZE64, GetColor(255, 255, 255), "機械決戦");

	
}