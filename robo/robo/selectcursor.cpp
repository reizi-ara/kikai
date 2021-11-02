
#pragma once
#include "char.h"


//コンストラクタ
Cursor::Cursor(float _x, float _y) {

	img = LoadGraph("image\\ArrowDown.png");

	Charcter.pos.x = _x;
	Charcter.pos.y = _y;

	Charcter.ID = 1;

	Charcter.FLAG = true;
}

//処理
int Cursor::Action(list<unique_ptr<Bace>>& bace) 
{
	if (CheckHitKey(KEY_INPUT_RIGHT) && key_flag == false)
	{
		if (Charcter.pos.x == 512.0f)
		{
			Charcter.pos.x = 128.0f;
			key_flag = true;
		}
		else
		{
			Charcter.pos.x += 128.0f;
			key_flag = true;
		}

	}
	

	if (CheckHitKey(KEY_INPUT_LEFT) && key_flag == false)
	{
		if (Charcter.pos.x == 128.0f)
		{
			Charcter.pos.x = 512.0f;
			key_flag = true;
		}
		else
		{
			Charcter.pos.x -= 128.0f;
			key_flag = true;
		}
	}
	
	if (!CheckHitKey(KEY_INPUT_LEFT) && !CheckHitKey(KEY_INPUT_RIGHT))
	{
		key_flag = false;
	}

	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		for (auto i = bace.begin(); i != bace.end(); i++)
		{
			if ((*i)->Charcter.ID == 1)
			{
				if (Charcter.pos.x == 128.0f)
				{
					select_type = 1;
				}
				else if (Charcter.pos.x == 256.0f)
				{
					select_type = 2;
				}
				else if (Charcter.pos.x == 384.0f)
				{
					select_type = 3;
				}
				else if (Charcter.pos.x == 512.0f)
				{
					select_type = 4;
				}
			}

			if ((*i)->Charcter.ID == 1)
			{
				Charcter.FLAG = false;
			}
		}
	}
	

	return 0;
}
//描画
void Cursor::Draw() {
	DrawGraphF(Charcter.pos.x, Charcter.pos.y, img, TRUE);

}