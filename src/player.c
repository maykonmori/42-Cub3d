/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:04:45 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/05/20 11:44:02 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_player(t_data *data, int x, int y)
{
	my_img_pixel_put(data, x - 1, y + 1, 0xFFFF00);
	my_img_pixel_put(data, x, y + 1, 0xFFFF00);
	my_img_pixel_put(data, x + 1, y + 1, 0xFFFF00);
	my_img_pixel_put(data, x - 1, y, 0xFFFF00);
	my_img_pixel_put(data, x, y, 0xFFFF00);
	my_img_pixel_put(data, x + 1, y, 0xFFFF00);
	my_img_pixel_put(data, x - 1, y - 1, 0xFFFF00);
	my_img_pixel_put(data, x, y - 1, 0xFFFF00);
	my_img_pixel_put(data, x + 1, y - 1, 0xFFFF00);
}