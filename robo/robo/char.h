#pragma once
#include "main.h"

//�ЂȌ`�v���C���[
class Player :public Bace {
private:
	

public:

	//������
	void Init();

	Player(float _x, float _y);
	int img1{ 0 };
	int img2{ 0 };
	int img3{ 0 };
	int img4{ 0 };

	Point pos{ 0.0f,0.0f };
	Vec vec{ 0.0f,0.0f };
	int Action(list<unique_ptr<Bace>>& bace);//�A�N�V����
	void Draw();//�`��

	int img_Vec = 1;

	int vx = 0;
	int vy = 0;

	int rotate_vx = 0;
	int rotate_vy = 0;

	float BulletSave_vx = 0.0f;
	float BulletSave_vy = 0.0f;

	bool ShotFlag = false;//���C�t���O


};

//�U���^
class attacktype :public Bace {
private:


public:

	//������
	void Init();

	attacktype(float _x, float _y);
	int img1{ 0 };
	int img2{ 0 };
	int img3{ 0 };
	int img4{ 0 };

	Point pos{ 0.0f,0.0f };
	Vec vec{ 0.0f,0.0f };
	int Action(list<unique_ptr<Bace>>& bace);//�A�N�V����
	void Draw();//�`��

	int img_Vec = 1;

	int vx = 0;
	int vy = 0;

	int rotate_vx = 0;
	int rotate_vy = 0;

	float BulletSave_vx = 0.0f;
	float BulletSave_vy = 0.0f;

	bool ShotFlag = false;//���C�t���O


};

//�h��^
class shieldtype :public Bace {
private:


public:

	//������
	void Init();

	shieldtype(float _x, float _y);
	int img1{ 0 };
	int img2{ 0 };
	int img3{ 0 };
	int img4{ 0 };

	Point pos{ 0.0f,0.0f };
	Vec vec{ 0.0f,0.0f };
	int Action(list<unique_ptr<Bace>>& bace);//�A�N�V����
	void Draw();//�`��

	int img_Vec = 1;

	int vx = 0;
	int vy = 0;

	int rotate_vx = 0;
	int rotate_vy = 0;

	float BulletSave_vx = 0.0f;
	float BulletSave_vy = 0.0f;

	bool ShotFlag = false;//���C�t���O


};

//㩌^
class traptype :public Bace {
private:


public:

	//������
	void Init();

	traptype(float _x, float _y);
	int img1{ 0 };
	int img2{ 0 };
	int img3{ 0 };
	int img4{ 0 };

	Point pos{ 0.0f,0.0f };
	Vec vec{ 0.0f,0.0f };
	int Action(list<unique_ptr<Bace>>& bace);//�A�N�V����
	void Draw();//�`��

	int img_Vec = 1;

	int vx = 0;
	int vy = 0;

	int rotate_vx = 0;
	int rotate_vy = 0;

	float BulletSave_vx = 0.0f;
	float BulletSave_vy = 0.0f;

	bool ShotFlag = false;//���C�t���O


};

//���x�^
class speedtype :public Bace {
private:


public:

	//������
	void Init();

	speedtype(float _x, float _y);
	int img1{ 0 };
	int img2{ 0 };
	int img3{ 0 };
	int img4{ 0 };

	Point pos{ 0.0f,0.0f };
	Vec vec{ 0.0f,0.0f };
	int Action(list<unique_ptr<Bace>>& bace);//�A�N�V����
	void Draw();//�`��

	int img_Vec = 1;

	int vx = 0;
	int vy = 0;

	int rotate_vx = 0;
	int rotate_vy = 0;

	float BulletSave_vx = 0.0f;
	float BulletSave_vy = 0.0f;

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
class SelectCursor :public Bace {
private:
public:
	//�R���X�g���N�^
	SelectCursor(float _x, float _y);
	int time = 25;

	int select_type = 0;

	bool key_flag = false;

	int img{ 0 };
	int Action(list<unique_ptr<Bace>>& bace);
	void Draw();
};
