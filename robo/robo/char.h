#pragma once
#include "main.h"


//ひな形プレイヤー
class Player :public Bace {
private:
	

public:

	Player(float _x, float _y,int type_nm,int pilot);
	int img1{ 0 };
	int img2{ 0 };
	int img3{ 0 };
	int img4{ 0 };

	int Action(list<unique_ptr<Bace>>& bace);//アクション
	void Draw();//描画

	int img_Vec = 1;

	int rotate_vx = 0;
	int rotate_vy = 0;

	float BulletSave_vx = 0.0f;
	float BulletSave_vy = 0.0f;

	bool ShotFlag = false;//発砲フラグ
};

//弾
class Bullet :public Bace {
private:
public:
	//コンストラクタ
	Bullet(float vx, float vy, float px, float py);

	int img{ 0 };
	int Action(list<unique_ptr<Bace>>& bace);
	void Draw();
};

//セレクトカーソル
class Cursor :public Bace {
private:
public:
	//コンストラクタ
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
	//コンストラクタ
	Itembox(float px, float py);

	int img{ 0 };
	int Action(list<unique_ptr<Bace>>& bace);
	void Draw();
};
