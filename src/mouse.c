/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:14:13 by esanchez          #+#    #+#             */
/*   Updated: 2022/08/25 17:14:16 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	mouse(int x, int y, t_data *data)
{
	float	mrsp;
	float	olddir_x;
	float	olddir_y;
	float	oldplane_x;

	if (data->activate_mouse == 1)
	{
		mrsp = ((float)(x - WIN_W / 2)) / 500.0;
		olddir_x = data->pdirx;
		olddir_y = data->pdiry;
		oldplane_x = data->planex;
		data->horizon = fmax(0,
				fmin(WIN_H, data->horizon + (WIN_H / 2 - y) / 1));
		data->pdirx = data->pdirx * cos(mrsp) - data->pdiry * sin(mrsp);
		data->pdiry = olddir_x * sin(mrsp) + data->pdiry * cos(mrsp);
		data->planex = data->planex * cos(mrsp) - data->planey * sin(mrsp);
		data->planey = oldplane_x * sin(mrsp) + data->planey * cos(mrsp);
		mlx_mouse_move(data->win, (int)(WIN_W / 2), (int)(WIN_H / 2));
		mlx_mouse_hide(data->win);
	}
	else
		mlx_mouse_show(data->win);
	return (0);
}
