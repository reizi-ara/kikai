#pragma once
#include "char.h"

#define PI  3.1415926535897932384626433832795f


//�R���X�g���N�^
Player::Player(float _x, float _y,int type_num,int pilot,int player_num, int window_num, Point Pos)
{
	//�摜���[�h-------------------------------------------------------------
	switch (type_num)
	{
	case SPEED_PLAYER:
		img_player[0] = LoadGraph("image\\Cube_Speed.png");
		img_player[1] = LoadGraph("image\\Cube_Speed_LEFT.png");
		img_player[2] = LoadGraph("image\\Cube_Speed_BACK.png");
		img_player[3] = LoadGraph("image\\Cube_Speed_RIGHT.png");
		break;
	case DEFFENSE_PLAYER:
		img_player[0] = LoadGraph("image\\Cube_Deffense.png");
		img_player[1] = LoadGraph("image\\Cube_Deffense_LEFT.png");
		img_player[2] = LoadGraph("image\\Cube_Deffense_BACK.png");
		img_player[3] = LoadGraph("image\\Cube_Deffense_RIGHT.png");
		break;
	case TRAP_PLAYER:
		img_player[0] = LoadGraph("image\\Cube_Trap.png");
		img_player[1] = LoadGraph("image\\Cube_Trap_LEFT.png");
		img_player[2] = LoadGraph("image\\Cube_Trap_BACK.png");
		img_player[3] = LoadGraph("image\\Cube_Trap_RIGHT.png");
		break;
	case ATTACK_PLAYER:
		img_player[0] = LoadGraph("image\\Cube_Attack.png");
		img_player[1] = LoadGraph("image\\Cube_Attack_LEFT.png");
		img_player[2] = LoadGraph("image\\Cube_Attack_BACK.png");
		img_player[3] = LoadGraph("image\\Cube_Attack_RIGHT.png");
		break;
	}

	status.img= LoadGraph("image\\square64.png");
	img = LoadGraph("image\\UI\\katana.png");
	w_img = LoadGraph("image\\bakuhatsu.png");

	//----------------------------------------------------------------------

	

	//�L�����N�^�[������--------------------------------------------------------------
	status.pos.x = Pos.x;
	status.pos.y = Pos.y;

	status.WIN_ID = window_num;

	for (int i = 0; i < 4; i++)
	{
		switch (type_num)
		{
		case SPEED_PLAYER:
			status.p_img[i] = img_player[i];
			break;
		case DEFFENSE_PLAYER:
			status.p_img[i] = img_player[i];
			break;
		case TRAP_PLAYER:
			status.p_img[i] = img_player[i];
			break;
		case ATTACK_PLAYER:
			status.p_img[i] = img_player[i];
			break;
		}
	}

	status.ID = type_num;
	status.Pilot = pilot;
	status.P_ID = player_num;

	status.hp = 0;
	status.sp = default_SP;
	status.f_atk = default_F_ATK;
	status.s_atk = default_S_ATK;
	status.def = default_DEF;
	status.skill_cooldown = 0;
	status.speed.x = default_SPD_X;
	status.speed.y = default_SPD_Y;
	
	SetMachine(&status, type_num, pilot);//�@�̏��A�p�C���b�g���}��

	

	
	//-------------------------------------------------------------------------------

	//�`�揇�ԍ�
	pri = 990;
}

