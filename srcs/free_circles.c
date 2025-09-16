#include "collision.h"

void	free_circles(void)
{
	free(balls);
	balls = 0;
	ball_count = 0;
}
