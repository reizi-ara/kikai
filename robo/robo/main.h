#pragma once
#include "DxLib.h"

#include <list>
#include <memory>
#include <math.h>

using namespace std;

typedef struct Vec {
	float x, y;
}Vec;


typedef struct Point {
	float x, y;
}Point;

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