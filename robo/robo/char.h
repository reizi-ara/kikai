#pragma once
#include "main.h"

//プレイヤー
class Player :public Bace {
private:
	

public:

	//初期化
	void Init();

	Player(float _x, float _y);
	int img1{ 0 };
	int img2{ 0 };
	int img3{ 0 };
	int img4{ 0 };

	Point pos{ 0.0f,0.0f };
	Vec vec{ 0.0f,0.0f };
	int Action(list<unique_ptr<Bace>>& bace);//アクション
	void Draw();//描画

	int img_Vec = 1;

	int vx = 0;
	int vy = 0;

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
