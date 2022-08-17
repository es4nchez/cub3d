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

int	stripe_calculator(t_data *data, t_raycasting *rc)
{
	rc->lineHeight = (WIN_H / rc->perpWallDist);
	rc->drawStart = (rc->lineHeight / -2) + data->horizon;
	if(rc->drawStart < 0)
		rc->drawStart = 0;
	rc->drawEnd = (rc->lineHeight / 2 + data->horizon);
	if(rc->drawEnd >= WIN_H)
		rc->drawEnd = WIN_H - 1;
	return (1);
}

int	texture_rendering(t_data *data, t_raycasting *rc)
{
//	int texNum = worldMap[mapX][mapY] - 1;
	rc->texWidth = data->n_addr->w;
	rc->texHeight = data->n_addr->h;
	if (rc->side == 0)
		rc->wallX = data->pPosY + rc->perpWallDist * rc->rayDirY;
	else
		rc->wallX = data->pPosX + rc->perpWallDist * rc->rayDirX;
//	printf("wallX : %f\n", rc->wallX);
//	rc->wallX += 1;

	rc->texX = (int)(rc->wallX * rc->texWidth);
//	printf("t1 texX : %d\n", rc->texX);
	if(rc->side == 0 && rc->rayDirX > 0)
		rc->texX = ((rc->texWidth * (rc->texHeight - 1)) - rc->texX - 1);
	if(rc->side == 1 && rc->rayDirY < 0)
		rc->texX = ((rc->texWidth * (rc->texHeight - 1)) - rc->texX - 1);
//	printf("t2 texX : %d\n", abs(rc->texX));
	return (1);
}

int	texturing(t_data *data, t_raycasting *rc, int x)
{
	int		y;
	int		texY;
	double	step;
	double	texPos;
	int		color;

	y = rc->drawStart;
	step = 1.0 * rc->texHeight / rc->lineHeight;
	texPos = (rc->drawStart - data->horizon + (rc->lineHeight / 2)) * step;
	while(y < rc->drawEnd)
	{
		texY = ((int)texPos) & (rc->texHeight - 1);
//		printf("texPos1 : %f\n", texPos);
		texPos += step;
//		printf("texPos2 : %f\n", texPos);
//		printf("texHeight : %d\ntexWidth: %f\ntexX : %d\ntexY : %d\n", rc->texHeight, rc->texWidth, rc->texX, texY);
//		printf("\npxs :%d\n", ((rc->texHeight * texY) + rc->texX));
		if (rc->texHeight * texY + rc->texX < 1024 && (rc->texHeight * texY + rc->texX) >= 0)
			color = data->n_addr->pxs[(rc->texHeight * texY) + rc->texX];
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
	if (data->activateMinimap > 0)
		minimap(data);
 	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	return (1);
}
