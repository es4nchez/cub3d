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
		printf("Error\n");
		printf("Please select a map-path in the \"maps\" directory as argument\n");
		return (0);
	}
	if (ac > 2)
	{
		printf("Error\n");
		printf("Cub3d take only one argument, the path of a map\n");
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	printf("\nStarting game...\n");
	if (!args_error(ac))
		return (0);
	if (!load_map(&data, av[1]))
		return (0);
	if (init_game(&data))
	{
		printf("Error\nError in assets path\n");
		exit_game(&data);
	}
	printf("\nInit done.\n\n");
	mlx_loop_hook(data.mlx, displayer, &data);
	mlx_mouse_hook(data.win, shoot, &data);
	mlx_hook(data.win, 2, 1L << 0, gameplay, &data);
	mlx_hook(data.win, 6, 1L << 4, mouse, &data);
	mlx_hook(data.win, 17, 0, &exit_game, &data);
	mlx_loop(data.mlx);
	return (0);
}
