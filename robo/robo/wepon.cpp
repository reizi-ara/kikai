#include"main.h"
#include"char.h"

//武器関数
void wepon_summary(list<unique_ptr<Base>>& base, Point p_pos, Vector scroll[4], int wepon_num, int WIN_ID, int img_Vec,int *kill)
{
	for (auto i = base.begin(); i != base.end(); i++)
	{	//リストからプレイヤーを探す。
		if ((*i)->status.WIN_ID >= 0 && (*i)->status.WIN_ID != WIN_ID && (*i)->status.ID != BULLET)
		{
			//プレイヤーの武器番号を見て、それに合わせた処理をする
			switch (wepon_num)
			{
				//剣処理---------------------------------------------------------------------
			case 1:
				switch ((*i)->status.WIN_ID)
				{
					//WINDOW 1
				case P1:
					switch (img_Vec)//プレイヤーも向き（img_Vec）に合わせた当たり判定を出す。
					{
						//下
					case 0:
						if (p_pos.x - scroll[P1].x < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
							p_pos.x + IMGSIZE64 - scroll[P1].x >(*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
							p_pos.y + IMGSIZE64 - scroll[P1].y  < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
							p_pos.y + IMGSIZE64 + IMGSIZE64 - scroll[P1].y >(*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
						{
							if ((*i)->status.WIN_ID == P1 && ((Player*)(*i).get())->r_flag == false)
							{
								//基本ダメージにステータス情報を入れ、ダメージを増減させる
								(*i)->status.hp -= 300.0f * (*i)->status.s_atk - (50.0f * (*i)->status.f_atk * (*i)->status.def);
								if ((*i)->status.hp <= 0)
								{
									*kill += 1;
								}
							}
						}
						break;
						//左
					case 1:
						if (p_pos.x - IMGSIZE64 - scroll[P1].x  < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
							p_pos.x + IMGSIZE64 - IMGSIZE64 - scroll[P1].x  >(*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
							p_pos.y - scroll[P1].y < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
							p_pos.y + IMGSIZE64 - scroll[P1].y >(*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
						{
							if ((*i)->status.WIN_ID == P1 && ((Player*)(*i).get())->r_flag == false)
							{
								//基本ダメージにステータス情報を入れ、ダメージを増減させる
								(*i)->status.hp -= 300.0f * (*i)->status.s_atk - (50.0f * (*i)->status.f_atk * (*i)->status.def);
								if ((*i)->status.hp <= 0)
								{
									*kill += 1;
								}
							}
						}
						break;
						//上
					case 2:
						if (p_pos.x - scroll[P1].x < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
							p_pos.x + IMGSIZE64 - scroll[P1].x >(*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
							p_pos.y - IMGSIZE64 - scroll[P1].y < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
							p_pos.y - IMGSIZE64 + IMGSIZE64 - scroll[P1].y >(*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
						{
							if ((*i)->status.WIN_ID == P1 && ((Player*)(*i).get())->r_flag == false)
							{
								//基本ダメージにステータス情報を入れ、ダメージを増減させる
								(*i)->status.hp -= 300.0f * (*i)->status.s_atk - (50.0f * (*i)->status.f_atk * (*i)->status.def);
								if ((*i)->status.hp <= 0)
								{
									*kill += 1;
								}
							}
						}
						break;
						//右
					case 3:
						if (p_pos.x + IMGSIZE64 - scroll[P1].x < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
							p_pos.x + IMGSIZE64 + IMGSIZE64 - scroll[P1].x  >(*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
							p_pos.y - scroll[P1].y < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
							p_pos.y + IMGSIZE64 - scroll[P1].y >(*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
						{
							if ((*i)->status.WIN_ID == P1 && ((Player*)(*i).get())->r_flag == false)
							{
								//基本ダメージにステータス情報を入れ、ダメージを増減させる
								(*i)->status.hp -= 300.0f * (*i)->status.s_atk - (50.0f * (*i)->status.f_atk * (*i)->status.def);
								if ((*i)->status.hp <= 0)
								{
									*kill += 1;
								}
							}
						}
						break;
					}
					break;
					//WINDOW 2
				case P2:
					switch (img_Vec)//プレイヤーも向き（img_Vec）に合わせた当たり判定を出す。
					{
						//下
					case 0:
						if (p_pos.x - scroll[P2].x < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
							p_pos.x + IMGSIZE64 - scroll[P2].x >(*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
							p_pos.y + IMGSIZE64 - scroll[P2].y  < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
							p_pos.y + IMGSIZE64 + IMGSIZE64 - scroll[P2].y >(*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
						{
							if ((*i)->status.WIN_ID == P2 && ((Player*)(*i).get())->r_flag == false)
							{
								//基本ダメージにステータス情報を入れ、ダメージを増減させる
								(*i)->status.hp -= 300.0f * (*i)->status.s_atk - (50.0f * (*i)->status.f_atk * (*i)->status.def);
								if ((*i)->status.hp <= 0)
								{
									*kill += 1;
								}
							}
						}
						break;
						//左
					case 1:
						if (p_pos.x - IMGSIZE64 - scroll[P2].x  < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
							p_pos.x + IMGSIZE64 - IMGSIZE64 - scroll[P2].x  >(*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
							p_pos.y - scroll[P2].y < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
							p_pos.y + IMGSIZE64 - scroll[P2].y >(*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
						{
							//基本ダメージにステータス情報を入れ、ダメージを増減させる
							if ((*i)->status.WIN_ID == P2&& ((Player*)(*i).get())->r_flag == false)
							{
								(*i)->status.hp -= 300.0f * (*i)->status.s_atk - (50.0f * (*i)->status.f_atk * (*i)->status.def);
								if ((*i)->status.hp <= 0)
								{
									*kill += 1;
								}
							}
						}
						break;
						//上
					case 2:
						if (p_pos.x - scroll[P2].x < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
							p_pos.x + IMGSIZE64 - scroll[P2].x >(*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
							p_pos.y - IMGSIZE64 - scroll[P2].y < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
							p_pos.y - IMGSIZE64 + IMGSIZE64 - scroll[P2].y >(*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
						{
							//基本ダメージにステータス情報を入れ、ダメージを増減させる
							if ((*i)->status.WIN_ID == P2 && ((Player*)(*i).get())->r_flag == false)
							{
								(*i)->status.hp -= 300.0f * (*i)->status.s_atk - (50.0f * (*i)->status.f_atk * (*i)->status.def);
								if ((*i)->status.hp <= 0)
								{
									*kill += 1;
									
								}
							}
						}
						break;
						//下
					case 3:
						if (p_pos.x + IMGSIZE64 - scroll[P2].x < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
							p_pos.x + IMGSIZE64 + IMGSIZE64 - scroll[P2].x  >(*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
							p_pos.y - scroll[P2].y < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
							p_pos.y + IMGSIZE64 - scroll[P2].y >(*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
						{
							//基本ダメージにステータス情報を入れ、ダメージを増減させる
							if ((*i)->status.WIN_ID == P2 && ((Player*)(*i).get())->r_flag == false)
							{
								(*i)->status.hp -= 300.0f * (*i)->status.s_atk - (50.0f * (*i)->status.f_atk * (*i)->status.def);
								if ((*i)->status.hp <= 0)
								{
									*kill += 1;
								}
							}
						}
						break;
					}
					break;
					//WINDOW 3
				case P3:
					switch (img_Vec)//プレイヤーも向き（img_Vec）に合わせた当たり判定を出す。
					{
						//下
					case 0:
						if (p_pos.x - scroll[P3].x < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
							p_pos.x + IMGSIZE64 - scroll[P3].x >(*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
							p_pos.y + IMGSIZE64 - scroll[P3].y  < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
							p_pos.y + IMGSIZE64 + IMGSIZE64 - scroll[P3].y >(*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
						{
							if ((*i)->status.WIN_ID == P3 && ((Player*)(*i).get())->r_flag == false)
							{
								//基本ダメージにステータス情報を入れ、ダメージを増減させる
								(*i)->status.hp -= 300.0f * (*i)->status.s_atk - (50.0f * (*i)->status.f_atk * (*i)->status.def);
								if ((*i)->status.hp <= 0)
								{
									*kill += 1;
								}
							}
						}
						break;
						//左
					case 1:
						if (p_pos.x - IMGSIZE64 - scroll[P3].x  < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
							p_pos.x + IMGSIZE64 - IMGSIZE64 - scroll[P3].x  >(*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
							p_pos.y - scroll[P3].y < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
							p_pos.y + IMGSIZE64 - scroll[P3].y >(*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
						{
							if ((*i)->status.WIN_ID == P3 && ((Player*)(*i).get())->r_flag == false)
							{
								//基本ダメージにステータス情報を入れ、ダメージを増減させる
								(*i)->status.hp -= 300.0f * (*i)->status.s_atk - (50.0f * (*i)->status.f_atk * (*i)->status.def);
								if ((*i)->status.hp <= 0)
								{
									*kill += 1;
								}
							}
						}
						break;
						//上
					case 2:
						if (p_pos.x - scroll[P3].x < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
							p_pos.x + IMGSIZE64 - scroll[P3].x >(*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
							p_pos.y - IMGSIZE64 - scroll[P3].y < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
							p_pos.y - IMGSIZE64 + IMGSIZE64 - scroll[P3].y >(*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
						{
							if ((*i)->status.WIN_ID == P3 && ((Player*)(*i).get())->r_flag == false)
							{
								//基本ダメージにステータス情報を入れ、ダメージを増減させる
								(*i)->status.hp -= 300.0f * (*i)->status.s_atk - (50.0f * (*i)->status.f_atk * (*i)->status.def);
								if ((*i)->status.hp <= 0)
								{
									*kill += 1;
								}
							}
						}
						break;
						//右
					case 3:
						if (p_pos.x + IMGSIZE64 - scroll[P3].x < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
							p_pos.x + IMGSIZE64 + IMGSIZE64 - scroll[P3].x  >(*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
							p_pos.y - scroll[P3].y < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
							p_pos.y + IMGSIZE64 - scroll[P3].y >(*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
						{
							if ((*i)->status.WIN_ID == P3 && ((Player*)(*i).get())->r_flag == false)
							{
								//基本ダメージにステータス情報を入れ、ダメージを増減させる
								(*i)->status.hp -= 300.0f * (*i)->status.s_atk - (50.0f * (*i)->status.f_atk * (*i)->status.def);
								if ((*i)->status.hp <= 0)
								{
									*kill += 1;
								}
							}
						}
						break;
					}
					//WINDOW 4
				case P4:
					switch (img_Vec)//プレイヤーも向き（img_Vec）に合わせた当たり判定を出す。
					{
						//下
					case 0:
						if (p_pos.x - scroll[P4].x < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
							p_pos.x + IMGSIZE64 - scroll[P4].x >(*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
							p_pos.y + IMGSIZE64 - scroll[P4].y  < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
							p_pos.y + IMGSIZE64 + IMGSIZE64 - scroll[P4].y >(*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
						{
							if ((*i)->status.WIN_ID == P4 && ((Player*)(*i).get())->r_flag == false)
							{
								//基本ダメージにステータス情報を入れ、ダメージを増減させる
								(*i)->status.hp -= 300.0f * (*i)->status.s_atk - (50.0f * (*i)->status.f_atk * (*i)->status.def);
								if ((*i)->status.hp <= 0)
								{
									*kill += 1;
								}
							}
						}
						break;
						//左
					case 1:
						if (p_pos.x - IMGSIZE64 - scroll[P4].x  < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
							p_pos.x + IMGSIZE64 - IMGSIZE64 - scroll[P4].x  >(*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
							p_pos.y - scroll[P4].y < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
							p_pos.y + IMGSIZE64 - scroll[P4].y >(*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
						{
							if ((*i)->status.WIN_ID == P4 && ((Player*)(*i).get())->r_flag == false)
							{
								//基本ダメージにステータス情報を入れ、ダメージを増減させる
								(*i)->status.hp -= 300.0f * (*i)->status.s_atk - (50.0f * (*i)->status.f_atk * (*i)->status.def);
								if ((*i)->status.hp <= 0)
								{
									*kill += 1;
								}
							}
						}
						break;
						//上
					case 2:
						if (p_pos.x - scroll[P4].x < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
							p_pos.x + IMGSIZE64 - scroll[P4].x >(*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
							p_pos.y - IMGSIZE64 - scroll[P4].y < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
							p_pos.y - IMGSIZE64 + IMGSIZE64 - scroll[P4].y >(*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
						{
							if ((*i)->status.WIN_ID == P4 && ((Player*)(*i).get())->r_flag == false)
							{
								//基本ダメージにステータス情報を入れ、ダメージを増減させる
								(*i)->status.hp -= 300.0f * (*i)->status.s_atk - (50.0f * (*i)->status.f_atk * (*i)->status.def);
								if ((*i)->status.hp <= 0)
								{
									*kill += 1;
								}
							}
						}
						break;
						//右
					case 3:
						if (p_pos.x + IMGSIZE64 - scroll[P4].x < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
							p_pos.x + IMGSIZE64 + IMGSIZE64 - scroll[P4].x  >(*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
							p_pos.y - scroll[P4].y < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
							p_pos.y + IMGSIZE64 - scroll[P4].y >(*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
						{
							if ((*i)->status.WIN_ID == P4 && ((Player*)(*i).get())->r_flag == false)
							{
								//基本ダメージにステータス情報を入れ、ダメージを増減させる
								(*i)->status.hp -= 300.0f * (*i)->status.s_atk - (50.0f * (*i)->status.f_atk * (*i)->status.def);
								if ((*i)->status.hp <= 0)
								{
									*kill += 1;
								}
							}
						}
						break;
					}
					break;
				}
			}
		}
	}
}