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
	data->pPosY -= SPD;
	return (0);
}

int	move_back(t_data *data)
{
	data->pPosY += SPD;
	return (0);
}

int	move_left(t_data *data)
{
	data->pDir += 355;
	data->pDir %= 360;
	return (0);
}

int	move_right(t_data *data)
{
	data->pDir += 5;
	data->pDir %= 360;
	return (0);
}
