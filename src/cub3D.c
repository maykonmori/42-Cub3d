/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:46:50 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/06/21 22:16:03 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_img	*init_texture(t_data *data, char *file)
{
	int		trash;
	t_img	*ret;

	ret = malloc (sizeof(t_img));
	ret->img = mlx_xpm_file_to_image(data->mlx, file, &trash, &trash);
	ret->img_addr = mlx_get_data_addr(ret->img, &ret->img_bits_per_pixel,
			&ret->img_line_length, &ret->img_endian);
	return (ret);
}

void	start_game(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 512, 512, "Cub3d");
	data->n_img = init_texture(data, data->n_tex);
	data->s_img = init_texture(data, data->s_tex);
	data->w_img = init_texture(data, data->w_tex);
	data->e_img = init_texture(data, data->e_tex);
	data->turn_left = 0;
	data->turn_right = 0;
	data->move_up = 0;
	data->move_down = 0;
	data->move_left = 0;
	data->move_right = 0;
	data->ray_num = 1;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		verify_arg(argc);
	data = ft_calloc (sizeof(t_data), 1);
	verify_map(argv, data);
	start_game(data);
	make_image (data);
	mlx_loop_hook(data->mlx, ft_run, data);
	mlx_hook(data->win, KEYPRESS, KEYPRESSMASK, arrows_down, data);
	mlx_hook(data->win, KEYRELEASE, KEYRELEASEMASK, arrows_up, data);
	mlx_hook(data->win, 17, 0L, exit_click, data);
	mlx_loop(data->mlx);
}
