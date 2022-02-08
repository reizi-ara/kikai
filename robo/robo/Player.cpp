#pragma once
#include "char.h"

#define PI  3.1415926535897932384626433832795f


//コンストラクタ
Player::Player(float _x, float _y,int type_num,int pilot,int player_num, int window_num, Point Pos)
{
	//画像ロード-------------------------------------------------------------
	switch (type_num)
	{
	case SPEED_PLAYER:
		img_player[0] = LoadGraph("image\\Cube_Speed.png");
		img_player[1] = LoadGraph("image\\Cube_Speed_LEFT.png");
		img_player[2] = LoadGraph("image\\Cube_Speed_BACK.png");
		img_player[3] = LoadGraph("image\\Cube_Speed_RIGHT.png");
		break;
	case DEFFENSE_PLAYER:
		img_player[0] = LoadGraph("image\\Cube_Deffense.png");
		img_player[1] = LoadGraph("image\\Cube_Deffense_LEFT.png");
		img_player[2] = LoadGraph("image\\Cube_Deffense_BACK.png");
		img_player[3] = LoadGraph("image\\Cube_Deffense_RIGHT.png");
		break;
	case TRAP_PLAYER:
		img_player[0] = LoadGraph("image\\Cube_Trap.png");
		img_player[1] = LoadGraph("image\\Cube_Trap_LEFT.png");
		img_player[2] = LoadGraph("image\\Cube_Trap_BACK.png");
		img_player[3] = LoadGraph("image\\Cube_Trap_RIGHT.png");
		break;
	case ATTACK_PLAYER:
		img_player[0] = LoadGraph("image\\Cube_Attack.png");
		img_player[1] = LoadGraph("image\\Cube_Attack_LEFT.png");
		img_player[2] = LoadGraph("image\\Cube_Attack_BACK.png");
		img_player[3] = LoadGraph("image\\Cube_Attack_RIGHT.png");
		break;
	}

	status.img= LoadGraph("image\\square64.png");
	img = LoadGraph("image\\UI\\katana.png");
	w_img = LoadGraph("image\\bakuhatsu.png");

	//----------------------------------------------------------------------

	

	//キャラクター初期化--------------------------------------------------------------
	status.pos.x = Pos.x;
	status.pos.y = Pos.y;

	status.WIN_ID = window_num;

	for (int i = 0; i < 4; i++)
	{
		switch (type_num)
		{
		case SPEED_PLAYER:
			status.p_img[i] = img_player[i];
			break;
		case DEFFENSE_PLAYER:
			status.p_img[i] = img_player[i];
			break;
		case TRAP_PLAYER:
			status.p_img[i] = img_player[i];
			break;
		case ATTACK_PLAYER:
			status.p_img[i] = img_player[i];
			break;
		}
	}

	status.ID = type_num;
	status.Pilot = pilot;
	status.P_ID = player_num;

	status.hp = 0;
	status.sp = default_SP;
	status.f_atk = default_F_ATK;
	status.s_atk = default_S_ATK;
	status.def = default_DEF;
	status.skill_cooldown = 0;
	status.speed.x = default_SPD_X;
	status.speed.y = default_SPD_Y;
	
	SetMachine(&status, type_num, pilot);//機体情報、パイロット情報挿入

	

	
	//-------------------------------------------------------------------------------

	//描画順番号
	pri = 990;
}

