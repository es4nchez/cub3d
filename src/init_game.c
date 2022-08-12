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

	data->rc.hit = -1;
	data->rc.dirX = -1;
	data->rc.dirY = 0;
	data->rc.planeX = 0;
	data->rc.planeY = 0.66;
	data->rc.dirX = 0;
	data->rc.dirX = 0;
}

void	init_game(t_data *data, char *mapPath)
{
	(void)mapPath;
//	load_map(data, mapPath);
//	get_pos(data);
//	init_data(data);
	data->pPosX = 3;
	data->pPosY = 3;
	data->pDir = 0;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_W, WIN_H, "Duckenstein");
}
