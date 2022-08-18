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

int	texture_rendering(t_data *data, t_raycasting *rc)
{
	rc->texwidth = data->n_addr->w;
	rc->texheight = data->n_addr->h;
	if (rc->side == 0)
		rc->wallx = data->pposy + rc->perpwalldist * rc->raydiry;
	else
		rc->wallx = data->pposx + rc->perpwalldist * rc->raydirx;
//	printf("wallx : %f\n", rc->wallx);
//	rc->wallx += 1;

	rc->texx = (int)(rc->wallx * rc->texwidth);
//	printf("t1 texx : %d\n", rc->texx);
	if(rc->side == 0 && rc->raydirx > 0)
		rc->texx = ((rc->texwidth * (rc->texheight - 1)) - rc->texx - 1);
	if(rc->side == 1 && rc->raydiry < 0)
		rc->texx = ((rc->texwidth * (rc->texheight - 1)) - rc->texx - 1);
//	printf("t2 texx : %d\n", abs(rc->texx));
	return (1);
}

int	texturing(t_data *data, t_raycasting *rc, int x)
{
	int		y;
	int		color;
	double	step;

	y = rc->drawstart;
	step = 1.0 * rc->texheight / rc->lineheight;
	rc->texpos = (rc->drawstart - data->horizon + (rc->lineheight / 2)) * step;
	while(y < rc->drawend)
	{
		rc->texy = ((int)rc->texpos) & (rc->texheight - 1);
//		printf("texpos1 : %f\n", texpos);
		rc->texpos += step;
//		printf("texpos2 : %f\n", texpos);
//		printf("texheight : %d\ntexwidth: %f\ntexx : %d\ntexy : %d\n", rc->texheight, rc->texwidth, rc->texx, texy);
//		printf("\npxs :%d\n", ((rc->texheight * texy) + rc->texx));
		if ((rc->texheight * rc->texy + rc->texx) >= 0)
			color = data->n_addr->pxs[(rc->texheight * rc->texy) + rc->texx];
//		printf("x : %dy : %d\n", x, y);
		ft_mlx_pixel_put(data->img, x, y, color);
		y++;
	}

	return (1);
}

int	raycasting(t_data *data)
{
	int				x;
	t_raycasting	rc;

	x = 0;
//	printf("pposx : %f | pposy : %f\n", data->pposx, data->pposy);
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
		texture_rendering(data, &rc);
//		draw_vert(data, &rc, x);
		texturing(data, &rc, x);
//		floorCeiling(data, &rc);
//		draw_vert(data, &rc, x);
		x++;
	}
	return (1);
}

int	displayer(t_data *data)
{
	data->img = malloc(sizeof(t_imgptr));
	data->img->img = mlx_new_image(data->mlx, WIN_W, WIN_H);
	data->img->path = mlx_get_data_addr(data->img->img, &data->img->bits, &data->img->line, &data->img->end);
	raycasting(data);
	if (data->activate_minimap > 0)
		minimap(data);
 	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	return (1);
}
