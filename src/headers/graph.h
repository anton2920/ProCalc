#pragma once

#include "input.h"
#include <SDL.h>
#undef main

namespace PC
{
	const int ratio_x = 16;
	const int ratio_y = 9;
	const int size = 100;
	const int window_width = size * ratio_x;
	const int window_height = size * ratio_y;
}

bool SDL_start(SDL_Window**, SDL_Renderer**);
void clear_window(SDL_Renderer*);
void plotGraph(SDL_Renderer*, func&, const int x_pos = PC::window_height / 2,
	const int y_pos = PC::window_width / 2);
void draw_y_axis(SDL_Renderer* renderer, const int y_pos = PC::window_width / 2);
void draw_x_axis(SDL_Renderer* renderer, const int x_pos = PC::window_height / 2, const int y_pos = PC::window_width / 2);
void draw_grid(SDL_Renderer*);