//�������s
int Player::Action(list<unique_ptr<Base>>& base)
{
	//�Đ����t���O��true�̎�
	if (r_flag == true)
	{
		r_time++;
		//HP�𑝂₵�čĐ�������
		if (status.hp < 400)
		{
			status.hp += 4;
		}
		//HP��200�𒴂���ƈʒu�����������A�Đ�������B
		if (status.hp >= 200)
		{
			p_flag = true;

			switch (status.WIN_ID)
			{
			case P1:
				status.pos.x = IMGSIZE64 * 2;
				status.pos.y = IMGSIZE64 * 2;
				break;
			case P2:
				status.pos.x = MAP_SIZE_X * IMGSIZE64 - IMGSIZE64 * 3;
				status.pos.y = IMGSIZE64 * 2;
				break;
			case P3:
				status.pos.x = IMGSIZE64 * 2;
				status.pos.y = (MAP_SIZE_Y * IMGSIZE64) - IMGSIZE64 * 3;
				break;
			case P4:
				status.pos.x = MAP_SIZE_X * IMGSIZE64 - IMGSIZE64 * 3;
				status.pos.y = (MAP_SIZE_Y * IMGSIZE64) - IMGSIZE64 * 3;
				break;
			}

			BulletSave_vx = 0;
			BulletSave_vy = 0;

			wepon_cd = 0;
			status.wepon_num = -1;
			img_Vec = 0;
			status.skill_cooldown = 0;
		}

		//�O�b��A�Đ�
		if (r_time >= TIME1*3)
		{
			r_flag = false;
			r_time = 0;
		}
	}
	//�ʏ펞
	else
	{
		//�ړ�����----------------------------------------------------
		static int vx, vy;

		//�R���g���[���[�X�e�B�b�N���擾
		GetJoypadAnalogInput(&vx, &vy, (Con[status.WIN_ID]));

		//�ʒu�̍X�V
		if (vx > 0)
		{
			status.pos.x += status.speed.x;
		}
		if (vx < 0)
		{
			status.pos.x -= status.speed.x;
		}
		if (vy > 0)
		{
			status.pos.y += status.speed.y;
		}
		if (vy < 0)
		{
			status.pos.y -= status.speed.y;
		}

		//�摜�p�̕ۑ��ϐ�
		if (vx != 0 || vy != 0)
		{
			rotate_vx = vx;
			rotate_vy = vy;
		}

		//�e�p�̕ۑ��ϐ�
		if (vx != 0 || vy != 0)
		{
			BulletSave_vx = vx / 250.0f;
			BulletSave_vy = vy / 250.0f;
		}

		//�`��@�E
		if (rotate_vx > 0)
		{
			img_Vec = 3;
		}
		//�`��@��
		if (rotate_vx < 0)
		{
			img_Vec = 1;
		}
		//�`��@��
		if (rotate_vy > 0)
		{
			img_Vec = 0;
		}
		//�`��@��
		if (rotate_vy < 0)
		{
			img_Vec = 2;
		}

		//------------------------------------------------------------------------------

		//�X�L������--------------------------------------------------------------------

		//�X�L���Q�|�W�����܂��Ă��Ȃ��Ƃ�
		if (status.skill_cooldown < 400 && (status.ID == TRAP_PLAYER || status.ID == ATTACK_PLAYER))
		{
			status.skill_cooldown++;
		}
		//�X�L���Q�[�W�����܂��Ă��鎞
		if (status.skill_cooldown == 400)
		{
			//�C���^
			if (status.ID == ATTACK_PLAYER)
			{
				//Y�{�^���������ƃX�L������
				if ((GetJoypadInputState(Con[status.WIN_ID]) & PAD_INPUT_X) != 0)
				{
					//�C�e����
					base.emplace_back((unique_ptr<Base>)new Bullet(BulletSave_vx, BulletSave_vy, status.pos.x + IMGSIZE64 / 2 + bullet.x, status.pos.y + IMGSIZE64 / 2 + bullet.y, status.WIN_ID, IMGSIZE64,status.s_atk));
					//�C�e����SE�Đ�
					PlaySoundMem(SE_canon, DX_PLAYTYPE_BACK);
					//�X�L���Q�[�W������
					status.skill_cooldown = 0;
				}
			}
			//�g���b�v�^
			if (status.ID == TRAP_PLAYER)
			{
				//Y�{�^���������ƃX�L������
				if ((GetJoypadInputState(Con[status.WIN_ID]) & PAD_INPUT_X) != 0)
				{
					//�g���b�v����
					base.emplace_back((unique_ptr<Base>)new Trap(BulletSave_vx, BulletSave_vy, status.pos.x , status.pos.y, status.WIN_ID, IMGSIZE64));
					//�g���b�v����SE�Đ�
					PlaySoundMem(SE_trap, DX_PLAYTYPE_BACK);

					//�X�L���Q�[�W������
					status.skill_cooldown = 0;
				}
			}
		}
		
		//���J�j�b�N�^����
		if (status.Pilot == MECHANIC)
		{
			ME_count++;
			if (ME_count > TIME1)//HP����b��5��
			{
				ME_count = 0;
				if (status.hp <= default_HP - 5)
				{
					status.hp += 5;
				}
			}
		}

		//---------------------------------------------------------------------------------------------
		//�A�C�e���{�b�N�X�擾����
		for (auto i = base.begin(); i != base.end(); i++)
		{
			if ((*i)->status.ID == ITEMBOX) {
				//�A�C�e���{�b�N�X�Ƃ̓����蔻��
				Item = ((Itembox*)(*i).get())->status.pos;
				if (Item.x < status.pos.x + 64 && Item.x + 64 > status.pos.x && Item.y < status.pos.y + 64 && Item.y + 64 > status.pos.y)
				{
					//����擾�t���Otrue
					if (status.wepon_num == -1)
						weponget_flag = true;
				}
			}
		}
		//����擾
		if (weponget_flag == true) {
			//�����_���i���j�ŕ���擾
			status.wepon_num = rand() % 2;
			ShotFlag = true;
			weponget_flag = false;
		}

		//���C�t������
		if (status.wepon_num == 0)
		{	
			//B�{�^���Œe�۔���
			if ((GetJoypadInputState(Con[status.WIN_ID]) & PAD_INPUT_B) == 0 && wepon_cd == 0)
			{
				ShotFlag = true;
			}
			else
			{
				//���C�t���ˌ��t���O
				if (ShotFlag == true && wepon_cd == 0)
				{
					ShotFlag = false;
				}
			}
			if (ShotFlag == false)
			{
				//wepon_cd��20���ƂɈꔭ�e�ۂ𔭎˂���B
				wepon_cd++;
				if (wepon_cd % 20 == 0)
				{
					//�u���b�N�ɐڐG���Ă���ƒe�𔭎˂ł��Ȃ����߉����p�i���j
					if (h_player.LEFT == true)
					{
						bullet.x = IMGSIZE64 / 8;
					}
					if (h_player.RIGHT == true)
					{
						bullet.x = -IMGSIZE64 / 4;
					}
					if (h_player.DOWN == true)
					{
						bullet.y = -IMGSIZE64 / 2;
					}
					if (h_player.UP == true)
					{
						bullet.y = IMGSIZE64 / 8;
					}
					//�e�ې���
					base.emplace_back((unique_ptr<Base>)new Bullet(BulletSave_vx, BulletSave_vy, status.pos.x + IMGSIZE64 / 2 + bullet.x, status.pos.y + IMGSIZE64 / 2 + bullet.y, status.WIN_ID, IMGSIZE64 / 4,status.s_atk));
					//�e�۔���SE�Đ�
					PlaySoundMem(SE_bullet, DX_PLAYTYPE_BACK);
				}
				//�O���ˌ�������A�C�e����������
				if (wepon_cd > 60)
				{
					wepon_cd = 0;
					status.wepon_num = -1;
				}
			}
		}
		//������
		if (status.wepon_num == 1)
		{
			//B�{�^���Ō�����
			if ((GetJoypadInputState(Con[status.WIN_ID]) & PAD_INPUT_B) == 0 && wepon_cd == 0)
			{
				ShotFlag = true;
			}
			else
			{
				//�������t���O
				if (ShotFlag == true && wepon_cd == 0)
				{
					ShotFlag = false;
				}
			}
			if (ShotFlag == false)
			{
				//����֐��Ō��𐶐�����
				wepon_summary(base, status.pos, e_scroll, status.wepon_num, status.WIN_ID, img_Vec, &kill, status.f_atk);
				//������SE�Đ�
				if (wepon_cd == 0)
					PlaySoundMem(SE_sord, DX_PLAYTYPE_BACK);
				wepon_cd++;
				//�����蔻��I��
				if (wepon_cd >= 20)
				{
					wepon_cd = 0;
					status.wepon_num = -1;
				}
			}
		}

		//HP��0�ɂȂ�����Đ����t���O��ON�ɂ���
		if (status.hp <= 0)
		{
			p_flag = false;
			r_flag = true;
		}
	}

	//���̑��d�����蔻���h������
	if (S_Hit_flag == true)
	{
		S_Hit_count++;
		if (S_Hit_count >= 30)
		{
			S_Hit_flag = false;
			S_Hit_count = 0;
		}
	}

	GetScroll(&status.pos, &scroll, status.WIN_ID);				//�X�N���[�����擾
	BlockHit(&h_player, &status.pos, &status.speed, IMGSIZE64);	//�u���b�N�Ƃ̓����蔻����s
	ScrollSet(e_scroll, e_pos, base);							//�X�N���[�����Z�b�e�B���O
	return 0;
}

