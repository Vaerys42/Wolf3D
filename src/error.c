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
