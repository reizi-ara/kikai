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

	//メインループ
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
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

		ScreenFlip();//画面更新
		//例外処理
		if ((ProcessMessage() == -1)) break;
	}

	DxLib_End();

	return 0;
}