
#pragma once
#include "char.h"


//コンストラクタ
SelectCursor::SelectCursor(float _x, float _y) {

	img = LoadGraph("image\\ArrowDown.png");

	pos.x = _x;
	pos.y = _y;

	ID = 1;

	FLAG = true;
}

//処理
int SelectCursor::Action(list<unique_ptr<Bace>>& bace) 
{
	if (CheckHitKey(KEY_INPUT_RIGHT) && key_flag == false)
	{
		if (pos.x == 512.0f)
		{
			pos.x = 128.0f;
			key_flag = true;
		}
		else
		{
			pos.x += 128.0f;
			key_flag = true;
		}

	}
	

	if (CheckHitKey(KEY_INPUT_LEFT) && key_flag == false)
	{
		if (pos.x == 128.0f)
		{
			pos.x = 512.0f;
			key_flag = true;
		}
		else
		{
			pos.x -= 128.0f;
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
			if ((*i)->ID == 1)
			{
				if (pos.x == 128.0f)
				{
					select_type = 1;
				}
				else if (pos.x == 256.0f)
				{
					select_type = 2;
				}
				else if (pos.x == 384.0f)
				{
					select_type = 3;
				}
				else if (pos.x == 512.0f)
				{
					select_type = 4;
				}
			}

			if ((*i)->ID == 1)
			{
				FLAG = false;
			}
		}
	}
	

	return 0;
}
//描画
void SelectCursor::Draw() {
	DrawGraphF(pos.x, pos.y, img, TRUE);

}