//処理実行
int Player::Action(list<unique_ptr<Base>>& base)
{
	//再生成フラグがtrueの時
	if (r_flag == true)
	{
		r_time++;
		//HPを増やして再生成する
		if (status.hp < 400)
		{
			status.hp += 4;
		}
		//HPが200を超えると位置を初期化し、再生成する。
		if (status.hp >= 200)
		{
			p_flag = true;

			switch (status.WIN_ID)
			{
			case P1:
				status.pos.x = IMGSIZE64 * 2;
				status.pos.y = IMGSIZE64 * 2;
				break;
			case P2:
				status.pos.x = MAP_SIZE_X * IMGSIZE64 - IMGSIZE64 * 3;
				status.pos.y = IMGSIZE64 * 2;
				break;
			case P3:
				status.pos.x = IMGSIZE64 * 2;
				status.pos.y = (MAP_SIZE_Y * IMGSIZE64) - IMGSIZE64 * 3;
				break;
			case P4:
				status.pos.x = MAP_SIZE_X * IMGSIZE64 - IMGSIZE64 * 3;
				status.pos.y = (MAP_SIZE_Y * IMGSIZE64) - IMGSIZE64 * 3;
				break;
			}

			BulletSave_vx = 0;
			BulletSave_vy = 0;

			wepon_cd = 0;
			status.wepon_num = -1;
			img_Vec = 0;
			status.skill_cooldown = 0;
		}

		//三秒後、再戦
		if (r_time >= TIME1*3)
		{
			r_flag = false;
			r_time = 0;
		}
	}
	//通常時
	else
	{
		//移動処理----------------------------------------------------
		static int vx, vy;

		//コントローラースティック情報取得
		GetJoypadAnalogInput(&vx, &vy, (Con[status.WIN_ID]));

		//位置の更新
		if (vx > 0)
		{
			status.pos.x += status.speed.x;
		}
		if (vx < 0)
		{
			status.pos.x -= status.speed.x;
		}
		if (vy > 0)
		{
			status.pos.y += status.speed.y;
		}
		if (vy < 0)
		{
			status.pos.y -= status.speed.y;
		}

		//画像用の保存変数
		if (vx != 0 || vy != 0)
		{
			rotate_vx = vx;
			rotate_vy = vy;
		}

		//弾用の保存変数
		if (vx != 0 || vy != 0)
		{
			BulletSave_vx = vx / 250.0f;
			BulletSave_vy = vy / 250.0f;
		}

		//描画　右
		if (rotate_vx > 0)
		{
			img_Vec = 3;
		}
		//描画　左
		if (rotate_vx < 0)
		{
			img_Vec = 1;
		}
		//描画　下
		if (rotate_vy > 0)
		{
			img_Vec = 0;
		}
		//描画　上
		if (rotate_vy < 0)
		{
			img_Vec = 2;
		}

		//------------------------------------------------------------------------------

		//スキル処理--------------------------------------------------------------------

		//スキルゲ－ジが溜まっていないとき
		if (status.skill_cooldown < 400 && (status.ID == TRAP_PLAYER || status.ID == ATTACK_PLAYER))
		{
			status.skill_cooldown++;
		}
		//スキルゲージが溜まっている時
		if (status.skill_cooldown == 400)
		{
			//砲撃型
			if (status.ID == ATTACK_PLAYER)
			{
				//Yボタンを押すとスキル発動
				if ((GetJoypadInputState(Con[status.WIN_ID]) & PAD_INPUT_X) != 0)
				{
					//砲弾生成
					base.emplace_back((unique_ptr<Base>)new Bullet(BulletSave_vx, BulletSave_vy, status.pos.x + IMGSIZE64 / 2 + bullet.x, status.pos.y + IMGSIZE64 / 2 + bullet.y, status.WIN_ID, IMGSIZE64,status.s_atk));
					//スキルゲージ初期化
					status.skill_cooldown = 0;
				}
			}
			//トラップ型
			if (status.ID == TRAP_PLAYER)
			{
				//Yボタンを押すとスキル発動
				if ((GetJoypadInputState(Con[status.WIN_ID]) & PAD_INPUT_X) != 0)
				{
					//トラップ生成
					base.emplace_back((unique_ptr<Base>)new Trap(BulletSave_vx, BulletSave_vy, status.pos.x , status.pos.y, status.WIN_ID, IMGSIZE64));
					//スキルゲージ初期化
					status.skill_cooldown = 0;
				}
			}
		}
		
		//メカニック型処理
		if (status.Pilot == MECHANIC)
		{
			ME_count++;
			if (ME_count > TIME1)//HPを一秒に5回復
			{
				ME_count = 0;
				if (status.hp <= default_HP - 5)
				{
					status.hp += 5;
				}
			}
		}

		//---------------------------------------------------------------------------------------------
		//アイテムボックス取得処理
		for (auto i = base.begin(); i != base.end(); i++)
		{
			if ((*i)->status.ID == ITEMBOX) {
				//アイテムボックスとの当たり判定
				Item = ((Itembox*)(*i).get())->status.pos;
				if (Item.x < status.pos.x + 64 && Item.x + 64 > status.pos.x && Item.y < status.pos.y + 64 && Item.y + 64 > status.pos.y)
				{
					//武器取得フラグtrue
					if (status.wepon_num == -1)
						weponget_flag = true;
				}
			}
		}
		//武器取得
		if (weponget_flag == true) {
			//ランダム（仮）で武器取得
			status.wepon_num = rand() % 2;
			ShotFlag = true;
			weponget_flag = false;
		}

		//ライフル処理
		if (status.wepon_num == 0)
		{	
			//Bボタンで弾丸発射
			if ((GetJoypadInputState(Con[status.WIN_ID]) & PAD_INPUT_B) == 0 && wepon_cd == 0)
			{
				ShotFlag = true;
			}
			else
			{
				//ライフル射撃フラグ
				if (ShotFlag == true && wepon_cd == 0)
				{
					ShotFlag = false;
				}
			}
			if (ShotFlag == false)
			{
				//wepon_cdが20ごとに一発弾丸を発射する。
				wepon_cd++;
				if (wepon_cd % 20 == 0)
				{
					//ブロックに接触していると弾を発射できないため解決用（仮）
					if (h_player.LEFT == true)
					{
						bullet.x = IMGSIZE64 / 8;
					}
					if (h_player.RIGHT == true)
					{
						bullet.x = -IMGSIZE64 / 4;
					}
					if (h_player.DOWN == true)
					{
						bullet.y = -IMGSIZE64 / 2;
					}
					if (h_player.UP == true)
					{
						bullet.y = IMGSIZE64 / 8;
					}
					//弾丸生成
					base.emplace_back((unique_ptr<Base>)new Bullet(BulletSave_vx, BulletSave_vy, status.pos.x + IMGSIZE64 / 2 + bullet.x, status.pos.y + IMGSIZE64 / 2 + bullet.y, status.WIN_ID, IMGSIZE64 / 4,status.s_atk));
				}
				//三発射撃したらアイテムを初期化
				if (wepon_cd > 60)
				{
					wepon_cd = 0;
					status.wepon_num = -1;
				}
			}
		}
		//剣処理
		if (status.wepon_num == 1)
		{
			//Bボタンで剣生成
			if ((GetJoypadInputState(Con[status.WIN_ID]) & PAD_INPUT_B) == 0 && wepon_cd == 0)
			{
				ShotFlag = true;
			}
			else
			{
				//剣生成フラグ
				if (ShotFlag == true && wepon_cd == 0)
				{
					ShotFlag = false;
				}
			}
			if (ShotFlag == false)
			{
				//武器関数で剣を生成する
				wepon_summary(base, status.pos, e_scroll, status.wepon_num, status.WIN_ID, img_Vec, &kill, status.f_atk);
				wepon_cd++;
				//当たり判定終了
				if (wepon_cd >= 20)
				{
					wepon_cd = 0;
					status.wepon_num = -1;
				}
			}
		}

		//HPが0になったら再生成フラグをONにする
		if (status.hp <= 0)
		{
			p_flag = false;
			r_flag = true;
		}
	}

	//剣の多重当たり判定を防ぐ処理
	if (S_Hit_flag == true)
	{
		S_Hit_count++;
		if (S_Hit_count >= 30)
		{
			S_Hit_flag = false;
			S_Hit_count = 0;
		}
	}

	GetScroll(&status.pos, &scroll, status.WIN_ID);				//スクロール情報取得
	BlockHit(&h_player, &status.pos, &status.speed, IMGSIZE64);	//ブロックとの当たり判定実行
	ScrollSet(e_scroll, e_pos, base);							//スクロール情報セッティング
	return 0;
}

