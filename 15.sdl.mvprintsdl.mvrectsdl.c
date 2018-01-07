

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include "SDL/SDL_ttf.h"



/////////////////////////////////////////////
void mvrectsdl( int tdx1, int tdx2, int tdx3, int tdx4, SDL_Surface *tdx_screen , long tdxcolor)
{
     SDL_Rect tdx_rect; 
     tdx_rect.y = tdx1;
     tdx_rect.x = tdx2;
     tdx_rect.h = tdx3-tdx1;
     tdx_rect.w = tdx4-tdx2;
     SDL_FillRect( tdx_screen, &tdx_rect,  tdxcolor );
}


/////////////////////////////////////////////
void mvprintsdl( int tdx_y, int tdx_x,  SDL_Surface *tdx_screen,  char *tdx_msg )
{
    TTF_Font *tdx_myfont = TTF_OpenFont( "DejaVuSans.ttf", 28 );
    SDL_Color tdx_color = { 255, 255, 255 };
    SDL_Surface *tdx_surface = TTF_RenderText_Solid( tdx_myfont, tdx_msg, tdx_color );
    SDL_Rect tdx_rect; 
    tdx_rect.x = tdx_x; tdx_rect.y = tdx_y;
    SDL_BlitSurface( tdx_surface , 0, tdx_screen , &tdx_rect ); 
    SDL_FreeSurface( tdx_surface );
}


int main(int argc, char *argv[]) 
{
    SDL_Event event;
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init(); 
    SDL_WM_SetCaption("SDL Example", NULL);
    int rows = 600; int cols = 800;
    SDL_Surface *screen;  // create screen
    screen = SDL_SetVideoMode( cols , rows, 32, SDL_HWSURFACE); 
    SDL_putenv("SDL_VIDEO_CENTERED=center"); 


    mvrectsdl( 2,10,  rows/2 , cols/3 , screen  , 0x0000FF );


    mvrectsdl( rows/2, cols/2, 40 , 40 , screen  , 0xFFFF00 );

    int i ; 
    for( i = 20 ; i <= rows ; i = i + 40 )
      mvrectsdl( i, cols/2, i+40, cols, screen, 0x112233 );

    // green
    mvrectsdl( 200, 200, 300, cols, screen, 0x00FF00 );

    // white
    mvrectsdl( rows -50 , cols -50, rows, cols, screen, 0xFFFFFF );

    // red, 800x600, means y1 500, x1 25, y2 580, x2 250 (like in ncurses)
    mvrectsdl( 500, 25, 580, 250 , screen, 0xFF0000 );
    


    int posy = 5;  
    posy += 40;  
    mvprintsdl( posy, 15, screen, "This is an example of mvprintsdl" );
    posy += 40;  
    mvprintsdl( posy , 25, screen, "This is a second ex of mvprintsdl" );
    posy += 40;  
    mvprintsdl( posy , 35, screen, "This is another example of mvprintsdl" );


    // draw pixels to screen 
    SDL_Flip( screen );


    // print bye and wait 
    printf( "Bye...\n" );
    SDL_Delay( 2000 );

    TTF_Quit();
    SDL_Quit();
    return 0;
}




