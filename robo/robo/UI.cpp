#pragma once
#include "char.h"

//�R���X�g���N�^
UI::UI()
{
	status.img = LoadGraph("image\\UI\\UI.png");
	

	//�`�揇�ԍ�
	pri = 999;
}

//�������s
int UI::Action(list<unique_ptr<Base>>& base)
{
	//�v���C���[���Ƃ̃X�e�[�^�X�����擾
	for (auto i = base.begin(); i != base.end(); i++)
	{
		if ((*i)->status.WIN_ID >= 0 && (*i)->status.ID != BULLET)
		{
			switch ((*i)->status.WIN_ID)
			{
				//WINDOW 1
			case P1:
				HP[P1] = (*i)->status.hp;
				WEPON[P1] = (*i)->status.wepon_num;
				Skill[P1] = (*i)->status.skill_cooldown;
				Kill[P1] = ((Player*)(*i).get())->kill;
				break;
				//WINDOW 2
			case P2:
				HP[P2] = (*i)->status.hp;
				WEPON[P2] = (*i)->status.wepon_num;
				Skill[P2] = (*i)->status.skill_cooldown;
				Kill[P2] = ((Player*)(*i).get())->kill;
				break;
				//WINDOW 3
			case P3:
				HP[P3] = (*i)->status.hp;
				WEPON[P3] = (*i)->status.wepon_num;
				Skill[P3] = (*i)->status.skill_cooldown;
				Kill[P3] = ((Player*)(*i).get())->kill;
				break;
				//WINDOW 4
			case P4:
				HP[P4] = (*i)->status.hp;
				WEPON[P4] = (*i)->status.wepon_num;
				Skill[P4] = (*i)->status.skill_cooldown;
				Kill[P4] = ((Player*)(*i).get())->kill;
				break;
			}
		}
	}
	return 0;
}

