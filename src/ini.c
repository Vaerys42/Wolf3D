/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 11:56:57 by kboucaud          #+#    #+#             */
/*   Updated: 2017/09/21 11:59:47 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	ft_create(t_wolf *wolf)
{
	if ((wolf->data = (t_data*)malloc(sizeof(t_data))) == NULL)
		ft_exit(wolf);
	if ((wolf->data->mlx = mlx_init()) == NULL)
		ft_exit(wolf);
	if ((wolf->data->mlx_window = mlx_new_window(wolf->data->mlx,\
	WIN_LEN, WIN_HEIGHT, "Wolf3D")) == NULL)
		ft_exit(wolf);
	if ((wolf->data->mlx_image = mlx_new_image(wolf->data->mlx,\
	WIN_LEN, WIN_HEIGHT)) == NULL)
		ft_exit(wolf);
	if ((wolf->data->image_string = mlx_get_data_addr(wolf->data->mlx_image,\
	&(wolf->data->bpp), &(wolf->data->s_l), &(wolf->data->endian))) == NULL)
		ft_exit(wolf);
}

void	ft_ini(t_wolf *wolf)
{
	if ((wolf->player = (t_player*)malloc(sizeof(t_player))) == NULL)
		ft_exit(wolf);
	if ((wolf->vect = (t_vect*)malloc(sizeof(t_vect))) == NULL)
		ft_exit(wolf);
	wolf->player->left = 0;
	wolf->player->right = 0;
	wolf->player->up = 0;
	wolf->player->down = 0;
	wolf->player->space_ray = 0;
	wolf->vect->dirX = -1;
	wolf->vect->dirY = 0;
	wolf->vect->screen_X = 0;
	wolf->vect->screen_Y = 0.66;
	wolf->move_speed = 0.03;
	wolf->rot_speed = 0.05;
	ft_save(wolf, 0);
	ft_create_map(wolf);
	ft_create(wolf);
}
