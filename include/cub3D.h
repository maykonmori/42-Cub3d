/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:02:45 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/05/20 13:57:37 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define KEYPRESS 2
# define KEYRELEASE 3
# define KEYPRESSMASK 1
# define KEYRELEASEMASK 10
# define PI 3.1415926535

typedef struct s_data
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *img_addr;
    int        fractal;
    int        color;
    int        img_bits_per_pixel;
    int        img_line_length;
    int        img_endian;
    int        px;
    int        py;
    float    pa;
    int        move_up;
    int        move_down;
    int        move_left;
    int        move_right;
    int        turn_left;
    int        turn_right;
    float    x_min;
    float    x_max;
    float    y_min;
    float    y_max;
    float    julia_x;
    float    julia_y;
}    t_data;

int		ft_run(t_data *data);
int		arrows_up(int keycode, t_data *data);
int		arrows_down(int keycode, t_data *data);
void	make_image(t_data *data);
void	draw_player(t_data *data, int x, int y);
void	my_img_pixel_put(t_data *data, int x, int y, int color);
void	start_game(t_data *data);
void	draw_line_from_player(t_data *data, double x, double y);
int	    validate_cub(char *s, char *ext);
void	error(char *s, int n);
void	verify_arg(int argc);
#endif
