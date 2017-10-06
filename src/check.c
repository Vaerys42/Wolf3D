/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 20:32:31 by kboucaud          #+#    #+#             */
/*   Updated: 2017/10/05 20:32:32 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

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
		if ((wolf->stepX == -1 && wolf->stepY == -1) ||
		(wolf->stepX == 1 && wolf->stepY == -1))
			return (WEST);
		if ((wolf->stepX == -1 && wolf->stepY == 1) ||
		(wolf->stepX == 1 && wolf->stepY == 1))
			return (EAST);
	}
	if ((wolf->stepX == -1 && wolf->stepY == -1) ||
	(wolf->stepX == -1 && wolf->stepY == 1))
		return (NORTH);
	return (SOUTH);
}
