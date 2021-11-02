#pragma once
#include "DxLib.h"

#include <list>
#include <memory>
#include <math.h>

//基礎ステ
#define default_HP    100
#define default_SP     50
#define default_ATK     0
#define default_DEF    10
#define default_CD     25
#define default_SPD_X   5
#define default_SPD_Y   5

//パイロットID
#define combat    1
#define shoot     2
#define run       3
#define mechanic  4

//パイロット能力
#define combat_type    0.5
#define shoot_type     0.2
#define run_type       0.3
#define mechanic_type  5.0

using namespace std;

enum  mode{
	SELECT,//セレクト画面
	GAME//ゲーム中
};

typedef struct Vec {
	float x, y;
}Vec;


typedef struct Point {
	float x, y;
}Point;

typedef struct Status
{
	int hp;//HP
	int sp;//SP
	Point pos;//位置
	Vec speed;//スピード
	float atk;//ATK
	float def;//DEF
	float skill_cooldown;//スキルクールダウン
	int wepon_num;// 武器の種類
};

typedef struct Pilot
{
	int Pilot_ID;//パイロットID
	int img{ 0 };//パイロットイメージ

	float up_date;//アップデート
};

//ベースクラス
class Bace {
private:
public:
	char ID{ -1 };

	Point pos{ 0.0f,0.0f };//位置
	Vec vec{ 0.0f,0.0f };//移動ベクトル

	bool FLAG{ false };

	virtual int Action(list<unique_ptr<Bace>>& bace) = 0;
	virtual void Draw() = 0;
};