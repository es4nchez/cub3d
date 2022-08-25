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
	if (rc->raydirx < 0)
	{
		rc->step_x = -1;
		rc->sidedistx = (data->pposx - (float)rc->mapx) * rc->deltadistx;
	}
	else
	{
		rc->step_x = 1;
		rc->sidedistx = ((float)rc->mapx + 1.0 - data->pposx) * rc->deltadistx;
	}
	if (rc->raydiry < 0)
	{
		rc->step_y = -1;
		rc->sidedisty = (data->pposy - (float)rc->mapy) * rc->deltadisty;
	}
	else
	{
		rc->step_y = 1;
		rc->sidedisty = ((float)rc->mapy + 1.0 - data->pposy) * rc->deltadisty;
	}
	return (1);
}

void	projected_distance(t_raycasting *rc)
{
	if (rc->side == 0 || rc->side == 2)
		rc->perpwalldist = (rc->sidedistx - rc->deltadistx);
	else
		rc->perpwalldist = (rc->sidedisty - rc->deltadisty);
}
