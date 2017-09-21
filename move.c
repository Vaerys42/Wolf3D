/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 12:04:35 by kboucaud          #+#    #+#             */
/*   Updated: 2017/09/21 12:04:37 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_rotate_left(t_wolf *wolf)
{
	double		old_dir_x;
	double		old_plane_x;

	old_dir_x = wolf->vect->dirX;
	wolf->vect->dirX = wolf->vect->dirX * cos(wolf->rot_speed)
	- wolf->vect->dirY * sin(wolf->rot_speed);
	wolf->vect->dirY = old_dir_x * sin(wolf->rot_speed)
	+ wolf->vect->dirY * cos(wolf->rot_speed);
	old_plane_x = wolf->vect->planeX;
	wolf->vect->planeX = wolf->vect->planeX * cos(wolf->rot_speed)
	- wolf->vect->planeY * sin(wolf->rot_speed);
	wolf->vect->planeY = old_plane_x * sin(wolf->rot_speed)
	+ wolf->vect->planeY * cos(wolf->rot_speed);
}

void	ft_rotate_right(t_wolf *wolf)
{
	double		old_dir_x;
	double		old_plane_x;

	old_dir_x = wolf->vect->dirX;
	wolf->vect->dirX = wolf->vect->dirX * cos(-wolf->rot_speed)
	- wolf->vect->dirY * sin(-wolf->rot_speed);
	wolf->vect->dirY = old_dir_x * sin(-wolf->rot_speed)
	+ wolf->vect->dirY * cos(-wolf->rot_speed);
	old_plane_x = wolf->vect->planeX;
	wolf->vect->planeX = wolf->vect->planeX * cos(-wolf->rot_speed)
	- wolf->vect->planeY * sin(-wolf->rot_speed);
	wolf->vect->planeY = old_plane_x * sin(-wolf->rot_speed)
	+ wolf->vect->planeY * cos(-wolf->rot_speed);
}

void	ft_move(t_wolf *wolf)
{
	if (wolf->player->up == 1)
	{
		if (check_wall(wolf, (int)(wolf->player->x +
			(wolf->vect->dirX * wolf->move_speed)), (int)wolf->player->y) == 0)
			wolf->player->x += wolf->vect->dirX * wolf->move_speed;
		if (check_wall(wolf, (int)wolf->player->x,
		(int)(wolf->player->y + (wolf->vect->dirY * wolf->move_speed))) == 0)
			wolf->player->y += wolf->vect->dirY * wolf->move_speed;
	}
	if (wolf->player->down == 1)
	{
		if (check_wall(wolf, (int)wolf->player->x -
			(wolf->vect->dirX * wolf->move_speed), (int)wolf->player->y) == 0)
			wolf->player->x -= wolf->vect->dirX * wolf->move_speed;
		if (check_wall(wolf, (int)wolf->player->x, (int)wolf->player->y
			- (wolf->vect->dirY * wolf->move_speed)) == 0)
			wolf->player->y -= wolf->vect->dirY * wolf->move_speed;
	}
	if (wolf->player->right == 1)
		ft_rotate_right(wolf);
	if (wolf->player->left == 1)
		ft_rotate_left(wolf);
	ft_raycasting(wolf);
	mlx_put_image_to_window(wolf->data->mlx, wolf->data->mlx_window,
	wolf->data->mlx_image, 0, 0);
}
