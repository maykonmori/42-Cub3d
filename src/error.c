/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:56:49 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/06/18 11:35:46 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	error(char *s, int n)
{
	printf("Error %s\n", s);
	exit(n);
}

void	verify_arg(int argc)
{
	if (argc > 2)
		error("\nToo many arguments", EXIT_FAILURE);
	if (argc < 2)
		error("\nHave few arguments", EXIT_FAILURE);
}

void	error_player(t_data *data)
{
	if (data->map.cont_player != 1)
	{
		printf("Error\nInvalid player quantity\n");
		exit_click(data);
		// error("\nInvalid player quantity", EXIT_FAILURE);
	}
}