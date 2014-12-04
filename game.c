#include "game.h"

struct vect2
mulvect(struct vec2 a, struct vec2 b)
{
	a.y=a.y*b.y;
	return a;
}
void
logic(void)
{
	ship1.vel.y=ship1.vel.y+0.1;
	if(colground())
	{
		ship.vel=mulvect(ship.vel,colground());
	}
	ship1.pos.x=ship1.pos.x+ship1.vel.x;
	ship1.pos.y=ship1.pos.y+ship1.vel.y;
	ship1.r=ship1.r+ship1.vr;
}
