/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:56:49 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/06/23 13:14:34 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	error_tex(t_data *data, char *buff, char *ret, int fd)
{
	if (buff)
		free (buff);
	if (ret)
		free (ret);
	if (fd >= 0)
		close(fd);
	error(data, "Error\nInvalid texture file\n");
}

void	error(t_data *data, char *s)
{
	printf("%s", s);
	exit_click(data);
}

void	verify_arg(int argc)
{
	if (argc > 2)
	{
		printf("Error\nToo many arguments\n");
		exit (1);
	}
	if (argc < 2)
	{
		printf("Error\nNot enough arguments\n");
		exit (1);
	}
}

void	error_player(t_data *data)
{
	if (data->map.cont_player != 1)
		error(data, "Error\nInvalid player quantity\n");
}
