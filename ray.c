
#include "wolf.h"

int		check_wall(int x, int y, t_wolf *wolf)
{
	x = x / 64;
	y = y / 64;
	printf("x: %d, y: %d\n", x, y);
	wolf->map = wolf->first;
	while (wolf->map->y != y)
		wolf->map = wolf->map->next;
	while (wolf->map->x != x)
		wolf->map = wolf->map->next;
	return (wolf->map->value);
}



int		ray_x(t_wolf *wolf)
{
	int		x;
	int		y;
	int		dst;

	if (wolf->player->view >= 90 && wolf->player->view <= 270)
		x = floor(wolf->player->x / 64) * 64 + 64;
	else
		x = floor(wolf->player->x / 64) * 64 - 1;
	y = wolf->player->y  + (wolf->player->x - x) * tan(wolf->player->view);
	while (check_wall(x, y, wolf) != 1)
	{
		if (wolf->player->view >= 90 && wolf->player->view <= 270)
			x += 64;
		else
			x -= 64;
		y = y + (64 / tan(wolf->player->view));
	}
	dst = sqrt(pow(x - wolf->player->x, 2) + pow(y - wolf->player->y, 2));
	return (dst);
}	

int			ray_y(t_wolf *wolf)
{
	int		x;
	int		y;
	int		dst;

	if (wolf->player->view >= 0 && wolf->player->view <= 180)
		y = floor(wolf->player->y / 64) * 64 - 1;
	else
		y = floor(wolf->player->y / 64) * 64 + 64;
	x = wolf->player->x + (wolf->player->y - y) / tan(wolf->player->view);
	while (check_wall(x, y, wolf) != 1)
	{
		if (wolf->player->view >= 0 && wolf->player->view <= 180)
			y -= 64;
		else
			y += 64;
		x = x + (64 / tan(wolf->player->view));
	}
	dst = sqrt(pow(x - wolf->player->x, 2) + pow(y - wolf->player->y, 2));
	return (dst);
}

void		ft_raycasting(t_wolf *wolf)
{
	double		dst;
	int			col;
	int			line;

	col = 0;
	while (wolf->player->view <= wolf->player->angle + 30)
	{
		printf("view :%f\n", wolf->player->view);
		dst = (ray_y(wolf) >= ray_x(wolf)) ? ray_x(wolf) : ray_y(wolf);
		dst = cos(60) * 64 * wolf->player->dst / dst;
		wolf->player->view += 0.1875;
		line = -1;
		while (++line < (WIN_HEIGHT / 2) - (dst / 2))
			put_pxl(wolf->data, col, line, SKY);
		while (++line < (WIN_HEIGHT / 2) + (dst / 2))
			put_pxl(wolf->data, col, line, NORTH);
		while (++line < WIN_HEIGHT)
			put_pxl(wolf->data, col, line, GROUND);
		col++;
	}
}
