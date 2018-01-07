
#include <stdio.h>
#include <SDL/SDL.h>

int main(int argc, char *argv[]) 
{
     //SDL_Init(SDL_INIT_EVERYTHING);
     SDL_Event event;
     SDL_Init(SDL_INIT_VIDEO); //Initialisation de la SDL
     SDL_WM_SetCaption("Hello World! :D", NULL);
     SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE); // charge la fenetre avec sa taille et ses flags
     SDL_putenv("SDL_VIDEO_CENTERED=center"); // Centre la fenetre a l'écran

     
    int gameover = 0 ; 
    while( gameover == 0 )
    {
         printf( "Wait for event... \n" );
         SDL_WaitEvent(&event);

         printf( "Event type: %d. \n", event.type );
         printf( "Event type (SDL_QUIT): %d. \n", SDL_QUIT ); // ctrl+c in terminal 
         
         switch(event.type)
         {
             case SDL_QUIT:
               gameover = 1;
               break;
         }
     }

     printf( "Bye...\n" );

     SDL_Quit(); // Quitte les systemes de la sdl
     return EXIT_SUCCESS; // tout c'est bien passé
}

