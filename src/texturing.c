/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 04:03:45 by esanchez          #+#    #+#             */
/*   Updated: 2022/08/16 04:03:48 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	texture_picker(t_data *data, t_raycasting *rc, int pix)
{
	if (rc->side == 0 && rc->raydirx > 0)
		return (data->n_addr->pxs[(int)pix]);
	if (rc->side == 0 && rc->raydirx <= 0)
		return (data->s_addr->pxs[(int)pix]);
	if (rc->side == 1 && rc->raydiry >= 0)
		return (data->w_addr->pxs[(int)pix]);
	else
		return (data->e_addr->pxs[(int)pix]);
}

int	texture_rendering(t_data *data, t_raycasting *rc)
{
	rc->texwidth = data->n_addr->w;
	rc->texheight = data->n_addr->h;
	if (rc->side == 0)
		rc->wallx = data->pposy + (rc->perpwalldist * rc->raydiry);
	else
		rc->wallx = data->pposx + (rc->perpwalldist * rc->raydirx);
	rc->wallx -= floor(rc->wallx);
	rc->texx = (int)(rc->wallx * (double)rc->texwidth);
	if (rc->side == 0 && rc->raydirx <= 0)
		rc->texx = rc->texwidth - rc->texx - 1;
	if (rc->side == 1 && rc->raydiry >= 0)
		rc->texx = rc->texwidth - rc->texx - 1;
	return (1);
}

int	texturing(t_data *data, t_raycasting *rc, int x)
{
	int		y;
	int		color;
	double	step;
	float	pix;

	y = rc->drawstart;
	texture_rendering(data, rc);
	step = 1.0 * rc->texheight / rc->lineheight;
	rc->texpos = (rc->drawstart - data->horizon + rc->lineheight / 2) * step;
	while (y < rc->drawend)
	{
		rc->texy = (int)rc->texpos & (rc->texheight - 1);
		rc->texpos += step;
		pix = (rc->texheight * (rc->texy) + rc->texx);
		color = texture_picker(data, rc, pix);
		ft_mlx_pixel_put(data->img, x, y, color);
		y++;
	}
	return (1);
}
