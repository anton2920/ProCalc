#ifndef GRAPH_HEADER
#define GRAPH_HEADER

#include "header.h"

#if (HAVE_SDL2_SDL_H == 1 || HAVE_SDL_H == 1 || HAVE_SDL_SDL_H == 1)

struct PC {
    int ratio_x;
    int ratio_y;
    int size;
    int window_width;
    int window_height;
};

bool SDL_start(SDL_Window**, SDL_Renderer**, PC *);
void clear_window(SDL_Renderer*);
void plotGraph(SDL_Renderer*, func&, int, int, PC *);
void draw_y_axis(SDL_Renderer* renderer, int, PC *);
void draw_x_axis(SDL_Renderer* renderer, int, PC *);
void draw_grid(SDL_Renderer*, PC *);

#endif

#endif

