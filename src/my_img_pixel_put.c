/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_img_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:20:21 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/06/22 02:53:41 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*byte;

	byte = img->img_addr + ((y * img->img_line_length)
			+ (x * img->img_bits_per_pixel / 8));
	*(unsigned int *)byte = color;
}

int	my_img_pixel_get(t_img *img, int x, int y)
{
	char	*byte;

	byte = img->img_addr + ((y * img->img_line_length)
			+ (x * img->img_bits_per_pixel / 8));
	return (*(unsigned int *)byte);
}
