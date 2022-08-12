/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanchez <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 04:19:48 by esanchez          #+#    #+#             */
/*   Updated: 2022/07/06 04:19:52 by esanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include <limits.h>
# include <stdint.h>
# include <stdbool.h>
# include <string.h>
# include <math.h>

#define WIN_W 5120 / 4
#define WIN_H 2880 / 4

#define SPD	0.05
#define SMP 10

#define RED 0x00FF0000
#define WHT 0x00FFFFFF
#define	GRN 0x0000FF00
#define BLU 0x000000FF

typedef struct s_imgptr {
	char	*path;
	void	*img;
	int		w;
	int		h;

	int		*pxs;
	int		bits;
	int		line;
	int		end;
}	t_imgptr;

typedef struct s_img {
	void	*img_name;
	char	*img_path;
	int		img_width;
	int		img_height;
}				t_img;


typedef struct s_line {
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	float	i;
	float dx;
	float dy;
	float step;
	float xin;
	float yin;
}				t_line;

typedef struct s_map {
	int	x;
	int	y;
	int	h;
}				t_map;

typedef struct s_data {
	void		*mlx;
	void		*win;
	int			j;
	char		*buff;
	int			**map;
	t_line		line;
	t_imgptr	*img;
	double		mapWidth;
	double		mapHeight;
	float		pPosX;
	float		pPosY;
	int			pDir;
	float		planeX;
	float		planeY;
	float		dirX;
	float		dirY;
	float		speed;
	int			minimapSize;

}				t_data;

// Project functions
void	load_map(t_data *data, char *s);
void	get_pos(t_data *data);
void	create_intmap(t_data *data);
void	init_game(t_data *data, char *mapPath);
int		gameplay(int keycode, t_data *data);
int		raycasting(t_data *data);
void	rendering(t_data *data);
void	dda(t_data *data);
int		exit_game(t_data *data);
void	ft_mlx_pixel_put(t_imgptr *img, int x, int y, int color);
int		draw_line(t_data *data);
int		draw_vert(t_data *data, float x, float y, float h);
int		minimap(t_data *data);

// Utils function
int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);

#endif
