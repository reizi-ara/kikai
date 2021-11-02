#pragma once
#include "main.h"
#include "char.h"

//リスト
list<unique_ptr<Bace>> bace;

unsigned char scene = SELECT;

//クライアント用プログラム(TCP/IP)
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE,
	_In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
	//windowモード切替
	ChangeWindowMode(TRUE);
	//windowサイズ
	SetGraphMode(800, 600, 32);

	//Dxライブラリの初期化
	if (DxLib_Init() == -1)return -1;

	//windowの名前
	SetWindowText("リストサンプル");

	//バックバッファを使用
	SetDrawScreen(DX_SCREEN_BACK);

	//リストオブジェクトを生成
	auto P = (unique_ptr<Bace>)new Player(0.0f, 0.0f);
	bace.emplace_back(move(P));

	bace.emplace_back((unique_ptr<Bace>)new SelectCursor(128.0f, 192.0f));
	
	//機体選択画面
	while (scene == SELECT)
	{
		ClearDrawScreen();//画面クリア

		
		for (auto i = bace.begin(); i != bace.end(); i++)
		{
			if ((*i)->ID == 1)
			{
				(*i)->Action(bace);//各オブジェクトの処理
			}
		}
		for (auto i = bace.begin(); i != bace.end(); i++)
		{
			if ((*i)->ID == 1)
			{
				(*i)->Draw();//各オブジェクトの処理
			}
		}

		if (CheckHitKey(KEY_INPUT_RETURN))
		{
			for (auto i = bace.begin(); i != bace.end(); i++)
			{
				if ((*i)->ID == 1)
				{
					if (((SelectCursor*)(*i).get())->select_type == 1)
					{
						auto Attack = (unique_ptr<Bace>)new attacktype(0.0f, 0.0f);
						bace.emplace_back(move(Attack));
					}
					else if (((SelectCursor*)(*i).get())->select_type == 2)
					{
						auto Speed = (unique_ptr<Bace>)new speedtype(0.0f, 0.0f);
						bace.emplace_back(move(Speed));
					}
					else if (((SelectCursor*)(*i).get())->select_type == 3)
					{
						auto Shield = (unique_ptr<Bace>)new shieldtype(0.0f, 0.0f);
						bace.emplace_back(move(Shield));
					}
					else if (((SelectCursor*)(*i).get())->select_type == 4)
					{
						auto Trap = (unique_ptr<Bace>)new traptype(0.0f, 0.0f);
						bace.emplace_back(move(Trap));
					}
				}
			}

			scene = GAME;
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


		//リストのメソッドを実行
		for (auto i = bace.begin(); i != bace.end(); i++)
		{
			(*i)->Action(bace);//各オブジェクトの処理
		}
		for (auto i = bace.begin(); i != bace.end(); i++)
		{
			(*i)->Draw();//各オブジェクトの処理
		}

		//リストから不要オブジェクトを削除（弾）
		for (auto i = bace.begin(); i != bace.end(); i++) {
			if ((*i)->FLAG == false) {
				i = bace.erase(i);
				break;
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