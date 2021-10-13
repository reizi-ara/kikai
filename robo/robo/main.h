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

//�x�[�X�N���X
class Bace {
private:
public:
	char ID{ -1 };

	Point pos{ 0.0f,0.0f };//�ʒu
	Vec vec{ 0.0f,0.0f };//�ړ��x�N�g��

	bool FLAG{ false };

	virtual int Action(list<unique_ptr<Bace>>& bace) = 0;
	virtual void Draw() = 0;
};