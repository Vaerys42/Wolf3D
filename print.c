
#include "wolf.h"

void	put_pxl(t_data *data, int x, int y, unsigned int c)
{
	int		i;

	i = (x * 4) + (y * data->s_l);
	data->image_string[i] = c;
	data->image_string[++i] = c >> 8;
	data->image_string[++i] = c >> 16;
}
