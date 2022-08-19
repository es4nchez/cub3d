/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 04:03:45 by esanchez          #+#    #+#             */
/*   Updated: 2022/08/16 04:03:48 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	texture_rendering(t_data *data, t_raycasting *rc)
{
	rc->texwidth = data->n_addr->w;
	rc->texheight = data->n_addr->h;
	printf("w : %d\nh : %d\n", data->n_addr->w, data->n_addr->h);
	if (rc->side == 0)
		rc->wallx = data->pposy + rc->perpwalldist * rc->raydiry;
	else
		rc->wallx = data->pposx + rc->perpwalldist * rc->raydirx;
	rc->texx = (int)(rc->wallx * rc->texwidth);
	if(rc->side == 0 && rc->raydirx > 0)
		rc->texx = ((rc->texwidth * (rc->texheight - 1)) - rc->texx - 1);
	if(rc->side == 1 && rc->raydiry < 0)
		rc->texx = ((rc->texwidth * (rc->texheight - 1)) - rc->texx - 1);
	return (1);
}

int	texturing(t_data *data, t_raycasting *rc, int x)
{
	int		y;
	int		color;
	double	step;
	int		pix;

	y = rc->drawstart;
	step = (double)rc->texheight / (double)rc->lineheight;
	rc->texpos = (rc->drawstart - data->horizon + ((double)rc->lineheight / 2)) * step;
	while(y < rc->drawend)
	{
		rc->texy = (int)rc->texpos;
		rc->texpos += step;
		pix = rc->texheight * rc->texy + rc->texx;
//		printf("pix :%d\n", pix);
		if (pix >= 0 && pix < 1024)
			color = data->n_addr->pxs[(rc->texheight * rc->texy) + rc->texx];
		ft_mlx_pixel_put(data->img, y, x, color);
		y++;
	}

	return (1);
}

int	floor_ceiling(t_data *data, t_raycasting *rc)
{
	int	i;
	int	j;

	(void)rc;
	i = 0;
	while (i < WIN_W)
	{
		j = 0;
		while (j < WIN_W)
		{
			if (i < (WIN_H / 2))
				ft_mlx_pixel_put(data->img, j, i, BRC);
			else
				ft_mlx_pixel_put(data->img, j, i, WOD);
			j++;
		}
		i++;
	}
	return (1);
}
