/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 04:41:55 by esanchez          #+#    #+#             */
/*   Updated: 2022/07/07 04:41:56 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	move_front(t_data *data);
int	move_back(t_data *data);
int	move_left(t_data *data);
int	move_right(t_data *data);
int	move_lateral_right(t_data *data);
int	move_lateral_left(t_data *data);

int	gameplay(int keycode, t_data *data)
{
	if (keycode == K_ESCAPE)
		exit_game(data);
	if (keycode == K_W)
		move_front(data);
	if (keycode == K_S)
		move_back(data);
	if (keycode == K_A)
		move_lateral_left(data);
	if (keycode == K_D)
		move_lateral_right(data);
	if (keycode == K_AR_L || keycode == K_Q)
		move_right(data);
	if (keycode == K_AR_R || keycode == K_E)
		move_left(data);
	if (keycode == K_M)
		data->activateMinimap *= -1;
	if (keycode == K_P)
		data->activate_mouse *= -1;
	return (0);
}
