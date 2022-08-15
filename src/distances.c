/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distances.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 21:59:34 by esanchez          #+#    #+#             */
/*   Updated: 2022/08/13 21:59:37 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	calculate_distance(t_data *data, t_raycasting *rc)
{
	if (rc->rayDirX < 0)
	{
		rc->stepX = -1;
		rc->sideDistX = (data->pPosX - (float)rc->mapX) * rc->deltaDistX;
	}
	else
	{
		rc->stepX = 1;
		rc->sideDistX = ((float)rc->mapX + 1.0 - data->pPosX) * rc->deltaDistX;
	}
	if (rc->rayDirY < 0)
	{
		rc->stepY = -1;
		rc->sideDistY = (data->pPosY - (float)rc->mapY) * rc->deltaDistY;
	}
	else
	{
		rc->stepY = 1;
		rc->sideDistY = ((float)rc->mapY + 1.0 - data->pPosY) * rc->deltaDistY;
	}
	return (1);
}

void	projected_distance(t_raycasting *rc)
{
	if(rc->side == 0)
		rc->perpWallDist = (rc->sideDistX - rc->deltaDistX);
	else
		rc->perpWallDist = (rc->sideDistY - rc->deltaDistY);
//	printf("rcWallDist : %f\n", rc->perpWallDist);
//	printf("perpWallDist : %f\n", rc->perpWallDist);
}
