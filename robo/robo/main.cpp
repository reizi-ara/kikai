#pragma once
#include "main.h"
#include "char.h"

//���X�g
list<unique_ptr<Base>> base;



//�N���C�A���g�p�v���O����(TCP/IP)
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE,
	_In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
	//window���[�h�ؑ�
	ChangeWindowMode(TRUE);

	//window�T�C�Y
	SetGraphMode(WINDOW_WIDTH - 10, WINDOW_HEIGHT - 10, 32);

	//Dx���C�u�����̏�����
	if (DxLib_Init() == -1)return -1;

	//window�̖��O
	SetWindowText("���X�g�T���v��");

	//�o�b�N�o�b�t�@���g�p
	SetDrawScreen(DX_SCREEN_BACK);

	int map[MAP_SIZE_Y][MAP_SIZE_X];

	//�v���C���[�̍��W�w��
	Point pos[4]
	{
		{ IMGSIZE64 * 2							,IMGSIZE64 * 2 },
		{ MAP_SIZE_X * IMGSIZE64 - IMGSIZE64 * 3,IMGSIZE64 * 2 },
		{ IMGSIZE64 * 2							,(MAP_SIZE_Y * IMGSIZE64) - IMGSIZE64 * 3 },
		{ MAP_SIZE_X * IMGSIZE64 - IMGSIZE64 * 3,(MAP_SIZE_Y * IMGSIZE64) - IMGSIZE64 * 3 }
	};

	//�v���C���[�쐬
	for (int i = 0; i < 4; i++)//i->WINDOW�ԍ�
		base.emplace_back((unique_ptr<Base>)new Player(0.0f, 0.0f, i, SPEED, PLAYER1, i, pos[i]));

	//�}�b�v�쐬
	base.emplace_back((unique_ptr<Base>)new Block());

	//UI�쐬
	base.emplace_back((unique_ptr<Base>)new UI());

	GetMap(map);
	for (int y = 0; y < MAP_SIZE_Y; y++)
	{
		for (int x = 0; x < MAP_SIZE_X; x++)
		{
			switch (map[y][x])
			{
			case 0:
				break;
			case 1:
				break;
			case 2:
				base.emplace_back((unique_ptr<Base>)new Itembox(x * IMGSIZE64, y * IMGSIZE64));
				break;
			case 3:
				break;
			}
		}
	}

	

	//bace.emplace_back((unique_ptr<Bace>)new Cursor(128.0f, 192.0f));

	int scene = GAME;
	
	//�@�̑I�����
	while (scene == SELECT)
	{
		ClearDrawScreen();//��ʃN���A

		for (auto i = base.begin(); i != base.end(); i++)
		{
			if ((*i)->status.ID == 1)
			{
				(*i)->Action(base);//�e�I�u�W�F�N�g�̏���
				(*i)->Draw();//�e�I�u�W�F�N�g�̏���
			}
		}

		//ESC�I������
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			scene = -1;
		}


		ScreenFlip();//��ʍX�V
	}

	//���C�����[�v
	while (scene == GAME) {
		ClearDrawScreen();//��ʃN���A

			//�\�[�g
		Pr pr;
		if (base.size() >= 2)
			base.sort(pr);//���X�g�̃\�[�g���\�b�h�̈����Ƀ\�[�g�����N���X������

		for (auto i = base.begin(); i != base.end(); i++)
		{
			(*i)->Action(base);//�e�I�u�W�F�N�g�̏���
			(*i)->Draw();//�e�I�u�W�F�N�g�̏���

		
		}
		for (auto i = base.begin(); i != base.end(); i++)
		{
			//���X�g����s�v�I�u�W�F�N�g���폜�i�e�j
			if ((*i)->status.FLAG == false) {
				i = base.erase(i);
				break;
				DeleteGraph((*i)->status.img, 0);
			}
		}
		

		//ESC�I������
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			scene = -1;
		}

		ScreenFlip();//��ʍX�V
		//��O����
		if ((ProcessMessage() == -1)) break;
	}

	DxLib_End();

	return 0;
}