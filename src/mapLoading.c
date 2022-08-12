
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

void	load_map(t_data *data, char *s)
{
	(void)s;
	int	**map;

	map = malloc(sizeof(int *) * 10);
	map[0] = malloc(sizeof(int) * 15);
	map[0][0] = 1;
	map[0][1] = 1;
	map[0][2] = 1;
	map[0][3] = 1;
	map[0][4] = 1;
	map[0][5] = 1;
	map[0][6] = 1;
	map[0][7] = 1;
	map[0][8] = 1;
	map[0][9] = 1;
	map[0][10] = 1;
	map[0][11] = 1;
	map[0][12] = 1;
	map[0][13] = 1;
	map[0][14] = 1;
	map[1] = malloc(sizeof(int) * 15);
	map[1][0] = 1;
	map[1][1] = 0;
	map[1][2] = 0;
	map[1][3] = 0;
	map[1][4] = 1;
	map[1][5] = 1;
	map[1][6] = 1;
	map[1][7] = 1;
	map[1][8] = 1;
	map[1][9] = 0;
	map[1][10] = 1;
	map[1][11] = 1;
	map[1][12] = 1;
	map[1][13] = 1;
	map[1][14] = 1;
	map[2] = malloc(sizeof(int) * 15);
	map[2][0] = 1;
	map[2][1] = 0;
	map[2][2] = 0;
	map[2][3] = 0;
	map[2][4] = 0;
	map[2][5] = 0;
	map[2][6] = 0;
	map[2][7] = 0;
	map[2][8] = 0;
	map[2][9] = 0;
	map[2][10] = 0;
	map[2][11] = 1;
	map[2][12] = 1;
	map[2][13] = 1;
	map[2][14] = 1;
	map[3] = malloc(sizeof(int) * 15);
	map[3][0] = 1;
	map[3][1] = 0;
	map[3][2] = 0;
	map[3][3] = 4;
	map[3][4] = 0;
	map[3][5] = 1;
	map[3][6] = 1;
	map[3][7] = 1;
	map[3][8] = 1;
	map[3][9] = 1;
	map[3][10] = 1;
	map[3][11] = 1;
	map[3][12] = 1;
	map[3][13] = 1;
	map[3][14] = 1;
	map[4] = malloc(sizeof(int) * 15);
	map[4][0] = 1;
	map[4][1] = 1;
	map[4][2] = 1;
	map[4][3] = 1;
	map[4][4] = 1;
	map[4][5] = 1;
	map[4][6] = 1;
	map[4][7] = 1;
	map[4][8] = 1;
	map[4][9] = 1;
	map[4][10] = 1;
	map[4][11] = 1;
	map[4][12] = 1;
	map[4][13] = 1;
	map[4][14] = 1;
	data->mapWidth = 5;
	data->mapHeight = 15;
	data->map = map;
	printf("\nx : %f\ny : %f\n", data->mapWidth, data->mapHeight);
	return ;
}
