/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 12:22:57 by kboucaud          #+#    #+#             */
/*   Updated: 2017/09/21 12:22:58 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	put_pxl(t_data *data, int x, int y, unsigned int c)
{
	int		i;

	if (x * 4 >= 2560 || x * 4 <= 0)
		return ;
	i = (x * 4) + (y * data->s_l);
	data->image_string[i] = c;
	data->image_string[++i] = c >> 8;
	data->image_string[++i] = c >> 16;
}
