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

int	read_map(t_data *data, char *filename);

int	load_map(t_data *data, char *s)
{
	data->no = NULL;
	data->so = NULL;
	data->ea = NULL;
	data->we = NULL;
	data->f = -1;
	data->c = -1;
	if (!read_map(data, s))
	{
		printf("PARSE ERROR\n");
		return (0);
	}
	printf("\nx : %f\ny : %f\n", data->mapwidth, data->mapheight);
	return (1);
}
