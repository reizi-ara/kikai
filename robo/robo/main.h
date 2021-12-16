#pragma once
#include "DxLib.h"

#include <list>
#include <memory>
#include <math.h>

#include <random>

//基礎ステ
#define default_HP    100
#define default_SP     50
#define default_S_ATK     10
#define default_F_ATK     15
#define default_DEF    10
#define default_CD     25
#define default_SPD_X   5
#define default_SPD_Y   5

//パイロット能力
#define combat_type    0.5
#define shoot_type     0.2
#define run_type       0.3
#define mechanic_type  5.0

#define NONE 0.0f

//windowサイズ
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

//マップサイズ
#define MAP_SIZE_X 50
#define MAP_SIZE_Y 50

//スクロールライン
#define SCROLL_LINE_X 464
#define SCROLL_LINE_Y 254
#define SCROLL_LINE_X_MAX  IMGSIZE64 * 50 - SCROLL_LINE_X
#define SCROLL_LINE_Y_MAX  IMGSIZE64 * 50 - SCROLL_LINE_Y

//イメージサイズ
#define IMGSIZE64 64

using namespace std;

enum  mode{
	SELECT,//セレクト画面
	GAME//ゲーム中
};

enum ID_NUMBER
{
	SPEED_PLAYER,
	DEFFENSE_PLAYER,
	ATTACK_PLAYER,
	TRAP_PLAYER,
	ITEMBOX,
	WEPON,
	BLOCK
};

enum WINDOW_NUMBER
{
	P1,
	P2,
	P3,
	P4
};

enum ROBO_NUMBER
{
	SPEED,
	DEFFENSE,
	ATTACK,
	TRAP
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

typedef struct Vector {
	float x, y;
}Vector;


typedef struct Point {
	float x, y;
}Point;

//当たり判定
typedef struct Hit {
	bool UP, DOWN, LEFT, RIGHT;
}Hit;

typedef struct MAP {
	float x, y;
}MAP;

typedef struct Status
{
	int img;//画像
	int ID;//リストのID
	int P_ID;//プレイヤーの番号
	int WIN_ID;//window ID
	int Pilot;//パイロットID
	bool FLAG;//リストの削除フラグ
	int hp;//HP
	int sp;//SP
	Point pos;//位置
	Vector speed;//スピード
	float f_atk;//ATK
	float s_atk;
	float def;//DEF
	float skill_cooldown;//スキルクールダウン
	int wepon_num;// 武器の種類
}Status;

typedef struct Pilot
{
	int Pilot_ID;//パイロットID
	int img{ 0 };//パイロットイメージ

	float up_date;//アップデート
};

//ベースクラス
class Base {
private:
public:

	int pri{ 0 };//描画の順番

	Status status{ 0,0,0,-1,0,TRUE,0,0,{0.0f,0.0f},{0.0f,0.0f},0.0f,0.0f,0.0f,0.0f,0 };

	virtual int Action(list<unique_ptr<Base>>& base) = 0;
	virtual void Draw() = 0;
};

//比較用クラス(ソート）
class Pr
{
private:
public:
	//ここで比較する要素を決める
	bool operator()(const unique_ptr<Base>& x, const unique_ptr<Base>& y) const
	{
		return x.get()->pri < y.get()->pri;
	}
};

//ステータス関数
void SetMachine(Status* st, int machine, int pilot);

//武器関数
void wepon_summary(list<unique_ptr<Base>>& base, float px, float py, int wepon_num,int p_id);