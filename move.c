
#include "wolf.h"

void	ft_move(t_wolf *wolf)
{
	double		oldDirX;
	double		oldPlaneX;

	if (wolf->player->up == 1)
	{
		if (check_wall(wolf, (int)(wolf->player->x + (wolf->vect->dirX * wolf->move_speed)), (int)wolf->player->y) == 0)
			wolf->player->x += wolf->vect->dirX;
		if (check_wall(wolf, (int)wolf->player->x, (int)(wolf->player->y + (wolf->vect->dirY * wolf->move_speed))) == 0)
			wolf->player->y += wolf->vect->dirY;
	}
	if (wolf->player->down == 1)
	{
		if (check_wall(wolf, (int)wolf->player->x - (wolf->vect->dirX * wolf->move_speed), (int)wolf->player->y) == 0)
			wolf->player->x -= wolf->vect->dirX;
		if (check_wall(wolf, (int)wolf->player->x, (int)wolf->player->y - (wolf->vect->dirY * wolf->move_speed)) == 0)
			wolf->player->y -= wolf->vect->dirY;
	}
	if (wolf->player->right == 1)
	{
		oldDirX = wolf->vect->dirX;
		wolf->vect->dirX = wolf->vect->dirX * cos(-wolf->rot_speed) - wolf->vect->dirY * sin(-wolf->rot_speed);
		wolf->vect->dirY = oldDirX * sin(-wolf->rot_speed) + wolf->vect->dirY * cos(-wolf->rot_speed);
		oldPlaneX = wolf->vect->planeX;
		wolf->vect->planeX = wolf->vect->planeX * cos(-wolf->rot_speed) - wolf->vect->planeY * sin(-wolf->rot_speed);
		wolf->vect->planeY = oldPlaneX * sin(-wolf->rot_speed) + wolf->vect->planeY * cos(-wolf->rot_speed);
	}
	if (wolf->player->left == 1)
	{
		oldDirX = wolf->vect->dirX;
		wolf->vect->dirX = wolf->vect->dirX * cos(wolf->rot_speed) - wolf->vect->dirY * sin(wolf->rot_speed);
		wolf->vect->dirY = oldDirX * sin(wolf->rot_speed) + wolf->vect->dirY * cos(wolf->rot_speed);
		oldPlaneX = wolf->vect->planeX;
		wolf->vect->planeX = wolf->vect->planeX * cos(wolf->rot_speed) - wolf->vect->planeY * sin(wolf->rot_speed);
		wolf->vect->planeY = oldPlaneX * sin(wolf->rot_speed) + wolf->vect->planeY * cos(wolf->rot_speed);
	}
	ft_raycasting(wolf);
	mlx_put_image_to_window(wolf->data->mlx, wolf->data->mlx_window, wolf->data->mlx_image, 0, 0);
}