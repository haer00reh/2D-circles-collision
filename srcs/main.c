#include "collision.h"

int	main(void)
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window	*window = SDL_CreateWindow("collisions", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	SDL_Renderer	*renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	int		running = 1;
	SDL_Event	eve;
	int 		flag_MouseDown = 0;
	static		Uint32 last_spawn = 0;

	while (running)
	{
		while (SDL_PollEvent(&eve)) 
		{
			if (eve.type == SDL_QUIT)
			{
			running = 0;
			}
			else if (eve.type == SDL_MOUSEBUTTONDOWN)
			{
			flag_MouseDown = 1;
			}
			else if (eve.type == SDL_MOUSEBUTTONUP)
			{
			flag_MouseDown = 0;
			}
	        }
        
	if (flag_MouseDown)
	{
	Uint32 now = SDL_GetTicks();
		if (now - last_spawn > 30)
		{
		int mouse_x, mouse_y;
		SDL_GetMouseState(&mouse_x, &mouse_y);
		add_circle(mouse_x, mouse_y);
		last_spawn = now;
		}

	}

	const Uint8 *keystate = SDL_GetKeyboardState(NULL);
	if (keystate[SDL_SCANCODE_P]) {
		int mx, my;
		SDL_GetMouseState(&mx, &my);
		pull_toward_cursor(mx, my, 50.0f);
	}

	handle_collisions();
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	redraw_circles(renderer);
	SDL_RenderPresent(renderer);
	}

	free_circles();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}
