/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:56:43 by esanchez          #+#    #+#             */
/*   Updated: 2022/10/03 12:56:47 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	shoot_loop(t_data *data)
{
	if (data->gun->gun_frame <= 3)
		mlx_put_image_to_window(data->mlx, data->win,
			data->gun->gun_f1->img_name,
			WIN_W / 2, WIN_H - data->gun->gun_f1->img_height);
	else if (data->gun->gun_frame <= 6)
		mlx_put_image_to_window(data->mlx, data->win,
			data->gun->gun_f2->img_name,
			WIN_W / 2, WIN_H - data->gun->gun_f2->img_height);
	else if (data->gun->gun_frame <= 9)
		mlx_put_image_to_window(data->mlx, data->win,
			data->gun->gun_f3->img_name,
			WIN_W / 2, WIN_H - data->gun->gun_f3->img_height);
	else if (data->gun->gun_frame <= 12)
		mlx_put_image_to_window(data->mlx, data->win,
			data->gun->gun_f4->img_name,
			WIN_W / 2, WIN_H - data->gun->gun_f4->img_height);
	else if (data->gun->gun_frame <= 15)
		mlx_put_image_to_window(data->mlx, data->win,
			data->gun->gun_f5->img_name,
			WIN_W / 2, WIN_H - data->gun->gun_f5->img_height);
	if (data->gun->gun_frame == 15)
	{
		data->gun->gun_loop = 0;
		data->gun->gun_frame = 0;
	}
}

int	shoot(int keycode, int x, int y, t_data *data)
{
	pid_t	pid;

	(void)x;
	(void)y;
	if (keycode == M_CLK_R)
		open_door(data);
	if (keycode != M_CLK_L)
		return (0);
	if (data->gun->gun_frame)
		return (0);
	data->gun->gun_loop = 1;
	pid = fork();
	if (pid == 0)
		execlp("afplay", "afplay", "-v", "5", "assets/gun_shot.mp3", NULL);
	return (0);
}
