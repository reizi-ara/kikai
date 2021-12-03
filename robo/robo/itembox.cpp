#pragma once
#include "char.h"

Itembox::Itembox(float px, float py)
{
	Charcter.pos.x = px;
	Charcter.pos.y = py;

	img = LoadGraph("image\\ケアパケ.png");

	Charcter.ID = ITEMBOX;

	Charcter.FLAG = true;

}

int Itembox::Action(list<unique_ptr<Bace>>& bace)
{
	

	return 0;
}

void Itembox::Draw() {
	DrawGraphF(Charcter.pos.x, Charcter.pos.y, img, TRUE);
}