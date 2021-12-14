#pragma once
#include "DxLib.h"

#include <list>
#include <memory>
#include <math.h>

#include <random>

//��b�X�e
#define default_HP    100
#define default_SP     50
#define default_S_ATK     10
#define default_F_ATK     15
#define default_DEF    10
#define default_CD     25
#define default_SPD_X   5
#define default_SPD_Y   5

//�p�C���b�g�\��
#define combat_type    0.5
#define shoot_type     0.2
#define run_type       0.3
#define mechanic_type  5.0

#define NONE 0.0f

#define Window_Size_x 800
#define Window_Size_y 600

using namespace std;

enum  mode{
	SELECT,//�Z���N�g���
	GAME//�Q�[����
};

enum ID_NUMBER
{
	SPEED_PLAYER,
	DEFENCE_PLAYER,
	SHOOTING_PLAYER,
	TRAP_PLAYER,
	ITEMBOX,
	WEPON,
};



enum PILOT_NUMBER
{
	COMBAT,
	SHOOT,
	RUN,
	MECHANIC
};

enum PLAYER_NUM
{
	PLAYER1,
	PLAYER2,
	PLAYER3,
	PLAYER4,
};

typedef struct Vec {
	float x, y;
}Vec;


typedef struct Point {
	float x, y;
}Point;

typedef struct Status
{
	int img;//�摜
	int ID;//���X�g��ID
	int P_ID;//�v���C���[�̔ԍ�
	int Pilot;//�p�C���b�gID
	bool FLAG;//���X�g�̍폜�t���O
	int hp;//HP
	int sp;//SP
	Point pos;//�ʒu
	Vec speed;//�X�s�[�h
	float f_atk;//ATK
	float s_atk;
	float def;//DEF
	float skill_cooldown;//�X�L���N�[���_�E��
	int wepon_num;// ����̎��
}Status;

typedef struct Pilot
{
	int Pilot_ID;//�p�C���b�gID
	int img{ 0 };//�p�C���b�g�C���[�W

	float up_date;//�A�b�v�f�[�g
};

//�x�[�X�N���X
class Bace {
private:
public:

	Status Charcter{ 0,0,0,0,false,0,0,{0.0f,0.0f},{0.0f,0.0f},0.0f,0.0f,0.0f,0.0f,0 };

	virtual int Action(list<unique_ptr<Bace>>& bace) = 0;
	virtual void Draw() = 0;
};

//�X�e�[�^�X�֐�
void SetMachine(Status* st, int machine, int pilot);

//����֐�
void wepon_summary(list<unique_ptr<Bace>>& bace, float px, float py, int wepon_num,int p_id);