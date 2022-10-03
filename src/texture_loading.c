/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loading.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:03:54 by esanchez          #+#    #+#             */
/*   Updated: 2022/08/17 14:03:55 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	check_assets(t_data *data)
{
	int	fd;

	fd = open(data->no, 'r');
	if (fd == -1)
		return (1);
	close(fd);
	fd = open(data->so, 'r');
	if (fd == -1)
		return (1);
	close(fd);
	fd = open(data->we, 'r');
	if (fd == -1)
		return (1);
	close(fd);
	fd = open(data->ea, 'r');
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}

void	load_gun2(t_data *data)
{
	data->gun->gun = malloc(sizeof(t_img));
	data->gun->gun->img_path = "./assets/gun.xpm";
	data->gun->gun->img_name = mlx_xpm_file_to_image(data->mlx,
			data->gun->gun->img_path,
			&data->gun->gun->img_width, &data->gun->gun->img_height);
	data->gun->gun_f1 = malloc(sizeof(t_img));
	data->gun->gun_f1->img_path = "./assets/gun_f1.xpm";
	data->gun->gun_f1->img_name = mlx_xpm_file_to_image(data->mlx,
			data->gun->gun_f1->img_path,
			&data->gun->gun_f1->img_width, &data->gun->gun_f1->img_height);
	data->gun->gun_f2 = malloc(sizeof(t_img));
	data->gun->gun_f2->img_path = "./assets/gun_f2.xpm";
	data->gun->gun_f2->img_name = mlx_xpm_file_to_image(data->mlx,
			data->gun->gun_f2->img_path,
			&data->gun->gun_f2->img_width, &data->gun->gun_f2->img_height);
}

void	load_gun(t_data *data)
{
	load_gun2(data);
	data->gun->gun_f3 = malloc(sizeof(t_img));
	data->gun->gun_f3->img_path = "./assets/gun_f3.xpm";
	data->gun->gun_f3->img_name = mlx_xpm_file_to_image(data->mlx,
			data->gun->gun_f3->img_path,
			&data->gun->gun_f3->img_width, &data->gun->gun->img_height);
	data->gun->gun_f4 = malloc(sizeof(t_img));
	data->gun->gun_f4->img_path = "./assets/gun_f4.xpm";
	data->gun->gun_f4->img_name = mlx_xpm_file_to_image(data->mlx,
			data->gun->gun_f4->img_path,
			&data->gun->gun_f4->img_width, &data->gun->gun_f4->img_height);
	data->gun->gun_f5 = malloc(sizeof(t_img));
	data->gun->gun_f5->img_path = "./assets/gun_f5.xpm";
	data->gun->gun_f5->img_name = mlx_xpm_file_to_image(data->mlx,
			data->gun->gun_f5->img_path,
			&data->gun->gun_f5->img_width, &data->gun->gun_f5->img_height);
}

int	load_assets(t_data *data)
{
	if (check_assets(data))
		return (1);
	load_gun(data);
	data->n_addr = ft_calloc(1, sizeof(t_imgptr));
	data->n_addr->img = mlx_xpm_file_to_image(data->mlx, data->no,
			&data->n_addr->w, &data->n_addr->h);
	data->n_addr->pxs = (int *)mlx_get_data_addr(data->n_addr->img,
			&data->n_addr->bits, &data->n_addr->line, &data->n_addr->end);
	data->s_addr = ft_calloc(1, sizeof(t_imgptr));
	data->s_addr->img = mlx_xpm_file_to_image(data->mlx, data->so,
			&data->s_addr->w, &data->s_addr->h);
	data->s_addr->pxs = (int *)mlx_get_data_addr(data->s_addr->img,
			&data->s_addr->bits, &data->s_addr->line, &data->s_addr->end);
	data->w_addr = ft_calloc(1, sizeof(t_imgptr));
	data->w_addr->img = mlx_xpm_file_to_image(data->mlx, data->we,
			&data->w_addr->w, &data->w_addr->h);
	data->w_addr->pxs = (int *)mlx_get_data_addr(data->w_addr->img,
			&data->w_addr->bits, &data->w_addr->line, &data->w_addr->end);
	data->e_addr = ft_calloc(1, sizeof(t_imgptr));
	data->e_addr->img = mlx_xpm_file_to_image(data->mlx, data->ea,
			&data->e_addr->w, &data->e_addr->h);
	data->e_addr->pxs = (int *)mlx_get_data_addr(data->e_addr->img,
			&data->e_addr->bits, &data->e_addr->line, &data->e_addr->end);
	return (0);
}
