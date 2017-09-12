
#include "wolf.h"

int		check_wall(int x, int y, t_wolf *wolf)
{
	if (y < 0)
		y = 0;
	if (x < 0)
		x = 0;
	printf("x: %d, y: %d\n", x, y);
	x = x / 64;
	y = y / 64;
	wolf->map = wolf->first;
	while (wolf->map->y != y)
		wolf->map = wolf->map->next;
	while (wolf->map->x != x)
		wolf->map = wolf->map->next;
	return (wolf->map->value);
}

void	ft_ray_ini(t_wolf *wolf)
{
	if ((wolf->player->view > 0 && wolf->player->view < 90) || (wolf->player->view > 180 && wolf->player->view < 270))
		wolf->ray->x_step = 1;
	else
		wolf->ray->x_step = -1;
	if ((wolf->player->view >= 0 && wolf->player->view <= 180))
		wolf->ray->y_step = 1;
	else
		wolf->ray->y_step = -1;
}

int		ray_x(t_wolf *wolf)
{
	int		x;
	int		y;
	int		dst;

	if (wolf->player->view >= 0 && wolf->player->view <= 180)
	{
		y = floor(wolf->player->y / 64) * 64 - 1;
		wolf->ray->beta = wolf->ray->x_step * (90 - wolf->player->view);
		wolf->ray->beta = wolf->ray->beta * M_PI / 180;
		x = wolf->player->x - wolf->ray->x_step * tan(wolf->ray->beta) * (wolf->player->y - y);
		while (check_wall(x, y, wolf) != 1)
		{
			x = x + wolf->ray->x_step * (64 / tan(wolf->ray->beta));
			y -= 64;
		}
	}
	else
	{
		y = ceil(wolf->player->y / 64) * 64;
		wolf->ray->beta = wolf->ray->x_step * (270 - wolf->player->view);
		wolf->ray->beta = wolf->ray->beta * M_PI / 180;
		x = wolf->player->x - wolf->ray->x_step * tan(wolf->ray->beta) * (wolf->player->y - y);
		while (check_wall(x, y, wolf) != 1)
		{
			x = x + wolf->ray->x_step * (64 / tan(wolf->ray->beta));
			y += 64;
		}
	}
	dst = sqrt(pow(x - wolf->player->x, 2) + pow(y - wolf->player->y, 2));
	return (dst);
}	

int			ray_y(t_wolf *wolf)
{
	int		x;
	int		y;
	int		dst;

	if (wolf->player->view >= 90 && wolf->player->view <= 270)
	{
		x = ceil(wolf->player->x / 64) * 64;
		wolf->ray->beta = wolf->ray->y_step * (180 - wolf->player->view);
		wolf->ray->beta = wolf->ray->beta * M_PI / 180;
		y = wolf->player->y + wolf->ray->y_step * tan(wolf->ray->beta) * (wolf->player->x - x);
		while (check_wall(x, y, wolf) != 1)
		{
			x += 64;
			y = y + wolf->ray->y_step * (64 * tan(wolf->ray->beta));
		}
	}
	else
	{
		x = floor(wolf->player->x / 64) * 64 - 1;
		if (wolf->player->view >= 0 && wolf->player->view < 90)
			wolf->ray->beta = wolf->player->view;
		else
			wolf->ray->beta = 270 - wolf->player->view;
		wolf->ray->beta = wolf->ray->beta * M_PI / 180;
		y = wolf->player->y - wolf->ray->y_step * tan(wolf->ray->beta) * (wolf->player->x - x);
		while (check_wall(x, y, wolf) != 1)
		{
			x -= 64;
			y = y - wolf->ray->y_step * 64 * tan(wolf->ray->beta);
		}
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
		printf("view :%f\nray: %d\n", wolf->player->view, col);
		ft_ray_ini(wolf);
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
