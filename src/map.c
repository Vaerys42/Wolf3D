/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:17:10 by kboucaud          #+#    #+#             */
/*   Updated: 2017/10/05 14:17:11 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	ft_new_map(t_wolf *wolf)
{
	if ((wolf->first = (t_map*)malloc(sizeof(t_map))) == NULL)
		ft_exit(wolf);
	ft_bzero(wolf->first, sizeof(wolf->first));
	wolf->first->x = 0;
	wolf->first->y = 0;
	wolf->first->value = 1;
	wolf->first->next = NULL;
	wolf->map = wolf->first;
}

void	ft_add_walls(t_map *new, int x, int y)
{
	if ((x == 3 && y == 1) || (x == 3 && y == 2) || (x == 3 && y == 3))
		new->value = 1;
	if ((x == 18 && y == 7) || (x == 18 && y == 8) || (x == 19 && y == 7))
		new->value = 1;
	if ((x == 15 && y == 4) || (x == 14 && y == 4) || (x == 13 && y == 4))
		new->value = 1;
	if ((x == 12 && y == 4) || (x == 12 && y == 5) || (x == 12 && y == 6))
		new->value = 1;
	if ((x == 12 && y == 7) || (x == 12 && y == 8) || (x == 12 && y == 9))
		new->value = 1;
	if ((x == 17 && y == 7) || (x == 18 && y == 6) || (x == 6 && y == 1))
		new->value = 1;
	if ((x == 6 && y == 2) || (x == 6 && y == 3) || (x == 6 && y == 4))
		new->value = 1;
	if ((x == 6 && y == 5) || (x == 6 && y == 6) || (x == 6 && y == 7))
		new->value = 1;
	if ((x == 6 && y == 9) || (y == 6 && x == 1) || (x == 2 && y == 6))
		new->value = 1;
	if ((x == 3 && y == 6) || (x == 3 && y == 9) || (x == 10 && y == 2))
		new->value = 1;
	if (x == 20 && y == 9)
		new->value = 2;
	if (x == 1 && y == 1)
		new->value = 3;
}

void	ft_add_map(t_wolf *wolf, int x, int y)
{
	t_map	*new;

	if ((new = (t_map*)malloc(sizeof(t_map))) == NULL)
		ft_exit(wolf);
	ft_bzero(new, sizeof(new));
	new->x = x;
	new->y = y;
	new->next = NULL;
	if (x == 0 || x == 21 || y == 0 || y == 10)
		new->value = 1;
	else
		new->value = 0;
	ft_add_walls(new, x, y);
	if (wolf->first->next == NULL)
		wolf->first->next = new;
	wolf->map->next = new;
	wolf->map = new;
}

void	ft_create_map(t_wolf *wolf)
{
	int		x;
	int		y;

	y = -1;
	while (++y < 11)
	{
		x = -1;
		while (++x < 22)
		{
			if (x == 0 && y == 0)
				ft_new_map(wolf);
			else
				ft_add_map(wolf, x, y);
		}
	}
}
