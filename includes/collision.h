# ifndef COLLISION_H
# define COLLISION_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

	typedef struct 
	{
		float x, y;
		float vx, vy;
		int radius;
		Uint8 r, g, b;
	} ball;

	extern ball *balls;
	extern int ball_count;

	void	handle_collisions();
	void	redraw_circles(SDL_Renderer *renderer);
	void	pull_toward_cursor(int target_x, int target_y, float force);
	void	free_circles(void);
	void	draw_all_circles(SDL_Renderer *renderer, int x0, int y0, int radius);
	void	add_circle(float x, float y);

#endif
