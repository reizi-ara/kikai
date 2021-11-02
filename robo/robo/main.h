#pragma once
#include "DxLib.h"

#include <list>
#include <memory>
#include <math.h>

//��b�X�e
#define default_HP    100
#define default_SP     50
#define default_ATK     0
#define default_DEF    10
#define default_CD     25
#define default_SPD_X   5
#define default_SPD_Y   5

//�p�C���b�gID
#define combat    1
#define shoot     2
#define run       3
#define mechanic  4

//�p�C���b�g�\��
#define combat_type    0.5
#define shoot_type     0.2
#define run_type       0.3
#define mechanic_type  5.0

#define NONE 0.0f

using namespace std;

enum  mode{
	SELECT,//�Z���N�g���
	GAME//�Q�[����
};

enum ID_NUMBER
{
	SPEED_PLAYER,
	DEFENSE_PLAYER,
	SHOOTING_PLAYER,
	TRAP_PLAYER
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
	bool FLAG;//���X�g�̍폜�t���O
	int hp;//HP
	int sp;//SP
	Point pos;//�ʒu
	Vec speed;//�X�s�[�h
	float atk;//ATK
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

	Status Charcter{ 0,0,false,0,0,{0.0f,0.0f},{0.0f,0.0f},0.0f,0.0f,0.0f,0 };

	virtual int Action(list<unique_ptr<Bace>>& bace) = 0;
	virtual void Draw() = 0;
};