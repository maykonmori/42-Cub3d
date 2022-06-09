/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:56:49 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/06/09 02:53:49 by rkenji-s         ###   ########.fr       */
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

void	error_player(t_data *data)
{
	if (data->map.cont_player != 1)
	{
		free_vector(data);
		error("Invalid player quantity", EXIT_FAILURE);
	}
}