#pragma once
#include "char.h"

//�R���X�g���N�^
Itembox::Itembox(float px, float py)
{
	img = LoadGraph("image\\Item.png");
	//������----------------------------
	status.pos.x = px;
	status.pos.y = py;
	status.ID = ITEMBOX;
	//----------------------------------

	//�`�揇�ԍ�
	pri = 80;

}

//�������s
int Itembox::Action(list<unique_ptr<Base>>& base)
{
	//�X�N���[�����Z�b�e�B���O
	ScrollSet(scroll,p_pos, base);

	//�v���C���[�Ƃ̓����蔻����s�iWINDOW�QID�͕K�v�Ȃ��̂Ł[�P������j
	Hit_Player(status.pos, scroll, base, IMGSIZE64, &status.FLAG, -1);
	//�A�C�e�����擾�����ꍇ
	if (status.FLAG == false)
	{
		//itembox �̔ԍ�������������
		SetMap(status.pos.x / IMGSIZE64, status.pos.y / IMGSIZE64, 0);
	}

	return 0;
}

//�`��֘A����
void Itembox::Draw() {

	//WINDOW���Ƃ̕`����s
	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
			//WINDOW 1
		case P1:
			if (status.pos.x - scroll[P1].x >= -IMGSIZE64 &&
				status.pos.x + IMGSIZE64 - scroll[P1].x <= 992 &&
				status.pos.y - scroll[P1].y >= 0 - IMGSIZE64 &&
				status.pos.y + IMGSIZE64 - scroll[P1].y <= 508 + IMGSIZE64)
			{
				DrawGraph(status.pos.x + (-scroll[i].x), status.pos.y + (-scroll[i].y), img, TRUE);
			}
			break;
			//WINDOW 2
		case P2:
			if (status.pos.x - scroll[P2].x + 992 >= 928 &&
				status.pos.x + IMGSIZE64 - scroll[P2].x + 992 <= WINDOW_WIDTH + IMGSIZE64 &&
				status.pos.y - scroll[P2].y >= 0 - IMGSIZE64 &&
				status.pos.y + IMGSIZE64 - scroll[P2].y <= 508 + IMGSIZE64)
			{
				DrawGraph(status.pos.x + (-scroll[i].x) + 928 + IMGSIZE64, status.pos.y + (-scroll[i].y), img, TRUE);
			}
			break;
			//WINDOW 3
		case P3:
			if (status.pos.x - scroll[P3].x >= -IMGSIZE64 &&
				status.pos.x + IMGSIZE64 - scroll[P3].x <= 928 + IMGSIZE64 &&
				status.pos.y - scroll[P3].y + 572 >= 572 - IMGSIZE64 &&
				status.pos.y + IMGSIZE64 - scroll[P3].y + 572 <= WINDOW_HEIGHT + IMGSIZE64)
			{
				DrawGraph(status.pos.x + (-scroll[i].x), status.pos.y + (-scroll[i].y) + 508 + IMGSIZE64, img, TRUE);
			}
			break;
			//WINDOW 4
		case P4:
			if (status.pos.x - scroll[P4].x + 992 >= 992 - IMGSIZE64 &&
				status.pos.x + IMGSIZE64 - scroll[P4].x + 992 <= WINDOW_WIDTH + IMGSIZE64 &&
				status.pos.y - scroll[P4].y + 572 >= 572 - IMGSIZE64 &&
				status.pos.y + IMGSIZE64 - scroll[P4].y + 572 <= WINDOW_HEIGHT + IMGSIZE64)
			{
				DrawGraph(status.pos.x + (-scroll[i].x) + 928 + IMGSIZE64, status.pos.y + (-scroll[i].y) + 508 + IMGSIZE64, img, TRUE);
			}
			break;
		}

	}
}