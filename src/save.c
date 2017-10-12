/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 17:25:31 by kboucaud          #+#    #+#             */
/*   Updated: 2017/10/05 17:25:33 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void		ft_load(t_wolf *wolf, int fd)
{
	char	*line;
	char	**coo;
	int		i;

	i = -1;
	get_next_line(fd, &line);
	if (ft_check(line) == 0)
	{
		wolf->player->x = 4;
		wolf->player->y = 5;
		return ;
	}
	coo = ft_strsplit(line, ' ');
	ft_check_number(coo, wolf);
	free(line);
	free(coo[0]);
	free(coo[1]);
	free(coo);
	close(fd);
}

void		ft_quit(t_wolf *wolf, int fd)
{
	wolf->player->x = (int)wolf->player->x;
	wolf->player->y = (int)wolf->player->y;
	write(fd, "          ", 10);
	lseek(fd, SEEK_SET, 0);
	write(fd, ft_itoa(wolf->player->x), ft_strlen(ft_itoa(wolf->player->x)));
	write(fd, " ", 1);
	write(fd, ft_itoa(wolf->player->y), ft_strlen(ft_itoa(wolf->player->y)));
	close(fd);
}

void		ft_save(t_wolf *wolf, int load)
{
	int		fd;

	fd = open("save.txt", O_RDWR);
	if (fd == -1)
	{
		wolf->player->x = 4;
		wolf->player->y = 5;
		creat("save.txt", S_IRWXU | S_IRWXG | S_IRWXO);
		return ;
	}
	else
	{
		if (load == 0)
			ft_load(wolf, fd);
		if (load == 1)
			ft_quit(wolf, fd);
	}
}
