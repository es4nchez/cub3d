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

void	kill_music(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execlp("killall", "killall", "afplay", NULL);
}

int	exit_game(t_data *data)
{
	int	i;

	i = 0;
	free(data->n_addr);
	free(data->s_addr);
	free(data->w_addr);
	free(data->e_addr);
	free(data->img);
	while (i < data->mapheight)
		free(data->map[i++]);
	free(data->map);
	free(data->fps);
	free(data->gun->gun);
	free(data->gun->gun_f1);
	free(data->gun->gun_f2);
	free(data->gun->gun_f3);
	free(data->gun->gun_f4);
	free(data->gun->gun_f5);
	free(data->gun);
	free(data->door);
	kill_music();
	exit (0);
}
