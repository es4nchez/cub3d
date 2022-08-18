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
		if (rc->sidedistx < rc->sidedisty)
		{
			rc->sidedistx += rc->deltadistx;
			rc->mapx += rc->step_x;
			rc->side = 0;
		}
		else
		{
			rc->sidedisty += rc->deltadisty;
			rc->mapy += rc->step_y;
			rc->side = 1;
		}
		if (data->map[rc->mapy][rc->mapx] > 0)
			rc->hit = 1;
	}
}
