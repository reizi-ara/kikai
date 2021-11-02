
#pragma once
#include "char.h"


//�R���X�g���N�^
SelectCursor::SelectCursor(float _x, float _y) {
	img = LoadGraph("image\\ArrowDown.png");

	pos.x = _x;
	pos.y = _y;

	ID = 1;

	FLAG = true;
}

//����
int SelectCursor::Action(list<unique_ptr<Bace>>& bace) 
{
	if (CheckHitKey(KEY_INPUT_RIGHT) && time >= 40)
	{
		if (pos.x == 512.0f)
		{
			pos.x = 128.0f;
			time = 0;
		}
		else
		{
			pos.x += 128.0f;
			time = 0;
			
		}

	}

	if (CheckHitKey(KEY_INPUT_LEFT) && time >= 40)
	{
		if (pos.x == 128.0f)
		{
			pos.x = 512.0f;
			time = 0;
		}
		else
		{
			pos.x -= 128.0f;
			time = 0;
		}
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



	time++;
	

	return 0;
}
//�`��
void SelectCursor::Draw() {
	DrawGraphF(pos.x, pos.y, img, TRUE);

}