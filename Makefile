all:
	gcc -Iinclude -Iinclude/sdl -Iinclude/header -Llib -o Main src/*.c -lmingw32 -lSDL2main -lSDL2 -lSDL2_image