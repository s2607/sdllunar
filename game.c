#include "game.h"

struct vect2
mulvect(struct vect2 a, struct vect2 b)
{
	return (struct vect2){.x=a.x*b.x,.y=a.y*b.y};//TODO: unfinished
}
struct vect2 
mulvectscal(struct vect2 vect, float scal)
{
	return (struct vect2){.x=vect.x*scal,.y=vect.y*scal}; 
}
struct vect2
addvect(struct vect2 a, struct vect2 b)
{
	return (struct vect2){.x=a.x+b.x, .y=a.y+b.y};
}
struct vect2
atovect(float a)
{
	return (struct vect2){
		.x=cos(atan(a)),
		.y=sin(atan(a))
	};
}
float
mag(struct vect2 v)
{
	return v.x+v.y;
}
float
nderiv( float (*f)(float), float x, float h)
{
	return (f(x+h)-f(x-h));	
}

int
colground()
{
	printf("%f %f\n", ship1.pos.y, terainf(ship1.pos.x));
	return ship1.pos.y>terainf(ship1.pos.x);
}
void
applyforce(struct mass *ob, struct force f)
{
	//f=ma
	//f/m=a
	//TODO:moments
	ob->vel=addvect(ob->vel,f.w);
}
void
applyforcecenter(struct mass *ob, struct vect2 f)
{
	ob->vel=addvect(ob->vel,f);
}
void
logic(void)
{
	//int a=getchar();
	ship1.vel.y=ship1.vel.y+0.1;
	if(colground())
	{
		puts("collision");
		applyforcecenter(&ship1, 
			mulvectscal(atovect(nderiv(terainf,0.1,ship1.pos.x)),
				mag(ship1.vel)*-2
			)
		);
	}
	ship1.pos.x=ship1.pos.x+ship1.vel.x;
	ship1.pos.y=ship1.pos.y+ship1.vel.y;
	ship1.r=ship1.r+ship1.vr;
}
void
gameinit()
{
	ship1.pos.x=50.0;
}
