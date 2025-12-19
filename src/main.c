#include <SDL2/SDL.h>
#include "../gfx/gfx.h"
#include <stdio.h>

int main()
{
  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window *window = SDL_CreateWindow(
      "Custom Graphics Library",
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      640, 480, 0);

  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  drawLine(renderer, 50, 50, 300, 300);
  drawCircle(renderer, 320, 240, 100);

  SDL_RenderPresent(renderer);
  SDL_Delay(5000);

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