// �`��֘A����
void Player::Draw() {

	//WINDOW���Ƃ̕`��
	switch (status.WIN_ID)
	{
		//WINDOW 1
	case P1:
		//���j����Ă��Ȃ��ꍇ
		if (p_flag == true)
		{
			//�ʏ펞
			if (r_flag == false)
			{
				DrawGraph(status.pos.x - scroll.x, status.pos.y - scroll.y, status.p_img[img_Vec], TRUE);
				DrawFormatString(status.pos.x - scroll.x, status.pos.y - scroll.y - IMGSIZE64 / 2, GetColor(255, 255, 255), "��%dP", status.WIN_ID + 1);
			}
			//�Đ�����
			else
				DrawGraph(status.pos.x - scroll.x, status.pos.y - scroll.y, status.img, TRUE);
			//���̕`��
			if (status.wepon_num == 1 && ShotFlag == false)
			{
				//�����ɂ���ĕ`��ꏊ���C��
				switch (img_Vec)
				{
					//��
				case 0:
					DrawRotaGraph(status.pos.x - scroll.x + IMGSIZE64 / 2, status.pos.y - scroll.y + IMGSIZE64 + IMGSIZE64 / 2, 1, PI / 2, img, TRUE, FALSE, FALSE);
					break;
					//��
				case 1:
					DrawRotaGraph(status.pos.x - scroll.x - IMGSIZE64 + IMGSIZE64 / 2, status.pos.y - scroll.y + IMGSIZE64 - IMGSIZE64 / 2, 1, PI, img, TRUE, FALSE, FALSE);
					break;
					//��
				case 2:
					DrawRotaGraph(status.pos.x - scroll.x + IMGSIZE64 / 2, status.pos.y - scroll.y + IMGSIZE64 - IMGSIZE64 - IMGSIZE64 / 2, 1, -PI / 2, img, TRUE, FALSE, FALSE);
					break;
					//�E
				case 3:
					DrawRotaGraph(status.pos.x - scroll.x + IMGSIZE64 + IMGSIZE64 / 2, status.pos.y - scroll.y + IMGSIZE64 - IMGSIZE64 / 2, 1, 0, img, TRUE, FALSE, FALSE);
					break;
				}
			}
		}
		else
		{
			//���j�摜�`��
			DrawGraph(status.pos.x - scroll.x, status.pos.y - scroll.y, w_img, TRUE);
			//���jSE�Đ�
			if (r_time == 1)
				PlaySoundMem(SE_bom, DX_PLAYTYPE_BACK);
			
		}
		break;
		//WINDOW 2
	case P2:
		//���j����Ă��Ȃ��ꍇ
		if (p_flag == true) 
		{
			//�ʏ펞
			if (r_flag == false)
			{
				DrawGraph(status.pos.x - scroll.x + 992.0f, status.pos.y - scroll.y, status.p_img[img_Vec], TRUE);
				DrawFormatString(status.pos.x - scroll.x + 992.0f, status.pos.y - scroll.y - IMGSIZE64 / 2, GetColor(255, 255, 255), "��%dP", status.WIN_ID + 1);
			}
			//�Đ�����
			else
				DrawGraph(status.pos.x - scroll.x + 992.0f, status.pos.y - scroll.y, status.img, TRUE);
			//���̕`��
			if (status.wepon_num == 1 && ShotFlag == false)
			{
				//�����ɂ���ĕ`��ꏊ���C��
				switch (img_Vec)
				{
					//��
				case 0:
					DrawRotaGraph(status.pos.x + 992.0f - scroll.x + IMGSIZE64 / 2, status.pos.y - scroll.y + IMGSIZE64 + IMGSIZE64 / 2, 1, PI / 2, img, TRUE, FALSE, FALSE);
					break;
					//��
				case 1:
					DrawRotaGraph(status.pos.x + 992.0f - scroll.x - IMGSIZE64 + IMGSIZE64 / 2, status.pos.y - scroll.y + IMGSIZE64 - IMGSIZE64 / 2, 1, PI, img, TRUE, FALSE, FALSE);
					break;
					//��
				case 2:
					DrawRotaGraph(status.pos.x + 992.0f - scroll.x + IMGSIZE64 / 2, status.pos.y - scroll.y + IMGSIZE64 - IMGSIZE64 - IMGSIZE64 / 2, 1, -PI / 2, img, TRUE, FALSE, FALSE);
					break;
					//�E
				case 3:
					DrawRotaGraph(status.pos.x + 992.0f - scroll.x + IMGSIZE64 + IMGSIZE64 / 2, status.pos.y - scroll.y + IMGSIZE64 - IMGSIZE64 / 2, 1, 0, img, TRUE, FALSE, FALSE);
					break;
				}
			}
		}
		else
		{
			//���j�摜�`��
			DrawGraph(status.pos.x - scroll.x + 992.0f, status.pos.y - scroll.y, w_img, TRUE);
			//���jSE�Đ�
			if (r_time == 1)
				PlaySoundMem(SE_bom, DX_PLAYTYPE_BACK);
		}
		break;
		//WINDOW 3
	case P3:
		//���j����Ă��Ȃ��ꍇ
		if (p_flag == true)
		{
			//�ʏ펞
			if (r_flag == false)
			{
				DrawGraph(status.pos.x - scroll.x, status.pos.y + 572.0f - scroll.y, status.p_img[img_Vec], TRUE);
				DrawFormatString(status.pos.x - scroll.x, status.pos.y + 572.0f - scroll.y - IMGSIZE64 / 2, GetColor(255, 255, 255), "��%dP", status.WIN_ID + 1);
			}
				
			//�Đ�����
			else
				DrawGraph(status.pos.x - scroll.x, status.pos.y + 572.0f - scroll.y, status.img, TRUE);
			//���̕`��
			if (status.wepon_num == 1 && ShotFlag == false)
			{
				//�����ɂ���ĕ`��ꏊ���C��
				switch (img_Vec)
				{
					//��
				case 0:
					DrawRotaGraph(status.pos.x - scroll.x + IMGSIZE64 / 2, status.pos.y + 572.0f - scroll.y + IMGSIZE64 + IMGSIZE64 / 2, 1, PI / 2, img, TRUE, FALSE, FALSE);
					break;
					//��
				case 1:
					DrawRotaGraph(status.pos.x - scroll.x - IMGSIZE64 + IMGSIZE64 / 2, status.pos.y + 572.0f - scroll.y + IMGSIZE64 - IMGSIZE64 / 2, 1, PI, img, TRUE, FALSE, FALSE);
					break;
					//��
				case 2:
					DrawRotaGraph(status.pos.x - scroll.x + IMGSIZE64 / 2, status.pos.y + 572.0f - scroll.y + IMGSIZE64 - IMGSIZE64 - IMGSIZE64 / 2, 1, -PI / 2, img, TRUE, FALSE, FALSE);
					break;
					//�E
				case 3:
					DrawRotaGraph(status.pos.x - scroll.x + IMGSIZE64 + IMGSIZE64 / 2, status.pos.y + 572.0f - scroll.y + IMGSIZE64 - IMGSIZE64 / 2, 1, 0, img, TRUE, FALSE, FALSE);
					break;
				}
			}
		}
		else
		{
			//���j�摜�`��
			DrawGraph(status.pos.x - scroll.x, status.pos.y - scroll.y + 572.0f, w_img, TRUE);
			//���jSE�Đ�
			if (r_time == 1)
				PlaySoundMem(SE_bom, DX_PLAYTYPE_BACK);
		}
		break;
		//WINDOW 4
	case P4:
		//���j����Ă��Ȃ��ꍇ
		if (p_flag == true)
		{
			//�ʏ펞
			if (r_flag == false)
			{
				DrawGraph(status.pos.x + 992.0f - scroll.x, status.pos.y + 572.0f - scroll.y, status.p_img[img_Vec], TRUE);
				DrawFormatString(status.pos.x + 992.0f - scroll.x, status.pos.y + 572.0f - scroll.y - IMGSIZE64 / 2, GetColor(255, 255, 255), "��%dP", status.WIN_ID + 1);
			}
			//�Đ�����
			else
				DrawGraph(status.pos.x + 992.0f - scroll.x, status.pos.y + 572.0f - scroll.y, status.img, TRUE);
			//���̕`��
			if (status.wepon_num == 1 && ShotFlag == false)
			{
				//�����ɂ���ĕ`��ꏊ���C��
				switch (img_Vec)
				{
					//��
				case 0:
					DrawRotaGraph(status.pos.x + 992.0f - scroll.x + IMGSIZE64 / 2, status.pos.y + 572.0f - scroll.y + IMGSIZE64 + IMGSIZE64 / 2, 1, PI / 2, img, TRUE, FALSE, FALSE);
					break;
					//��
				case 1:
					DrawRotaGraph(status.pos.x + 992.0f - scroll.x - IMGSIZE64 + IMGSIZE64 / 2, status.pos.y + 572.0f - scroll.y + IMGSIZE64 - IMGSIZE64 / 2, 1, PI, img, TRUE, FALSE, FALSE);
					break;
					//��
				case 2:
					DrawRotaGraph(status.pos.x + 992.0f - scroll.x + IMGSIZE64 / 2, status.pos.y + 572.0f - scroll.y + IMGSIZE64 - IMGSIZE64 - IMGSIZE64 / 2, 1, -PI/2, img, TRUE, FALSE, FALSE);
					break;
					//�E
				case 3:
					DrawRotaGraph(status.pos.x + 992.0f - scroll.x + IMGSIZE64 + IMGSIZE64 / 2,  status.pos.y + 572.0f - scroll.y + IMGSIZE64 - IMGSIZE64 / 2, 1, 0, img, TRUE, FALSE, FALSE);
					break;
				}
			}
		}
		else
		{
			//���j�摜�`��
			DrawGraph(status.pos.x - scroll.x + 992.0f, status.pos.y - scroll.y + 572.0f, w_img, TRUE);
			//���jSE�Đ�
			if (r_time == 1)
				PlaySoundMem(SE_bom, DX_PLAYTYPE_BACK);
		}
		break;
	}	

	
}