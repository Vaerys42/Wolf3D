/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 21:36:34 by kboucaud          #+#    #+#             */
/*   Updated: 2017/10/14 21:36:35 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	ft_success(t_wolf *wolf)
{
	int		i;
	int		j;

	j = -1;
	wolf->success = 1;
	while (++j < WIN_HEIGHT)
	{
		i = -1;
		while (++i < WIN_LEN)
			put_pxl(wolf->data, i, j, BLACK);
	}
	mlx_put_image_to_window(wolf->data->mlx, wolf->data->mlx_window,\
	wolf->data->mlx_image, 0, 0);
	mlx_string_put(wolf->data->mlx, wolf->data->mlx_window, 120, 150,
	WHITE, "YOU WIN");
	mlx_string_put(wolf->data->mlx, wolf->data->mlx_window, 120, 200,
	WHITE, "PRESS ESCAPE OR CLICK THE CROSS FOR LEAVE");
}

void	special_case(t_wolf *wolf)
{
	if ((int)wolf->player->x == 20 && (int)wolf->player->y == 9)
	{
		wolf->player->y = 8.5;
		wolf->player->x = 1.5;
	}
	if ((int)wolf->player->x == 1 && (int)wolf->player->y == 1)
		ft_success(wolf);
}
