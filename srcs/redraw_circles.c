#include "collision.h"

void	redraw_circles(SDL_Renderer *renderer)
{
	int	i;

	i = 0;
	while (i < ball_count)
	{

		SDL_SetRenderDrawColor(renderer, balls[i].r, balls[i].g, balls[i].b, 255);
		draw_all_circles(renderer, (int)balls[i].x, (int)balls[i].y, balls[i].radius);
	i++;
	}
}
