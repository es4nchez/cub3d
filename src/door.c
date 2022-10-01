/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 22:05:03 by esanchez          #+#    #+#             */
/*   Updated: 2022/09/30 22:05:05 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	open_door(t_data *data)
{
	printf("case : %d\n", data->map[(int)(data->pposy) + 1][(int)(data->pposx)]);
	if (data->map[(int)(data->pposy) - 1][(int)(data->pposx)] == 2)
		data->map[(int)(data->pposy) - 1][(int)(data->pposx)] = 0;
}

void	door_loading(t_data *data)
{
	data->door->dr = ft_calloc(1, sizeof(t_imgptr));
	data->door->dr->img = mlx_xpm_file_to_image(data->mlx, "./assets/door.xpm",
			&data->door->dr->w, &data->door->dr->h);
	data->door->dr->pxs = (int *)mlx_get_data_addr(data->door->dr->img,
			&data->door->dr->bits, &data->door->dr->line, &data->door->dr->end);
}
