/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 01:05:12 by rkenji-s          #+#    #+#             */
/*   Updated: 2022/06/15 17:25:59 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	exit_click(t_data *data)
{
	if(data->map.temp)
		free(data->map.temp);
	free_vector(data);
	free_images(data);
	free(data);
	exit(1);
	return (0);
}