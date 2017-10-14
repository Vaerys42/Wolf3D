#ifndef WOLF_H
# define WOLF_H

# define WIN_HEIGHT 400
# define WIN_LEN 640
# define WALL_HEIGHT 64
# define PLAYER_HEIGHT 32
# define MINIMAP_START 424
# define MINIMAP_END 112

# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define SPRINT 257
# define W 13
# define A 0
# define S 1
# define D 2

# define SKY 0x60A2F9
# define GROUND 0x8D4607
# define NORTH 0x11EA35
# define SOUTH 0xEA1118
# define WEST 0xEAEA11
# define EAST 0x0D00C8
# define BLACK 0x00000000
# define PLAYER 0x00FE811E
# define EXIT 0x001EFAFE
# define TELEPORT 0x00FE1EFC
# define WHITE 0x00FFFFFF

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
	double			screen_X;
	double			screen_Y;
	double			view_X;
	double			view_Y;
	double			rayDirY;
	double			rayDirX;	
	int				mapX;
	int				mapY;
	double			ray_len_X;
	double			ray_len_Y;
	double			scaleX;
	double			scaleY;
}					t_vect;

typedef struct 		s_player
{
	double				x;
	double				y;
	int				right;
	int				left;
	int				up;
	int				down;
	double			space_ray;
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
	int				zone_X;
	int				zone_Y;
	int				hit;
	int				side;
	double			wallDist;
	double			move_speed;
	double			rot_speed;
	int				success;
}					t_wolf;

void 				ft_create_map(t_wolf *wolf);
void				ft_create(t_wolf *wolf);
void				ft_ini(t_wolf *wolf);

void				ft_exit_start();
void				ft_exit(t_wolf *wolf);
int					ft_exit_cross(t_wolf *wolf);

void				put_pxl(t_data *data, int x, int y, unsigned int c);
void				ft_raycasting(t_wolf *wolf);
int					check_wall(t_wolf *wolf, int x, int y);
int					get_color(t_wolf *wolf);

void				ft_move(t_wolf *wolf);
void				ft_save(t_wolf *wolf, int load);
void				minimap(t_wolf *wolf);
void				ft_check_number(char **coo, t_wolf *wolf);
int					ft_check(char *line);

void				special_case(t_wolf *wolf);

#endif