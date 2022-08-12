/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 01:39:00 by esanchez          #+#    #+#             */
/*   Updated: 2022/07/08 01:39:03 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
// Digital Differential Analysis
/*
void	dda(t_data *data)
{
	printf("Start dda...\n");
	while (data->rc.hit == 0)
	{
  		if (data->rc.sideDistX < data->rc.sideDistY)	//jump to next map square, either in x-direction, or in y-direction
		{
			data->rc.sideDistX += data->rc.deltaDistX;
			data->rc.mapX += data->rc.stepX;
			data->rc.side = 0;
		}
		else
		{
			data->rc.sideDistY += data->rc.deltaDistY;
			data->rc.mapY += data->rc.stepY;
			data->rc.side = 1;
		}
//		printf("mapX : %d\nmapY : %d\n", data->rc.mapX, data->rc.mapY);
		if (data->mapi[data->rc.mapX][data->rc.mapY] > 0)  //Check if ray has hit a wall
			data->rc.hit = 1;
	}
	printf("hit : %d on mapX : %d & mapY : %d\n", data->rc.hit, data->rc.mapX, data->rc.mapY);
}
*/
