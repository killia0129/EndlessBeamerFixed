#include "ObstructBase.h"

void ObstructBase::GivenDmg(float dmg)
{
	hp -= dmg;
}

void ObstructBase::ColorCanger()
{
	redColorValue = MaxColorValue * (1 - (hp / maxHp));//HPの割合分赤を増加
	color = GetColor(redColorValue, MaxColorValue - redColorValue, 0);
}
