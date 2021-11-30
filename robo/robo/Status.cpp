#include"main.h"
#include"char.h"

void SetMachine(Status* st, int machine,int pilot)
{
	if (machine == SPEED_PLAYER)
	{
		st->speed.x += default_SPD_X * 0.5f;
		st->speed.y += default_SPD_Y * 0.5f;
	}
	if (machine == DEFENCE_PLAYER)
	{
		st->def += default_DEF * 0.1f;
		st->speed.x += default_SPD_X * -0.1f;
		st->speed.y += default_SPD_X * -0.1f;
	}
	if (machine == SHOOTING_PLAYER)
	{
		;
	}
	if (machine == TRAP_PLAYER)
	{
		;
	}
	if (pilot == COMBAT)
	{
		st->f_atk += default_F_ATK * 0.5f;
	}
	if (pilot == SHOOT)
	{
		st->s_atk += default_S_ATK * 0.2f;
	}
	if (pilot == RUN)
	{
		st->speed.x += default_SPD_X * 0.3f;
		st->speed.y += default_SPD_Y * 0.3f;
	}
	if (pilot == MECHANIC)
	{
		;
	}
}