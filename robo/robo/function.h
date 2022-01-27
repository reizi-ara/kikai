#pragma once
#include "main.h"
#include "char.h"

//スクロール情報取得関数
void GetScroll(Point* _pos, Vector* _scroll, int _WIN_ID);

//マップ情報取得関数
void GetMap(int _map[MAP_SIZE_Y][MAP_SIZE_X]);

//ブロックとの当たり判定関数
void BlockHit(Hit* player, Point* _pos, Vector* _vec, int IMGSIZE);

//スクロール情報セッティング関数
void ScrollSet(Vector _scroll[4], Point pos[4], list<unique_ptr<Base>>& base);

//ブロック描画（画面分割）関数
int BlockDraw(Vector scroll[4], Point pos[4], int WIN_ID, int x, int y);

//プレイヤーの画像取得関数
void Getimg(list<unique_ptr<Base>>& base, int img[4]);

//プレイヤーとの当たり判定関数
int Hit_Player(Point p_pos, Vector scroll[4], list<unique_ptr<Base>>& base, int IMGSIZE, bool* FLAG, int WIN_ID);

//マップ情報変更関数
void SetMap(int x, int y, int NUM);

//ステータス関数
void SetMachine(Status* st, int machine, int pilot);

//武器関数
void wepon_summary(list<unique_ptr<Base>>& base, Point p_pos, Vector scroll[4], int wepon_num, int WIN_ID, int img_Vec, int* kill);