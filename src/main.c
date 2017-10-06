/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 12:00:02 by kboucaud          #+#    #+#             */
/*   Updated: 2017/09/21 12:02:34 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

int		ft_exit_cross(t_wolf *wolf)
{
	mlx_destroy_image(wolf->data->mlx, wolf->data->mlx_image);
	system("killall afplay");
	ft_save(wolf, 1);
	exit(EXIT_SUCCESS);
	return (0);
}

int		my_key_press(int key, t_wolf *wolf)
{
	if (key == 53)
	{
		mlx_destroy_window(wolf->data->mlx, wolf->data->mlx_window);
		system("killall afplay");
		ft_save(wolf, 1);
		free(wolf);
		exit(0);
	}
	if (key == KEY_LEFT || key == A)
		wolf->player->left = 1;
	if (key == KEY_RIGHT || key == D)
		wolf->player->right = 1;
	if (key == KEY_UP || key == W)
		wolf->player->up = 1;
	if (key == KEY_DOWN || key == S)
		wolf->player->down = 1;
	if (key == SPRINT)
		wolf->move_speed = 0.08;
	return (0);
}

int		my_key_release(int key, t_wolf *wolf)
{
	if (key == KEY_LEFT || key == A)
		wolf->player->left = 0;
	if (key == KEY_RIGHT || key == D)
		wolf->player->right = 0;
	if (key == KEY_UP || key == W)
		wolf->player->up = 0;
	if (key == KEY_DOWN || key == S)
		wolf->player->down = 0;
	if (key == SPRINT)
		wolf->move_speed = 0.03;
	return (0);
}

int		ft_loop(t_wolf *wolf)
{
	ft_move(wolf);
	ft_raycasting(wolf);
	minimap(wolf);
	mlx_put_image_to_window(wolf->data->mlx, wolf->data->mlx_window,\
	wolf->data->mlx_image, 0, 0);
	return (0);
}

int		main(void)
{
	t_wolf		*wolf;

	if ((wolf = (t_wolf*)malloc(sizeof(t_wolf))) == NULL)
		ft_exit_start();
	ft_ini(wolf);
	system("afplay wolf.mp3 &");
	mlx_loop_hook(wolf->data->mlx, ft_loop, wolf);
	mlx_hook(wolf->data->mlx_window, 2, 1L << 0, my_key_press, wolf);
	mlx_hook(wolf->data->mlx_window, 3, 1L << 1, my_key_release, wolf);
	mlx_hook(wolf->data->mlx_window, 17, 0, ft_exit_cross, wolf);
	mlx_put_image_to_window(wolf->data->mlx, wolf->data->mlx_window,\
	wolf->data->mlx_image, 0, 0);
	mlx_loop(wolf->data->mlx);
	return (0);
}
