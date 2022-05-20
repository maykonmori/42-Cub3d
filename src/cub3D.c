/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:46:50 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/05/20 11:51:22 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	start_game(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 512, 512, "Cub3d");
	data->px = 200;
	data->py = 200;
	data->pa = PI / 2;
}

int main(void)
{
	t_data *data;

	// if (argc != 2)
	// 	verify_arg(argc);
	data = malloc (sizeof(t_data));
	start_game(data);
	make_image (data);
	mlx_hook(data->win, KEYPRESS, KEYPRESSMASK, arrows_down, data);
	mlx_hook(data->win, KEYRELEASE, KEYRELEASEMASK, arrows_up, data);
	mlx_loop_hook(data->mlx, ft_run, data);
	mlx_loop(data->mlx);
}





