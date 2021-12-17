#pragma once
#include "main.h"
#include "char.h"

int Get_time();

void GetScroll(Point* _pos, Vector* _scroll, int _WIN_ID);

void GetMap(int _map[MAP_SIZE_Y][MAP_SIZE_X]);

void BlockHit(Hit* player, Point* _pos, Vector* _vec, int IMGSIZE);

void ScrollSet(Vector _scroll[4], Point pos[4], list<unique_ptr<Base>>& base);

int BlockDraw(Vector scroll[4], Point pos[4], int WIN_ID, int x, int y);

void Getimg(list<unique_ptr<Base>>& base, int img[4]);

int Hit_Player(Point p_pos, Vector scroll[4], list<unique_ptr<Base>>& base, int IMGSIZE, bool* FLAG, int WIN_ID);

void SetMap(int x, int y, int NUM);

//ステータス関数
void SetMachine(Status* st, int machine, int pilot);

//武器関数
void wepon_summary(list<unique_ptr<Base>>& base, float px, float py, int wepon_num, int p_id);