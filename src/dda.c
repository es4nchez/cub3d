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

void	dda(t_data *data, t_raycasting *rc)
{
	while (rc->hit == 0)
	{
  		if (rc->sideDistX < rc->sideDistY)	//jump to next map square, either in x-direction, or in y-direction
		{
			rc->sideDistX += rc->deltaDistX;
			rc->mapX += rc->stepX;
			rc->side = 0;
		}
		else
		{
			rc->sideDistY += rc->deltaDistY;
			rc->mapY += rc->stepY;
			rc->side = 1;
		}
		if (data->map[rc->mapY][rc->mapX] > 0)  //Check if ray has hit a wall
			rc->hit = 1;
	}
//	printf("hit : %d on mapX : %d & mapY : %d\n", rc->hit, rc->mapX, rc->mapY);
}
