#include "cub3D.h"

void	my_img_pixel_put(t_data *data, int x, int y, int color)
{
	char	*byte;

	byte = data->img_addr + ((y * data->img_line_length)
			+ (x * data->img_bits_per_pixel / 8));
	*(unsigned int *)byte = color;
}