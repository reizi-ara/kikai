#pragma once
#include "char.h"

//コンストラクタ
UI::UI()
{
	status.img = LoadGraph("image\\UI\\UI.png");

	//描画順番号
	pri = 999;
}

//処理実行
int UI::Action(list<unique_ptr<Base>>& base)
{
	//プレイヤーごとのステータス情報を取得
	for (auto i = base.begin(); i != base.end(); i++)
	{
		if ((*i)->status.WIN_ID >= 0 && (*i)->status.ID != BULLET)
		{
			switch ((*i)->status.WIN_ID)
			{
				//WINDOW 1
			case P1:
				HP[P1] = (*i)->status.hp;
				WEPON[P1] = (*i)->status.wepon_num;
				Skill[P1] = (*i)->status.skill_cooldown;
				Kill[P1] = ((Player*)(*i).get())->kill;
				break;
				//WINDOW 2
			case P2:
				HP[P2] = (*i)->status.hp;
				WEPON[P2] = (*i)->status.wepon_num;
				Skill[P2] = (*i)->status.skill_cooldown;
				Kill[P2] = ((Player*)(*i).get())->kill;
				break;
				//WINDOW 3
			case P3:
				HP[P3] = (*i)->status.hp;
				WEPON[P3] = (*i)->status.wepon_num;
				Skill[P3] = (*i)->status.skill_cooldown;
				Kill[P3] = ((Player*)(*i).get())->kill;
				break;
				//WINDOW 4
			case P4:
				HP[P4] = (*i)->status.hp;
				WEPON[P4] = (*i)->status.wepon_num;
				Skill[P4] = (*i)->status.skill_cooldown;
				Kill[P4] = ((Player*)(*i).get())->kill;
				break;
			}
		}
	}
	return 0;
}

