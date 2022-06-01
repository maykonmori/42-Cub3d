/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:04:45 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/06/01 05:34:38 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_player(t_data *data, int x, int y)
{
	my_img_pixel_put(data->game_img, x - 1, y + 1, 0xFFFF00);
	my_img_pixel_put(data->game_img, x, y + 1, 0xFFFF00);
	my_img_pixel_put(data->game_img, x + 1, y + 1, 0xFFFF00);
	my_img_pixel_put(data->game_img, x - 1, y, 0xFFFF00);
	my_img_pixel_put(data->game_img, x, y, 0xFFFF00);
	my_img_pixel_put(data->game_img, x + 1, y, 0xFFFF00);
	my_img_pixel_put(data->game_img, x - 1, y - 1, 0xFFFF00);
	my_img_pixel_put(data->game_img, x, y - 1, 0xFFFF00);
	my_img_pixel_put(data->game_img, x + 1, y - 1, 0xFFFF00);
}