
#include "wolf.h"

void	ft_new_map(t_wolf *wolf)
{
	if ((wolf->first = (t_map*)malloc(sizeof(t_map))) == NULL)
		ft_exit(wolf);
	wolf->first->x = 0;
	wolf->first->y = 0;
	wolf->first->value = 1;
	wolf->first->next = NULL;
	wolf->map = wolf->first;
}

void	ft_add_map(t_wolf *wolf, int x, int y)
{
	t_map	*new;

	if ((new = (t_map*)malloc(sizeof(t_map))) == NULL)
		ft_exit(wolf);
	new->x = x;
	new->y = y;
	new->next = NULL;
	if (x == 0 || x == 21 || y == 0 || y == 10)
		new->value = 1;
	else
		new->value = 0;
	if (wolf->first->next == NULL)
		wolf->first->next = new;
	wolf->map->next = new;
	wolf->map = wolf->map->next;
}

void 	ft_create_map(t_wolf *wolf)
{
	int 	x;
	int 	y;

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

void	ft_create(t_wolf *wolf)
{
	t_data		*data;

	if ((wolf->data = (t_data*)malloc(sizeof(t_data))) == NULL)
		ft_exit(wolf);
	if ((wolf->data->mlx = mlx_init()) == NULL)
		ft_exit(wolf);
	if ((wolf->data->mlx_window = mlx_new_window(wolf->data->mlx, WIN_LEN, WIN_HEIGHT, "Wolf3D")) == NULL)
		ft_exit(wolf);
	if ((wolf->data->mlx_image = mlx_new_image(wolf->data->mlx, WIN_LEN, WIN_HEIGHT)) == NULL)
		ft_exit(wolf);
	if ((wolf->data->image_string = mlx_get_data_addr(wolf->data->mlx_image, &(wolf->data->bpp), &(wolf->data->s_l), &(wolf->data->endian))) == NULL)
		ft_exit(wolf);
}

void		ft_ini(t_wolf *wolf)
{
	if ((wolf->player = (t_player*)malloc(sizeof(t_player))) == NULL)
		ft_exit(wolf);
	if ((wolf->vect = (t_vect*)malloc(sizeof(t_vect))) == NULL)
		ft_exit(wolf);	
	wolf->player->x = 4;
	wolf->player->y = 5;
	wolf->player->left = 0;
	wolf->player->right = 0;
	wolf->player->up = 0;
	wolf->player->down = 0;
	wolf->player->cameraX = 0;
	wolf->vect->dirX = -1;
	wolf->vect->dirY = 0;
	wolf->vect->planeX = 0;
	wolf->vect->planeY = 0.66;
	wolf->move_speed = 0.05;
	wolf->rot_speed = 0.05;
	ft_create_map(wolf);
	ft_create(wolf);
}
