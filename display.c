#include <SDL.h>
#include <SDL_ttf.h>

#define CYAN {100,255,255}
#define AMBER {255,255,100}

int main (int argc, char **argv) {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *window = SDL_CreateWindow("Demo", 0, 0, 640, 480, 0);
  SDL_Surface *screen = SDL_GetWindowSurface(window);

  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
  SDL_UpdateWindowSurface(window);

  TTF_Init();

  TTF_Font *font = TTF_OpenFont("dos.ttf", 16);

  char lines[4][8] = {
    " _N_   ",
    "<_====",
    " |T|`  ",
    " E E   "
  };
  
  SDL_Color color = AMBER;
  SDL_Surface *text;
  SDL_Rect dst;

  for (int i = 0; i < 4; i++) {
    dst.y = i * 16;
    text = TTF_RenderText_Solid(font, lines[i], color);
    SDL_BlitSurface(text, NULL, screen, &dst);
    SDL_FreeSurface(text);
  }
 
  SDL_UpdateWindowSurface(window); 
  SDL_Delay(5000);
  
  return 0;
}
