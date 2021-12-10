//function.cpp
#pragma once
#include "main.h"

//リストの中から指定したIDの位置情報(pos)を取得
Point Get_Point(list<unique_ptr<Bace>>& base, int _ID) {
	Point p{ -1.0f,-1.0f };

	for (auto a = base.begin(); a != base.end(); a++) {
		if ((*a)->Charcter.ID == _ID)return (*a)->Charcter.pos;
	}
}