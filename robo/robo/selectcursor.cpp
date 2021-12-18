
#pragma once
#include "char.h"


//コンストラクタ
Cursor::Cursor(float _x, float _y) {

	img = LoadGraph("image\\ArrowDown.png");

	status.pos.x = _x;
	status.pos.y = _y;

	status.ID = 1;

	status.FLAG = true;
}

//処理
int Cursor::Action(list<unique_ptr<Base>>& base) 
{
	if (CheckHitKey(KEY_INPUT_RIGHT) && key_flag == false)
	{
		if (status.pos.x == 512.0f)
		{
			status.pos.x = 128.0f;
			key_flag = true;
		}
		else
		{
			status.pos.x += 128.0f;
			key_flag = true;
		}

	}
	

	if (CheckHitKey(KEY_INPUT_LEFT) && key_flag == false)
	{
		if (status.pos.x == 128.0f)
		{
			status.pos.x = 512.0f;
			key_flag = true;
		}
		else
		{
			status.pos.x -= 128.0f;
			key_flag = true;
		}
	}
	
	if (!CheckHitKey(KEY_INPUT_LEFT) && !CheckHitKey(KEY_INPUT_RIGHT))
	{
		key_flag = false;
	}

	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		for (auto i = base.begin(); i != base.end(); i++)
		{
			if ((*i)->status.ID == 1)
			{
				if (status.pos.x == 128.0f)
				{
					select_type = 1;
				}
				else if (status.pos.x == 256.0f)
				{
					select_type = 2;
				}
				else if (status.pos.x == 384.0f)
				{
					select_type = 3;
				}
				else if (status.pos.x == 512.0f)
				{
					select_type = 4;
				}
			}

			if ((*i)->status.ID == 1)
			{
				status.FLAG = false;
			}
		}
	}
	

	return 0;
}
//描画
void Cursor::Draw() {
	DrawGraphF(status.pos.x, status.pos.y, img, TRUE);

}