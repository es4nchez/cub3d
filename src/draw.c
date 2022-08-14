/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:11:27 by esanchez          #+#    #+#             */
/*   Updated: 2022/08/09 16:11:30 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_mlx_pixel_put(t_imgptr *img, int x, int y, int color)
{
	char	*dst;

	dst = img->path + (y * img->line + x * (img->bits / 8));
	*(unsigned int *)dst = color;
}

int	draw_vert(t_data *data, t_raycasting *rc, int x)
{
	int	y;
	int	y2;
	int	color;

	y = rc->drawStart;
	y2 = rc->drawEnd;
	color = GRY;
	if (rc->side == 1)
		color = DRY;
    while (y < y2)
    {
//    	printf("pixel putted on : %d - %d\n", x, y);
		ft_mlx_pixel_put(data->img, x, y, color);
		y++;
	}
//	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
    return (0);
}


int	draw_line(t_data *data)
{
	int			k;
	t_imgptr	img;

	k = 0;
	data->line.dx = data->line.x2 - data->line.x1;
	data->line.dy = data->line.y2 - data->line.y1;
	if (data->line.dx >= data->line.dy)
		data->line.step = data->line.dx;
	else
		data->line.step = data->line.dy;
	data->line.xin = data->line.dx / data->line.step;
	data->line.yin = data->line.dy / data->line.step;
	data->line.dx = data->line.x1 + 0.5;
	data->line.dy = data->line.y1 + 0.5;
	img.img = mlx_new_image(data->mlx, 1920, 1080);
	img.path = mlx_get_data_addr(img.img, &img.bits, &img.line,
			&img.end);
	while (k < data->line.step)
	{
		data->line.dx = data->line.dx + data->line.xin;
		data->line.dy = data->line.dy + data->line.yin;
		ft_mlx_pixel_put(&img, data->line.dx, data->line.dy, 0x00FF0000);
		k++;
	}
	mlx_put_image_to_window(data->mlx, data->win, img.img, 0, 0);
	return (0);
}
