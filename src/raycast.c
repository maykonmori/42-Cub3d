#include "cub3D.h"

void	get_sidedist(t_data *data, double ra)
{
	if (ra < PI)
	{
		data->sideDistY = fabs(((int)(data->py) % 64) / sin (ra));
		data->stepY = -1;
	}
	else
	{
		data->sideDistY = fabs((64 - (int)(data->py) % 64)/ sin (ra));
		data->stepY = 1;
	}
	if (ra > PI / 2 && ra < 3 * PI / 2)
	{
		data->sideDistX = fabs(((int)(data->px) % 64) / cos (ra));
		data->stepX = -1;
	}
	else
	{
		data->sideDistX = fabs((64 - (int)(data->px) % 64) / cos (ra));
		data->stepX = 1;
	}
}

void	get_deltadist(t_data *data, double ra)
{
	if (cos(ra) == 0)
		data->deltaDistX = 10000000;
	else
		data->deltaDistX = fabs(64 / cos(ra));
	if (sin(ra) == 0)
		data->deltaDistY = 10000000;
	else
		data->deltaDistY = fabs(64 / sin(ra));
}

double	get_distance(t_data *data, double ra)
{
	if (ra >= 2 * PI)
		ra -= 2 * PI;
	if (ra < 0)
		ra += 2 * PI;
	get_deltadist(data, ra);
	get_sidedist(data, ra);
	data->mapX = (int)(data->px) >> 6;
	data->mapY = (int)(data->py) >> 6;
	while (data->map.map[data->mapY][data->mapX] != '1')
	{
		if (data->sideDistX < data->sideDistY)
		{
			data->sideDistX += data->deltaDistX;
			data->mapX += data->stepX;
			data->wall = 0;
		}
		else
		{
			data->sideDistY += data->deltaDistY;
			data->mapY += data->stepY;
			data->wall = 1;
		}
	}
	if(data->wall == 0)
		return (data->sideDistX - data->deltaDistX);
    else
		return (data->sideDistY - data->deltaDistY);
}

void	raycast(t_data *data, double ra)
{
	double		ca;
	double		dist;

	if (ra >= 2 * PI)
		ra -= 2 * PI;
	if (ra < 0)
		ra += 2 * PI;
	data->wall = 0;
	dist = get_distance(data, ra);
	ca = data->pa - data->ra;
	dist = dist * cos(ca);
	if (data->wall == 0 && (ra <= PI / 2 || ra >= 3 * PI / 2))
		make_vertical_line(data, dist, data->py - dist * sin(ra), data->e_img);
	else if (data->wall == 0)
		make_vertical_line(data, dist, data->py - dist * sin(ra), data->w_img);
	else if (data->wall == 1 && ra <= PI)
		make_vertical_line(data, dist, data->px + dist * cos(ra), data->n_img);
	else
		make_vertical_line(data, dist, data->px + dist * cos(ra), data->s_img);
}