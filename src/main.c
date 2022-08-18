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

int	args_error(int ac)
{
	if (ac == 1)
	{
		printf("Please select a map-path in the \"maps\" directory as argument\n");
		return (0);
	}
	if (ac > 2)
	{
		printf("Cub3d take only one argument, the path of a map\n");
		return (0);
	}
	return (1);
}

int	exit_game(t_data *data)
{
	(void)data;
	exit (0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	printf("\nStarting game...\n\n");
	if (!args_error(ac))
		return (0);
	if (!load_map(&data, av[1]))
		return (0);
	init_game(&data);
	printf("\nInit done.\n\n");
	mlx_loop_hook(data.mlx, displayer, &data);
	mlx_hook(data.win, 2, 1L << 0, gameplay, &data);
	mlx_hook(data.win, 6, 1L << 4, mouse, &data);
	mlx_hook(data.win, 17, 0, &exit_game, &data);
	mlx_loop(data.mlx);
	return (0);
}
