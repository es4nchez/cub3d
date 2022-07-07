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

int	gameplay(int keycode, t_data *data)
{
	(void)data;

	if (keycode == 53)
		exit_game(data);
	raycasting(data);

	return (0);
}
