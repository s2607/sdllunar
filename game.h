#include <SDL/SDL.h>
#include "SDL/SDL_opengl.h"
#include <math.h>
struct vect2
{
	float x,y;
}
struct mass
{
	vect2.pos;
	vect2.vel;
	float r,vr; //rotation (speed)
	float rm[10]; //varius submases that can be jetosoned to cause a rection force on the object
	float imp[10]; //impulse of mass being jetosoned
	//TODO:   ^that's retarded
	//TODO: change center of gravity when mass is jetosoned
} ship1;

