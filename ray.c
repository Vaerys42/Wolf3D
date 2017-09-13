
#include "wolf.h"

int		check_wall(int x, int y, t_wolf *wolf)
{
	x = x / 64;
	y = y / 64;
	if (y <= 0 || y >= 200)
		return (1);
	if (x <= 0 || x >= 320)
		return (1);
	wolf->map = wolf->first;
	while (wolf->map->y != y)
		wolf->map = wolf->map->next;
	while (wolf->map->x != x)
		wolf->map = wolf->map->next;
	return (wolf->map->value);
}

void	ft_ray_ini(t_wolf *wolf)
{
	if (wolf->player->view > 0 && wolf->player->view < 180)
		wolf->ray->x_step = 1;
	else
		wolf->ray->x_step = -1;
	if (wolf->player->view > 90 && wolf->player->view < 270)
		wolf->ray->y_step = 1;
	else 
		wolf->ray->y_step = -1;
}

int		ray_x(t_wolf *wolf)
{
	int		x;
	int		y;
	int		dst;

	//printf("ray x\n");
	if (wolf->player->view > 0 && wolf->player->view < 180)
		y = nearbyint(wolf->player->y / 64) * 64 - 1;
	else
		y = nearbyint(wolf->player->y / 64) * 64 + 64;
	x = nearbyint(wolf->player->x + ((wolf->player->y - y) / tan(((360 - wolf->player->view) * M_PI) / 180)));
	while (check_wall(x, y, wolf) != 1)
	{
		y = y + wolf->ray->x_step * 64;
		x = x + 64 / tan((wolf->player->view * M_PI) / 180);
	}
	printf("x: %d, y: %d\n", x, y);
	dst = sqrt(pow(x - wolf->player->x, 2) + pow(y - wolf->player->y, 2));
	return (dst);
}	

int			ray_y(t_wolf *wolf)
{
	int		x;
	int		y;
	int		dst;

	//printf("ray y\n");
	if (wolf->player->view > 90 && wolf->player->view < 270)
		x = nearbyint(wolf->player->x / 64) * 64 + 64;
	else
		x = nearbyint(wolf->player->x / 64) * 64 - 1;
	y = nearbyint(wolf->player->y + (wolf->player->x - x) * tan(((360 - wolf->player->view) * M_PI) / 180));
	while (check_wall(x, y, wolf) != 1)
	{
		x = x + wolf->ray->y_step * 64;
		y = y + (64 * tan((wolf->player->view * M_PI) / 180));
	}
	//printf("x: %d, y: %d\n", x, y);
	dst = sqrt(pow(x - wolf->player->x, 2) + pow(y - wolf->player->y, 2));
	return (dst);
}

void		ft_raycasting(t_wolf *wolf)
{
	int			dst;
	int			col;
	int			line;
	int			height;
	int			max;

	col = 0;
	while (wolf->player->view <= wolf->player->angle - 10)
	{
		//printf("view :%f\nray: %d\n", wolf->player->view, col);
		ft_ray_ini(wolf);
		dst = (ray_y(wolf) >= ray_x(wolf)) ? ray_x(wolf) : ray_y(wolf);
		dst = dst * cos((wolf->player->view * M_PI) / 180);
		height = 100 - (64 * dst / 277);
		max = height / 2;
		//printf("dst :%d height : %d\n", dst, height);
		wolf->player->view += 0.1875;
		if (wolf->player->view > 360)
			wolf->player->view = 0;
		if (wolf->player->view < 0)
			wolf->player->view = 360;
		line = -1;
		while (++line < max)
			put_pxl(wolf->data, col, line, SKY);
		while (++line < max + height)
			put_pxl(wolf->data, col, line, NORTH);
		while (++line < WIN_HEIGHT)
			put_pxl(wolf->data, col, line, GROUND);
		col++;
	}
}
