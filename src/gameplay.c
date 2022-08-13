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
//	printf("key press : %d\n", keycode);
	if (keycode == 53)
		exit_game(data);
	if (keycode == 13)
		move_front(data);
	if (keycode == 1)
		move_back(data);
	if (keycode == 0)
		move_lateral_left(data);
	if (keycode == 2)
		move_lateral_right(data);
	if (keycode == 123)
		move_right(data);
	if (keycode == 124)
		move_left(data);
	if (keycode == 46)
		data->activateMinimap *= -1;
//	printf("Player pos : %f - %f  dir : %d | dirx : %f diry : %f\n", data->pPosX, data->pPosY, data->pDir, data->pDirX, data->pDirY);
	return (0);
}
