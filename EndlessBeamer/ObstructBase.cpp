#include "ObstructBase.h"

void ObstructBase::GivenDmg(float dmg)
{
	hp -= dmg;
}

void ObstructBase::ColorCanger()
{
	redColorValue = MaxColorValue * (1 - (hp / maxHp));//HP‚ÌŠ„‡•ªÔ‚ğ‘‰Á
	color = GetColor(redColorValue, MaxColorValue - redColorValue, 0);
}
