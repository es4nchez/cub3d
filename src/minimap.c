/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:50:30 by esanchez          #+#    #+#             */
/*   Updated: 2022/08/10 14:50:32 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	draw_sqr_minimap(t_data *data, t_map minimap, int color)
{
	int x;
	int	y;

	x = minimap.x * SMP;
	while (x < ((minimap.x + 1) * SMP))
	{
		y = minimap.y * SMP;
		while(y < ((minimap.y + 1) * SMP))
		{
			ft_mlx_pixel_put(data->img, y, x, color);
			y++;
		}
		x++;
	}
	return (0);
}

int	minimap_player(t_data *data)
{
	ft_mlx_pixel_put(data->img, (data->pPosX * SMP), (data->pPosY * SMP), GRN);
	ft_mlx_pixel_put(data->img, (data->pPosX * SMP) + 1, (data->pPosY * SMP), GRN);
	ft_mlx_pixel_put(data->img, (data->pPosX * SMP) + 1, (data->pPosY * SMP) + 1, GRN);
	ft_mlx_pixel_put(data->img, (data->pPosX * SMP) + 1, (data->pPosY * SMP) - 1, GRN);
	ft_mlx_pixel_put(data->img, (data->pPosX * SMP) - 1, (data->pPosY * SMP), GRN);
	ft_mlx_pixel_put(data->img, (data->pPosX * SMP) - 1, (data->pPosY * SMP) + 1,GRN);
	ft_mlx_pixel_put(data->img, (data->pPosX * SMP) - 1, (data->pPosY * SMP) - 1, GRN);
	ft_mlx_pixel_put(data->img, (data->pPosX * SMP), (data->pPosY * SMP) + 1, GRN);
	ft_mlx_pixel_put(data->img, (data->pPosX * SMP), (data->pPosY * SMP) - 1, GRN);
	return (0);
}

int	print_minimap(t_data *data, int x, int y, int nb)
{
	t_map	minimap;
	minimap.h = SMP;
	minimap.x = x;
	minimap.y = y;
	if (nb == 0 )
		draw_sqr_minimap(data, minimap, WHT);
	if (nb == 1)
		draw_sqr_minimap(data, minimap, GRY);
	if (nb == 4)
		draw_sqr_minimap(data, minimap, WHT);
	return (0);
}

int	minimap_dir(t_data *data)
{
	int		i;
	float	s;
	float	x;
	float	y;

	i = 0;
	s = 0.1;
	while (++i <= 8)
	{
		x = data->pPosX + data->pDirX * s;
		y = data->pPosY + data->pDirY * s;
		ft_mlx_pixel_put(data->img, (x * SMP), (y * SMP), BLU);
		s += 0.2;
	}
	return (0);
}


int	minimap(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->mapHeight)
	{
		j = -1;
		while (++j < data->mapWidth)
			print_minimap(data, i, j, data->map[i][j]);
		i++;
	}
	minimap_player(data);
	minimap_dir(data);
	return (0);
}

