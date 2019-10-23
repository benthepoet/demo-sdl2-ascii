CC = gcc
CFLAGS = -g -Wall
SDL2 = `sdl2-config --cflags --libs` -I/usr/local/include/SDL2 -lSDL2_ttf
NCURSES = -lncurses
OUTDIR = bin

curses: src/curses.c
	$(CC) $(CFLAGS) -o $(OUTDIR)/$@ $^ $(NCURSES)

render: src/render.c
	$(CC) $(CFLAGS) -o $(OUTDIR)/$@ $^ $(SDL2)
