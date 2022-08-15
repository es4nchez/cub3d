#include <unistd.h>
#include <fcntl.h>
#include "../inc/cub3d.h"

char	*get_next_line(int fd);

#define SUCCESS 1
#define ERROR 0

typedef struct s_infos {
	char	*no;
	char	*so;
	char	*we;
	char	*ea;

	char	*f;
	char	*c;

	int		map_width;
	int		map_height;

	int		x;
	int		y;
	int		ori;
}	t_infos;

int	concat_tab(char ***tab, char *newstr)
{
	char	**newtab;
	int		len;

	len = 0;
	while (*tab != NULL && (*tab)[len] != NULL)
		len++;

	newtab = malloc(sizeof(char *) * (len + 2));
	if (newtab == NULL)
		return (ERROR);

	len = 0;
	while (*tab != NULL && (*tab)[len] != NULL)
	{
		newtab[len] = (*tab)[len];
		len++;
	}
	newtab[len] = newstr;
	newtab[len + 1] = NULL;

	if (*tab != NULL)
		free(*tab);

	*tab = newtab;
	return (SUCCESS);
}

int	tab_len(char **tab)
{
	int	len;

	len = 0;
	while (tab != NULL && tab[len] != NULL)
		len++;
	return (len);
}

int	free_tab(char **tab)
{
	int	len;

	len = 0;
	while (tab != NULL && tab[len] != NULL)
	{
		free(tab[len]);
		len++;
	}
	free(tab);
	return (SUCCESS);
}

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

	else if (ft_strncmp(splitted[0], "F", 3) == 0 && data->f == NULL)
		data->f = ft_strdup(splitted[1]);
	else if (ft_strncmp(splitted[0], "C", 3) == 0 && data->c == NULL)
		data->c = ft_strdup(splitted[1]);
	else
		return (0);
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
		if (nbinfos < 6)
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

void	remove_gnl_endline(char *str)
{
	char	*tmp;

	tmp = ft_strchr(str, '\n');
	if (tmp != NULL)
		*tmp = '\0';
}

void	init_player_pos(t_data *data, int x, int y, char *ori)
{
	data->pPosX = x + 0.5;
	data->pPosY = y + 0.5;
	if (*ori == 'N')
		data->pDir = 0;
	if (*ori == 'S')
		data->pDir = 1;
	if (*ori == 'W')
		data->pDir = 2;
	if (*ori == 'E')
		data->pDir = 3;

	*ori = '0';
}

int	check_around(t_data *data, char **raw, int x, int y)
{
	if (x <= 0 || x >= (int)ft_strlen(raw[y]) - 1)
		return (ERROR);

	if (y <= 0 || y >= data->mapHeight)
		return (ERROR);

	if (raw[y][x - 1] == ' ' || raw[y][x + 1] == ' ')
		return (ERROR);

	if (x >= (int)ft_strlen(raw[y - 1]) || raw[y - 1][x] == ' ')
		return (ERROR);
	if (x >= (int)ft_strlen(raw[y + 1]) || raw[y + 1][x] == ' ')
		return (ERROR);

	return (SUCCESS);
}

int	check_map(char **raw, t_data *data)
{
	int	len;
	int	i;

	data->mapWidth = 0;
	len = 0;
	while (raw != NULL && raw[len] != NULL)
	{
		i = 0;

		remove_gnl_endline(raw[len]);
		if ((int)ft_strlen(raw[len]) > data->mapWidth)
			data->mapWidth = (int)ft_strlen(raw[len]);

		while (i < (int)ft_strlen(raw[len]))
		{
			if (ft_strchr("NSWE", raw[len][i]) != NULL && data->pPosX == -1)
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
	data->map = malloc(sizeof(int *) * data->mapHeight);
	if (data->map == NULL)
		return (ERROR);
	while (i < data->mapHeight)
	{
		data->map[i] = malloc(sizeof(int) * data->mapWidth);
		if (data->map[i] == NULL)
			return (ERROR);
		j = 0;
		while (j < data->mapWidth)
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

	printf("no %s\n", data->no);
	printf("so %s\n", data->so);
	printf("we %s\n", data->we);
	printf("ea %s\n", data->ea);
	printf("f %s\n", data->f);
	printf("c %s\n", data->c);
	i = 0;
	while (i < data->mapHeight)
	{
		j = 0;
		while (j < data->mapWidth)
		{
			printf("%d", data->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	read_map(t_data *data, char *filename)
{
	char	**raw;
	int		fd;
//	t_infos	infos;

	raw = NULL;
//	ft_memset(&infos, 0, sizeof(t_infos));
	data->pPosX = -1;

	fd = open_filename(filename);

	if (fd == -1)
		return (ERROR);

	if (!search_args(data, fd))
		return (ERROR);

	if (!search_map(&raw, fd))
		return (ERROR);

	close(fd);

	data->mapHeight = tab_len(raw);

	if (!check_map(raw, data))
		return (ERROR);

	if (!convert_map(raw, data))
		return (ERROR);

	display_infos(data);

	return (SUCCESS);
}
