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
	data->fps = ft_calloc(1, sizeof(t_frame));
	data->fps->frame = 1;
	data->fps->starttime = time_now();
	data->door = ft_calloc(1, sizeof(t_door));
	data->door->exist = 1;
}

int	move_start(t_data *data, float dist)
{
	float	olddirx;
	float	olddiry;
	float	oldplanex;

	olddirx = data->pdirx;
	olddiry = data->pdiry;
	oldplanex = data->planex;
	data->pdirx = data->pdirx * cos(dist) - data->pdiry * sin(dist);
	data->pdiry = olddirx * sin(dist) + data->pdiry * cos(dist);
	data->planex = data->planex * cos(dist) - data->planey * sin(dist);
	data->planey = oldplanex * sin(dist) + data->planey * cos(dist);
	return (0);
}

void	init_player(t_data *data)
{
	data->pdirx = 0;
	data->pdiry = -1;
	if (data->pdir == 'N')
		move_start(data, 0);
	if (data->pdir == 'S')
		move_start(data, (M_PI));
	if (data->pdir == 'W')
		move_start(data, -(M_PI / 2));
	if (data->pdir == 'E')
		move_start(data, (M_PI / 2));
}

int	init_game(t_data *data)
{
	init_data(data);
	init_player(data);
	if (data->pposx <= 0 || data->pposy <= 0)
		return (1);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_W, WIN_H, "duckenstein");
	data->img = ft_calloc(1, sizeof(t_imgptr));
	data->img->img = mlx_new_image(data->mlx, WIN_W, WIN_H);
	data->img->path = mlx_get_data_addr(data->img->img, &data->img->bits,
			&data->img->line, &data->img->end);
	if (load_assets(data))
		return (1);
	if (data->door->exist)
		door_loading(data);
	mlx_mouse_move(data->win, (int)(WIN_W / 2), (int)(WIN_H / 2));
	mlx_mouse_hide(data->win);
	return (0);
}
