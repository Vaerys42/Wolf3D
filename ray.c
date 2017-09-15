
#include "wolf.h"

int			check_wall(t_wolf *wolf, int x, int y)
{
	if (x < 0)
		x = 0;
	if (x > 21)
		x = 21;
	if (y < 0)
		y = 0;
	if (y > 10)
		y = 10;
	wolf->map = wolf->first;
	while (wolf->map->y != y)
		wolf->map = wolf->map->next;
	while (wolf->map->x != x)
		wolf->map = wolf->map->next;
	return (wolf->map->value);
}

int			get_color(t_wolf *wolf)
{
	if (wolf->side == 1)
	{
			if ((wolf->stepX == -1 &&  wolf->stepY == -1) || (wolf->stepX == 1 && wolf->stepY == -1))
				return (WEST);
			if ((wolf->stepX == -1 && wolf->stepY == 1) || (wolf->stepX == 1 && wolf->stepY == 1))
				return (EAST);
	}
	if ((wolf->stepX == -1 && wolf->stepY == -1) || (wolf->stepX == -1 && wolf->stepY == 1))
		return (NORTH);
	return (SOUTH);
}

void		ft_draw_col(t_wolf *wolf, int x)
{
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		i;

	i = -1;
	lineHeight =  (int)(WIN_HEIGHT / wolf->wallDist);
	drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;
	if (drawStart < 0)
		drawStart = 0;
	drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;
	if (drawEnd >= WIN_HEIGHT)
		drawEnd = WIN_HEIGHT - 1;
	while (++i < drawStart)
		put_pxl(wolf->data, x, i, SKY);
	i--;
	while (++i <= drawEnd)
		put_pxl(wolf->data, x, i, get_color(wolf));
	i--;
	while (++i < WIN_HEIGHT)
		put_pxl(wolf->data, x, i, GROUND);

}

void		ft_ray_hit(t_wolf *wolf)
{
	while (wolf->hit == 0)
	{
		if (wolf->vect->sideDistX < wolf->vect->sideDistY)
		{
			wolf->vect->sideDistX += wolf->vect->deltaDistX;
			wolf->vect->mapX += wolf->stepX;
			wolf->side = 0;
		}
		else
		{
			wolf->vect->sideDistY += wolf->vect->deltaDistY;
			wolf->vect->mapY += wolf->stepY;
			wolf->side = 1;
		}
		if (check_wall(wolf, wolf->vect->mapX, wolf->vect->mapY) == 1)
		{
			wolf->hit = 1;
			if (wolf->side == 0)
				wolf->wallDist = (wolf->vect->mapX - wolf->vect->rayPosX + (1 - wolf->stepX) / 2) / wolf->vect->rayDirX;
			else
				wolf->wallDist = (wolf->vect->mapY - wolf->vect->rayPosY + (1 - wolf->stepY) / 2) / wolf->vect->rayDirY;
		}
	}
}

void		ft_ray_dir(t_wolf *wolf)
{
	if (wolf->vect->rayDirX < 0)
	{
		wolf->stepX = - 1;
		wolf->vect->sideDistX = (wolf->vect->rayPosX - wolf->vect->mapX) * wolf->vect->deltaDistX;
	}
	else
	{
		wolf->stepX = 1;
		wolf->vect->sideDistX = (wolf->vect->mapX + 1.0 - wolf->vect->rayPosX) * wolf->vect->deltaDistX;
	}
	if (wolf->vect->rayDirY < 0)
	{
		wolf->stepY = -1;
		wolf->vect->sideDistY = (wolf->vect->rayPosY - wolf->vect->mapY) * wolf->vect->deltaDistY;
	}
	else
	{
		wolf->stepY = 1;
		wolf->vect->sideDistY = (wolf->vect->mapY + 1.0 - wolf->vect->rayPosY) * wolf->vect->deltaDistY;
	}
}

void		ft_ray_ini(t_wolf *wolf, int i)
{
	wolf->player->cameraX = (2 * i) / (double)WIN_LEN - 1;
	wolf->vect->rayDirX = wolf->vect->dirX + wolf->vect->planeX * wolf->player->cameraX;
	wolf->vect->rayDirY = wolf->vect->dirY + wolf->vect->planeY * wolf->player->cameraX;
	wolf->vect->mapX = (int)wolf->vect->rayPosX;
	wolf->vect->mapY = (int)wolf->vect->rayPosY;
	wolf->vect->deltaDistX = sqrt(1 + (wolf->vect->rayDirY * wolf->vect->rayDirY) / (wolf->vect->rayDirX * wolf->vect->rayDirX));
	wolf->vect->deltaDistY = sqrt(1 + (wolf->vect->rayDirX * wolf->vect->rayDirX) / (wolf->vect->rayDirY * wolf->vect->rayDirY));
	wolf->hit = 0;
	wolf->wallDist = -1;
	wolf->side = -1;
}

void		ft_raycasting(t_wolf *wolf)
{
	int		i;

	i = -1;
	wolf->vect->rayPosX = wolf->player->x;
	wolf->vect->rayPosY = wolf->player->y;
	while(++i < 320)
	{
		ft_ray_ini(wolf, i);
		ft_ray_dir(wolf);
		ft_ray_hit(wolf);
		ft_draw_col(wolf, i);
	}
}
