#include "collision.h"


void	draw_all_circles(SDL_Renderer *renderer, int x0, int y0, int radius)
{
	int	y;
	int	x;

	y = -radius;
	while (y <= radius)
	{
	x = -radius;
		while (x <= radius)
		{
			if (x * x + y * y <= radius * radius)
			{
			SDL_RenderDrawPoint(renderer, x0 + x, y0 + y);
			}
		x++;
		}
	y++;
	}
}
