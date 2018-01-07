
// make ttf 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
/// TTF 
// libsdl-ttf2.0-0:i386 (2.0.11-4)  // awful no??
// libsdl-ttf2.0-dev:i386 (2.0.11-4) // awful no??
#include "SDL/SDL_ttf.h"

int main(int argc, char *argv[]) 
{
    SDL_Event event;
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init(); 

    SDL_WM_SetCaption("Hello World! :D", NULL);

    int rows = 600; int cols = 800;
    SDL_Surface *screen;  // create screen
    screen = SDL_SetVideoMode( cols , rows, 32, SDL_HWSURFACE); // charge la fenetre avec sa taille et ses flags
    SDL_putenv("SDL_VIDEO_CENTERED=center"); // Centre la fenetre a l'écran

    // make the background
    SDL_FillRect( screen,  0 , SDL_MapRGB( screen->format, 125, 125, 125  ) );

    // small rectangle
    SDL_Rect rect     = { 25 , 25 , cols / 3 , rows / 4 } ;
    SDL_FillRect( screen, &rect, 0xFF0000 );

    // text hello world (sdl rectangle)
    SDL_Color txtcolor = { 40, 40 , 40 };
    TTF_Font *myfont = TTF_OpenFont( "DejaVuSans.ttf", 28 );
    SDL_Surface *mytext = TTF_RenderText_Blended( myfont, "Hello World (TTF)!!", txtcolor );
    SDL_Rect textrect;
    textrect.x = 250;
    textrect.y = 250;
    SDL_BlitSurface( mytext, 0, screen , &textrect ); 

    // draw pixels to screen 
    SDL_Flip( screen );


    SDL_Delay( 2000 );

    printf( "Bye...\n" );
    SDL_FreeSurface( mytext );
    TTF_CloseFont( myfont );

    SDL_Quit();
    return 0;
}




