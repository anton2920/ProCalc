#include "graph.h"

bool SDL_start(SDL_Window** window, SDL_Renderer** renderer)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "Initialization failed!\n";
		return false;
	}

	*window = SDL_CreateWindow("Graphing plot",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		PC::window_width, PC::window_height, SDL_WINDOW_SHOWN);
	if (*window == nullptr)
	{
		std::cout << "Failed to create a window!\n";
		SDL_Quit();
		return false;
	}

	*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
	if (*renderer == nullptr)
	{
		std::cout << "Failed to create a renderer!\n";
		SDL_DestroyWindow(*window);
		SDL_Quit();
		return false;
	}

	SDL_SetRenderDrawColor(*renderer, 0x27, 0x27, 0x22, 0x00);
	SDL_RenderClear(*renderer);

	return true;
}

void clear_window(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0x27, 0x27, 0x22, 0x00);
	SDL_RenderClear(renderer);
}

void plotGraph(SDL_Renderer* renderer, func& foo, const int x_pos, const int y_pos)
{
	using namespace PC;

	SDL_SetRenderDrawColor(renderer, 0xff, 0xcc, 0x00, 0x00);

	for (int i = 0; i < window_width; i++)
	{
		if (abs(eval(foo, (i - y_pos)) - DBL_MAX) <= 0.000000000001 || abs(eval(foo, (i + 1 - y_pos)) - DBL_MAX) <= 0.000000001)
			continue;
		SDL_RenderDrawLine(renderer,
			i, -size / 2 * eval(foo, (i - y_pos) / (size / 2.0)) + x_pos,
			i + 1, -size / 2 * eval(foo, (i + 1 - y_pos) / (size / 2.0)) + x_pos);
	}
}

void draw_y_axis(SDL_Renderer* renderer, const int y_pos)
{
	using namespace PC;
	SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0x00);

	//draw y-axis
	SDL_RenderDrawLine(renderer, y_pos, 0, y_pos, window_height);

	// draw arrow on y-axis
	SDL_RenderDrawLine(renderer, y_pos, 0, y_pos - size / 16, size / 4);
	SDL_RenderDrawLine(renderer, y_pos, 0, y_pos + size / 16, size / 4);

	for (int i = size / 2; i <= window_height; i += size / 2)
	{
		SDL_RenderDrawLine(renderer, y_pos - size / 15, i, y_pos + size / 15, i);
	}
}

void draw_x_axis(SDL_Renderer* renderer,
	const int x_pos, const int y_pos)
{
	using namespace PC;
	SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0x00);

	// draw x-axis
	SDL_RenderDrawLine(renderer, 0, x_pos, window_width, x_pos);
	// draw arrow on x-axis
	SDL_RenderDrawLine(renderer, window_width, x_pos,
		window_width - size / 4, x_pos - size / 16);
	SDL_RenderDrawLine(renderer, window_width, x_pos,
		window_width - size / 4, x_pos + size / 16);

	// draw divisions on x-axis
	for (int i = size / 2; i < window_width; i += size / 2)
	{
		SDL_RenderDrawLine(renderer, i, x_pos - 4, i, x_pos + 4);
	}
}

void draw_grid(SDL_Renderer* renderer)
{
	using namespace PC;
	SDL_SetRenderDrawColor(renderer, 0x46, 0x46, 0x46, 0xaa);
	for (int i = size / 2; i < window_width; i += size / 2)
	{
		SDL_RenderDrawLine(renderer, i, 0, i, window_height);
	}
	for (int i = size / 2; i < window_height; i += size / 2)
	{
		SDL_RenderDrawLine(renderer, 0, i, window_width, i);
	}
}