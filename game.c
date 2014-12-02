#include <SDL/SDL.h>
#include "SDL/SDL_opengl.h"
#include <math.h>
void
drawship(void)
{
	glBegin( GL_LINES );
		glVertex2f( 0.f, 4.f );
		glVertex2f( 1.f, 0.f );
		glVertex2f( 1.f, 0.f );
		glVertex2f( 2.f, 4.f );
		glVertex2f( 2.f, 4.f );
		glVertex2f( 0.f, 4.f );
	glEnd();

}
float
terainf(float x)
{
	return sin(x);

}
void
drawworld(float start, float end, float t, float (*f)(float) )
{
	float x=1.0;
	glBegin( GL_LINES );
		for(x=start;x<end;x=x+t){
			glVertex2f( x-0.1, f(x-0.1) );
			glVertex2f( x, f(x) );
		}
	glEnd();
}
void
drawframe(void)
{
	glLoadIdentity();
	glColor3f(0.0,1.0,1.0);
	glScalef(10.f,10.f,10.f);
	drawship();
	glLoadIdentity();
	glTranslatef(0.0,10.0,0.0);

	glColor3f(0.0,1.0,0.0);
	glScalef(10.f,10.f,10.f);
	drawworld(1.0,100.0,0.1,terainf);
}

void
logic(void)
{

}
