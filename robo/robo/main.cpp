#pragma once
#include "main.h"
#include "char.h"

//リスト
list<unique_ptr<Bace>> bace;



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

	//bace.emplace_back((unique_ptr<Bace>)new Cursor(128.0f, 192.0f));

	int scene = GAME;
	
	//機体選択画面
	while (scene == SELECT)
	{
		ClearDrawScreen();//画面クリア

		
		for (auto i = bace.begin(); i != bace.end(); i++)
		{
			if ((*i)->Charcter.ID == 1)
			{
				(*i)->Action(bace);//各オブジェクトの処理
			}
		}
		for (auto i = bace.begin(); i != bace.end(); i++)
		{
			if ((*i)->Charcter.ID == 1)
			{
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
			if ((*i)->Charcter.FLAG == false) {
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