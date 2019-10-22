#include <SDL.h>
#include <SDL_ttf.h>
#include <unistd.h>

#define CYAN {100,200,255}
#define AMBER {255,200,100}
#define BLACK {0,0,0}

#define WIN_W 640
#define WIN_H 480

#define FONT_FILE "dos.ttf"
#define FONT_W 9
#define FONT_H 16

#define TICKS_PER_SECOND 10
#define SKIP_TICKS (1000 / TICKS_PER_SECOND)

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *texture;
TTF_Font *font;

void initw() {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_CreateWindowAndRenderer(WIN_W, WIN_H, 0, &window, &renderer);

  TTF_Init();
  font = TTF_OpenFont(FONT_FILE, FONT_H);
}

void clearw() {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
  SDL_RenderClear(renderer);
}

void printw(int x, int y, char *str) {
  SDL_Rect dest = { x * FONT_W, y * FONT_H, FONT_W, FONT_H };
  SDL_RenderCopy(renderer, texture, NULL, &dest);
}

void refreshw() {
  SDL_RenderPresent(renderer);
}

void exitw() {
  TTF_Quit();
  SDL_DestroyWindow(window);
  SDL_Quit();
}

int main (int argc, char **argv) {
  initw();
  clearw();
  refreshw();

  Uint32 next_tick, sleep_ticks;

  SDL_Color color = CYAN;
  SDL_Surface *text_surface = TTF_RenderText_Solid(font, "\xb0", color);
  texture = SDL_CreateTextureFromSurface(renderer, text_surface);
  SDL_FreeSurface(text_surface);
  
  for (int j = 0; j < 70; j++) {
    next_tick = SDL_GetTicks() + SKIP_TICKS;
    
    clearw();
    printw(j, 15, "");
    refreshw();

    sleep_ticks = next_tick - SDL_GetTicks();
    if (sleep_ticks >= 0) {
      SDL_Delay(sleep_ticks);
    }
  }
  
  return 0;
}
