/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maputils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:32:35 by esanchez          #+#    #+#             */
/*   Updated: 2022/08/25 22:32:38 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_selftrim(char **s1, const char *set)
{
	char	*trimmed;

	trimmed = ft_strtrim(*s1, set);
	free(*s1);
	if (trimmed == NULL)
		return (ERROR);
	*s1 = trimmed;
	return (SUCCESS);
}

int	search_map(char ***raw, int fd)
{
	char	*tmp;

	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		if (!concat_tab(raw, tmp))
		{
			free(tmp);
			free_tab(*raw);
			return (ERROR);
		}
		tmp = get_next_line(fd);
	}
	return (SUCCESS);
}

int	check_map(char **raw, t_data *data)
{
	int	len;
	int	i;

	data->mapwidth = 0;
	len = 0;
	while (raw != NULL && raw[len] != NULL)
	{
		i = 0;
		remove_gnl_endline(raw[len]);
		if ((int)ft_strlen(raw[len]) > data->mapwidth)
			data->mapwidth = (int)ft_strlen(raw[len]);
		while (i < (int)ft_strlen(raw[len]))
		{
			if (ft_strchr("NSWE", raw[len][i]) != NULL && data->pposx == -1)
				init_player_pos(data, i, len, &raw[len][i]);
			else if (raw[len][i] == '0' && !check_around(data, raw, i, len))
				return (ERROR);
			else if (ft_strchr(" 01", raw[len][i]) == NULL)
				return (ERROR);
			i++;
		}
		len++;
	}
	return (SUCCESS);
}

int	convert_map(char **raw, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->map = malloc(sizeof(int *) * data->mapheight);
	if (data->map == NULL)
		return (ERROR);
	while (i < data->mapheight)
	{
		data->map[i] = malloc(sizeof(int) * data->mapwidth);
		if (data->map[i] == NULL)
			return (ERROR);
		j = 0;
		while (j < data->mapwidth)
		{
			data->map[i][j] = 1;
			if (j < (int)ft_strlen(raw[i]) && raw[i][j] == '0')
				data->map[i][j] = 0;
			j++;
		}
		i++;
	}
	free_tab(raw);
	return (SUCCESS);
}

void	display_infos(t_data *data)
{
	int	i;
	int	j;

	printf("f %d %d %d %d\n", (data->f & 0xFF000000)
		>> 24, (data->f & 0x00FF0000)
		>> 16, (data->f & 0x0000FF00)
		>> 8, (data->f & 0x000000FF));
	printf("c %d %d %d %d\n", (data->c & 0xFF000000)
		>> 24, (data->c & 0x00FF0000)
		>> 16, (data->c & 0x0000FF00)
		>> 8, (data->c & 0x000000FF));
	i = 0;
	while (i < data->mapheight)
	{
		j = 0;
		while (j < data->mapwidth)
		{
			printf("%d", data->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
