#include "game.h"

void
drawsb(void)
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
drawship(struct mass *ship)
{
	glLoadIdentity();
	glTranslatef(ship->x,ship->y,0.0);
	glRotatef(0.0,0.0,0.0);
	glColor3f(0.0,1.0,1.0);

	glScalef(4.f,4.f,4.f);//scale is wrong at this point
	drawship();

}
float
terainf(float x)
{
	x=x/30;
	return sin(x*8.7)*10+sin(x*5.5)*10;
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
	draship(ship1);
	glLoadIdentity();
	glTranslatef(0.0,100.0,0.0);

	glColor3f(0.0,1.0,0.0);
	glScalef(4.f,4.f,4.f);
	drawworld(1.0,100.0,0.1,terainf);
}


