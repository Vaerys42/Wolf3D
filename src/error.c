/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 12:00:40 by kboucaud          #+#    #+#             */
/*   Updated: 2017/09/21 12:00:41 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	ft_exit(t_wolf *wolf)
{
	free(wolf);
	ft_putstr("error\n");
	exit(0);
}

void	ft_exit_start(void)
{
	ft_putstr("error\n");
	exit(0);
}

int		ft_exit_cross(t_wolf *wolf)
{
	mlx_destroy_image(wolf->data->mlx, wolf->data->mlx_image);
	system("killall afplay");
	ft_save(wolf, 1);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_param_error(void)
{
	ft_putstr("Bad parameters. Use 1 for map 1 and 2 for map 2\n");
	exit(0);
}
