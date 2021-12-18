#include"main.h"
#include"char.h"


void wepon_summary(list<unique_ptr<Base>>& base, float px, float py, int wepon_num,int p_id)
{
	int set_wepon = wepon_num;

	Point pos{ 0.0f,0.0f };
	Point enmey{ 0.0f,0.0f };
	pos.x = px;
	pos.y = py;

	int player_id = p_id;//プレイヤー判別用

	/*if (set_wepon == 0)
	{
		for (auto i = bace.begin(); i != bace.end(); i++)
		{
			if ((*i)->Charcter.P_ID != player_id ) {
				enmey = ((*)(*i).get())->Charcter.pos;
				if (enmey.x < pos.x + 64 && enmey.x + 64 > pos.x && enmey.y < pos.y + 64 && enmey.y + 64 > pos.y)
				{
					
				}
			}

		}
	}*/
}