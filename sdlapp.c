#include <SDL/SDL.h>
#include "SDL/SDL_opengl.h"
//gcc -c sdlapp.c game.c && gcc sdlapp.o game.o -o sdlapp `sdl-config --cflags --libs` -framework opengl

void
resetglstate(void)
{
		glEnable( GL_TEXTURE_2D );
		glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
		glViewport( 0, 0, 640, 480 );
		glClear( GL_COLOR_BUFFER_BIT );
		glMatrixMode( GL_PROJECTION );
		glLoadIdentity();
		glOrtho(0.0f, 640, 480, 0.0f, -1.0f, 1.0f);
		glMatrixMode( GL_MODELVIEW );
		glLoadIdentity();
}
int main(int argc, char *argv[]) {
	int gogogo = 1;
	SDL_Event event;
	const SDL_VideoInfo* video;

	SDL_Init(SDL_INIT_EVERYTHING);
	video = SDL_GetVideoInfo( );
	if( video == NULL ) {
		fprintf(stderr, "Couldn't get video information: %s\n", SDL_GetError());
		exit(1);
	}

   /* Set the minimum requirements for the OpenGL window */
	SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 5 );
	SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 5 );
	SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 5 );
	SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
	SDL_Surface* screen =SDL_SetVideoMode(800, 600, video->vfmt->BitsPerPixel, SDL_OPENGL);
	SDL_WM_SetCaption("Hello World! :D", NULL);
	resetglstate();


	while (gogogo) {
	drawframe();
	logic();
	SDL_GL_SwapBuffers();
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT)
			gogogo = 0;
		
	}
	SDL_Quit();
	return 0;
}


