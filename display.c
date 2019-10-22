#include <SDL.h>
#include <SDL_ttf.h>
#include <unistd.h>

#define CYAN {100,200,255}
#define AMBER {255,200,100}
#define BLACK {0,0,0}

#define WIN_TITLE "Demo"
#define WIN_W 640
#define WIN_H 480

#define FONT_FILE "dos.ttf"
#define FONT_W 9
#define FONT_H 16

#define TICKS_PER_SECOND 10
#define SKIP_TICKS (1000 / TICKS_PER_SECOND)

SDL_Window *window;
SDL_Surface *screen;
TTF_Font *font;

void initw() {
  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow(WIN_TITLE, 0, 0, WIN_W, WIN_H, 0);
  screen = SDL_GetWindowSurface(window);

  TTF_Init();
  font = TTF_OpenFont(FONT_FILE, FONT_H);
}

void clearw() {
  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
}

void printw(int x, int y, char *str) {
  SDL_Color color = CYAN;
  SDL_Surface *text_surface = TTF_RenderText_Solid(font, str, color);
  SDL_Rect dest = { x * FONT_W, y * FONT_H };
  SDL_BlitSurface(text_surface, NULL, screen, &dest);
  SDL_FreeSurface(text_surface);
}

void refreshw() {
  SDL_UpdateWindowSurface(window);
}

void exitw() {
  SDL_DestroyWindow(window);
  SDL_Quit();
}

int main (int argc, char **argv) {
  initw();
  clearw();
  refreshw();
  
  unsigned char lines[5][16] = {
    " _N_  / ",
    "<_==== -=:",
    " |T|` \\ ",
    " E E   ",
    "\xb0\xb0\xb0\xb0\xb0\xb0\xb0"
  };

  Uint32 next_tick, sleep_ticks;
  SDL_Event event;
  
  for (int j = 0; j < 70; j++) {
    next_tick = SDL_GetTicks() + SKIP_TICKS;
    
    clearw();
    for (int i = 0; i < 5; i++) {
      printw(j, i + 15, lines[i]);
    }
    refreshw();

    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT:
	  return 0;
	  break;
      }
    }

    sleep_ticks = next_tick - SDL_GetTicks();
    if (sleep_ticks >= 0) {
      SDL_Delay(sleep_ticks);
    }
  }
  
  return 0;
}
