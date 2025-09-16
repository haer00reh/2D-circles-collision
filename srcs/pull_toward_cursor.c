#include "collision.h"

void pull_toward_cursor(int target_x, int target_y, float force)
{
	int	i;
	float	dx;
	float	dy;
	float	dist;

	i = 0;
	while (i < ball_count)
	{
	dx = target_x - balls[i].x;
	dy = target_y - balls[i].y;

	dist = sqrtf(dx*dx + dy*dy);
	if (dist == 0)
		continue;

	balls[i].x += (dx / dist) * force;
	balls[i].y += (dy / dist) * force;
	i++;
	}
}

