/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:18:53 by esanchez          #+#    #+#             */
/*   Updated: 2022/08/25 22:18:55 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	fill_arg(t_data *data, char **splitted)
{
	if (ft_strncmp(splitted[0], "NO", 3) == 0 && data->no == NULL)
		data->no = ft_strdup(splitted[1]);
	else if (ft_strncmp(splitted[0], "SO", 3) == 0 && data->so == NULL)
		data->so = ft_strdup(splitted[1]);
	else if (ft_strncmp(splitted[0], "WE", 3) == 0 && data->we == NULL)
		data->we = ft_strdup(splitted[1]);
	else if (ft_strncmp(splitted[0], "EA", 3) == 0 && data->ea == NULL)
		data->ea = ft_strdup(splitted[1]);
	else if (ft_strncmp(splitted[0], "F", 2) == 0 && data->f == -1)
	{
		if (!fill_color(&data->f, splitted[1]))
			return (-10);
	}
	else if (ft_strncmp(splitted[0], "C", 2) == 0 && data->c == -1)
	{
		if (!fill_color(&data->c, splitted[1]))
			return (-10);
	}
	else
		return (-10);
	return (1);
}

int	manage_arg_line(t_data *data, char *tmp)
{
	char	**splitted;
	int		got_info;

	got_info = 0;
	splitted = ft_split(tmp, ' ');
	if (splitted == NULL)
		return (ERROR);
	if (tab_len(splitted) == 2)
	{
		if (!ft_selftrim(&splitted[0], " \t\n\r\f\v")
			|| !ft_selftrim(&splitted[1], " \t\n\r\f\v"))
			return (ERROR);
		got_info = fill_arg(data, splitted);
	}
	free_tab(splitted);
	return (got_info);
}

int	search_args(t_data *data, int fd)
{
	char	*tmp;
	int		nbinfos;

	nbinfos = 0;
	tmp = get_next_line(fd);
	while (tmp != NULL && nbinfos < 6)
	{
		if (!ft_selftrim(&tmp, " \t\n\r\f\v"))
			return (ERROR);
		nbinfos += manage_arg_line(data, tmp);
		free(tmp);
		if (nbinfos < 6 && nbinfos >= 0)
			tmp = get_next_line(fd);
		else
			tmp = NULL;
	}
	if (nbinfos < 6)
		return (ERROR);
	return (SUCCESS);
}

int	open_filename(char *filename)
{
	int	fd;

	if (filename == NULL || ft_strlen(filename) < 4)
		return (-1);
	if (ft_strncmp(&filename[ft_strlen(filename) - 4], ".cub", 5) != 0)
		return (-1);
	fd = open(filename, O_RDONLY);
	return (fd);
}
