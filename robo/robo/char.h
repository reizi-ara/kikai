#pragma once
#include "main.h"


//�ЂȌ`�v���C���[
class Player :public Bace {
private:
	

public:

	Player(float _x, float _y,int type_nm,int pilot,int player_num);
	int img1{ 0 };
	int img2{ 0 };
	int img3{ 0 };
	int img4{ 0 };

	int w_img{ 0 };//����C���[�W

	int Action(list<unique_ptr<Bace>>& bace);//�A�N�V����
	void Draw();//�`��

	int img_Vec = 1;

	int rotate_vx = 0;
	int rotate_vy = 0;

	float BulletSave_vx = 0.0f;
	float BulletSave_vy = 0.0f;

	Point Item{ 0.0f,0.0f };

	int a = 0;//����m�F�p

	int wepon_cd = 0;//����N�[���_�E��



	bool weponget_flag = false;//�擾�t���O
	int wepon_num = -1;//�����

	bool ShotFlag = false;//���C�t���O
};

//�e
class Bullet :public Bace {
private:
public:
	//�R���X�g���N�^
	Bullet(float vx, float vy, float px, float py);

	int img{ 0 };
	int Action(list<unique_ptr<Bace>>& bace);
	void Draw();
};

//�Z���N�g�J�[�\��
class Cursor :public Bace {
private:
public:
	//�R���X�g���N�^
	Cursor(float _x, float _y);
	int time = 25;

	int select_type = 0;

	bool key_flag = false;

	int img{ 0 };
	int Action(list<unique_ptr<Bace>>& bace);
	void Draw();
};

//itembox
class Itembox :public Bace {
private:
public:
	//�R���X�g���N�^
	Itembox(float px, float py);

	int img{ 0 };
	int Action(list<unique_ptr<Bace>>& bace);
	void Draw();
};
