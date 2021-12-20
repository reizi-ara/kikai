#pragma once
#include "main.h"
#include "char.h"

//リスト
list<unique_ptr<Base>> base;



//クライアント用プログラム(TCP/IP)
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE,
	_In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
	//windowモード切替
	ChangeWindowMode(TRUE);

	//windowサイズ
	SetGraphMode(WINDOW_WIDTH-10, WINDOW_HEIGHT-10, 32);

	//Dxライブラリの初期化
	if (DxLib_Init() == -1)return -1;

	//windowの名前
	SetWindowText("リストサンプル");

	//バックバッファを使用
	SetDrawScreen(DX_SCREEN_BACK);

	int map[MAP_SIZE_Y][MAP_SIZE_X];

	//プレイヤーの座標指定
	Point pos[4]
	{
		{ IMGSIZE64 * 2							,IMGSIZE64 * 2 },
		{ MAP_SIZE_X * IMGSIZE64 - IMGSIZE64 * 3,IMGSIZE64 * 2 },
		{ IMGSIZE64 * 2							,(MAP_SIZE_Y * IMGSIZE64) - IMGSIZE64 * 3 },
		{ MAP_SIZE_X * IMGSIZE64 - IMGSIZE64 * 3,(MAP_SIZE_Y * IMGSIZE64) - IMGSIZE64 * 3 }
	};

	bool vic = false;

	int vic_p = -1;

	//プレイヤー作成
	for (int i = 0; i < 4; i++)//i->WINDOW番号
		base.emplace_back((unique_ptr<Base>)new Player(0.0f, 0.0f, i, SPEED, PLAYER1, i, pos[i]));

	//マップ作成
	base.emplace_back((unique_ptr<Base>)new Block());

	//UI作成
	base.emplace_back((unique_ptr<Base>)new UI());

	GetMap(map);
	for (int y = 0; y < MAP_SIZE_Y; y++)
	{
		for (int x = 0; x < MAP_SIZE_X; x++)
		{
			switch (map[y][x])
			{
			case 0:
				break;
			case 1:
				break;
			case 2:
				base.emplace_back((unique_ptr<Base>)new Itembox(x * IMGSIZE64, y * IMGSIZE64));
				break;
			case 3:
				break;
			}
		}
	}

	

	//bace.emplace_back((unique_ptr<Bace>)new Cursor(128.0f, 192.0f));

	int scene = GAME;
	
	//機体選択画面
	while (scene == SELECT)
	{
		ClearDrawScreen();//画面クリア

		for (auto i = base.begin(); i != base.end(); i++)
		{
			if ((*i)->status.ID == 1)
			{
				(*i)->Action(base);//各オブジェクトの処理
				(*i)->Draw();//各オブジェクトの処理
			}
		}

		//ESC終了処理
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			scene = -1;
		}


		ScreenFlip();//画面更新
	}

	//メインループ
	while (scene == GAME) {
		ClearDrawScreen();//画面クリア

			//ソート
		Pr pr;
		if (base.size() >= 2)
			base.sort(pr);//リストのソートメソッドの引数にソート条件クラスを入れる

		for (auto i = base.begin(); i != base.end(); i++)
		{
			if (vic == false)
				(*i)->Action(base);//各オブジェクトの処理
			(*i)->Draw();//各オブジェクトの処理

			if ((*i)->status.WIN_ID >= 0 && (*i)->status.ID != BULLET)
			{
				if (((Player*)(*i).get())->kill >= 10)
				{
					vic = true;
					vic_p = (*i)->status.WIN_ID;
				}
			}
		}
		if (vic == true)
		{
			DrawFormatString(WINDOW_WIDTH / 2 - IMGSIZE64 - IMGSIZE64 / 2, WINDOW_HEIGHT / 2, GetColor(255, 255, 255), "%dP WIN", vic_p);
		}
		for (auto i = base.begin(); i != base.end(); i++)
		{
			//リストから不要オブジェクトを削除（弾）
			if ((*i)->status.FLAG == false) {
				i = base.erase(i);
				break;
				DeleteGraph((*i)->status.img, 0);
			}
		}
		
		

		//ESC終了処理
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			scene = -1;
		}

		ScreenFlip();//画面更新
		//例外処理
		if ((ProcessMessage() == -1)) break;
	}

	DxLib_End();

	return 0;
}