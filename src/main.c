/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 04:16:50 by esanchez          #+#    #+#             */
/*   Updated: 2022/07/06 04:16:53 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	exit_game(t_data *data)
{
	(void)data;
	exit (0);
	return (0);
}

int	main(int ac, char **av)
{
	(void)ac;
	t_data	data;

	load_map(&data, av[1]);
	init_game(&data);
	mlx_hook(data.win, 2, 1L << 0, gameplay, &data);
	mlx_hook(data.win, 17, 0, &exit_game, &data);
	mlx_loop(data.mlx);
	return (0);
}

