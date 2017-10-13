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

#include "../wolf.h"

void	ft_rotate_left(t_wolf *wolf)
{
	double		old_dir_x;
	double		old_screen__x;

	old_dir_x = wolf->vect->dirX;
	wolf->vect->dirX = wolf->vect->dirX * cos(wolf->rot_speed)
	- wolf->vect->dirY * sin(wolf->rot_speed);
	wolf->vect->dirY = old_dir_x * sin(wolf->rot_speed)
	+ wolf->vect->dirY * cos(wolf->rot_speed);
	old_screen__x = wolf->vect->screen_X;
	wolf->vect->screen_X = wolf->vect->screen_X * cos(wolf->rot_speed)
	- wolf->vect->screen_Y * sin(wolf->rot_speed);
	wolf->vect->screen_Y = old_screen__x * sin(wolf->rot_speed)
	+ wolf->vect->screen_Y * cos(wolf->rot_speed);
}

void	ft_rotate_right(t_wolf *wolf)
{
	double		old_dir_x;
	double		old_screen__x;

	old_dir_x = wolf->vect->dirX;
	wolf->vect->dirX = wolf->vect->dirX * cos(-wolf->rot_speed)
	- wolf->vect->dirY * sin(-wolf->rot_speed);
	wolf->vect->dirY = old_dir_x * sin(-wolf->rot_speed)
	+ wolf->vect->dirY * cos(-wolf->rot_speed);
	old_screen__x = wolf->vect->screen_X;
	wolf->vect->screen_X = wolf->vect->screen_X * cos(-wolf->rot_speed)
	- wolf->vect->screen_Y * sin(-wolf->rot_speed);
	wolf->vect->screen_Y = old_screen__x * sin(-wolf->rot_speed)
	+ wolf->vect->screen_Y * cos(-wolf->rot_speed);
}

void	ft_move(t_wolf *wolf)
{
	if (wolf->player->up == 1)
	{
		if (check_wall(wolf, (wolf->player->x +
			(wolf->vect->dirX * wolf->move_speed)), wolf->player->y) == 0)
			wolf->player->x += wolf->vect->dirX * wolf->move_speed;
		if (check_wall(wolf, wolf->player->x,
		(wolf->player->y + (wolf->vect->dirY * wolf->move_speed))) == 0)
			wolf->player->y += wolf->vect->dirY * wolf->move_speed;
	}
	if (wolf->player->down == 1)
	{
		if (check_wall(wolf, wolf->player->x -
		(wolf->vect->dirX * wolf->move_speed), wolf->player->y) == 0)
			wolf->player->x -= wolf->vect->dirX * wolf->move_speed;
		if (check_wall(wolf, wolf->player->x, wolf->player->y -
		(wolf->vect->dirY * wolf->move_speed)) == 0)
			wolf->player->y -= wolf->vect->dirY * wolf->move_speed;
	}
	if (wolf->player->right == 1)
		ft_rotate_right(wolf);
	if (wolf->player->left == 1)
		ft_rotate_left(wolf);
	ft_raycasting(wolf);
}
