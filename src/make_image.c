/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:04:14 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/05/20 11:51:31 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	make_image(t_data *data)
{
	int		x;
	int		y;

	data->img = mlx_new_image(data->mlx, 800, 800);
	data->img_addr = mlx_get_data_addr(data->img, &data->img_bits_per_pixel,
			&data->img_line_length, &data->img_endian);
	y = -1;
	while (++y <= 512)
	{
		x = -1;
		while (++x <= 512)
			my_img_pixel_put(data, x, y, 0x808080);
	}
	draw_player(data, data->px, data->py);
	draw_line_from_player(data, data->px + roundf(100 * sin(data->pa)), data->py + roundf(100 * cos(data->pa)));
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
}

void	draw_line_from_player(t_data *data, double x, double y)
{
	double	ix;
	double	iy;
	double	dx;
	double	dy;

	dx = abs((int)x - data->px);
	dy = abs((int)y - data->py);
	ix = 0;
	iy = 0;
	while (abs((int)ix) < dx || abs((int)iy) < dy)
	{
		if ((0.5 + abs((int)ix)) / dx < (0.5 + abs((int)iy)) / dy)
		{
			if (data->px < x)
				ix++;
			else
				ix--;
		}
		else
		{
			if (data->py < y)
				iy++;
			else
				iy--;
		}
		my_img_pixel_put(data, data->px + ix, data->py + iy, 0xFFFF00);
	}
}