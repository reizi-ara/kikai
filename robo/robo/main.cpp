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
	SetGraphMode(WINDOW_WIDTH-10, WINDOW_HEIGHT-10, 32);

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

	int get_select[2][4];

	bool vic = false;

	int time = 0;

	int vic_p = -1;

	bool select[4]{ false,false,false,false };

	bool scene_change = false;

	GetMap(map);

	int scene = SELECT;


	
	for (int i = 0; i < 4; i++)
	{
		base.emplace_back((unique_ptr<Base>)new Cursor(i));
	}
	


	
	//�@�̑I�����
	while (scene == SELECT)
	{
		ClearDrawScreen();//��ʃN���A
		if (scene_change == false)
		{
			for (auto i = base.begin(); i != base.end(); i++)
			{
				if ((*i)->status.ID == 1)
				{
					(*i)->Action(base);//�e�I�u�W�F�N�g�̏���
					(*i)->Draw();//�e�I�u�W�F�N�g�̏���
				}
				if ((*i)->status.WIN_ID >= 0)
				{
					select[(*i)->status.WIN_ID] = ((Cursor*)(*i).get())->complete_select;
					get_select[0][(*i)->status.WIN_ID] = ((Cursor*)(*i).get())->get_select[0][(*i)->status.WIN_ID];
					get_select[1][(*i)->status.WIN_ID] = ((Cursor*)(*i).get())->get_select[1][(*i)->status.WIN_ID];
				}
			}
			for (int i = 0; i < 4; i++)
			{
				if (select[i] == false)
					break;
				if (select[i] == true && i == 3)
				{
					scene_change = true;
					for (auto i = base.begin(); i != base.end(); i++)
					{
						if ((*i)->status.ID == 1)
						{
							(*i)->status.FLAG = false;
						}
					}
				}
			}
		}

		if (scene_change == true)
		{
			
			time++;

			if (time > 20)
			{
				//�v���C���[�쐬
					for (int i = 0; i < 4; i++)//i->WINDOW�ԍ�
						base.emplace_back((unique_ptr<Base>)new Player(0.0f, 0.0f, get_select[0][i], get_select[1][i], 0, i, pos[i]));

					//�}�b�v�쐬
					base.emplace_back((unique_ptr<Base>)new Block());

					//UI�쐬
					base.emplace_back((unique_ptr<Base>)new UI());

					//�}�b�v�`�b�v�ɂ��A�C�e������
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

				scene = GAME;
				time = 0;
			}
			
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
			if (vic == false)
				(*i)->Action(base);//�e�I�u�W�F�N�g�̏���
			(*i)->Draw();//�e�I�u�W�F�N�g�̏���

			if ((*i)->status.WIN_ID >= 0 && (*i)->status.ID != BULLET)
			{
				if (((Player*)(*i).get())->kill >= 10)
				{
					vic = true;
					vic_p = (*i)->status.WIN_ID;
				}
			}
		}
		if (vic == true)
		{
			SetFontSize(IMGSIZE64 * 2);
			DrawFormatString(WINDOW_WIDTH / 2 - IMGSIZE64 - IMGSIZE64*2 , WINDOW_HEIGHT / 2 - IMGSIZE64, GetColor(255, 0, 0), "%dP WIN", vic_p + 1);
			SetFontSize(16);
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