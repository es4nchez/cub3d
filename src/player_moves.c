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
	data->pPosX += data->pDirX * SPD;
	data->pPosY += data->pDirY * SPD;
	return (0);
}

int	move_back(t_data *data)
{
	data->pPosX -= data->pDirX * SPD;
	data->pPosY -= data->pDirY * SPD;
	return (0);
}

int	move_left(t_data *data)
{
	float	oldDirX;
	float	oldDirY;

	data->pDir += 355;
	data->pDir %= 360;

	oldDirX = data->pDirX;
	oldDirY = data->pDirY;
	data->pDirX = data->pDirX * cos(RSP) - data->pDirY * sin(RSP);
	data->pDirY = oldDirX * sin(RSP) + data->pDirY * cos(RSP);
	return (0);
}

int	move_right(t_data *data)
{
	float	oldDirX;
	float	oldDirY;

	data->pDir += 5;
	data->pDir %= 360;

	oldDirX = data->pDirX;
	oldDirY = data->pDirY;
	data->pDirX = data->pDirX * cos(-RSP) - data->pDirY * sin(-RSP);
	data->pDirY = oldDirX * sin(-RSP) + data->pDirY * cos(-RSP);
	return (0);
}
