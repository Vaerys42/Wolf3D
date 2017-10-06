/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 19:58:35 by kboucaud          #+#    #+#             */
/*   Updated: 2017/10/05 19:58:38 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void		ft_draw_col(t_wolf *wolf, int x)
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		i;

	i = -1;
	line_height = (int)(WIN_HEIGHT / wolf->wallDist);
	draw_start = -line_height / 2 + WIN_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + WIN_HEIGHT / 2;
	if (draw_end >= WIN_HEIGHT)
		draw_end = WIN_HEIGHT - 1;
	while (++i < draw_start)
		put_pxl(wolf->data, x, i, SKY);
	i--;
	while (++i <= draw_end)
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
				wolf->wallDist = (wolf->vect->mapX - wolf->vect->rayPosX
				+ (1 - wolf->stepX) / 2) / wolf->vect->rayDirX;
			else
				wolf->wallDist = (wolf->vect->mapY - wolf->vect->rayPosY
				+ (1 - wolf->stepY) / 2) / wolf->vect->rayDirY;
		}
	}
}

void		ft_ray_dir(t_wolf *wolf)
{
	if (wolf->vect->rayDirX < 0)
	{
		wolf->stepX = -1;
		wolf->vect->sideDistX = (wolf->vect->rayPosX
		- wolf->vect->mapX) * wolf->vect->deltaDistX;
	}
	else
	{
		wolf->stepX = 1;
		wolf->vect->sideDistX = (wolf->vect->mapX
		+ 1.0 - wolf->vect->rayPosX) * wolf->vect->deltaDistX;
	}
	if (wolf->vect->rayDirY < 0)
	{
		wolf->stepY = -1;
		wolf->vect->sideDistY = (wolf->vect->rayPosY
		- wolf->vect->mapY) * wolf->vect->deltaDistY;
	}
	else
	{
		wolf->stepY = 1;
		wolf->vect->sideDistY = (wolf->vect->mapY +
		1.0 - wolf->vect->rayPosY) * wolf->vect->deltaDistY;
	}
}

void		ft_ray_ini(t_wolf *wolf, int i)
{
	wolf->player->cameraX = (2 * i) / (double)WIN_LEN - 1;
	wolf->vect->rayDirX = wolf->vect->dirX + wolf->vect->planeX
	* wolf->player->cameraX;
	wolf->vect->rayDirY = wolf->vect->dirY + wolf->vect->planeY
	* wolf->player->cameraX;
	wolf->vect->mapX = (int)wolf->vect->rayPosX;
	wolf->vect->mapY = (int)wolf->vect->rayPosY;
	wolf->vect->deltaDistX = sqrt(1 + (wolf->vect->rayDirY *
	wolf->vect->rayDirY) / (wolf->vect->rayDirX * wolf->vect->rayDirX));
	wolf->vect->deltaDistY = sqrt(1 + (wolf->vect->rayDirX *
	wolf->vect->rayDirX) / (wolf->vect->rayDirY * wolf->vect->rayDirY));
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
	while (++i < WIN_LEN)
	{
		ft_ray_ini(wolf, i);
		ft_ray_dir(wolf);
		ft_ray_hit(wolf);
		ft_draw_col(wolf, i);
	}
}
