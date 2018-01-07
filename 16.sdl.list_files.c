

//////////////////////////////////////////
//////////////////////////////////////////
//////////////////////////////////////////
#include <stdio.h>
#if defined(__linux__)
#define MYOS 1
#elif defined(_WIN32)
#define MYOS 2
#elif defined(_WIN64)
#define MYOS 3
#elif defined(__unix__)
#define MYOS 4
#define PATH_MAX 2500
#else
#define MYOS 0
#endif

#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include "SDL/SDL_ttf.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h> 
#include <ncurses.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>


////////////////////////////////////////////////////////////////////
char *strrlf(char *str) 
{     // copyleft, C function made by Spartrekus 
      char ptr[strlen(str)+1];
      int i,j=0;
      for(i=0; str[i]!='\0'; i++)
      {
        if (str[i] != '\n' && str[i] != '\n') 
        ptr[j++]=str[i];
      } 
      ptr[j]='\0';
      size_t siz = sizeof ptr ; 
      char *r = malloc( sizeof ptr );
      return r ? memcpy(r, ptr, siz ) : NULL;
}
////////////////////////////////////////////////////////////////////
char *strcut( char *str , int myposstart, int myposend )
{     // copyleft, C function made by Spartrekus 
      char ptr[strlen(str)+1];
      int i,j=0;
      for(i=0; str[i]!='\0'; i++)
      {
        if ( ( str[i] != '\0' ) && ( str[i] != '\0') )
         if ( ( i >=  myposstart-1 ) && (  i <= myposend-1 ) )
           ptr[j++]=str[i];
      } 
      ptr[j]='\0';
      size_t siz = sizeof ptr ; 
      char *r = malloc( sizeof ptr );
      return r ? memcpy(r, ptr, siz ) : NULL;
}






/////////////////////////////////////////////
void mvrectsdl( int tdx1, int tdx2, int tdx3, int tdx4, SDL_Surface *tdx_screen , long tdxcolor)
{
     // copyleft, C function made by Spartrekus 
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
    // copyleft, C function made by Spartrekus 
    TTF_Font *tdx_myfont = TTF_OpenFont( "DejaVuSans.ttf", 28 );
    SDL_Color tdx_color = { 255, 255, 255 };
    SDL_Surface *tdx_surface = TTF_RenderText_Solid( tdx_myfont, tdx_msg, tdx_color );
    SDL_Rect tdx_rect; 
    tdx_rect.x = tdx_x; tdx_rect.y = tdx_y;
    SDL_BlitSurface( tdx_surface , 0, tdx_screen , &tdx_rect ); 
    SDL_FreeSurface( tdx_surface );
}











/////////////////////////////////
/////////////////////////////////
/////////////////////////////////
int fexist(char *a_option)
{
  char dir1[PATH_MAX]; 
  char *dir2;
  DIR *dip;
  strncpy( dir1 , "",  PATH_MAX  );
  strncpy( dir1 , a_option,  PATH_MAX  );

  struct stat st_buf; 
  int status; 
  int fileordir = 0 ; 

  status = stat ( dir1 , &st_buf);
  if (status != 0) {
    fileordir = 0;
  }

  // this is compatible to check if a file exists
  FILE *fp2check = fopen( dir1  ,"r");
  if( fp2check ) {
  // exists
  fileordir = 1; 
  fclose(fp2check);
  } 

  if (S_ISDIR (st_buf.st_mode)) {
    fileordir = 2; 
  }
return fileordir;
/////////////////////////////
}



int nconsole_explorer = 1;
int gameselection = 1;
int gamescrolly = 0;
int gamedirfcheck = 1;
char gamefilter[PATH_MAX];
char gamefilter_previous[PATH_MAX];
char fileselection[PATH_MAX];




int main(int argc, char *argv[]) 
{

    strncpy( gamefilter, "", PATH_MAX );
    strncpy( gamefilter_previous, "", PATH_MAX );


    SDL_Event event;
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init(); 
    SDL_WM_SetCaption("SDL Example", NULL);
    int rows = 600; 
    int cols = 800;
    SDL_Surface *screen;  // create screen
    screen = SDL_SetVideoMode( cols , rows, 32, SDL_HWSURFACE); 
    SDL_putenv("SDL_VIDEO_CENTERED=center"); 

   int ch ; 
   char userinp[PATH_MAX];
   int gameover_nsc = 0;
   strncpy( gamefilter, "", PATH_MAX );

    // rects
    mvrectsdl( 100 , cols-200, 200, cols-10 , screen, 0x00FF00 );
    mvrectsdl( 400 , cols-200, 500, cols-10 , screen, 0xFF0000 );

    mvprintsdl( rows-40, cols- 140 , screen, "[Explorer]" );


    char searchitem[PATH_MAX];
    int tc_show_hidden = 0; 

    DIR *dir;
    struct dirent *entry;
    char *name = ".";
    
    int posy = 40;

    dir = opendir(name);
    while ((entry = readdir(dir)) != NULL) 
    {
        if (entry->d_type == DT_DIR) 
	{
            char path[1024];

            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;


            //snprintf( path, sizeof(path), "%s/%s", name, entry->d_name);

            //listdir( path, indent + 2);
        } 
	else 
	{
	    if ( strstr( entry->d_name , searchitem ) != 0 ) 
	    {
               if ( posy <= rows ) 
                  mvprintsdl( posy , 10, screen , entry->d_name );
               posy = posy + 40;
	    }
        }
    }
    closedir(dir);

    // draw pixels to screen 
    SDL_Flip( screen );

    // print bye and wait 
    printf( "Bye...\n" );
    SDL_Delay( 2000 );

    TTF_Quit();
    SDL_Quit();
    return 0;
}



