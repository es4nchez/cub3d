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

/*
void	raydirection(t_data *data)
{
	int x;

	x = 0;
	while (x < data->mapWidth)
	{
		data->rc.cameraX = 2 * x / data->mapWidth - 1;
		data->rc.rayDirX = data->rc.dirX + data->rc.planeX * data->rc.cameraX;
		data->rc.rayDirY = data->rc.dirY + data->rc.planeY * data->rc.cameraX;
		x++;
//  	printf("cameraX : %f\n", data->rc.cameraX);
//		printf("rayDirX : %f\n", data->rc.rayDirX);
//		printf("rayDirY : %f\n", data->rc.rayDirY);
	}
	printf("posX : %f\nposY : %f\n", data->rc.posX, data->rc.posY);
	data->rc.mapX = (int)data->rc.posX;	//which box of the map we're in
	data->rc.mapY = (int)data->rc.posY;	//

	if(data->rc.side == 0)
		data->rc.perpWallDist = (data->rc.sideDistX - data->rc.deltaDistX); //Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
	else
		data->rc.perpWallDist = (data->rc.sideDistY - data->rc.deltaDistY);

}

void	pre_rendering(t_data *data)
{
	//Calculate height of line to draw on screen
	data->render->h = WIN_H;
	data->render->lineHeight = (int)(data->render->h / data->rc.perpWallDist);

	//calculate lowest and highest pixel to fill in current stripe
	data->render->drawStart = -data->render->lineHeight / 2 + data->render->h / 2;
	if(data->render->drawStart < 0)
		data->render->drawStart = 0;
	data->render->drawEnd = data->render->lineHeight / 2 + data->render->h / 2;
	if(data->render->drawEnd >= data->render->h)
		data->render->drawEnd = data->render->h - 1;

}

void	precalculate_next_step(t_data *data)
{
	  //calculate step and initial sideDist
	if (data->rc.rayDirX < 0)
	{
		data->rc.stepX = -1;
		data->rc.sideDistX = (data->rc.posX - data->rc.mapX) * data->rc.deltaDistX;
	}
	else
	{
		data->rc.stepX = 1;
		data->rc.sideDistX = (data->rc.mapX + 1.0 - data->rc.posX) * data->rc.deltaDistX;
	}
	if (data->rc.rayDirY < 0)
	{
		data->rc.stepY = -1;
		data->rc.sideDistY = (data->rc.posY - data->rc.mapY) * data->rc.deltaDistY;
	}
	else
	{
		data->rc.stepY = 1;
		data->rc.sideDistY = (data->rc.mapY + 1.0 - data->rc.posY) * data->rc.deltaDistY;
	}
//	printf("Dist side X : %f\nDist side Y : %f\n", data->rc.sideDistX, data->rc.sideDistY);
}
*/
int	raycasting(t_data *data)
{
	data->img = malloc(sizeof(t_imgptr));
 //   data->img->img = mlx_new_image(data->mlx, 1920, 1080);
//    data->img->path = mlx_get_data_addr(data->img->img, &data->img->bits, &data->img->line, &data->img->end);
//	minimap(data);
 //   mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	return (1);
}
