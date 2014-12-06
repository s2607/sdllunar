#include <SDL/SDL.h>
#include "SDL/SDL_opengl.h"
#include <math.h>
#define vec2 vect2
//I keep typoing vect2 as vec2 
float terainf(float x);

struct vect2 {
	float x,y;
};
struct force {
	struct vect2 pos;
	struct vect2 w;
};

struct mass
{
	float mass; //<- kind of important
	float elasticity;
	struct vect2 pos;
	struct vect2 vel;
	float r,vr; //rotation (speed)
	float rm[10]; //varius submases that can be jetosoned to cause a rection force on the object
	float imp[10]; //impulse of mass being jetosoned
	//TODO:   ^that's retarded
	//TODO: change center of gravity when mass is jetosoned
} ship1;


