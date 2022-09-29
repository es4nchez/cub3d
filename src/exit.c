/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:53:09 by esanchez          #+#    #+#             */
/*   Updated: 2022/09/29 17:53:12 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	exit_game(t_data *data)
{
	int i;

	i = 0;
	free(data->n_addr);
	free(data->s_addr);
	free(data->w_addr);
	free(data->e_addr);
	free(data->img);
	while (i < data->mapheight)
		free(data->map[i++]);
	free(data->map);
	exit (0);
}
