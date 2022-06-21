/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkenji-s <rkenji-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:02:45 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/06/21 02:43:55 by rkenji-s         ###   ########.fr       */
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
	char		**lines;
	char		*temp;
	char		**map;
	int			x_size;
	int			y_size;
	int			count_column;
	int			count_line;
	int			cont_player;
	int			map_start;
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
	t_img	*n_img;
	t_img	*s_img;
	t_img	*w_img;
	t_img	*e_img;
	char	*s_tex;
	char	*n_tex;
	char	*w_tex;
	char	*e_tex;
	int		c_color;
	int		f_color;
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
	double	deltaDistX;
    double	deltaDistY;
	double	sideDistX;
	double	sideDistY;
	int		mapX;
	int		mapY;
	int		stepX;
	int		stepY;
	int		wall;
	t_map	map;
}	t_data;


int		ft_run(t_data *data);
int		arrows_up(int keycode, t_data *data);
int		arrows_down(int keycode, t_data *data);
void	make_image(t_data *data);
void	draw_player(t_data *data, int x, int y);
void	my_img_pixel_put(t_img	*img, int x, int y, int color);
void	start_game(t_data *data);
void	raycast(t_data *data, double ra);
int	    validate_cub(char *s, char *ext);
void	error(char *s, int n);
void	verify_arg(int argc);
void	verify_map(char **argv, t_data *data);
void	validate_map(t_data *data);
void	error_player(t_data *data);
void	verify_wall(t_data *data);
void	free_split(char **split);
char	*ft_strjoin_free(char *s1, char const *s2);
void	validate_cep(int x, int y, t_data *data);
int		check_pixel_color(t_data *data, int x, int y);
int		exit_click(t_data *data);
int		my_img_pixel_get(t_img *img, int x, int y);
char	*add_tex_location(char *line, char *tex, t_data *data);
void	check_line(t_data *data, char *line);
int		get_rgb(t_data *data, char *line, int color);
int		check_colors(t_data *data, char *line);
void	get_map(t_data *data);
int		check_map_chars(char *line);
void	free_images(t_data *data);
void	check_walls(t_data *data);
void	make_vertical_line(t_data *data, int distance, double ix, t_img *img);
int		matriz_len(char **split);
void	check_diagonal_up_right(t_data *data, int y, int x);
void	check_diagonal_up_left(t_data *data, int y, int x);
void	check_diagonal_down_right(t_data *data, int y, int x);
void	check_diagonal_down_left(t_data *data, int y, int x);
double	get_distance(t_data *data, double ra);

#endif
