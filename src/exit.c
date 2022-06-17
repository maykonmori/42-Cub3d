/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 01:05:12 by rkenji-s          #+#    #+#             */
/*   Updated: 2022/06/17 02:50:20 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	exit_click(t_data *data)
{
	if(data->map.line)
		free(data->map.line);
	if(data->map.temp)
		free(data->map.temp);
	if(data->map.map)
		free_split(data->map.map);
	free_split(data->map.lines);
	free_images(data);
	free(data);
	exit(1);
	return (0);
}