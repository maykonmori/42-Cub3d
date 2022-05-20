/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:56:49 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/05/20 12:57:29 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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