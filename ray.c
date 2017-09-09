
#include "wolf.h"

int		check_wall(int x, int y, t_wolf *wolf)
{
	x = x / 64;
	y = y / 64;
	wolf->map = wolf->first;
	while (wolf->map->y != y && wolf->map->next != NULL)
		wolf->map = wolf->map->next;
	while (wolf->map->x != x)
		wolf->map = wolf->map->next;
	return (wolf->map->value);
}

int		ray_x(t_wolf *wolf)
{
	double		distance;
	int			x;
	int			y;

	if (wolf->player->view >= 90 && wolf->player->view <= 180)
		x = (wolf->player->x / 64) + 64;
	else
		x = (wolf->player->x / 64) - 64;
	y = wolf->player->y + ((wolf->player->x - x) * tan(wolf->player->view));
	while (check_wall(x, y, wolf) != 1)
	{
		y = y * 64 * tan(wolf->player->view);
		if (wolf->player->view > 180 && wolf->player->view < 360)
			y *= -1;
		x += 64;
	}
	distance = sqrt(pow((x - wolf->player->x),2) + pow((y - wolf->player->y), 2));
	return (distance);
}

int			ray_y(t_wolf *wolf)
{
	double		distance;
	int			x;
	int			y;

	if (wolf->player->view >= 0 && wolf->player->view <= 180)
		y = (wolf->player->y / 64) + 64;
	else
		y = (wolf->player->y / 64) - 64;
	x = wolf->player->x + ((wolf->player->y - y) * tan(wolf->player->view));
	while (check_wall(x, y, wolf) != 1)
	{
		y += 64;
		x = x * 64 * tan(wolf->player->view);
		if (wolf->player->view > 180 && wolf->player->view < 360)
			x *= -1;
	}
	distance = sqrt(pow((x - wolf->player->x),2) + pow((y - wolf->player->y), 2));
	return (distance);
}

void		ft_raycasting(t_wolf *wolf)
{
	double		dst;
	int			col;
	int			line;

	col = 0;
	while (wolf->player->view <= wolf->player->angle + 30)
	{
		line = -1;
		printf("%d\n", ray_y(wolf));
		//dst = (ray_y(wolf) > ray_x(wolf)) ? ray_x(wolf) : ray_y(wolf);
		dst = cos(60) * 64 * wolf->player->dst / dst;
		wolf->player->view += 0.1875;
		while (++line < (WIN_HEIGHT / 2) - (dst / 2))
			put_pxl(wolf->data, col, line, SKY);
		while (++line < (WIN_HEIGHT / 2) + (dst / 2))
			put_pxl(wolf->data, col, line, NORTH);
		while (++line < WIN_HEIGHT)
			put_pxl(wolf->data, col, line, GROUND);
		col++;
	}
}
