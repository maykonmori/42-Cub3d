/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:02:45 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/06/01 06:14:42 by rkenji-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

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
# define TILE_SIZE 64

typedef struct s_map
{
	char		*line;
	char		*temp;
	char		**map;
	int			count_column;
	int			count_line;
	int			cont_player;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*img_addr;
	int		img_bits_per_pixel;
	int		img_line_length;
	int		img_endian;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	*game_img;
	t_img	*tex_img;
	int		fractal;
	int		color;
	double	px;
	double	py;
	float	pa;
	float	ra;
	int		move_up;
	int		move_down;
	int		move_left;
	int		move_right;
	int		turn_left;
	int		turn_right;
	int		ray_num;
	float	x_min;
	float	x_max;
	float	y_min;
	float	y_max;
	float	julia_x;
	float	julia_y;
	t_map	map;
}	t_data;


int		ft_run(t_data *data);
int		arrows_up(int keycode, t_data *data);
int		arrows_down(int keycode, t_data *data);
void	make_image(t_data *data);
void	draw_player(t_data *data, int x, int y);
void	my_img_pixel_put(t_img	*img, int x, int y, int color);
void	start_game(t_data *data);
void	raycast(t_data *data, double x, double y);
int	    validate_cub(char *s, char *ext);
void	error(char *s, int n);
void	verify_arg(int argc);
void	verify_map(char **argv, t_data *data);
void	count_column(t_data *data);
void	validate_map(t_data *data);
void	error_player(t_data *data);
void	error_wall(t_data *data);
void	free_vector(t_data *data);
char	*ft_strjoin_free(char *s1, char const *s2);
void	validate_cep(int x, int y, t_data *data);
char	*get_next_line(int fd);
char	*ft_gnl_strjoin(char *s1, char *s2);
int		check_pixel_color(t_data *data, int x, int y);
int		exit_click(void);
int		my_img_pixel_get(t_img *img, int x, int y);

#endif
