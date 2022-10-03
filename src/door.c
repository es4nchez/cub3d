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

void	door_near_by(t_data *data)
{
	if (data->map[(int)(data->pposy) - 1][(int)(data->pposx)] == 2)
		data->map[(int)(data->pposy) - 1][(int)(data->pposx)] = 3;
	else if (data->map[(int)(data->pposy) - 1][(int)(data->pposx)] == 3)
		data->map[(int)(data->pposy) - 1][(int)(data->pposx)] = 2;
	else if (data->map[(int)(data->pposy) + 1][(int)(data->pposx)] == 2)
		data->map[(int)(data->pposy) + 1][(int)(data->pposx)] = 3;
	else if (data->map[(int)(data->pposy) + 1][(int)(data->pposx)] == 3)
		data->map[(int)(data->pposy) + 1][(int)(data->pposx)] = 2;
	else if (data->map[(int)(data->pposy)][(int)(data->pposx) - 1] == 2)
		data->map[(int)(data->pposy)][(int)(data->pposx) - 1] = 3;
	else if (data->map[(int)(data->pposy)][(int)(data->pposx) - 1] == 3)
		data->map[(int)(data->pposy)][(int)(data->pposx) - 1] = 2;
	else if (data->map[(int)(data->pposy)][(int)(data->pposx) + 1] == 2)
		data->map[(int)(data->pposy)][(int)(data->pposx) + 1] = 3;
	else if (data->map[(int)(data->pposy)][(int)(data->pposx) + 1] == 3)
		data->map[(int)(data->pposy)][(int)(data->pposx) + 1] = 2;
}

void	open_door(t_data *data)
{
	door_near_by(data);
}

void	door_loading(t_data *data)
{
	data->door->dr = ft_calloc(1, sizeof(t_imgptr));
	data->door->dr->img = mlx_xpm_file_to_image(data->mlx, "./assets/door.xpm",
			&data->door->dr->w, &data->door->dr->h);
	data->door->dr->pxs = (int *)mlx_get_data_addr(data->door->dr->img,
			&data->door->dr->bits, &data->door->dr->line, &data->door->dr->end);
}
