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
		if (wolf->vect->ray_len_X < wolf->vect->ray_len_Y)
		{
			wolf->vect->ray_len_X += wolf->vect->scaleX;
			wolf->vect->mapX += wolf->zone_X;
			wolf->side = 0;
		}
		else
		{
			wolf->vect->ray_len_Y += wolf->vect->scaleY;
			wolf->vect->mapY += wolf->zone_Y;
			wolf->side = 1;
		}
		if (check_wall(wolf, wolf->vect->mapX, wolf->vect->mapY) == 1)
		{
			wolf->hit = 1;
			if (wolf->side == 0)
				wolf->wallDist = (wolf->vect->mapX - wolf->player->x + (1 - wolf->zone_X) / 2) / wolf->vect->rayDirX;
			else
				wolf->wallDist = (wolf->vect->mapY - wolf->player->y + (1 - wolf->zone_Y) / 2) / wolf->vect->rayDirY;
		}
	}
}

void		ft_ray_dir(t_wolf *wolf)
{
	if (wolf->vect->rayDirX < 0)
	{
		wolf->zone_X = -1;
		wolf->vect->ray_len_X = (wolf->player->x - wolf->vect->mapX) * wolf->vect->scaleX;
	}
	else
	{
		wolf->zone_X = 1;
		wolf->vect->ray_len_X = (wolf->vect->mapX + 1.0 - wolf->player->x) * wolf->vect->scaleX;
	}
	if (wolf->vect->rayDirY < 0)
	{
		wolf->zone_Y = -1;
		wolf->vect->ray_len_Y = (wolf->player->y - wolf->vect->mapY) * wolf->vect->scaleY;
	}
	else
	{
		wolf->zone_Y = 1;
		wolf->vect->ray_len_Y = (wolf->vect->mapY + 1.0 - wolf->player->y) * wolf->vect->scaleY;
	}
}

void		ft_ray_ini(t_wolf *wolf, int i)
{
	wolf->player->space_ray = (2 * i) / (double)WIN_LEN - 1;
	wolf->vect->rayDirX = wolf->vect->view_X + wolf->vect->screen_X * wolf->player->space_ray;
	wolf->vect->rayDirY = wolf->vect->view_Y + wolf->vect->screen_Y * wolf->player->space_ray;
	wolf->vect->scaleX = sqrt(1 + (wolf->vect->rayDirY * wolf->vect->rayDirY) / (wolf->vect->rayDirX * wolf->vect->rayDirX));
	wolf->vect->scaleY = sqrt(1 + (wolf->vect->rayDirX * wolf->vect->rayDirX) / (wolf->vect->rayDirY * wolf->vect->rayDirY));
	wolf->hit = 0;
	wolf->wallDist = -1;
	wolf->side = -1;
}

void		ft_raycasting(t_wolf *wolf)
{
	int		i;

	i = -1;
	while (++i < WIN_LEN)
	{
		wolf->vect->mapX = (int)wolf->player->x;
		wolf->vect->mapY = (int)wolf->player->y;
		ft_ray_ini(wolf, i);
		ft_ray_dir(wolf);
		ft_ray_hit(wolf);
		ft_draw_col(wolf, i);
	}
}
