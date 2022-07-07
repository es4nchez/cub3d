/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapLoading.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:32:54 by esanchez          #+#    #+#             */
/*   Updated: 2022/07/06 16:32:56 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_data(t_data *data)
{
	data->rc.dirX = -1;
	data->rc.dirY = 0;
	data->rc.planeX = 0;
	data->rc.planeY = 0.66;
	data->rc.dirX = 0;
	data->rc.dirX = 0;

}

void	init_game(t_data *data)
{
	create_map(data);
	init_data(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_W, WIN_H, "Duckenstein");

}

void	create_map(t_data *data)
{
	int			x;
	int			y;
	int			i;
	int			control;

	i = 0;
	y = 0;
	control = 0;
	while (y <= data->mapHeight && *data->buff)
	{
		x = 0;
		while (x <= data->mapWidth && *data->buff)
		{
			if (*data->buff == 'P')
			{
				data->rc.posX = x;
				data->rc.posY = y + 1;
				printf("\nStart : %d %d\n", x, y + 1);
			}
			data->buff++;
			control++;
			x += 1;
		}
		y += 1;
	}
	data->buff -= control;
}

void	load_map(t_data *data, char *s)
{
	int	fd;
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->buff = malloc(sizeof(char) * 2000);
	fd = open(s, O_RDONLY);
	j = read(fd, data->buff, 2000);
	data->buff[j] = '\0';
	close(fd);
	while (data->buff[i] != 0)
	{
		if (data->buff[i] != '\n')
			data->mapWidth++;
		else
		{
			data->mapWidth = 0;
			data->mapHeight++;
		}
		i++;
	}
	data->mapHeight += 1;
	printf("\nx : %f\ny : %f\n", data->mapWidth, data->mapHeight);
	return ;
}
