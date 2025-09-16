#include "collision.h"

void handle_collisions() {
	int	i;
	int	j;

	i = 0;
	while (i < ball_count)
	{
		j = i + 1;
        while (j < ball_count)
	{
		float dx = balls[j].x - balls[i].x;
		float dy = balls[j].y - balls[i].y;
		float dist = sqrtf(dx*dx + dy*dy);
		float min_dist = balls[i].radius + balls[j].radius;

		if (dist < min_dist)
		{
			float temp_vx = balls[i].vx;
			float temp_vy = balls[i].vy;
			balls[i].vx = balls[j].vx;
			balls[i].vy = balls[j].vy;
			balls[j].vx = temp_vx;
			balls[j].vy = temp_vy;

			float olap = 0.5f * (min_dist - dist);
			balls[i].x -= olap * dx / dist;
			balls[i].y -= olap * dy / dist;
			balls[j].x += olap * dx / dist;
			balls[j].y += olap * dy / dist;
		}
	    	j++;
		}
	i++;
	}
}
