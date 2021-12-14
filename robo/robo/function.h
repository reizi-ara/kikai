#pragma once
#include "main.h"
#include "char.h"

void GetScroll(Point* _pos, Vector* _scroll, int _WIN_ID);

void GetMap(int _map[MAP_SIZE_Y][MAP_SIZE_X]);

void BlockHit(Hit* player, Point* _pos, Vector* _vec);