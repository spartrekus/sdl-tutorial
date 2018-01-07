#include <SDL/SDL.h>
int main(int argc, char *argv[]) 
{
    SDL_Event event;

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_WM_SetCaption("Hello World! :D", NULL);

    SDL_SetVideoMode(1024, 768, 0, SDL_SWSURFACE );

    SDL_Delay( 2000 );

    SDL_Quit();
    return 0;
}

