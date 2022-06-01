/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:46:50 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/06/01 06:11:46 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3D.h"

void	start_game(t_data *data)
{
	int	trash;

	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1024, 1024, "Cub3d");
	data->tex_img = malloc(sizeof(t_img));
	data->tex_img->img = mlx_xpm_file_to_image(data->mlx, "./img/bricks.xpm", \
		&trash, &trash);
	data->tex_img->img_addr = mlx_get_data_addr(data->tex_img->img, &data->tex_img->img_bits_per_pixel,
			&data->tex_img->img_line_length, &data->tex_img->img_endian);
	data->move_up = 0;
	data->move_down = 0;
	data->move_left = 0;
	data->move_right = 0;
	data->ray_num = 1;
}

int main(int argc, char **argv)
{
	t_data *data;

	if (argc != 2)
		verify_arg(argc);
	data = malloc (sizeof(t_data));
	verify_map(argv, data);
	start_game(data);
	make_image (data);
	mlx_hook(data->win, KEYPRESS, KEYPRESSMASK, arrows_down, data);
	mlx_hook(data->win, KEYRELEASE, KEYRELEASEMASK, arrows_up, data);
	mlx_hook(data->win, 17, 0L, exit_click, &data);
	mlx_loop_hook(data->mlx, ft_run, data);
	mlx_hook(data->win, 17, 0L, exit_click, &data);
	mlx_loop(data->mlx);
}
