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

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	select_side(t_raycasting *rc)
{
	if (rc->side == 0)
	{
		if (rc->rayDirX > 0)
			return (GRY);
		else
			return (GRN);
	}
	else
	{
		if (rc->rayDirY > 0)
			return (BLU);
		else
			return (RED);
	}
}

int	draw_vert(t_data *data, t_raycasting *rc, int x)
{
	int	i;
	int	y;
	int	y2;
	int	color;

	i = 0;
	y = rc->drawStart;
	y2 = rc->drawEnd;
	color = select_side(rc);
	while (i < y)
		ft_mlx_pixel_put(data->img, x, i++, data->f);
	while (y < y2)
		ft_mlx_pixel_put(data->img, x, y++, 3553695);
	while (y < (WIN_H - 1))
		ft_mlx_pixel_put(data->img, x, y++, data->c);
	return (0);
}
