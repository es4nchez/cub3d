/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 00:35:17 by esanchez          #+#    #+#             */
/*   Updated: 2022/07/08 00:35:22 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	init_raycasting(t_data *data, t_raycasting *rc)
{
	rc->w = -1;
	rc->mapx = data->pposx;
	rc->mapy = data->pposy;
	rc->hit = 0;
	return (1);
}

int	stripe_calculator(t_data *data, t_raycasting *rc)
{
	rc->lineheight = (WIN_H / rc->perpwalldist);
	rc->drawstart = (rc->lineheight / -2) + data->horizon;
	if(rc->drawstart < 0)
		rc->drawstart = 0;
	rc->drawend = (rc->lineheight / 2 + data->horizon);
	if(rc->drawend >= WIN_H)
		rc->drawend = WIN_H - 1;
	return (1);
}



int	raycasting(t_data *data)
{
	int				x;
	t_raycasting	rc;

	x = 0;
	while(x <= WIN_W)
	{
		init_raycasting(data, &rc);
		rc.camerax = 2 * x / (float)WIN_W - 1.0;
		rc.raydirx = data->pdirx + data->planex * rc.camerax;
		rc.raydiry = data->pdiry + data->planey * rc.camerax;
		if (rc.raydirx == 0)
			rc.deltadistx = INFINITY;
		else
			rc.deltadistx = fabs(1 / rc.raydirx);
		if (rc.raydiry == 0)
			rc.deltadisty = INFINITY;
		else
			rc.deltadisty = fabs(1 / rc.raydiry);
		calculate_distance(data, &rc);
		dda(data, &rc);
		projected_distance(&rc);
		stripe_calculator(data, &rc);
		draw_vert(data, &rc, x);
		texturing(data, &rc, x);
		x++;
	}
	return (1);
}

int	displayer(t_data *data)
{
	raycasting(data);
	if (data->activate_minimap > 0)
		minimap(data);
 	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
 //	mlx_destroy_image(data->mlx, data->img);
	return (1);
}
