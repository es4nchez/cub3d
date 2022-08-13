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

void	get_pos(t_data *data)
{
	int			x;
	int			y;
	int			i;
	int			control;

	i = 0;
	y = 0;
	control = 0;
	while (y <= data->mapHeight && data->buff[i])
	{
		x = 0;
		while (x <= data->mapWidth && data->buff[i])
		{
			if (data->buff[i] == 'P')
			{
				printf("\nx : %d\ny : %d\n", x, y);
//				data->rc->posX = x;
//				data->rc->posY = y + 1;
//				printf("\nStart : %d %d\n", x, y + 1);
			}
			i++;
			control++;
			x += 1;
		}
		y += 1;
	}
//	data->buff -= control;
}

int	read_map(t_data *data, char *filename);


void	load_map(t_data *data, char *s)
{
	(void)s;
//	int	**map;

	data->no = NULL;
	data->so = NULL;
	data->ea = NULL;
	data->we = NULL;
	data->f = NULL;
	data->c = NULL;

	if (!read_map(data, "maps/little.cub"))
		printf("PARSE ERROR\n");


//	map[4][14] = 1;
//	data->mapWidth = 5;
//	data->mapHeight = 15;
//	data->map = map;
	printf("\nx : %f\ny : %f\n", data->mapWidth, data->mapHeight);
	return ;
}
