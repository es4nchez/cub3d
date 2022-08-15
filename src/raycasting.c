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
	rc->mapX = data->pPosX;
	rc->mapY = data->pPosY;
	rc->hit = 0;
	return (1);
}

int	stripe_calculator(t_raycasting *rc)
{
	rc->lineHeight = (WIN_H / rc->perpWallDist);
	rc->drawStart = (rc->lineHeight / -2) + (WIN_H / 2);
	if(rc->drawStart < 0)
		rc->drawStart = 0;
	rc->drawEnd = (rc->lineHeight / 2 + WIN_H / 2);
	if(rc->drawEnd >= WIN_H)
		rc->drawEnd = WIN_H - 1;
	return (1);
}

int	raycasting(t_data *data)
{
	int				x;
	t_raycasting	rc;

	x = 0;
//	printf("pPosX : %f | pPosY : %f\n", data->pPosX, data->pPosY);
	while(x <= WIN_W)
	{
		init_raycasting(data, &rc);
		rc.cameraX = 2 * x / (float)WIN_W - 1.0;
		rc.rayDirX = data->pDirX + data->planeX * rc.cameraX;
		rc.rayDirY = data->pDirY + data->planeY * rc.cameraX;
		if (rc.rayDirX == 0)
			rc.deltaDistX = INFINITY;
		else
			rc.deltaDistX = fabs(1 / rc.rayDirX);
		if (rc.rayDirY == 0)
			rc.deltaDistY = INFINITY;
		else
			rc.deltaDistY = fabs(1 / rc.rayDirY);
		calculate_distance(data, &rc);
		dda(data, &rc);
		projected_distance(&rc);
		stripe_calculator(&rc);
		draw_vert(data, &rc, x);
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
	if (data->activateMinimap > 0)
		minimap(data);
 	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	return (1);
}
