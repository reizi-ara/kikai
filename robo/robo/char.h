#pragma once
#include "main.h"
#include"function.h"


//ひな形プレイヤー
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

	int w_img{ 0 };//武器イメージ

	int Action(list<unique_ptr<Base>>& base);//アクション
	void Draw();//描画

	int img_Vec = 0;

	int rotate_vx = 0;
	int rotate_vy = 0;

	float BulletSave_vx = 0.0f;
	float BulletSave_vy = 0.0f;

	Point Item{ 0.0f,0.0f };

	int a = 0;//動作確認用

	int wepon_cd = 0;//武器クールダウン

	int Con[4] = { DX_INPUT_PAD1, DX_INPUT_PAD2, DX_INPUT_PAD3, DX_INPUT_PAD4 };

	bool weponget_flag = false;//取得フラグ
	int wepon_num = -1;//武器種

	bool ShotFlag = false;//発砲フラグ

	Hit h_player;//当たり判定

	Vector scroll{ 0.0f,0.0f };//スクロール

	Point bullet{ 0.0f,0.0f };

	//プレイヤー生成フラグ
	bool r_flag = true;
	int r_time = 0;

	int kill = 0;

	bool p_flag = true;

	int ME_count = 0;//メカニックパイロット用カウント
};

//弾
class Bullet :public Base {
private:
public:
	//コンストラクタ
	Bullet(float vx, float vy, float px, float py,int WIN_ID,int IMGSIZE);

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

	int img_size = 0;

	int hit_player = -1;

	int delete_time = 0;

	Hit h_bullet;//当たり判定

	bool kill_flag = false;
};


//トラップ
class Trap :public Base {
private:
public:
	//コンストラクタ
	Trap(float vx, float vy, float px, float py, int WIN_ID, int IMGSIZE);

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

	int ID[4]{ 0,0,0,0 };

	int img_size = 0;

	int hit_player = -1;

	int delete_time = 0;

	Hit h_bullet;//当たり判定

	bool kill_flag = false;
};

//セレクトカーソル
class Cursor :public Base {
private:
public:
	//コンストラクタ
	Cursor(int WIN_ID);
	int time = 25;

	int select_type = 0;

	bool key_flag = false;
	bool button_flag = false;

	int x_count = 0;
	int y_count = 0;
	int Icount = 0;
	int Dcount = 0;

	bool complete_select{ false };
	int get_select[2][4] = { {-1,-1,-1,-1},
							{-1,-1,-1,-1} };
	int select_mode = 0;

	int img_m[4];
	int img_p[4];

	int Con[4] = { DX_INPUT_PAD1, DX_INPUT_PAD2, DX_INPUT_PAD3, DX_INPUT_PAD4 };

	int img{ 0 };
	int img1{ 0 };
	int Action(list<unique_ptr<Base>>& base);
	void Draw();
};

//itembox
class Itembox :public Base {
private:
public:
	//コンストラクタ
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

//Blockクラス
class Block :public Base {
private:
public:

	Block();//コンストラクタ
	int Action(list<unique_ptr<Base>>& base);//処理
	void Draw();//描画

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

	bool w_flag[4] = { false,false,false,false };

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
	//コンストラクタ
	UI();

	int img{ 0 };
	int Action(list<unique_ptr<Base>>& base);
	void Draw();

	int HP[4] = { 0,0,0,0 };

	int Skill[4] = { 0,0,0,0 };

	int WEPON[4] = { 0,0,0,0 };

	int Kill[4] = { 0,0,0,0 };

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

//Title
class Title :public Base {
private:
public:
	//コンストラクタ
	Title();

	int img_m[4];

	Point p_pos[8] = { {0.0f,0.0f},{0.0f,0.0f},{0.0f,0.0f},{0.0f,0.0f},{0.0f,0.0f},{0.0f,0.0f},{0.0f,0.0f},{0.0f,0.0f} };//画像移動用ポジション

	int Con[4] = { DX_INPUT_PAD1, DX_INPUT_PAD2, DX_INPUT_PAD3, DX_INPUT_PAD4 };

	bool Change_Scene = false;

	int Action(list<unique_ptr<Base>>& base);
	void Draw();
};