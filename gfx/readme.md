# GFX - Custom Graphics Library

A lightweight 2D graphics library built on top of SDL2, implementing classic computer graphics algorithms for educational purposes.

## Overview

This library provides low-level drawing primitives using well-known graphics algorithms:

- **Bresenham's Line Algorithm** - Efficient integer-based line rasterization
- **Midpoint Circle Algorithm** - Efficient circle drawing using integer arithmetic

## API Reference

### Pixel Functions

#### `putpixel`

```c
void putpixel(SDL_Renderer *renderer, int x, int y);
```

Draws a single pixel at the specified coordinates.

| Parameter  | Description           |
| ---------- | --------------------- |
| `renderer` | SDL2 renderer context |
| `x`        | X coordinate          |
| `y`        | Y coordinate          |

#### `getpixel`

```c
Uint32 getpixel(SDL_Renderer *renderer, int x, int y);
```

Retrieves the color value of a pixel at the specified coordinates.

| Parameter  | Description           |
| ---------- | --------------------- |
| `renderer` | SDL2 renderer context |
| `x`        | X coordinate          |
| `y`        | Y coordinate          |

**Returns:** `Uint32` - Pixel color in ARGB8888 format.

---

### Drawing Functions

#### `drawLine`

```c
void drawLine(SDL_Renderer *renderer, int x1, int y1, int x2, int y2);
```

Draws a line between two points using **Bresenham's Line Algorithm**.

| Parameter  | Description                |
| ---------- | -------------------------- |
| `renderer` | SDL2 renderer context      |
| `x1`, `y1` | Starting point coordinates |
| `x2`, `y2` | Ending point coordinates   |

#### `drawCircle`

```c
void drawCircle(SDL_Renderer *renderer, int xc, int yc, int r);
```

Draws a circle using the **Midpoint Circle Algorithm** with 8-way symmetry.

| Parameter  | Description           |
| ---------- | --------------------- |
| `renderer` | SDL2 renderer context |
| `xc`, `yc` | Center coordinates    |
| `r`        | Radius                |

## Building

```sh
make        # Build the project
make clean  # Remove build artifacts
make rebuild # Clean and rebuild
```

## Dependencies

- **SDL2** - Simple DirectMedia Layer 2.0

Install on Ubuntu/Debian:

```sh
sudo apt install libsdl2-dev
```

## License

Educational use.
