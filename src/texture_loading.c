/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loading.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:03:54 by esanchez          #+#    #+#             */
/*   Updated: 2022/08/17 14:03:55 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	load_assets(t_data *data)
{
	data->n_addr = calloc(1, sizeof(t_imgptr));
	data->n_addr->img = mlx_xpm_file_to_image(data->mlx, data->no,
			&data->n_addr->w, &data->n_addr->h);
	data->n_addr->pxs = (int *)mlx_get_data_addr(data->n_addr->img,
			&data->n_addr->bits, &data->n_addr->line, &data->n_addr->end);
	data->s_addr = calloc(1, sizeof(t_imgptr));
	data->s_addr->img = mlx_xpm_file_to_image(data->mlx, data->so,
			&data->s_addr->w, &data->s_addr->h);
	data->s_addr->pxs = (int *)mlx_get_data_addr(data->s_addr->img,
			&data->s_addr->bits, &data->s_addr->line, &data->s_addr->end);
	data->w_addr = calloc(1, sizeof(t_imgptr));
	data->w_addr->img = mlx_xpm_file_to_image(data->mlx, data->we,
			&data->w_addr->w, &data->w_addr->h);
	data->w_addr->pxs = (int *)mlx_get_data_addr(data->w_addr->img,
			&data->w_addr->bits, &data->w_addr->line, &data->w_addr->end);
	data->e_addr = calloc(1, sizeof(t_imgptr));
	data->e_addr->img = mlx_xpm_file_to_image(data->mlx, data->ea,
			&data->e_addr->w, &data->e_addr->h);
	data->e_addr->pxs = (int *)mlx_get_data_addr(data->e_addr->img,
			&data->e_addr->bits, &data->e_addr->line, &data->e_addr->end);
	return (1);
}
