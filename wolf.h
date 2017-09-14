
#ifndef WOLF_H
# define WOLF_H

# define WIN_HEIGHT 200
# define WIN_LEN 320
# define WALL_HEIGHT 64
# define PLAYER_HEIGHT 32

# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125

# define SKY 0x4D8DEC
# define GROUND 0x7C3710
# define NORTH 0x11EA35
# define SOUTH 0xEA1118
# define WEST 0xEAEA11
# define EAST 0xE311EA

# include <stdlib.h>
# include <math.h>
# include "libft/includes/libft.h"
# include "minilibx_macos/mlx.h"

typedef struct s_map t_map;

typedef struct 		s_map
{
	int				x;
	int				y;
	int				value;
	t_map			*next;
}					t_map;

typedef	struct 		s_vect
{
	double			planeX;
	double			planeY;
	double			dirX;
	double			dirY;
	double			rayPosX;
	double			rayPosY;
	double			rayDirY;
	double			rayDirX;	
	int				mapX;
	int				mapY;
	double			sideDistX;
	double			sideDistY;
	double			deltaDistX;
	double			deltaDistY;
}					t_vect;

typedef struct 		s_player
{
	double				x;
	double				y;
	int				right;
	int				left;
	int				up;
	int				down;
	double			cameraX;
}					t_player;

typedef struct 		s_data
{
	void			*mlx;
	void			*mlx_window;
	void			*mlx_image;
	char 			*image_string;
	int				s_l;
	int				bpp;
	int				endian;
}					t_data;

typedef struct 		s_wolf
{
	t_player		*player;
	t_data			*data;
	t_map			*map;
	t_map			*first;
	t_vect			*vect;
	double			time;
	double			old_time;
	int				stepX;
	int				stepY;
	int				hit;
	int				side;
	double			wallDist;
}					t_wolf;

void 				ft_create_map(t_wolf *wolf);
void				ft_create(t_wolf *wolf);
void				ft_ini(t_wolf *wolf);

void				ft_exit_start();
void				ft_exit(t_wolf *wolf);

void				put_pxl(t_data *data, int x, int y, unsigned int c);
void				ft_raycasting(t_wolf *wolf);

#endif