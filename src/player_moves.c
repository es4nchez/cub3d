/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:56:20 by esanchez          #+#    #+#             */
/*   Updated: 2022/08/10 23:56:33 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	move_front(t_data *data)
{
	float	oldPosX;
	float	oldPosY;

	oldPosX = data->pPosX;
	oldPosY = data->pPosY;
	data->pPosX += data->pDirX * SPD;
	data->pPosY += data->pDirY * SPD;
	if (data->map[(int)(data->pPosY)][(int)(data->pPosX)] == 1)
	{
		data->pPosX = oldPosX;
		data->pPosY = oldPosY;
	}
	return (1);
}

int	move_back(t_data *data)
{
	float	oldPosX;
	float	oldPosY;

	oldPosX = data->pPosX;
	oldPosY = data->pPosY;
	data->pPosX -= data->pDirX * SPD;
	data->pPosY -= data->pDirY * SPD;
	if (data->map[(int)(data->pPosY)][(int)(data->pPosX)] == 1)
	{
		data->pPosX = oldPosX;
		data->pPosY = oldPosY;
	}
	return (1);
}

int	move_left(t_data *data)
{
	float	oldDirX;
	float	oldDirY;
	float	oldPlaneX;

	data->pDir += 355;
	data->pDir %= 360;
	oldDirX = data->pDirX;
	oldDirY = data->pDirY;
	oldPlaneX = data->planeX;
	data->pDirX = data->pDirX * cos(RSP) - data->pDirY * sin(RSP);
	data->pDirY = oldDirX * sin(RSP) + data->pDirY * cos(RSP);
	data->planeX = data->planeX * cos(RSP) - data->planeY * sin(RSP);
	data->planeY = oldPlaneX * sin(RSP) + data->planeY * cos(RSP);
	return (0);
}

int	move_right(t_data *data)
{
	float	oldDirX;
	float	oldDirY;
	float	oldPlaneX;

	data->pDir += 5;
	data->pDir %= 360;

	oldDirX = data->pDirX;
	oldDirY = data->pDirY;
	oldPlaneX = data->planeX;
	data->pDirX = data->pDirX * cos(-RSP) - data->pDirY * sin(-RSP);
	data->pDirY = oldDirX * sin(-RSP) + data->pDirY * cos(-RSP);
	data->planeX = data->planeX * cos(-RSP) - data->planeY * sin(-RSP);
	data->planeY = oldPlaneX * sin(-RSP) + data->planeY * cos(-RSP);
	return (0);
}