//�`��֘A����
void UI::Draw() 
{
	//�iBlock�߂荞�ݑ΍�jUI�\��
	DrawGraph(0, 0, status.img, TRUE);
	
	//WINDOW���Ƃ�UI�`��
	for (int z = 0; z < 4; z++)
	{
		switch (z)
		{
		case P1:
			DrawGraph(928 - IMGSIZE64 * 2, 0, img_Item_UI, TRUE);	//�A�C�e���\���ꏊUI
			DrawGraph(0, 0, img_HP_UI, TRUE);						//HP�\���ꏊUI
			DrawGraph(0, 508 - IMGSIZE64, img_Skill_UI, TRUE);		//�X�L���Q�[�W�\���ꏊUI
			//HP�`�揈��
			for (int i = 1; i < HP[P1] / 4; i++)
			{
				DrawGraph(2 + i * 4-4, 0 + 1, img_HP, TRUE);//HP�ʂɍ��킹�ĕ`��
			}
			//�X�L���Q�[�W�`�揈��
			for (int i = 1; i <= Skill[P1] / 25; i++)
			{
				DrawGraph(0, 508 - i * 4, img_Skill, TRUE);//�X�L���Q�[�W�ʂɍ��킹�ĕ`��
			}
			SetFontSize(16);
			//�X�L����������
			if (Skill[P1] == 400)
			{
				DrawFormatString(0, 508 - 32, GetColor(255, 255, 255), "��������");
			}
			
			//��������UI�`��
			switch (WEPON[P1])
			{
				//���C�t��
			case 0:
				DrawGraph(928  - IMGSIZE64 * 2, 0, img_rifle, TRUE);
				//���C�t�������\��
				DrawFormatString(928 + IMGSIZE64 / 2 - IMGSIZE64 * 2, 0 + IMGSIZE64 + IMGSIZE64, GetColor(255, 255, 255), "���C�t��");
				break;
				
				//��
			case 1:
				DrawGraph(928  - IMGSIZE64 * 2, 0, img_katana, TRUE);
				//�������\��
				DrawFormatString(928 + IMGSIZE64 / 2 - IMGSIZE64 * 2, 0 + IMGSIZE64 + IMGSIZE64, GetColor(255, 255, 255), "�J�^�i");
				break;
			}
			SetFontSize(32);
			DrawFormatString(0 + IMGSIZE64*2, 508, GetColor(0, 0, 0), "���@���j���F%d", Kill[P1]);//�L�����\��
			break;
		case P2:
			DrawGraph(WINDOW_WIDTH - IMGSIZE64*2, 0, img_Item_UI, TRUE);				//�A�C�e���\���ꏊUI
			DrawGraph(928 + IMGSIZE64, 0, img_HP_UI, TRUE);								//HP�\���ꏊUI
			DrawGraph(WINDOW_WIDTH - IMGSIZE64, 508 - IMGSIZE64, img_Skill_UI, TRUE);	//�X�L���Q�[�W�\���ꏊUI
			
			SetFontSize(16);
			//HP�`�揈��
			for (int i = 1; i < HP[P2] / 4; i++)
			{
				DrawGraph(928 + 2 + IMGSIZE64 + i * 4, 0 + 1, img_HP, TRUE);//HP�ʂɍ��킹�ĕ`��
			}
			//�X�L���Q�[�W�`�揈��
			for (int i = 1; i <= Skill[P2] / 25; i++)
			{
				DrawGraph(WINDOW_WIDTH - IMGSIZE64, 508 - i * 4 - 4, img_Skill, TRUE);//�X�L���Q�[�W�ʂɍ��킹�ĕ`��
			}
			//�X�L����������
			if (Skill[P2] == 400)
			{
				DrawFormatString(WINDOW_WIDTH - IMGSIZE64, 508 - 32, GetColor(255, 255, 255), "��������");
			}
			//��������UI�`��
			switch (WEPON[P2])
			{
			case 0:
				//���C�t��
				DrawGraph(WINDOW_WIDTH - IMGSIZE64 * 2, 0, img_rifle, TRUE);
				//���C�t�������\��
				DrawFormatString(WINDOW_WIDTH + IMGSIZE64 / 2 - IMGSIZE64 * 2, 0 + IMGSIZE64 + IMGSIZE64, GetColor(255, 255, 255), "���C�t��");
				break;
			case 1:
				//��
				DrawGraph(WINDOW_WIDTH  - IMGSIZE64 * 2, 0, img_katana, TRUE);
				//�������\��
				DrawFormatString(WINDOW_WIDTH + IMGSIZE64 / 2 - IMGSIZE64 * 2, 0 + IMGSIZE64 + IMGSIZE64, GetColor(255, 255, 255), "�J�^�i");
				break;
			}
			SetFontSize(32);
			DrawFormatString(908 + IMGSIZE64 + IMGSIZE64 * 4, 508, GetColor(0, 0, 0), "���@���j���F%d", Kill[P2]);//�L�����\��
			break;
		case P3:
			DrawGraph(928 - IMGSIZE64 * 2, 508 + IMGSIZE64, img_Item_UI, TRUE);	//�A�C�e���\���ꏊUI
			DrawGraph(0, 508 + IMGSIZE64, img_HP_UI, TRUE);						//HP�\���ꏊUI
			DrawGraph(0, WINDOW_HEIGHT - IMGSIZE64, img_Skill_UI, TRUE);		//�X�L���Q�[�W�\���ꏊUI
			SetFontSize(16);
			//HP�`�揈��
			for (int i = 1; i < HP[P3] / 4; i++)
			{
				DrawGraph(2 + i * 4-4, 508 + IMGSIZE64 + 1, img_HP, TRUE);//HP�ʂɍ��킹�ĕ`��
			}
			//�X�L���Q�[�W�`�揈��
			for (int i = 1; i <= Skill[P3] / 25; i++)
			{
				DrawGraph(0, WINDOW_HEIGHT - i * 4, img_Skill, TRUE);//�X�L���Q�[�W�ʂɍ��킹�ĕ`��
			}
			//�X�L����������
			if (Skill[P3] == 400)
			{
				DrawFormatString(0, WINDOW_HEIGHT - 32, GetColor(255, 255, 255), "��������");
			}
			//��������UI�`��
			switch (WEPON[P3])
			{
				//���C�t��
			case 0:
				DrawGraph(928 - IMGSIZE64 * 2, 508 + IMGSIZE64 , img_rifle, TRUE);
				//���C�t�������\��
				DrawFormatString(928 + IMGSIZE64 / 2 - IMGSIZE64 * 2, 508 + IMGSIZE64 + IMGSIZE64 + IMGSIZE64, GetColor(255, 255, 255), "���C�t��");
				break;
				//��
			case 1:
				DrawGraph(928 - IMGSIZE64 * 2, 508 + IMGSIZE64, img_katana, TRUE);
				//�������\��
				DrawFormatString(928 + IMGSIZE64 / 2 - IMGSIZE64 * 2, 508 + IMGSIZE64 + IMGSIZE64 + IMGSIZE64, GetColor(255, 255, 255), "�J�^�i");
				break;
			}
			SetFontSize(32);
			DrawFormatString(0 + IMGSIZE64*2, 508 + 32, GetColor(0, 0, 0), "���@���j���F%d", Kill[P3]);//�L�����\��
			break;
		case P4:
			DrawGraph(WINDOW_WIDTH - IMGSIZE64*2, 508 + IMGSIZE64, img_Item_UI, TRUE);			//�A�C�e���\���ꏊUI
			DrawGraph(928 + IMGSIZE64, 508 + IMGSIZE64, img_HP_UI, TRUE);						//HP�\���ꏊUI
			DrawGraph(WINDOW_WIDTH - IMGSIZE64, WINDOW_HEIGHT - IMGSIZE64, img_Skill_UI, TRUE);	//�X�L���Q�[�W�\���ꏊUI
			SetFontSize(16);
			//HP�`�揈��
			for (int i = 1; i < HP[P4] / 4; i++)
			{
				DrawGraph(2 + 928 + IMGSIZE64 + i * 4, 508 + IMGSIZE64 + 1, img_HP, TRUE);//HP�ʂɍ��킹�ĕ`��
			}
			//�X�L���Q�[�W�`�揈��
			for (int i = 1; i <= Skill[P4] / 25; i++)
			{
				DrawGraph(WINDOW_WIDTH - IMGSIZE64, WINDOW_HEIGHT - i * 4 - 4, img_Skill, TRUE);//�X�L���Q�[�W�ʂɍ��킹�ĕ`��
			}
			//�X�L����������
			if (Skill[P4] == 400)
			{
				DrawFormatString(WINDOW_WIDTH - IMGSIZE64, WINDOW_HEIGHT - 32, GetColor(255, 255, 255), "��������");
			}

			//��������UI�`��
			switch (WEPON[P4])
			{
				//���C�t��
			case 0:
				DrawGraph(WINDOW_WIDTH  - IMGSIZE64 * 2, 508 + IMGSIZE64, img_rifle, TRUE);
				//���C�t�������\��
				DrawFormatString(WINDOW_WIDTH + IMGSIZE64 / 2 - IMGSIZE64 * 2, 508 + IMGSIZE64 + IMGSIZE64 + IMGSIZE64, GetColor(255, 255, 255), "���C�t��");
				break;
				//��
			case 1:
				DrawGraph(WINDOW_WIDTH - IMGSIZE64 * 2, 508 + IMGSIZE64, img_katana, TRUE);
				//�������\��
				DrawFormatString(WINDOW_WIDTH + IMGSIZE64 / 2 - IMGSIZE64 * 2, 508 + IMGSIZE64 + IMGSIZE64 + IMGSIZE64, GetColor(255, 255, 255), "�J�^�i");
				break;
			}
			SetFontSize(32);
			DrawFormatString(908 + IMGSIZE64 + IMGSIZE64 * 4, 508+32, GetColor(0, 0, 0), "���@���j���F%d", Kill[P4]);//�L�����\��
			break;
		}
		
	}
	SetFontSize(32);
	DrawFormatString(WINDOW_WIDTH / 2 - IMGSIZE64 * 3, 508 + IMGSIZE64 / 4, GetColor(0, 0, 0), "10�̓|�����珟���I");
}