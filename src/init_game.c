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
	data->planey = 0;
	data->planex = 0.66;
	data->activate_minimap = 1;
	data->activate_mouse = 1;
	data->horizon = WIN_H / 2;
}

void	init_player(t_data *data)
{
	data->pdirx = 0;
	data->pdiry = 0;
	if (data->pdir == 0)
		data->pdiry = -1;
	if (data->pdir == 1)
		data->pdiry = 1;
	if (data->pdir == 2)
		data->pdirx = -1;
	if (data->pdir == 3)
		data->pdirx = 1;
}

void	init_game(t_data *data)
{
	init_data(data);
	init_player(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_W, WIN_H, "duckenstein");
	data->img = malloc(sizeof(t_imgptr));
	data->img->img = mlx_new_image(data->mlx, WIN_W, WIN_H);
	data->img->path = mlx_get_data_addr(data->img->img, &data->img->bits,
			&data->img->line, &data->img->end);
	load_assets(data);
}
