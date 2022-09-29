/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:08:39 by esanchez          #+#    #+#             */
/*   Updated: 2022/08/25 22:08:43 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "../inc/cub3d.h"

char	*get_next_line(int fd);

int	fill_color(int *output, char *colors)
{
	char	**ints;
	int		color;

	ints = ft_split(colors, ',');
	if (ints == NULL)
		return (ERROR);
	if (tab_len(ints) != 3)
		return (free_tab(ints) * ERROR);
	*output = 0;
	color = ft_atoi(ints[0]);
	if (color < 0 || color >= 256)
		return (free_tab(ints) * ERROR);
	*output = (*output << 8) | color;
	color = ft_atoi(ints[1]);
	if (color < 0 || color >= 256)
		return (free_tab(ints) * ERROR);
	*output = (*output << 8) | color;
	color = ft_atoi(ints[2]);
	if (color < 0 || color >= 256)
		return (free_tab(ints) * ERROR);
	*output = (*output << 8) | color;
	free_tab(ints);
	return (SUCCESS);
}

void	remove_gnl_endline(char *str)
{
	char	*tmp;

	tmp = ft_strchr(str, '\n');
	if (tmp != NULL)
		*tmp = '\0';
}

void	init_player_pos(t_data *data, int x, int y, char *ori)
{
	data->pposx = x + 0.5;
	data->pposy = y + 0.5;
	if (*ori == 'N')
		data->pdir = 'N';
	if (*ori == 'S')
		data->pdir = 'S';
	if (*ori == 'W')
		data->pdir = 'W';
	if (*ori == 'E')
		data->pdir = 'E';
	*ori = '0';
}

int	check_around(t_data *data, char **raw, int x, int y)
{
	if (x <= 0 || x >= (int)ft_strlen(raw[y]) - 1)
		return (ERROR);
	if (y <= 0 || y >= data->mapheight)
		return (ERROR);
	if (raw[y][x - 1] == ' ' || raw[y][x + 1] == ' ')
		return (ERROR);
	if (x >= (int)ft_strlen(raw[y - 1]) || raw[y - 1][x] == ' ')
		return (ERROR);
	if (x >= (int)ft_strlen(raw[y + 1]) || raw[y + 1][x] == ' ')
		return (ERROR);
	return (SUCCESS);
}

int	read_map(t_data *data, char *filename)
{
	char	**raw;
	int		fd;

	raw = NULL;
	data->pposx = -1;
	fd = open_filename(filename);
	if (fd == -1)
		return (ERROR);
	if (!search_args(data, fd))
		return (ERROR);
	if (!search_map(&raw, fd))
		return (ERROR);
	close(fd);
	data->mapheight = tab_len(raw);
	if (!check_map(raw, data))
		return (ERROR);
	if (!convert_map(raw, data))
		return (ERROR);
	return (SUCCESS);
}
