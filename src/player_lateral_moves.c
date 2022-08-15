/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_lateral_moves.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 23:14:31 by esanchez          #+#    #+#             */
/*   Updated: 2022/08/12 23:14:34 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	move_lateral_left(t_data *data)
{
	float	oldPosX;
	float	oldPosY;

	oldPosX = data->pPosX;
	oldPosY = data->pPosY;
	data->pPosX += data->pDirY * SPD;
	data->pPosY -= data->pDirX * SPD;
	if (data->map[(int)(data->pPosY)][(int)(data->pPosX)] == 1)
	{
		data->pPosX = oldPosX;
		data->pPosY = oldPosY;
	}
	return (1);
}

int	move_lateral_right(t_data *data)
{
	float	oldPosX;
	float	oldPosY;

	oldPosX = data->pPosX;
	oldPosY = data->pPosY;
	data->pPosX -= data->pDirY * SPD;
	data->pPosY += data->pDirX * SPD;
	if (data->map[(int)(data->pPosY)][(int)(data->pPosX)] == 1)
	{
		data->pPosX = oldPosX;
		data->pPosY = oldPosY;
	}
	return (1);
}
