#ifndef GFX_H
#define GFX_H

#include <SDL2/SDL.h>

// Pixel functions
void putpixel(SDL_Renderer *renderer, int x, int y);
Uint32 getpixel(SDL_Renderer *renderer, int x, int y);

// Drawing Algorithms
void drawLine(SDL_Renderer *renderer, int x1, int y1, int x2, int y2);
void drawCircle(SDL_Renderer *renderer, int xc, int yc, int r);

#endif
