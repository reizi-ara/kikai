#include "main.h"
#include"char.h"
#include"Function.h"

int time_count = 0;

//�}�b�v�ϐ�
int map[MAP_SIZE_Y][MAP_SIZE_X]{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

//�X�N���[���֐�
//Point *_pos		�v���C���[���W
//vector *_scroll	�v���C���[�̃X�N���[�����
//int _WIN_ID		WINDOW_ID
void GetScroll(Point* _pos, Vector* _scroll, int _WIN_ID)
{
	//�X�N���[���ۑ��p�ϐ�
	_scroll->x = 0.0f;
	_scroll->y = 0.0f;

	//X���X�N���[�����C��
	if (_pos->x + IMGSIZE64 >= SCROLL_LINE_X)
	{
		_scroll->x = _pos->x + IMGSIZE64 - SCROLL_LINE_X;
	}
	if (_pos->x + IMGSIZE64 >= SCROLL_LINE_X_MAX)
	{
		_scroll->x = SCROLL_LINE_X_MAX - SCROLL_LINE_X;
	}
	//Y���X�N���[�����C��
	if (_pos->y >= SCROLL_LINE_Y)
	{
		_scroll->y = _pos->y - SCROLL_LINE_Y;
	}
	if (_pos->y >= SCROLL_LINE_Y_MAX)
	{
		_scroll->y = SCROLL_LINE_Y_MAX - SCROLL_LINE_Y;
	}

	//WINDOW�ɂ��킹���ʒu�𒲐�
	switch (_WIN_ID)
	{
	case P1:
		break;
	case P2:
		_scroll->x + 928.0f;
		break;
	case P3:
		_scroll->y + 508.0f;
		break;
	case P4:
		_scroll->x + 928.0f;
		_scroll->y + 508.0f;
		break;
	}

}


//MAP���擾�֐�
//_map[MAP_SIZE_Y][MAP_SIZE_X]	�ۑ�����map�ϐ�
void GetMap(int _map[MAP_SIZE_Y][MAP_SIZE_X])
{
	for (int y = 0; y < MAP_SIZE_Y; y++)
	{
		for (int x = 0; x < MAP_SIZE_Y; x++)
		{
			_map[y][x] = map[y][x];
		}
	}
}

void SetMap(int x, int y,int NUM)
{
	map[y][x] = NUM;
}

//�u���b�N�̓����蔻��
void BlockHit(Hit* player, Point* _pos, Vector* _vec,int IMGSIZE)
{
	//�}�b�v
	int map[MAP_SIZE_Y][MAP_SIZE_X];
	//�}�b�v�ǂݍ���
	GetMap(map);

	//�����蔻�菉���� �d�v!!!!!!!!
	player->UP = false;
	player->DOWN = false;
	player->LEFT = false;
	player->RIGHT = false;

	//�}�b�v�`�b�v���瓖�����Ă��邩��T��
	for (int y = 0; y < MAP_SIZE_Y; y++) {
		for (int x = 0; x < MAP_SIZE_X; x++) {
			//�u���b�N
			if (map[y][x] == 1)
			{
				//�L�����N�^�[�̉E��������������
				if ((x * IMGSIZE64) + IMGSIZE64 >= _pos->x + IMGSIZE &&
					(x * IMGSIZE64) - IMGSIZE64 <= _pos->x &&
					y * IMGSIZE64 - 1 < _pos->y + (IMGSIZE / 2) &&
					(y * IMGSIZE64) + IMGSIZE64 > _pos->y + (IMGSIZE / 2))
				{
					
					_pos->x = x * IMGSIZE64 - IMGSIZE;//�ʒu���E���ɂ��� 
					player->RIGHT = true;
				}
				//�L�����N�^�[�̍���������������
				if ((x * IMGSIZE64) <= _pos->x &&
					(x * IMGSIZE64) + (IMGSIZE64 * 2) >= _pos->x + IMGSIZE &&
					y * IMGSIZE64 - 1 < _pos->y + (IMGSIZE / 2) &&
					(y * IMGSIZE64) + IMGSIZE64 > _pos->y + (IMGSIZE / 2))
				{
					_pos->x = x * IMGSIZE64 + IMGSIZE;//�ʒu�������ɂ���
					player->LEFT = true;
				}
				//�L�����N�^�[�̏㑤������������
				if ((y * IMGSIZE64) + IMGSIZE64 >= _pos->y &&
					(y * IMGSIZE64) <= _pos->y &&
					(x * IMGSIZE64) + IMGSIZE64 >= _pos->x + (IMGSIZE / 2) &&
					(x * IMGSIZE64) <= _pos->x + (IMGSIZE / 2))
				{
					_pos->y = (y * IMGSIZE64) + IMGSIZE;//�ʒu���u���b�N�̏�ɂ���
					player->UP = true;
				}
				////�L�����N�^�[�̉���������������
				if ((y * IMGSIZE64) >= _pos->y &&
					(y * IMGSIZE64) - (IMGSIZE64) <= _pos->y &&
					(x * IMGSIZE64) + IMGSIZE64 >= _pos->x + (IMGSIZE / 2) &&
					(x * IMGSIZE64) <= _pos->x + (IMGSIZE / 2))
				{
					_pos->y = (y * IMGSIZE64) - IMGSIZE - 2;//�ʒu���u���b�N�̏�ɂ���
					player->DOWN = true;
				}
			}
		}

	}
}

//�v���C���[�̃X�N���[�����擾�֐�
void ScrollSet(Vector _scroll[4],Point pos[4], list<unique_ptr<Base>>& base)
{
	//�v���C���[���Ƃ̈ʒu�擾
	for (auto i = base.begin(); i != base.end(); i++)
	{
		if ((*i)->status.ID == SPEED_PLAYER || (*i)->status.ID == DEFFENSE_PLAYER || (*i)->status.ID == ATTACK_PLAYER || (*i)->status.ID == TRAP_PLAYER)
		{
			switch ((*i)->status.WIN_ID)
			{
				//WINDOW 1�̃v���C���[�̈ʒu,�X�N���[�����擾
			case P1:
				pos[P1].x = (*i)->status.pos.x;
				pos[P1].y = (*i)->status.pos.y;
				_scroll[P1].x = ((Player*)(*i).get())->scroll.x;
				_scroll[P1].y = ((Player*)(*i).get())->scroll.y;
				break;
				//WINDOW 2�̃v���C���[�̈ʒu,�X�N���[�����擾
			case P2:
				pos[P2].x = (*i)->status.pos.x;
				pos[P2].y = (*i)->status.pos.y;
				_scroll[P2].x = ((Player*)(*i).get())->scroll.x;
				_scroll[P2].y = ((Player*)(*i).get())->scroll.y;
				break;
				//WINDOW 2�̃v���C���[�̈ʒu,�X�N���[�����擾
			case P3:
				pos[P3].x = (*i)->status.pos.x;
				pos[P3].y = (*i)->status.pos.y;
				_scroll[P3].x = ((Player*)(*i).get())->scroll.x;
				_scroll[P3].y = ((Player*)(*i).get())->scroll.y;
				break;
				//WINDOW 2�̃v���C���[�̈ʒu,�X�N���[�����擾
			case P4:
				pos[P4].x = (*i)->status.pos.x;
				pos[P4].y = (*i)->status.pos.y;
				_scroll[P4].x = ((Player*)(*i).get())->scroll.x;
				_scroll[P4].y = ((Player*)(*i).get())->scroll.y;
				break;
			}
		}
	}
}

//�u���b�NDraw�֐�
//Draw����Block�̔ԍ���Ԃ�
int BlockDraw(Vector scroll[4], Point pos[4], int WIN_ID, int x, int y)
{
	//��ʕ��������J�n------------------------------------------------------------------------------------
	//WINDOW���Ƃ�Block�`����s
	switch (WIN_ID)
	{
		//WINDOW 1
	case P1:
		if (x * IMGSIZE64 - scroll[P1].x >= -IMGSIZE64 &&
			x * IMGSIZE64 + IMGSIZE64 - scroll[P1].x <= 992 &&
			y * IMGSIZE64 - scroll[P1].y >= 0 - IMGSIZE64 &&
			y * IMGSIZE64 + IMGSIZE64 - scroll[P1].y <= 508 + IMGSIZE64)
		{
			return map[y][x];
		}
		break;
		//WINDOW 2
	case P2:
		if (x * IMGSIZE64 - scroll[P2].x + 992 >= 928 &&
			x * IMGSIZE64 + IMGSIZE64 - scroll[P2].x + 992 <= WINDOW_WIDTH + IMGSIZE64 &&
			y * IMGSIZE64 - scroll[P2].y >= 0 - IMGSIZE64 &&
			y * IMGSIZE64 + IMGSIZE64 - scroll[P2].y <= 508 + IMGSIZE64)
		{
			return map[y][x];

		}
		break;
		//WINDOW 3
	case P3:
		if (x * IMGSIZE64 - scroll[P3].x >= -IMGSIZE64 &&
			x * IMGSIZE64 + IMGSIZE64 - scroll[P3].x <= 928 + IMGSIZE64 &&
			y * IMGSIZE64 - scroll[P3].y + 572 >= 572 - IMGSIZE64 &&
			y * IMGSIZE64 + IMGSIZE64 - scroll[P3].y + 572 <= WINDOW_HEIGHT + IMGSIZE64)
		{
			return map[y][x];
		}
		break;
		//WINDOW 4
	case P4:
		if (x * IMGSIZE64 - scroll[P4].x + 992 >= 992 - IMGSIZE64 &&
			x * IMGSIZE64 + IMGSIZE64 - scroll[P4].x + 992 <= WINDOW_WIDTH + IMGSIZE64 &&
			y * IMGSIZE64 - scroll[P4].y + 572 >= 572 - IMGSIZE64 &&
			y * IMGSIZE64 + IMGSIZE64 - scroll[P4].y + 572 <= WINDOW_HEIGHT + IMGSIZE64)
		{
			return map[y][x];
		}
		break;
	}

	return -99;
}

//�v���C���[�̉摜�擾�֐�
void Getimg(list<unique_ptr<Base>>& base, int img[4])
{
	for (auto i = base.begin(); i != base.end(); i++)
	{
		if ((*i)->status.WIN_ID >= 0)
		{
			switch ((*i)->status.WIN_ID)
			{
			case P1:
				img[P1] = (*i)->status.img;
				break;
			case P2:
				img[P2] = (*i)->status.img;
				break;
			case P3:
				img[P3] = (*i)->status.img;
				break;
			case P4:
				img[P4] = (*i)->status.img;
				break;
			}
		}
	}
}

//�v���C���[�Ƃ̓����蔻��֐�
void Hit_Player(Point p_pos, Vector scroll[4], list<unique_ptr<Base>>& base, int IMGSIZE, bool* FLAG)
{
	for (auto i = base.begin(); i != base.end(); i++)
	{
		if ((*i)->status.WIN_ID >= 0)
		{
			switch ((*i)->status.WIN_ID)
			{
			case P1:
				if (p_pos.x - scroll[P1].x < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
					p_pos.x + IMGSIZE - scroll[P1].x > (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
					p_pos.y - scroll[P1].y < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
					p_pos.y + IMGSIZE - scroll[P1].y > (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
				{
					*FLAG = false;
				}
				break;
			case P2:
				if (p_pos.x - scroll[P2].x < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
					p_pos.x + IMGSIZE - scroll[P2].x > (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
					p_pos.y - scroll[P2].y < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
					p_pos.y + IMGSIZE - scroll[P2].y > (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
				{
					*FLAG = false;
				}
				break;
			case P3:
				if (p_pos.x - scroll[P3].x < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
					p_pos.x + IMGSIZE - scroll[P3].x > (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
					p_pos.y - scroll[P3].y < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
					p_pos.y + IMGSIZE - scroll[P3].y > (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
				{
					*FLAG = false;
				}
				break;
			case P4:
				if (p_pos.x - scroll[P4].x < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
					p_pos.x + IMGSIZE - scroll[P4].x > (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
					p_pos.y - scroll[P4].y < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
					p_pos.y + IMGSIZE - scroll[P4].y > (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
				{
					*FLAG = false;
				}
				break;
			}
		}
	}
}

void SetMachine(Status* st, int machine, int pilot)
{
	if (machine == SPEED_PLAYER)
	{
		st->speed.x += default_SPD_X * 0.5f;
		st->speed.y += default_SPD_Y * 0.5f;
	}
	if (machine == DEFFENSE_PLAYER)
	{
		st->def += default_DEF * 0.1f;
		st->speed.x += default_SPD_X * -0.1f;
		st->speed.y += default_SPD_X * -0.1f;
	}
	if (machine == ATTACK_PLAYER)
	{
		;
	}
	if (machine == TRAP_PLAYER)
	{
		;
	}
	if (pilot == COMBAT)
	{
		st->f_atk += default_F_ATK * 0.5f;
	}
	if (pilot == SHOOT)
	{
		st->s_atk += default_S_ATK * 0.2f;
	}
	if (pilot == RUN)
	{
		st->speed.x += default_SPD_X * 0.3f;
		st->speed.y += default_SPD_Y * 0.3f;
	}
	if (pilot == MECHANIC)
	{
		;
	}
}