// 描画関連処理
void Player::Draw() {

	//WINDOWごとの描画
	switch (status.WIN_ID)
	{
		//WINDOW 1
	case P1:
		//撃破されていない場合
		if (p_flag == true)
		{
			//通常時
			if (r_flag == false)
			{
				DrawGraph(status.pos.x - scroll.x, status.pos.y - scroll.y, status.p_img[img_Vec], TRUE);
				DrawFormatString(status.pos.x - scroll.x, status.pos.y - scroll.y - IMGSIZE64 / 2, GetColor(255, 255, 255), "↓%dP", status.WIN_ID + 1);
			}
			//再生成中
			else
				DrawGraph(status.pos.x - scroll.x, status.pos.y - scroll.y, status.img, TRUE);
			//剣の描画
			if (status.wepon_num == 1 && ShotFlag == false)
			{
				//向きによって描画場所を修正
				switch (img_Vec)
				{
					//下
				case 0:
					DrawRotaGraph(status.pos.x - scroll.x + IMGSIZE64 / 2, status.pos.y - scroll.y + IMGSIZE64 + IMGSIZE64 / 2, 1, PI / 2, img, TRUE, FALSE, FALSE);
					break;
					//左
				case 1:
					DrawRotaGraph(status.pos.x - scroll.x - IMGSIZE64 + IMGSIZE64 / 2, status.pos.y - scroll.y + IMGSIZE64 - IMGSIZE64 / 2, 1, PI, img, TRUE, FALSE, FALSE);
					break;
					//上
				case 2:
					DrawRotaGraph(status.pos.x - scroll.x + IMGSIZE64 / 2, status.pos.y - scroll.y + IMGSIZE64 - IMGSIZE64 - IMGSIZE64 / 2, 1, -PI / 2, img, TRUE, FALSE, FALSE);
					break;
					//右
				case 3:
					DrawRotaGraph(status.pos.x - scroll.x + IMGSIZE64 + IMGSIZE64 / 2, status.pos.y - scroll.y + IMGSIZE64 - IMGSIZE64 / 2, 1, 0, img, TRUE, FALSE, FALSE);
					break;
				}
			}
		}
		else
		{
			//撃破画像描画
			DrawGraph(status.pos.x - scroll.x, status.pos.y - scroll.y, w_img, TRUE);
		}
		break;
		//WINDOW 2
	case P2:
		//撃破されていない場合
		if (p_flag == true) 
		{
			//通常時
			if (r_flag == false)
			{
				DrawGraph(status.pos.x - scroll.x + 992.0f, status.pos.y - scroll.y, status.p_img[img_Vec], TRUE);
				DrawFormatString(status.pos.x - scroll.x + 992.0f, status.pos.y - scroll.y - IMGSIZE64 / 2, GetColor(255, 255, 255), "↓%dP", status.WIN_ID + 1);
			}
			//再生成中
			else
				DrawGraph(status.pos.x - scroll.x + 992.0f, status.pos.y - scroll.y, status.img, TRUE);
			//剣の描画
			if (status.wepon_num == 1 && ShotFlag == false)
			{
				//向きによって描画場所を修正
				switch (img_Vec)
				{
					//下
				case 0:
					DrawRotaGraph(status.pos.x + 992.0f - scroll.x + IMGSIZE64 / 2, status.pos.y - scroll.y + IMGSIZE64 + IMGSIZE64 / 2, 1, PI / 2, img, TRUE, FALSE, FALSE);
					break;
					//左
				case 1:
					DrawRotaGraph(status.pos.x + 992.0f - scroll.x - IMGSIZE64 + IMGSIZE64 / 2, status.pos.y - scroll.y + IMGSIZE64 - IMGSIZE64 / 2, 1, PI, img, TRUE, FALSE, FALSE);
					break;
					//上
				case 2:
					DrawRotaGraph(status.pos.x + 992.0f - scroll.x + IMGSIZE64 / 2, status.pos.y - scroll.y + IMGSIZE64 - IMGSIZE64 - IMGSIZE64 / 2, 1, -PI / 2, img, TRUE, FALSE, FALSE);
					break;
					//右
				case 3:
					DrawRotaGraph(status.pos.x + 992.0f - scroll.x + IMGSIZE64 + IMGSIZE64 / 2, status.pos.y - scroll.y + IMGSIZE64 - IMGSIZE64 / 2, 1, 0, img, TRUE, FALSE, FALSE);
					break;
				}
			}
		}
		else
		{
			//撃破画像描画
			DrawGraph(status.pos.x - scroll.x + 992.0f, status.pos.y - scroll.y, w_img, TRUE);
		}
		break;
		//WINDOW 3
	case P3:
		//撃破されていない場合
		if (p_flag == true)
		{
			//通常時
			if (r_flag == false)
			{
				DrawGraph(status.pos.x - scroll.x, status.pos.y + 572.0f - scroll.y, status.p_img[img_Vec], TRUE);
				DrawFormatString(status.pos.x - scroll.x, status.pos.y + 572.0f - scroll.y - IMGSIZE64 / 2, GetColor(255, 255, 255), "↓%dP", status.WIN_ID + 1);
			}
				
			//再生成中
			else
				DrawGraph(status.pos.x - scroll.x, status.pos.y + 572.0f - scroll.y, status.img, TRUE);
			//剣の描画
			if (status.wepon_num == 1 && ShotFlag == false)
			{
				//向きによって描画場所を修正
				switch (img_Vec)
				{
					//下
				case 0:
					DrawRotaGraph(status.pos.x - scroll.x + IMGSIZE64 / 2, status.pos.y + 572.0f - scroll.y + IMGSIZE64 + IMGSIZE64 / 2, 1, PI / 2, img, TRUE, FALSE, FALSE);
					break;
					//左
				case 1:
					DrawRotaGraph(status.pos.x - scroll.x - IMGSIZE64 + IMGSIZE64 / 2, status.pos.y + 572.0f - scroll.y + IMGSIZE64 - IMGSIZE64 / 2, 1, PI, img, TRUE, FALSE, FALSE);
					break;
					//上
				case 2:
					DrawRotaGraph(status.pos.x - scroll.x + IMGSIZE64 / 2, status.pos.y + 572.0f - scroll.y + IMGSIZE64 - IMGSIZE64 - IMGSIZE64 / 2, 1, -PI / 2, img, TRUE, FALSE, FALSE);
					break;
					//右
				case 3:
					DrawRotaGraph(status.pos.x - scroll.x + IMGSIZE64 + IMGSIZE64 / 2, status.pos.y + 572.0f - scroll.y + IMGSIZE64 - IMGSIZE64 / 2, 1, 0, img, TRUE, FALSE, FALSE);
					break;
				}
			}
		}
		else
		{
			//撃破画像描画
			DrawGraph(status.pos.x - scroll.x, status.pos.y - scroll.y + 572.0f, w_img, TRUE);
		}
		break;
		//WINDOW 4
	case P4:
		//撃破されていない場合
		if (p_flag == true)
		{
			//通常時
			if (r_flag == false)
			{
				DrawGraph(status.pos.x + 992.0f - scroll.x, status.pos.y + 572.0f - scroll.y, status.p_img[img_Vec], TRUE);
				DrawFormatString(status.pos.x + 992.0f - scroll.x, status.pos.y + 572.0f - scroll.y - IMGSIZE64 / 2, GetColor(255, 255, 255), "↓%dP", status.WIN_ID + 1);
			}
			//再生成中
			else
				DrawGraph(status.pos.x + 992.0f - scroll.x, status.pos.y + 572.0f - scroll.y, status.img, TRUE);
			//剣の描画
			if (status.wepon_num == 1 && ShotFlag == false)
			{
				//向きによって描画場所を修正
				switch (img_Vec)
				{
					//下
				case 0:
					DrawRotaGraph(status.pos.x + 992.0f - scroll.x + IMGSIZE64 / 2, status.pos.y + 572.0f - scroll.y + IMGSIZE64 + IMGSIZE64 / 2, 1, PI / 2, img, TRUE, FALSE, FALSE);
					break;
					//左
				case 1:
					DrawRotaGraph(status.pos.x + 992.0f - scroll.x - IMGSIZE64 + IMGSIZE64 / 2, status.pos.y + 572.0f - scroll.y + IMGSIZE64 - IMGSIZE64 / 2, 1, PI, img, TRUE, FALSE, FALSE);
					break;
					//上
				case 2:
					DrawRotaGraph(status.pos.x + 992.0f - scroll.x + IMGSIZE64 / 2, status.pos.y + 572.0f - scroll.y + IMGSIZE64 - IMGSIZE64 - IMGSIZE64 / 2, 1, -PI/2, img, TRUE, FALSE, FALSE);
					break;
					//右
				case 3:
					DrawRotaGraph(status.pos.x + 992.0f - scroll.x + IMGSIZE64 + IMGSIZE64 / 2,  status.pos.y + 572.0f - scroll.y + IMGSIZE64 - IMGSIZE64 / 2, 1, 0, img, TRUE, FALSE, FALSE);
					break;
				}
			}
		}
		else
		{
			//撃破画像描画
			DrawGraph(status.pos.x - scroll.x + 992.0f, status.pos.y - scroll.y + 572.0f, w_img, TRUE);
		}
		break;
	}	

	
}