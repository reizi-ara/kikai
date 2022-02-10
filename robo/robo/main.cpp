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
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);

	//Dx���C�u�����̏�����
	if (DxLib_Init() == -1)return -1;

	//window�̖��O
	SetWindowText("�@�B�ΐ�");

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

	//�L�����N�^�[�Z���N�g�ϐ�-------------------
	int get_select[2][4];
	bool select[4]{ false,false,false,false };
	//-------------------------------------------

	//�V�[���ȍ~�p�ϐ�
	int time = 0;
	bool scene_change = false;

	//���������ϐ�-------------------------
	bool vic = false;
	int vic_p = -1;
	//------------------------------------
	//���g���C�t���O
	bool re_flag = false;
	
	//BGM�ݒ�
	int BGM_VIC = LoadSoundMem("BGM,SE\\winBGM.mp3");
	//�}�b�v���擾
	GetMap(map);

	//�^�C�g���쐬
	base.emplace_back((unique_ptr<Base>)new Title());

	int scene = TITLE;

	while (scene != -1)
	{



		//�^�C�g����ʏ���
		while (scene == TITLE)
		{
			ClearDrawScreen();//��ʃN���A


			for (auto i = base.begin(); i != base.end(); i++)
			{
				(*i)->Action(base);
				(*i)->Draw();
				//���X�g����s�v�I�u�W�F�N�g���폜
				if ((*i)->status.FLAG == false) {

					scene = SELECT;
					//�J�[�\���쐬
					for (int z = 0; z < 4; z++)
					{
						base.emplace_back((unique_ptr<Base>)new Cursor(z));
					}

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


		//�@�̑I�����
		while (scene == SELECT)
		{
			ClearDrawScreen();//��ʃN���A
			if (scene_change == false)
			{
					//�S�����L�����N�^�[��I�����Ă��邩�m�F
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
				for (auto i = base.begin(); i != base.end(); i++)
				{
					if ((*i)->status.ID == 1)
					{
						(*i)->Action(base);//�e�I�u�W�F�N�g�̏���
						(*i)->Draw();//�e�I�u�W�F�N�g�̏���
					}
					//�Z���N�g���擾
					if ((*i)->status.WIN_ID >= 0)
					{
						select[(*i)->status.WIN_ID] = ((Cursor*)(*i).get())->complete_select;
						get_select[0][(*i)->status.WIN_ID] = ((Cursor*)(*i).get())->get_select[0][(*i)->status.WIN_ID];
						get_select[1][(*i)->status.WIN_ID] = ((Cursor*)(*i).get())->get_select[1][(*i)->status.WIN_ID];
					}
				}
			
			}
			//�S�����L�����N�^�[��I�����Ă�����V�[���ȍ~
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

					//�V�[�����Q�[���Ɉڍs
					scene = GAME;
					time = 0;
				}

			}

			for (auto i = base.begin(); i != base.end(); i++)
			{
				//���X�g����s�v�I�u�W�F�N�g���폜
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

				//������������
				if ((*i)->status.WIN_ID >= 0 && (*i)->status.ID != BULLET)
				{
					if (((Player*)(*i).get())->kill >= 10 && vic == false)
					{
						vic = true;
						//���ʒ���
						ChangeVolumeSoundMem(150, BGM_VIC);
						//BGM�Đ�
						PlaySoundMem(BGM_VIC, DX_PLAYTYPE_BACK);
						vic_p = (*i)->status.WIN_ID;
					}
				}
				//Block���炵�Ă���BGM���~�߂�
				if (vic == true && (*i)->status.ID == BLOCK)
				{
					StopSoundMem(((Block*)(*i).get())->BGM_main);
				}
				//���g���C��Ԃ̏ꍇ���ׂẴI�u�W�F�N�g���폜���ATitle�V�[���Ɉڍs����B
				if (re_flag == true)
				{
					(*i)->status.FLAG = false;
				}
			}
			//�����v���C���[�������ꍇ
			if (vic == true)
			{
				SetFontSize(IMGSIZE64 * 2);
				DrawFormatString(WINDOW_WIDTH / 2 - IMGSIZE64 - IMGSIZE64 * 2, WINDOW_HEIGHT / 2 - IMGSIZE64, GetColor(0, 0, 0), "%dP WIN", vic_p + 1);
				DrawFormatString(WINDOW_WIDTH / 2 - IMGSIZE64 - IMGSIZE64 * 4, WINDOW_HEIGHT / 2 + IMGSIZE64, GetColor(0, 0, 0), "�PP�@Press A");
				SetFontSize(16);
			
				if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B) != 0)
					re_flag = true;
			}
			if (vic == true && re_flag == true)
			{
				time++;
			}
			if (re_flag == true && time >= 20)
			{
				//�^�C�g���쐬
				base.emplace_back((unique_ptr<Base>)new Title());

				//BGM���~�߂�
				StopSoundMem(BGM_VIC);

				//������
				time = 0;
				vic = false;
				re_flag = false;
				scene = TITLE;
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
	}

	DxLib_End();

	return 0;
}