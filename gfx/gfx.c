#include "gfx.h"
#include <stdlib.h>

// Pixel functions
void putpixel(SDL_Renderer *renderer, int x, int y)
{
  SDL_RenderDrawPoint(renderer, x, y);
}

Uint32 getpixel(SDL_Renderer *renderer, int x, int y)
{
  Uint32 pixel;
  SDL_Rect rect = {x, y, 1, 1};
  SDL_RenderReadPixels(
      renderer,
      &rect,
      SDL_PIXELFORMAT_ARGB8888,
      &pixel,
      sizeof(Uint32));
  return pixel;
}

// Drawing Algorithms
void drawLine(SDL_Renderer *renderer, int x1, int y1, int x2, int y2)
{
  int dx = abs(x2 - x1);
  int dy = abs(y2 - y1);
  int sx = (x1 < x2) ? 1 : -1;
  int sy = (y1 < y2) ? 1 : -1;

  int err = dx - dy;
  while (1)
  {
    putpixel(renderer, x1, y1);
    if (x1 == x2 && y1 == y2)
      break;
    int e2 = 2 * err;
    if (e2 > -dy)
    {
      err -= dy;
      x1 += sx;
    }
    if (e2 < dx)
    {
      err += dx;
      y1 += sy;
    }
  }
}

// Midpint circle algorigthm
void drawCircle(SDL_Renderer *renderer, int xc, int yc, int r)
{
  int x = 0, y = r;
  int d = 1 - r;
  while (x <= y)
  {
    // 8-neighbour paint
    putpixel(renderer, xc + x, yc + y);
    putpixel(renderer, xc - x, yc + y);
    putpixel(renderer, xc + x, yc - y);
    putpixel(renderer, xc - x, yc - y);
    putpixel(renderer, xc + y, yc + x);
    putpixel(renderer, xc - y, yc + x);
    putpixel(renderer, xc + y, yc - x);
    putpixel(renderer, xc - y, yc - x);

    if (d < 0)
    {
      d += 2 * x + 3;
    }
    else
    {
      d += 2 * (x - y) + 5;
      y--;
    }
    x++;
  }
}
