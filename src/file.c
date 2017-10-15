/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 13:06:30 by kboucaud          #+#    #+#             */
/*   Updated: 2017/10/12 13:06:31 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

int			ft_check_line(char *line)
{
	int		i;

	i = 0;
	while (line[i] != 0)
	{
		if (ft_isdigit(line[i] == 0) && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int			ft_check(char *line)
{
	if (ft_strlen(line) == 0)
		return (0);
	if (ft_check_line(line) == 0)
		return (0);
	return (1);
}

void		ft_check_number(char **coo, t_wolf *wolf)
{
	int		i;

	i = 0;
	while (coo[i] != NULL)
		i++;
	if (i != 2)
	{
		wolf->player->x = 1.5;
		wolf->player->y = 8.5;
		return ;
	}
	wolf->player->x = ft_atoi(coo[0]);
	wolf->player->y = ft_atoi(coo[1]);
	if (check_wall(wolf, (int)wolf->player->x, (int)wolf->player->y) == 1)
	{
		wolf->player->x = 1;
		wolf->player->y = 8;
	}
	wolf->player->x += 0.5;
	wolf->player->y += 0.5;
}
