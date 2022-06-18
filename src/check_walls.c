#include "cub3D.h"

void	check_left(t_data *data, int y, int x)
{
	while (x >= 0)
	{
		if (data->map.map[y][x] == '1')
			return ;
		x--;
	}
	printf ("Error\n mapa nao rodeado por 1\n");
	exit_click(data);
}

void	check_right(t_data *data, int y, int x)
{
	while (x < data->map.x_size)
	{
		if (data->map.map[y][x] == '1')
			return ;
		x++;
	}
	printf ("Error\n mapa nao rodeado por 1\n");
	exit_click(data);
}

void	check_down(t_data *data, int y, int x)
{
	while (y < data->map.y_size)
	{
		if (data->map.map[y][x] == '1')
			return ;
		y++;
	}
	printf ("Error\n mapa nao rodeado por 1\n");
	exit_click(data);
}

void	check_up(t_data *data, int y, int x)
{
	while (y >= 0)
	{
		if (data->map.map[y][x] == '1')
			return ;
		y--;
	}
	printf ("Error\nMapa nao rodeado por 1\n");
	exit_click(data);
}

void	check_walls(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (data->map.map[++y])
	{
		x = -1;
		while (data->map.map[y][++x])
		{
			if (data->map.map[y][x] == '0')
			{
				check_up(data, y, x);
				check_left(data, y, x);
				check_right(data, y, x);
				check_down(data, y, x);
			}
		}
	}
}