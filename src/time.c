/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:23:35 by esanchez          #+#    #+#             */
/*   Updated: 2022/09/30 17:23:38 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

size_t	time_now(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	fps(t_data *data)
{
	data->fps->timestamp = time_now();
	if ((data->fps->timestamp - data->fps->starttime) / 1000 >= 1)
	{
		data->fps->frame_now = data->fps->frame;
		data->fps->frame = 0;
		data->fps->starttime += 1000;
	}
}
