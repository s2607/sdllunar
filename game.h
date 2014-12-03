#include <SDL/SDL.h>
#include "SDL/SDL_opengl.h"
#include <math.h>
struct mass
{
	float x,y,vx,vy,r,vr; //location (velocity) rotation (velocity)
	float rm[10]; //varius types of mass that can be jetosoned to cause a rection force on the object
	float imp[10]; //impulse of mass being jetosoned
	//TODO: change center of gravity when mass is jetosoned
} ship1;

