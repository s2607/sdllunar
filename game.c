#include "game.h"
void
logic(void)
{
	ship1.vy=ship1.vy+0.1;
	ship1.x=ship1.x+ship1.vx;
	ship1.y=ship1.y+ship1.vy;
	ship1.r=ship1.r+ship1.vr;
}
