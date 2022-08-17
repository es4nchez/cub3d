/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 02:00:03 by esanchez          #+#    #+#             */
/*   Updated: 2022/07/08 02:00:07 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_data(t_data *data)
{
//	t_rc	*rc;

	data->planeY = 0;
	data->planeX = 0.66;
	data->activateMinimap = 1;
	data->activate_mouse = 1;
	data->horizon = WIN_H / 2;
}

void	init_player(t_data *data)
{
	data->pDirX = 0;
	data->pDirY = 0;
	if (data->pDir == 0)
		data->pDirY = -1;
	if (data->pDir == 1)
		data->pDirY = 1;
	if (data->pDir == 2)
		data->pDirX = -1;
	if (data->pDir == 3)
		data->pDirX = 1;
}

void	init_game(t_data *data)
{
	init_data(data);
	init_player(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_W, WIN_H, "Duckenstein");
	load_assets(data);
	texture_loading(data);
//	exit (1);
}
