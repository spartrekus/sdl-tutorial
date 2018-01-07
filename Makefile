

all:
	   gcc sdl.c -o sdl -lSDL 


run:
	   gcc sdl.c -o sdl -lSDL  ; ./sdl 

ttf:
	   gcc sdl.c -o sdl -lSDL_ttf  -lSDL  ; ./sdl 

