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
	data->pPosX += data->pDirY * SPD;
	data->pPosY -= data->pDirX * SPD;

	return (0);
}

int	move_lateral_right(t_data *data)
{
	data->pPosX -= data->pDirY * SPD;
	data->pPosY += data->pDirX * SPD;
	return (0);
}
