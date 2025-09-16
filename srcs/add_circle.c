#include "collision.h"

	ball	*balls = NULL;
	int	ball_count = 0;

void	add_circle(float x, float y)
{
	ball new_ball = {
	.x = x, .y = y,
	.vx = 0, .vy = 0,
	.radius = 10,
	.r = rand() % 256,
	.g = rand() % 256,
	.b = rand() % 256
	};

	ball *tmp = realloc(balls, (ball_count + 1) * sizeof(ball));
	
	if (!tmp)
	{
	fprintf(stderr, "realloc failed, git MORE MEMORY!!");
	return;
	}
	balls = tmp;
	balls[ball_count] = new_ball;
	ball_count++;
}
