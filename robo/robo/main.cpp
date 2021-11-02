#pragma once
#include "main.h"
#include "char.h"

//���X�g
list<unique_ptr<Bace>> bace;

unsigned char scene = SELECT;

//�N���C�A���g�p�v���O����(TCP/IP)
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE,
	_In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
	//window���[�h�ؑ�
	ChangeWindowMode(TRUE);
	//window�T�C�Y
	SetGraphMode(800, 600, 32);

	//Dx���C�u�����̏�����
	if (DxLib_Init() == -1)return -1;

	//window�̖��O
	SetWindowText("���X�g�T���v��");

	//�o�b�N�o�b�t�@���g�p
	SetDrawScreen(DX_SCREEN_BACK);

	//���X�g�I�u�W�F�N�g�𐶐�
	auto P = (unique_ptr<Bace>)new Player(0.0f, 0.0f);
	bace.emplace_back(move(P));

	bace.emplace_back((unique_ptr<Bace>)new SelectCursor(128.0f, 192.0f));
	
	//�@�̑I�����
	while (scene == SELECT)
	{
		ClearDrawScreen();//��ʃN���A

		
		for (auto i = bace.begin(); i != bace.end(); i++)
		{
			if ((*i)->ID == 1)
			{
				(*i)->Action(bace);//�e�I�u�W�F�N�g�̏���
			}
		}
		for (auto i = bace.begin(); i != bace.end(); i++)
		{
			if ((*i)->ID == 1)
			{
				(*i)->Draw();//�e�I�u�W�F�N�g�̏���
			}
		}

		if (CheckHitKey(KEY_INPUT_RETURN))
		{
			for (auto i = bace.begin(); i != bace.end(); i++)
			{
				if ((*i)->ID == 1)
				{
					if (((SelectCursor*)(*i).get())->select_type == 1)
					{
						auto Attack = (unique_ptr<Bace>)new attacktype(0.0f, 0.0f);
						bace.emplace_back(move(Attack));
					}
					else if (((SelectCursor*)(*i).get())->select_type == 2)
					{
						auto Speed = (unique_ptr<Bace>)new speedtype(0.0f, 0.0f);
						bace.emplace_back(move(Speed));
					}
					else if (((SelectCursor*)(*i).get())->select_type == 3)
					{
						auto Shield = (unique_ptr<Bace>)new shieldtype(0.0f, 0.0f);
						bace.emplace_back(move(Shield));
					}
					else if (((SelectCursor*)(*i).get())->select_type == 4)
					{
						auto Trap = (unique_ptr<Bace>)new traptype(0.0f, 0.0f);
						bace.emplace_back(move(Trap));
					}
				}
			}

			scene = GAME;
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


		//���X�g�̃��\�b�h�����s
		for (auto i = bace.begin(); i != bace.end(); i++)
		{
			(*i)->Action(bace);//�e�I�u�W�F�N�g�̏���
		}
		for (auto i = bace.begin(); i != bace.end(); i++)
		{
			(*i)->Draw();//�e�I�u�W�F�N�g�̏���
		}

		//���X�g����s�v�I�u�W�F�N�g���폜�i�e�j
		for (auto i = bace.begin(); i != bace.end(); i++) {
			if ((*i)->FLAG == false) {
				i = bace.erase(i);
				break;
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