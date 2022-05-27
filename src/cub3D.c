/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:46:50 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/05/28 01:29:14 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	start_game(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1024, 1024, "Cub3d");
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
	mlx_loop(data->mlx);
}
