/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 16:49:45 by kboucaud          #+#    #+#             */
/*   Updated: 2017/10/05 16:49:46 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void		put_case(t_wolf *wolf, int x, int y, int type)
{
	int		color;
	int		i;
	int		j;
	int		pos_x;
	int		pos_y;

	if (type == 0)
		return ;
	else if (type == 1)
		color = BLACK;
	else
		color = RED;
	j = 0;
	while (++j < 11)
	{
		i = 0;
		pos_y = (y * 10 + j);
		while (++i < 11)
		{
			pos_x = (MINIMAP_START + x * 10 + i);
			put_pxl(wolf->data, pos_x, pos_y, color);
		}
	}
}

void		minimap(t_wolf *wolf)
{
	wolf->map = wolf->first;
	while (wolf->map->next != NULL)
	{
		put_case(wolf, wolf->map->x, wolf->map->y, wolf->map->value);
		wolf->map = wolf->map->next;
	}
	put_case(wolf, wolf->map->x, wolf->map->y, wolf->map->value);
	put_case(wolf, wolf->player->x, wolf->player->y, 3);
}
