#include <SDL/SDL.h>
#include "SDL/SDL_opengl.h"
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
void
drawframe(void)
{
	glLoadIdentity();
	glColor3f(0.0,1.0,1.0);
	glScalef(10.f,10.f,10.f);
	drawship();
}
void
logic(void)
{

}
