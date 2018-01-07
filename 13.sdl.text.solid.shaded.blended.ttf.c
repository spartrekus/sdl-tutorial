

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


    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    // small rectangle
    SDL_Rect rect     = { 25 , 25 , cols / 3 , rows / 4 } ;
    SDL_FillRect( screen, &rect, 0xFF0000 );



    ///////////////////////////////////////
    ///////////////////////////////////////
    ///////////////////////////////////////
    // text hello world (sdl rectangle)
    int posy = 250 ; 
    SDL_Color txtcolor = { 255 , 0 , 0 };
    TTF_Font *myfont = TTF_OpenFont( "DejaVuSans.ttf", 28 );

    SDL_Surface *mytext = TTF_RenderText_Blended( myfont, "This is the first line (TTF, Blended)!!", txtcolor );
    SDL_Rect textrect; 
    textrect.x = 25; textrect.y = posy;
    SDL_BlitSurface( mytext, 0, screen , &textrect ); 


    ///////////////////////////////////////
    posy += 40;  
    SDL_Color txtcolor2 = { 0, 0 , 255 };
    SDL_Surface *mytext2 = TTF_RenderText_Solid( myfont, "This is the second line (TTF, Solid)!!", txtcolor2 );
    SDL_Rect textrect2; 
    textrect2.x = 25; textrect2.y = posy;
    SDL_BlitSurface( mytext2 , 0, screen , &textrect2 ); 
    SDL_FreeSurface( mytext2 );

    ///////////////////////////////////////
    posy += 40;  
    SDL_Color txtcolor3 = { 0, 0 , 255 };
    SDL_Color txtshade3 = { 100, 100 , 100 };
    SDL_Surface *mytext3 = TTF_RenderText_Shaded( myfont, "This is the third line (TTF, Shaded)!!", txtcolor3 , txtshade3 );
    SDL_Rect textrect3; 
    textrect3.x = 25; textrect3.y = posy;
    SDL_BlitSurface( mytext3 , 0, screen , &textrect3 ); 
    SDL_FreeSurface( mytext3 );


    // draw pixels to screen 
    SDL_Flip( screen );


    // print bye and wait 
    printf( "Bye...\n" );
    SDL_Delay( 2000 );

    TTF_CloseFont( myfont );
    TTF_Quit();
    SDL_Quit();
    return 0;
}




