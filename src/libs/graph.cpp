#include <SDL2/SDL_video.h>
#include "../headers/graph.h"

#if (HAVE_SDL2_SDL_H == 1 || HAVE_SDL_H == 1 || HAVE_SDL_SDL_H == 1)

bool SDL_start(SDL_Window** window, SDL_Renderer** renderer, PC *computer)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "| SDL: Initialization failed! Error: " << SDL_GetError() << "\n";
		return false;
	}

    SDL_DisplayMode current;

    for(int i = 0; i < SDL_GetNumVideoDisplays(); ++i){

        int should_be_zero = SDL_GetCurrentDisplayMode(i, &current);
        if (should_be_zero != 0) {
            std::cout << "| SDL: Could not get display mode for video display! Error: " << SDL_GetError() << "\n";
        }
    }

    computer->window_width = 2 * current.w / 3;
    computer->window_height = 2 * current.h / 3;

	*window = SDL_CreateWindow("Graphing plot",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		computer->window_width, computer->window_height, SDL_WINDOW_SHOWN);
	if (*window == nullptr)
	{
		std::cout << "| SDL: Failed to create a window! Error: " << SDL_GetError() << "\n";
		SDL_Quit();
		return false;
	}

	*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
	if (*renderer == nullptr)
	{
		std::cout << "| SDL: Failed to create a renderer! Error: " << SDL_GetError() << "\n";
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

void plotGraph(SDL_Renderer* renderer, func& foo, const int x_pos, const int y_pos, PC *computer)
{

	SDL_SetRenderDrawColor(renderer, 0xff, 0xcc, 0x00, 0x00);

	for (int i = 0; i < computer->window_width; i++)
	{
		if (abs(eval(foo, (i - y_pos)) - DBL_MAX) <= 0.000000000001 || abs(eval(foo, (i + 1 - y_pos)) - DBL_MAX) <= 0.000000001)
			continue;
		SDL_RenderDrawLine(renderer,
			i, -computer->size / 2 * eval(foo, (i - y_pos) / (computer->size / 2.0)) + x_pos,
			i + 1, -computer->size / 2 * eval(foo, (i + 1 - y_pos) / (computer->size / 2.0)) + x_pos);
	}
}

void draw_y_axis(SDL_Renderer* renderer, const int y_pos, PC *computer)
{

	SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0x00);

	//draw y-axis
	SDL_RenderDrawLine(renderer, y_pos, 0, y_pos, computer->window_height);

	// draw arrow on y-axis
	SDL_RenderDrawLine(renderer, y_pos, 0, y_pos - computer->size / 16, computer->size / 4);
	SDL_RenderDrawLine(renderer, y_pos, 0, y_pos + computer->size / 16, computer->size / 4);

	for (int i = computer->size / 2; i <= computer->window_height; i += computer->size / 2)
	{
		SDL_RenderDrawLine(renderer, y_pos - computer->size / 15, i, y_pos + computer->size / 15, i);
	}
}

void draw_x_axis(SDL_Renderer* renderer, const int x_pos, PC *computer)
{

	SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0x00);

	// draw x-axis
	SDL_RenderDrawLine(renderer, 0, x_pos, computer->window_width, x_pos);
	// draw arrow on x-axis
	SDL_RenderDrawLine(renderer, computer->window_width, x_pos,
                       computer->window_width - computer->size / 4, x_pos - computer->size / 16);
	SDL_RenderDrawLine(renderer, computer->window_width, x_pos,
                       computer->window_width - computer->size / 4, x_pos + computer->size / 16);

	// draw divisions on x-axis
	for (int i = computer->size / 2; i < computer->window_width; i += computer->size / 2)
	{
		SDL_RenderDrawLine(renderer, i, x_pos - 4, i, x_pos + 4);
	}
}

void draw_grid(SDL_Renderer* renderer, PC *computer)
{

	SDL_SetRenderDrawColor(renderer, 0x46, 0x46, 0x46, 0xaa);
	for (int i = computer->size / 2; i < computer->window_width; i += computer->size / 2)
	{
		SDL_RenderDrawLine(renderer, i, 0, i, computer->window_height);
	}
	for (int i = computer->size / 2; i < computer->window_height; i += computer->size / 2)
	{
		SDL_RenderDrawLine(renderer, 0, i, computer->window_width, i);
	}
}

#endif