#include "cub3D.h"

void	raycast(t_data *data, double ra)
{
	double		ca;
	double		dist;
	double		deltaDistX;
    double		deltaDistY;
	double		sideDistX;
	double		sideDistY;
	int			hit;
	int			mapX;
	int			mapY;
	int			stepX;
	int			stepY;
	int			side;

	hit = 0;
	if (ra >= 2 * PI)
		ra -= 2 * PI;
	if (ra < 0)
		ra += 2 * PI;
	if (cos(ra) == 0)
		deltaDistX = 10000000;
	else
		deltaDistX = fabs(64 / cos(ra));
	if (sin(ra) == 0)
		deltaDistY = 10000000;
	else
		deltaDistY = fabs(64 / sin(ra));
	if (ra < PI)
	{
		sideDistY = fabs(((int)(data->py) % 64) / sin (ra));
		stepY = -1;
	}
	else
	{
		sideDistY = fabs((64 - (int)(data->py) % 64)/ sin (ra));
		stepY = 1;
	}
	if (ra > PI / 2 && ra < 3 * PI / 2)
	{
		sideDistX = fabs(((int)(data->px) % 64) / cos (ra));
		stepX = -1;
	}
	else
	{
		sideDistX = fabs((64 - (int)(data->px) % 64) / cos (ra));
		stepX = 1;
	}
	mapX = (int)(data->px) >> 6;
	mapY = (int)(data->py) >> 6;
    while (hit == 0)
    {
    	if (sideDistX < sideDistY)
        {
        	sideDistX += deltaDistX;
        	mapX += stepX;
        	side = 0;
        }
        else
        {
        	sideDistY += deltaDistY;
        	mapY += stepY;
        	side = 1;
        }
        if (data->map.map[mapY][mapX] == '1')
			hit = 1;
      } 
	if(side == 0)
		dist = (sideDistX - deltaDistX);
    else
		dist = (sideDistY - deltaDistY);
	ca = data->pa - data->ra;
	dist = dist * cos(ca);
	if (side == 0 && (ra <= PI / 2 || ra >= 3 * PI / 2))
		make_vertical_line(data, dist, data->py - dist * sin(ra), data->e_img);
	else if (side == 0)
		make_vertical_line(data, dist, data->py - dist * sin(ra), data->w_img);
	else if (side == 1 && ra <= PI)
		make_vertical_line(data, dist, data->px + dist * cos(ra), data->n_img);
	else
		make_vertical_line(data, dist, data->px + dist * cos(ra), data->s_img);
}