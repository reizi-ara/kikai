#pragma once
#include "main.h"
#include "char.h"

//�X�N���[�����擾�֐�
void GetScroll(Point* _pos, Vector* _scroll, int _WIN_ID);

//�}�b�v���擾�֐�
void GetMap(int _map[MAP_SIZE_Y][MAP_SIZE_X]);

//�u���b�N�Ƃ̓����蔻��֐�
void BlockHit(Hit* player, Point* _pos, Vector* _vec, int IMGSIZE);

//�X�N���[�����Z�b�e�B���O�֐�
void ScrollSet(Vector _scroll[4], Point pos[4], list<unique_ptr<Base>>& base);

//�u���b�N�`��i��ʕ����j�֐�
int BlockDraw(Vector scroll[4], Point pos[4], int WIN_ID, int x, int y);

//�v���C���[�̉摜�擾�֐�
void Getimg(list<unique_ptr<Base>>& base, int img[4]);

//�v���C���[�Ƃ̓����蔻��֐�
int Hit_Player(Point p_pos, Vector scroll[4], list<unique_ptr<Base>>& base, int IMGSIZE, bool* FLAG, int WIN_ID);

//�}�b�v���ύX�֐�
void SetMap(int x, int y, int NUM);

//�X�e�[�^�X�֐�
void SetMachine(Status* st, int machine, int pilot);

//����֐�
void wepon_summary(list<unique_ptr<Base>>& base, Point p_pos, Vector scroll[4], int wepon_num, int WIN_ID, int img_Vec, int* kill);