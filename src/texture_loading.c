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
	data->n_addr = malloc(sizeof(t_imgptr *) * 4);
	data->n_addr->img = mlx_xpm_file_to_image(data->mlx, data->no, &data->n_addr->w, &data->n_addr->h);
	data->n_addr->pxs = (int *)mlx_get_data_addr(data->n_addr->img, &data->n_addr->bits, &data->n_addr->line, &data->n_addr->end);
	printf("pixcolor : %d\nsize : %lu", data->n_addr->pxs[0], sizeof(data->n_addr->pxs));
	return (1);
}

int	texture_loading(t_data *data)
{
	(void)data;
	return (1);
}
