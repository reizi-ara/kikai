#pragma once
#include "main.h"
#include"function.h"


//�ЂȌ`�v���C���[
class Player :public Base {
private:
	

public:

	Player(float _x, float _y,int type_nm,int pilot,int player_num, int window_num, Point Pos);
	int img{ 0 };

	int img_player[4]{ -1,-1,-1,-1 };

	Point e_pos[4]
	{
		{0.0f,0.0f},
		{0.0f,0.0f},
		{0.0f,0.0f},
		{0.0f,0.0f}
	};

	Vector e_scroll[4]
	{
		{0.0f,0.0f},
		{0.0f,0.0f},
		{0.0f,0.0f},
		{0.0f,0.0f}
	};

	int id[4]{ 0,0,0,0 };

	int w_img{ 0 };//����C���[�W

	int Action(list<unique_ptr<Base>>& base);//�A�N�V����
	void Draw();//�`��

	int img_Vec = 0;

	int rotate_vx = 0;
	int rotate_vy = 0;

	float BulletSave_vx = 0.0f;
	float BulletSave_vy = 0.0f;

	Point Item{ 0.0f,0.0f };

	int a = 0;//����m�F�p

	int wepon_cd = 0;//����N�[���_�E��

	int Con[4] = { DX_INPUT_PAD1, DX_INPUT_PAD2, DX_INPUT_PAD3, DX_INPUT_PAD4 };

	bool weponget_flag = false;//�擾�t���O
	int wepon_num = -1;//�����

	bool ShotFlag = false;//���C�t���O

	Hit h_player;//�����蔻��

	Vector scroll{ 0.0f,0.0f };//�X�N���[��

	Point bullet{ 0.0f,0.0f };
};

//�e
class Bullet :public Base {
private:
public:
	//�R���X�g���N�^
	Bullet(float vx, float vy, float px, float py,int WIN_ID);

	int img{ 0 };
	int Action(list<unique_ptr<Base>>& base);
	void Draw();

	Vector scroll[4]{
		{0.0f,0.0f},
		{0.0f,0.0f},
		{0.0f,0.0f},
		{0.0f,0.0f}
	};
	Point p_pos[4]{
	{0.0f,0.0f},
	{0.0f,0.0f},
	{0.0f,0.0f},
	{0.0f,0.0f}
	};

	int hit_player = -1;

	int delete_time = 0;

	Hit h_bullet;//�����蔻��
};

//�Z���N�g�J�[�\��
class Cursor :public Base {
private:
public:
	//�R���X�g���N�^
	Cursor(float _x, float _y);
	int time = 25;

	int select_type = 0;

	bool key_flag = false;

	int img{ 0 };
	int Action(list<unique_ptr<Base>>& base);
	void Draw();
};

//itembox
class Itembox :public Base {
private:
public:
	//�R���X�g���N�^
	Itembox(float px, float py);

	int img{ 0 };
	int Action(list<unique_ptr<Base>>& base);
	void Draw();

	Vector scroll[4]{
		{0.0f,0.0f},
		{0.0f,0.0f},
		{0.0f,0.0f},
		{0.0f,0.0f}
	};
		Point p_pos[4]{
		{0.0f,0.0f},
		{0.0f,0.0f},
		{0.0f,0.0f},
		{0.0f,0.0f}
	};
};

//Block�N���X
class Block :public Base {
private:
public:

	Block();//�R���X�g���N�^
	int Action(list<unique_ptr<Base>>& base);//����
	void Draw();//�`��

	int map[MAP_SIZE_Y][MAP_SIZE_X];

	Point p_pos[4]
	{
		{0.0f,0.0f},
		{0.0f,0.0f},
		{0.0f,0.0f},
		{0.0f,0.0f}
	};

	Vector scroll[4]
	{
		{0.0f,0.0f},
		{0.0f,0.0f},
		{0.0f,0.0f},
		{0.0f,0.0f}
	};

	MAP p_map[4]
	{
		{0.0f,0.0f},
		{0.0f,0.0f},
		{0.0f,0.0f},
		{0.0f,0.0f}
	};

	bool Draw_flag = false;

	int img = LoadGraph("image\\block.png", 0);
	int img_green = LoadGraph("image\\green.png", 0);
	int img_back = LoadGraph("image\\UI\\UI.png", 0);
	int img_speed = LoadGraph("image\\robo.png", 0);
	int img_attack = LoadGraph("image\\attack.png", 0);
	int img_deffense = LoadGraph("image\\deffense.png", 0);
	int img_trap = LoadGraph("image\\trap.png", 0);

	int p_img[4]{ -1,-1,-1,-1 };

	int Item_time = 0;

	bool Item_time_flag = false;

	Point Item_pos[10]
	{
		{0.0f,0.0f},
		{0.0f,0.0f},
		{0.0f,0.0f},
		{0.0f,0.0f},
		{0.0f,0.0f},
		{0.0f,0.0f},
		{0.0f,0.0f},
		{0.0f,0.0f},
		{0.0f,0.0f},
		{0.0f,0.0f}
	};

};

//UI
class UI :public Base {
private:
public:
	//�R���X�g���N�^
	UI();

	int img{ 0 };
	int Action(list<unique_ptr<Base>>& base);
	void Draw();

	int HP[4] = { 0,0,0,0 };

	int WEPON[4] = { 0,0,0,0 };

	int img_Item =		LoadGraph("image\\UI\\Item_UI.png", 0);
	int img_Item_UI =	LoadGraph("image\\UI\\Item_UI.png", 0);
	int img_HP =		LoadGraph("image\\UI\\HP.png", 0);
	int img_HP_UI =		LoadGraph("image\\UI\\HP_UI.png", 0);
	int img_Skill_UI =	LoadGraph("image\\UI\\Skill_UI.png", 0);
	int img_Skill =		LoadGraph("image\\UI\\Skill.png", 0);
	int img_rifle =		LoadGraph("image\\UI\\rifle.png", 0);
	int img_katana =	LoadGraph("image\\UI\\katana.png", 0);
	int img_missile =	LoadGraph("image\\UI\\missile.png", 0);
	int img_rerugan =	LoadGraph("image\\UI\\rerugan.png", 0);
};