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
	float	oldposx;
	float	oldposy;

	oldposx = data->pposx;
	oldposy = data->pposy;
	data->pposx += data->pdirx * SPD;
	data->pposy += data->pdiry * SPD;
	if (data->map[(int)(data->pposy)][(int)(data->pposx)] == 1)
	{
		data->pposx = oldposx;
		data->pposy = oldposy;
	}
	return (1);
}

int	move_back(t_data *data)
{
	float	oldposx;
	float	oldposy;

	oldposx = data->pposx;
	oldposy = data->pposy;
	data->pposx -= data->pdirx * SPD;
	data->pposy -= data->pdiry * SPD;
	if (data->map[(int)(data->pposy)][(int)(data->pposx)] == 1)
	{
		data->pposx = oldposx;
		data->pposy = oldposy;
	}
	return (1);
}

int	move_left(t_data *data)
{
	float	olddirx;
	float	olddiry;
	float	oldplanex;

	data->pdir += 355;
	data->pdir %= 360;
	olddirx = data->pdirx;
	olddiry = data->pdiry;
	oldplanex = data->planex;
	data->pdirx = data->pdirx * cos(RSP) - data->pdiry * sin(RSP);
	data->pdiry = olddirx * sin(RSP) + data->pdiry * cos(RSP);
	data->planex = data->planex * cos(RSP) - data->planey * sin(RSP);
	data->planey = oldplanex * sin(RSP) + data->planey * cos(RSP);
	return (0);
}

int	move_right(t_data *data)
{
	float	olddirx;
	float	olddiry;
	float	oldplanex;

	data->pdir += 5;
	data->pdir %= 360;
	olddirx = data->pdirx;
	olddiry = data->pdiry;
	oldplanex = data->planex;
	data->pdirx = data->pdirx * cos(-RSP) - data->pdiry * sin(-RSP);
	data->pdiry = olddirx * sin(-RSP) + data->pdiry * cos(-RSP);
	data->planex = data->planex * cos(-RSP) - data->planey * sin(-RSP);
	data->planey = oldplanex * sin(-RSP) + data->planey * cos(-RSP);
	return (0);
}