//描画関連処理
void UI::Draw() 
{
	//（Blockめり込み対策）UI表示
	DrawGraph(0, 0, status.img, TRUE);
	
	//WINDOWごとのUI描画
	for (int z = 0; z < 4; z++)
	{
		switch (z)
		{
		case P1:
			DrawGraph(928 - IMGSIZE64 * 2, 0, img_Item_UI, TRUE);	//アイテム表示場所UI
			DrawGraph(0, 0, img_HP_UI, TRUE);						//HP表示場所UI
			DrawGraph(0, 508 - IMGSIZE64, img_Skill_UI, TRUE);		//スキルゲージ表示場所UI
			//HP描画処理
			for (int i = 1; i < HP[P1] / 4; i++)
			{
				DrawGraph(2 + i * 4-4, 0 + 1, img_HP, TRUE);//HP量に合わせて描画
			}
			//スキルゲージ描画処理
			for (int i = 1; i <= Skill[P1] / 25; i++)
			{
				DrawGraph(0, 508 - i * 4, img_Skill, TRUE);//スキルゲージ量に合わせて描画
			}
			SetFontSize(16);
			//スキル準備完了
			if (Skill[P1] == 400)
			{
				DrawFormatString(0, 508 - 32, GetColor(255, 255, 255), "準備完了");
			}
			
			//所持武器UI描画
			switch (WEPON[P1])
			{
				//ライフル
			case 0:
				DrawGraph(928  - IMGSIZE64 * 2, 0, img_rifle, TRUE);
				//ライフル文字表示
				DrawFormatString(928 + IMGSIZE64 / 2 - IMGSIZE64 * 2, 0 + IMGSIZE64 + IMGSIZE64, GetColor(255, 255, 255), "ライフル");
				break;
				
				//剣
			case 1:
				DrawGraph(928  - IMGSIZE64 * 2, 0, img_katana, TRUE);
				//剣文字表示
				DrawFormatString(928 + IMGSIZE64 / 2 - IMGSIZE64 * 2, 0 + IMGSIZE64 + IMGSIZE64, GetColor(255, 255, 255), "カタナ");
				break;
			}
			SetFontSize(32);
			DrawFormatString(0 + IMGSIZE64*2, 508, GetColor(0, 0, 0), "↑　撃破数：%d", Kill[P1]);//キル数表示
			break;
		case P2:
			DrawGraph(WINDOW_WIDTH - IMGSIZE64*2, 0, img_Item_UI, TRUE);				//アイテム表示場所UI
			DrawGraph(928 + IMGSIZE64, 0, img_HP_UI, TRUE);								//HP表示場所UI
			DrawGraph(WINDOW_WIDTH - IMGSIZE64, 508 - IMGSIZE64, img_Skill_UI, TRUE);	//スキルゲージ表示場所UI
			
			SetFontSize(16);
			//HP描画処理
			for (int i = 1; i < HP[P2] / 4; i++)
			{
				DrawGraph(928 + 2 + IMGSIZE64 + i * 4, 0 + 1, img_HP, TRUE);//HP量に合わせて描画
			}
			//スキルゲージ描画処理
			for (int i = 1; i <= Skill[P2] / 25; i++)
			{
				DrawGraph(WINDOW_WIDTH - IMGSIZE64, 508 - i * 4 - 4, img_Skill, TRUE);//スキルゲージ量に合わせて描画
			}
			//スキル準備完了
			if (Skill[P2] == 400)
			{
				DrawFormatString(WINDOW_WIDTH - IMGSIZE64, 508 - 32, GetColor(255, 255, 255), "準備完了");
			}
			//所持武器UI描画
			switch (WEPON[P2])
			{
			case 0:
				//ライフル
				DrawGraph(WINDOW_WIDTH - IMGSIZE64 * 2, 0, img_rifle, TRUE);
				//ライフル文字表示
				DrawFormatString(WINDOW_WIDTH + IMGSIZE64 / 2 - IMGSIZE64 * 2, 0 + IMGSIZE64 + IMGSIZE64, GetColor(255, 255, 255), "ライフル");
				break;
			case 1:
				//剣
				DrawGraph(WINDOW_WIDTH  - IMGSIZE64 * 2, 0, img_katana, TRUE);
				//剣文字表示
				DrawFormatString(WINDOW_WIDTH + IMGSIZE64 / 2 - IMGSIZE64 * 2, 0 + IMGSIZE64 + IMGSIZE64, GetColor(255, 255, 255), "カタナ");
				break;
			}
			SetFontSize(32);
			DrawFormatString(908 + IMGSIZE64 + IMGSIZE64 * 4, 508, GetColor(0, 0, 0), "↑　撃破数：%d", Kill[P2]);//キル数表示
			break;
		case P3:
			DrawGraph(928 - IMGSIZE64 * 2, 508 + IMGSIZE64, img_Item_UI, TRUE);	//アイテム表示場所UI
			DrawGraph(0, 508 + IMGSIZE64, img_HP_UI, TRUE);						//HP表示場所UI
			DrawGraph(0, WINDOW_HEIGHT - IMGSIZE64, img_Skill_UI, TRUE);		//スキルゲージ表示場所UI
			SetFontSize(16);
			//HP描画処理
			for (int i = 1; i < HP[P3] / 4; i++)
			{
				DrawGraph(2 + i * 4-4, 508 + IMGSIZE64 + 1, img_HP, TRUE);//HP量に合わせて描画
			}
			//スキルゲージ描画処理
			for (int i = 1; i <= Skill[P3] / 25; i++)
			{
				DrawGraph(0, WINDOW_HEIGHT - i * 4, img_Skill, TRUE);//スキルゲージ量に合わせて描画
			}
			//スキル準備完了
			if (Skill[P3] == 400)
			{
				DrawFormatString(0, WINDOW_HEIGHT - 32, GetColor(255, 255, 255), "準備完了");
			}
			//所持武器UI描画
			switch (WEPON[P3])
			{
				//ライフル
			case 0:
				DrawGraph(928 - IMGSIZE64 * 2, 508 + IMGSIZE64 , img_rifle, TRUE);
				//ライフル文字表示
				DrawFormatString(928 + IMGSIZE64 / 2 - IMGSIZE64 * 2, 508 + IMGSIZE64 + IMGSIZE64 + IMGSIZE64, GetColor(255, 255, 255), "ライフル");
				break;
				//剣
			case 1:
				DrawGraph(928 - IMGSIZE64 * 2, 508 + IMGSIZE64, img_katana, TRUE);
				//剣文字表示
				DrawFormatString(928 + IMGSIZE64 / 2 - IMGSIZE64 * 2, 508 + IMGSIZE64 + IMGSIZE64 + IMGSIZE64, GetColor(255, 255, 255), "カタナ");
				break;
			}
			SetFontSize(32);
			DrawFormatString(0 + IMGSIZE64*2, 508 + 32, GetColor(0, 0, 0), "↓　撃破数：%d", Kill[P3]);//キル数表示
			break;
		case P4:
			DrawGraph(WINDOW_WIDTH - IMGSIZE64*2, 508 + IMGSIZE64, img_Item_UI, TRUE);			//アイテム表示場所UI
			DrawGraph(928 + IMGSIZE64, 508 + IMGSIZE64, img_HP_UI, TRUE);						//HP表示場所UI
			DrawGraph(WINDOW_WIDTH - IMGSIZE64, WINDOW_HEIGHT - IMGSIZE64, img_Skill_UI, TRUE);	//スキルゲージ表示場所UI
			SetFontSize(16);
			//HP描画処理
			for (int i = 1; i < HP[P4] / 4; i++)
			{
				DrawGraph(2 + 928 + IMGSIZE64 + i * 4, 508 + IMGSIZE64 + 1, img_HP, TRUE);//HP量に合わせて描画
			}
			//スキルゲージ描画処理
			for (int i = 1; i <= Skill[P4] / 25; i++)
			{
				DrawGraph(WINDOW_WIDTH - IMGSIZE64, WINDOW_HEIGHT - i * 4 - 4, img_Skill, TRUE);//スキルゲージ量に合わせて描画
			}
			//スキル準備完了
			if (Skill[P4] == 400)
			{
				DrawFormatString(WINDOW_WIDTH - IMGSIZE64, WINDOW_HEIGHT - 32, GetColor(255, 255, 255), "準備完了");
			}

			//所持武器UI描画
			switch (WEPON[P4])
			{
				//ライフル
			case 0:
				DrawGraph(WINDOW_WIDTH  - IMGSIZE64 * 2, 508 + IMGSIZE64, img_rifle, TRUE);
				//ライフル文字表示
				DrawFormatString(WINDOW_WIDTH + IMGSIZE64 / 2 - IMGSIZE64 * 2, 508 + IMGSIZE64 + IMGSIZE64 + IMGSIZE64, GetColor(255, 255, 255), "ライフル");
				break;
				//剣
			case 1:
				DrawGraph(WINDOW_WIDTH - IMGSIZE64 * 2, 508 + IMGSIZE64, img_katana, TRUE);
				//剣文字表示
				DrawFormatString(WINDOW_WIDTH + IMGSIZE64 / 2 - IMGSIZE64 * 2, 508 + IMGSIZE64 + IMGSIZE64 + IMGSIZE64, GetColor(255, 255, 255), "カタナ");
				break;
			}
			SetFontSize(32);
			DrawFormatString(908 + IMGSIZE64 + IMGSIZE64 * 4, 508+32, GetColor(0, 0, 0), "↓　撃破数：%d", Kill[P4]);//キル数表示
			break;
		}
		
	}
	SetFontSize(32);
	DrawFormatString(WINDOW_WIDTH / 2 - IMGSIZE64 * 3, 508 + IMGSIZE64 / 4, GetColor(0, 0, 0), "10体倒したら勝利！");
}