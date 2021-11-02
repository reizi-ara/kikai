#pragma once
#include "char.h"

//コンストラクタ
speedtype::speedtype(float _x, float _y)
{
	img1 = LoadGraph("image\\Arrow.png");
	img2 = LoadGraph("image\\ArrowDown.png");
	img3 = LoadGraph("image\\ArrowRight.png");
	img4 = LoadGraph("image\\ArrowLeft.png");

	pos.x = _x;
	pos.y = _y;

	FLAG = true;
}

void speedtype::Init()
{
	img1 = -1;
	img2 = -1;
	img3 = -1;
	img4 = -1;
	pos.x = 0.0f;
	pos.y = 0.0f;
	rotate_vx = 0;
	rotate_vy = 0;
	img_Vec = 4;
}

int speedtype::Action(list<unique_ptr<Bace>>& bace)
{
	vec.x = 0.0f; vec.y = 0.0f;

	//移動方向入力
	GetJoypadAnalogInput(&vx, &vy, (DX_INPUT_PAD1));

	vec.x = vx / 250.0f;
	vec.y = vy / 250.0f;

	pos.x += vec.x;
	pos.y += vec.y;

	//画像用の保存変数
	if (vx != 0 || vy != 0)
	{
		rotate_vx = vx;
		rotate_vy = vy;
	}
	else
		;

	//弾用の保存変数
	if (vx != 0 || vy != 0)
	{
		BulletSave_vx = vec.x;
		BulletSave_vy = vec.y;
	}
	else
		;


	if (rotate_vx > 0)
	{
		img_Vec = 3;
	}
	if (rotate_vx < 0)
	{
		img_Vec = 4;
	}
	if (rotate_vy > 0)
	{
		img_Vec = 2;
	}
	if (rotate_vy < 0)
	{
		img_Vec = 1;
	}



	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B) == 0)
	{
		ShotFlag = true;
	}
	else
	{
		if (ShotFlag == true)
		{
			auto B = (unique_ptr<Bace>)new Bullet(BulletSave_vx, BulletSave_vy, pos.x, pos.y);
			bace.emplace_back(move(B));

			ShotFlag = false;

		}
	}

	return 0;
}

// 描画
void speedtype::Draw() {

	if (img_Vec == 3) {
		DrawGraph(pos.x, pos.y, img3, TRUE);

	}
	if (img_Vec == 4) {
		DrawGraph(pos.x, pos.y, img4, TRUE);
	}
	if (img_Vec == 2) {
		DrawGraph(pos.x, pos.y, img2, TRUE);
	}
	if (img_Vec == 1) {
		DrawGraph(pos.x, pos.y, img1, TRUE);
	}


}