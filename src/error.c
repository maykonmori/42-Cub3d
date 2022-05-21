/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:56:49 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/05/21 15:29:33 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_vector(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.count_line)
	{
		free(data->map.map[i]);
		i++;
	}
	free(data->map.map);
	data->map.map = NULL;
}

void	error(char *s, int n)
{
	printf("ERROR: %s\n", s);
	exit(n);
}

void	verify_arg(int argc)
{
	if (argc > 2)
		error("Too many arguments", EXIT_FAILURE);
	if (argc < 2)
		error("Have few arguments", EXIT_FAILURE);
}

void	error_wall(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			if (data->map.map[0][x] != '1' || \
			data->map.map[data->map.count_line - 1][x] != '1')
			{
				free_vector(data);
				error("Missing Wall", EXIT_FAILURE);
			}
			if (data->map.map[y][0] != '1' || \
			data->map.map[y][data->map.count_column - 1] != '1')
			{
				free_vector(data);
				error("Missing Wall", EXIT_FAILURE);
			}
			x++;
		}
		y++;
	}
}

void	error_player(t_data *data)
{
	if (data->map.cont_player != 1)
	{
		free_vector(data);
		error("Invalid player quantity", EXIT_FAILURE);
	}
}