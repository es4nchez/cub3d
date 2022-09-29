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

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map != NULL && i < data->mapheight)
	{
		free(data->map[i]);
		i++;
	}
	if (data->map != NULL)
		free(data->map);
	if (data->no != NULL)
		free(data->no);
	if (data->so != NULL)
		free(data->so);
	if (data->we != NULL)
		free(data->we);
	if (data->ea != NULL)
		free(data->ea);
}

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
		free_map(data);
		printf("PARSE ERROR\n");
		return (0);
	}
	return (1);
}
