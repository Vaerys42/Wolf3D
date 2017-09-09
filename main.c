
#include "wolf.h"

void	ft_exit(t_wolf *wolf)
{
	free(wolf);
	ft_putstr("error\n");
	exit(1);
}

void	ft_exit_start()
{
	ft_putstr("error\n");
	exit(1);
}

int			my_key_press(int key, t_wolf *wolf)
{
	if (key == 53)
	{
		mlx_destroy_window(wolf->data->mlx, wolf->data->mlx_window);
		free(wolf);
		exit(1);
	}
	if (key == KEY_LEFT)
		wolf->player->left = 1;
	if (key == KEY_RIGHT)
		wolf->player->right = 1;
	if (key == KEY_UP)
		wolf->player->up = 1;
	if (key == KEY_DOWN)
		wolf->player->down = 1;
	return (0);
}

int		my_key_release(int key, t_wolf *wolf)
{
	if (key == KEY_LEFT)
		wolf->player->left = 0;
	if (key == KEY_RIGHT)
		wolf->player->right = 0;
	if (key == KEY_UP)
		wolf->player->up = 0;
	if (key == KEY_DOWN)
		wolf->player->down = 0;
	return (0);
}

int		main(int argc, char **argv)
{
	t_wolf		*wolf;

	if ((wolf = (t_wolf*)malloc(sizeof(t_wolf))) == NULL)
		ft_exit_start();
	ft_ini(wolf);
	ft_raycasting(wolf);
	mlx_hook(wolf->data->mlx_window, 2, 1L<<0, my_key_press, wolf);
	mlx_hook(wolf->data->mlx_window, 3, 1L<<1, my_key_release, wolf);
	mlx_loop(wolf->data->mlx);
	return (0);
}