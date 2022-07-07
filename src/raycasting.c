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

	data->rc.mapX = (int)data->rc.posX;	//which box of the map we're in
	data->rc.mapY = (int)data->rc.posY;	//

}

void	calculate_next_step(t_data *data)
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
		data->rc.sideDistY = (data->rc.mapY + data->rc.1.0 - data->rc.posY) * data->rc.deltaDistY;
	}
}

void	raycasting(t_data *data)
{

	if (data->rc.rayDirX == 0)
		data->rc.deltaDistX = 1e30;
	else
		data->rc.deltaDistX = fabs(1 / data->rc.rayDirX);   //length of ray from current position to next x or y-side
	if (data->rc.rayDirY == 0)
		data->rc.deltaDistY = 1e30;
	else
		data->rc.deltaDistY = fabs(1 / data->rc.rayDirY);

	data->rc.hit = 0; //was there a wall hit?

}
