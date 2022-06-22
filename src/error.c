/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:56:49 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/06/22 03:19:06 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	error(t_data *data, char *s)
{
	printf("%s", s);
	exit_click(data);
}

void	verify_arg(int argc)
{
	if (argc > 2)
	{
		printf("\nToo many arguments");
		exit (1);
	}
	if (argc < 2)
	{
		printf("\nNot enough arguments");
		exit (1);
	}
}

void	error_player(t_data *data)
{
	if (data->map.cont_player != 1)
		error(data, "Error\nInvalid player quantity\n");
}