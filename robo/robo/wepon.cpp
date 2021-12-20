#include"main.h"
#include"char.h"


void wepon_summary(list<unique_ptr<Base>>& base, Point p_pos, Vector scroll[4], int wepon_num, int WIN_ID, int img_Vec,int *kill)
{
	for (auto i = base.begin(); i != base.end(); i++)
	{
		if ((*i)->status.WIN_ID >= 0 && (*i)->status.WIN_ID != WIN_ID && (*i)->status.ID != BULLET)
		{
			switch (wepon_num)
			{
			case 1:
				switch ((*i)->status.WIN_ID)
				{
				case P1:
					switch (img_Vec)
					{
					case 0:
						if (p_pos.x - scroll[P1].x < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
							p_pos.x + IMGSIZE64 - scroll[P1].x >(*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
							p_pos.y + IMGSIZE64 - scroll[P1].y  < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
							p_pos.y + IMGSIZE64 + IMGSIZE64 - scroll[P1].y >(*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
						{
							if ((*i)->status.WIN_ID == P1 && ((Player*)(*i).get())->r_flag == false)
							{
								(*i)->status.hp -= 300.0f * (*i)->status.s_atk - (50.0f * (*i)->status.f_atk * (*i)->status.def);
								if ((*i)->status.hp <= 0)
								{
									*kill += 1;
								}
							}
						}
						break;
					case 1:
						if (p_pos.x - IMGSIZE64 - scroll[P1].x  < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
							p_pos.x + IMGSIZE64 - IMGSIZE64 - scroll[P1].x  >(*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
							p_pos.y - scroll[P1].y < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
							p_pos.y + IMGSIZE64 - scroll[P1].y >(*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
						{
							if ((*i)->status.WIN_ID == P1 && ((Player*)(*i).get())->r_flag == false)
							{
								(*i)->status.hp -= 300.0f * (*i)->status.s_atk - (50.0f * (*i)->status.f_atk * (*i)->status.def);
								if ((*i)->status.hp <= 0)
								{
									*kill += 1;
								}
							}
						}
						break;
					case 2:
						if (p_pos.x - scroll[P1].x < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
							p_pos.x + IMGSIZE64 - scroll[P1].x >(*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
							p_pos.y - IMGSIZE64 - scroll[P1].y < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
							p_pos.y - IMGSIZE64 + IMGSIZE64 - scroll[P1].y >(*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
						{
							if ((*i)->status.WIN_ID == P1 && ((Player*)(*i).get())->r_flag == false)
							{
								(*i)->status.hp -= 300.0f * (*i)->status.s_atk - (50.0f * (*i)->status.f_atk * (*i)->status.def);
								if ((*i)->status.hp <= 0)
								{
									*kill += 1;
								}
							}
						}
						break;
					case 3:
						if (p_pos.x + IMGSIZE64 - scroll[P1].x < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
							p_pos.x + IMGSIZE64 + IMGSIZE64 - scroll[P1].x  >(*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
							p_pos.y - scroll[P1].y < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
							p_pos.y + IMGSIZE64 - scroll[P1].y >(*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
						{
							if ((*i)->status.WIN_ID == P1 && ((Player*)(*i).get())->r_flag == false)
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
				case P2:
					switch (img_Vec)
					{
					case 0:
						if (p_pos.x - scroll[P2].x < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
							p_pos.x + IMGSIZE64 - scroll[P2].x >(*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
							p_pos.y + IMGSIZE64 - scroll[P2].y  < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
							p_pos.y + IMGSIZE64 + IMGSIZE64 - scroll[P2].y >(*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
						{
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
					case 1:
						if (p_pos.x - IMGSIZE64 - scroll[P2].x  < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
							p_pos.x + IMGSIZE64 - IMGSIZE64 - scroll[P2].x  >(*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
							p_pos.y - scroll[P2].y < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
							p_pos.y + IMGSIZE64 - scroll[P2].y >(*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
						{
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
					case 2:
						if (p_pos.x - scroll[P2].x < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
							p_pos.x + IMGSIZE64 - scroll[P2].x >(*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
							p_pos.y - IMGSIZE64 - scroll[P2].y < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
							p_pos.y - IMGSIZE64 + IMGSIZE64 - scroll[P2].y >(*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
						{
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
					case 3:
						if (p_pos.x + IMGSIZE64 - scroll[P2].x < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
							p_pos.x + IMGSIZE64 + IMGSIZE64 - scroll[P2].x  >(*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
							p_pos.y - scroll[P2].y < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
							p_pos.y + IMGSIZE64 - scroll[P2].y >(*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
						{
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
				case P3:
					switch (img_Vec)
					{
					case 0:
						if (p_pos.x - scroll[P3].x < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
							p_pos.x + IMGSIZE64 - scroll[P3].x >(*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
							p_pos.y + IMGSIZE64 - scroll[P3].y  < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
							p_pos.y + IMGSIZE64 + IMGSIZE64 - scroll[P3].y >(*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
						{
							if ((*i)->status.WIN_ID == P3 && ((Player*)(*i).get())->r_flag == false)
							{
								(*i)->status.hp -= 300.0f * (*i)->status.s_atk - (50.0f * (*i)->status.f_atk * (*i)->status.def);
								if ((*i)->status.hp <= 0)
								{
									*kill += 1;
								}
							}
						}
						break;
					case 1:
						if (p_pos.x - IMGSIZE64 - scroll[P3].x  < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
							p_pos.x + IMGSIZE64 - IMGSIZE64 - scroll[P3].x  >(*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
							p_pos.y - scroll[P3].y < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
							p_pos.y + IMGSIZE64 - scroll[P3].y >(*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
						{
							if ((*i)->status.WIN_ID == P3 && ((Player*)(*i).get())->r_flag == false)
							{
								(*i)->status.hp -= 300.0f * (*i)->status.s_atk - (50.0f * (*i)->status.f_atk * (*i)->status.def);
								if ((*i)->status.hp <= 0)
								{
									*kill += 1;
								}
							}
						}
						break;
					case 2:
						if (p_pos.x - scroll[P3].x < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
							p_pos.x + IMGSIZE64 - scroll[P3].x >(*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
							p_pos.y - IMGSIZE64 - scroll[P3].y < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
							p_pos.y - IMGSIZE64 + IMGSIZE64 - scroll[P3].y >(*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
						{
							if ((*i)->status.WIN_ID == P3 && ((Player*)(*i).get())->r_flag == false)
							{
								(*i)->status.hp -= 300.0f * (*i)->status.s_atk - (50.0f * (*i)->status.f_atk * (*i)->status.def);
								if ((*i)->status.hp <= 0)
								{
									*kill += 1;
								}
							}
						}
						break;
					case 3:
						if (p_pos.x + IMGSIZE64 - scroll[P3].x < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
							p_pos.x + IMGSIZE64 + IMGSIZE64 - scroll[P3].x  >(*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
							p_pos.y - scroll[P3].y < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
							p_pos.y + IMGSIZE64 - scroll[P3].y >(*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
						{
							if ((*i)->status.WIN_ID == P3 && ((Player*)(*i).get())->r_flag == false)
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
				case P4:
					switch (img_Vec)
					{
					case 0:
						if (p_pos.x - scroll[P4].x < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
							p_pos.x + IMGSIZE64 - scroll[P4].x >(*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
							p_pos.y + IMGSIZE64 - scroll[P4].y  < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
							p_pos.y + IMGSIZE64 + IMGSIZE64 - scroll[P4].y >(*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
						{
							if ((*i)->status.WIN_ID == P4 && ((Player*)(*i).get())->r_flag == false)
							{
								(*i)->status.hp -= 300.0f * (*i)->status.s_atk - (50.0f * (*i)->status.f_atk * (*i)->status.def);
								if ((*i)->status.hp <= 0)
								{
									*kill += 1;
								}
							}
						}
						break;
					case 1:
						if (p_pos.x - IMGSIZE64 - scroll[P4].x  < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
							p_pos.x + IMGSIZE64 - IMGSIZE64 - scroll[P4].x  >(*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
							p_pos.y - scroll[P4].y < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
							p_pos.y + IMGSIZE64 - scroll[P4].y >(*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
						{
							if ((*i)->status.WIN_ID == P4 && ((Player*)(*i).get())->r_flag == false)
							{
								(*i)->status.hp -= 300.0f * (*i)->status.s_atk - (50.0f * (*i)->status.f_atk * (*i)->status.def);
								if ((*i)->status.hp <= 0)
								{
									*kill += 1;
								}
							}
						}
						break;
					case 2:
						if (p_pos.x - scroll[P4].x < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
							p_pos.x + IMGSIZE64 - scroll[P4].x >(*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
							p_pos.y - IMGSIZE64 - scroll[P4].y < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
							p_pos.y - IMGSIZE64 + IMGSIZE64 - scroll[P4].y >(*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
						{
							if ((*i)->status.WIN_ID == P4 && ((Player*)(*i).get())->r_flag == false)
							{
								(*i)->status.hp -= 300.0f * (*i)->status.s_atk - (50.0f * (*i)->status.f_atk * (*i)->status.def);
								if ((*i)->status.hp <= 0)
								{
									*kill += 1;
								}
							}
						}
						break;
					case 3:
						if (p_pos.x + IMGSIZE64 - scroll[P4].x < (*i)->status.pos.x - ((Player*)(*i).get())->scroll.x + IMGSIZE64 &&
							p_pos.x + IMGSIZE64 + IMGSIZE64 - scroll[P4].x  >(*i)->status.pos.x - ((Player*)(*i).get())->scroll.x &&
							p_pos.y - scroll[P4].y < (*i)->status.pos.y - ((Player*)(*i).get())->scroll.y + IMGSIZE64 &&
							p_pos.y + IMGSIZE64 - scroll[P4].y >(*i)->status.pos.y - ((Player*)(*i).get())->scroll.y)
						{
							if ((*i)->status.WIN_ID == P4 && ((Player*)(*i).get())->r_flag == false)
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
				}
			}
		}
	}
}