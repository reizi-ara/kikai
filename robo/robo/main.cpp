#pragma once
#include "main.h"
#include "char.h"

//���X�g
list<unique_ptr<Bace>> bace;

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

	//���C�����[�v
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
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

		ScreenFlip();//��ʍX�V
		//��O����
		if ((ProcessMessage() == -1)) break;
	}

	DxLib_End();

	return 0;
}