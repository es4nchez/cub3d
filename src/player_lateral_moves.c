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
	float	oldposx;
	float	oldposy;

	oldposx = data->pposx;
	oldposy = data->pposy;
	data->pposx += data->pdiry * SPD;
	data->pposy -= data->pdirx * SPD;
	if (data->map[(int)(data->pposy)][(int)(data->pposx)] == 1)
	{
		data->pposx = oldposx;
		data->pposy = oldposy;
	}
	return (1);
}

int	move_lateral_right(t_data *data)
{
	float	oldposx;
	float	oldposy;

	oldposx = data->pposx;
	oldposy = data->pposy;
	data->pposx -= data->pdiry * SPD;
	data->pposy += data->pdirx * SPD;
	if (data->map[(int)(data->pposy)][(int)(data->pposx)] == 1)
	{
		data->pposx = oldposx;
		data->pposy = oldposy;
	}
	return (1);
}
