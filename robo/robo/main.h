#pragma once
#include "DxLib.h"

#include <list>
#include <memory>
#include <math.h>

#include <random>

//��b�X�e�[�^�X
#define default_HP    400
#define default_SP     50
#define default_S_ATK     1.5
#define default_F_ATK     1.5
#define default_DEF    0.2
#define default_CD     25
#define default_SPD_X   5
#define default_SPD_Y   5

//�p�C���b�g�\��
#define combat_type    0.5
#define shoot_type     0.2
#define run_type       0.3
#define mechanic_type  5.0

#define NONE 0.0f

//window�T�C�Y
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

//�}�b�v�T�C�Y
#define MAP_SIZE_X 50
#define MAP_SIZE_Y 50

//�X�N���[�����C��
#define SCROLL_LINE_X 464
#define SCROLL_LINE_Y 254
#define SCROLL_LINE_X_MAX  IMGSIZE64 * 50 - SCROLL_LINE_X
#define SCROLL_LINE_Y_MAX  IMGSIZE64 * 50 - SCROLL_LINE_Y

//�C���[�W�T�C�Y
#define IMGSIZE64 64

//��b
#define TIME1 60

using namespace std;

//�Q�[�����[�h
enum  mode{
	TITLE,//�^�C�g�����
	SELECT,//�Z���N�g���
	GAME//�Q�[����
};

//�I�u�W�F�N�gID
enum ID_NUMBER
{
	SPEED_PLAYER,
	DEFFENSE_PLAYER,
	ATTACK_PLAYER,
	TRAP_PLAYER,
	ITEMBOX,
	WEPON,
	BLOCK,
	BULLET
};

//WINDOW�ԍ�
enum WINDOW_NUMBER
{
	P1,//�v���C���[1
	P2,//�v���C���[2
	P3,//�v���C���[3
	P4,//�v���C���[4
};

//�@�̔ԍ�
enum ROBO_NUMBER
{
	SPEED,
	DEFFENSE,
	ATTACK,
	TRAP
};

//�p�C���b�g�ԍ�
enum PILOT_NUMBER
{
	COMBAT,
	SHOOT,
	RUN,
	MECHANIC
};

//�\���́@�F�@�x�N�g��
typedef struct Vector {
	float x, y;
}Vector;

//�\���́@�F�@�ʒu
typedef struct Point {
	float x, y;
}Point;

//�����蔻��
typedef struct Hit {
	bool UP, DOWN, LEFT, RIGHT;
}Hit;

//�}�b�v���W
typedef struct MAP {
	float x, y;
}MAP;

//�X�e�[�^�X�\����
typedef struct Status
{
	int img;//�摜
	int p_img[4];
	int ID;//���X�g��ID
	int P_ID;//�v���C���[�̔ԍ�
	int WIN_ID;//window ID
	int Pilot;//�p�C���b�gID
	bool FLAG;//���X�g�̍폜�t���O
	int hp;//HP
	int sp;//SP
	Point pos;//�ʒu
	Vector speed;//�X�s�[�h
	float f_atk;//ATK
	float s_atk;
	float def;//DEF
	float skill_cooldown;//�X�L���N�[���_�E��
	int wepon_num;// ����̎��
}Status;

//�x�[�X�N���X
class Base {
private:
public:

	int pri{ 0 };//�`��̏���

	Status status{ 0,{0,0,0,0},0,0,-1,0,TRUE,0,0,{0.0f,0.0f},{0.0f,0.0f},0.0f,0.0f,0.0f,0.0f,-1 };

	virtual int Action(list<unique_ptr<Base>>& base) = 0;
	virtual void Draw() = 0;
};

//��r�p�N���X(�\�[�g�j
class Pr
{
private:
public:
	//�����Ŕ�r����v�f�����߂�
	bool operator()(const unique_ptr<Base>& x, const unique_ptr<Base>& y) const
	{
		return x.get()->pri < y.get()->pri;
	}
};

