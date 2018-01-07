
#include <stdio.h>
#include <SDL/SDL.h>

int main(int argc, char *argv[]) 
{

    SDL_Event event;
    SDL_Init(SDL_INIT_VIDEO); //Initialisation de la SDL
    SDL_WM_SetCaption("Hello World! :D", NULL);

    SDL_putenv("SDL_VIDEO_CENTERED=center"); // Centre la fenetre a l'écran
     
    SDL_Surface *screen;
    screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE); // charge la fenetre avec sa taille et ses flags

     
    int gameover = 0 ; 
    while( gameover == 0 )
    {

         SDL_WaitEvent(&event);

         // draw pixels to screen 
         SDL_Flip( screen );

         if ( event.type == SDL_QUIT )
            gameover = 1;
         
         switch(event.type)
         {
             case SDL_KEYDOWN:
               printf( "EVENT KEYDOWN...\n" );
               break;
             case SDL_QUIT:
               printf( "EVENT QUIT...\n" );
               gameover = 1;
               break;
         }
     }

     printf( "Bye...\n" );

     SDL_Quit(); // Quitte les systemes de la sdl
     return EXIT_SUCCESS; // tout c'est bien passé
}

