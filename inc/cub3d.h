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
# include <stddef.h>
# include <sys/time.h>

# include "../libft/libft.h"
# include "../inc/key_macos.h"

# define SUCCESS 1
# define ERROR 0

//# define WIN_W (1280 * 2)
# define WIN_W 1920
//# define WIN_H (720 * 2)
# define WIN_H 1080

# define SPD 0.1
# define SMP 5

# define RSP 0.05

# define RED 0x00FF0000
# define BLK 0x00999999
# define WHT 0x00FFFFFF
# define GRN 0x0000FF00
# define BLU 0x000000FF
# define GRY 0X00999896
# define DRY 0X006e6d6d
# define WOD 0X00202020
# define BRC 0X007d4131

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

typedef struct s_map {
	int	x;
	int	y;
	int	h;
}				t_map;

typedef struct s_raycasting {
	int		hit;
	int		side;
	int		mapx;
	int		mapy;
	int		step_x;
	int		step_y;
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	w;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	double	wallx;
	int		texwidth;
	int		texx;
	int		texy;
	double	texpos;
	int		lineheight;
	int		texheight;
	int		drawstart;
	int		drawend;
}				t_raycasting;

typedef struct s_frame {
	int		frame;
	int		frame_now;
	size_t	starttime;
	size_t	timestamp;
}				t_frame;

typedef struct s_data {
	void		*mlx;
	void		*win;
	int			**map;
	t_frame		*fps;
	t_imgptr	*img;
	double		mapwidth;
	double		mapheight;
	int			horizon;
	float		pposx;
	float		pposy;
	float		pdirx;
	float		pdiry;
	char		pdir;
	float		planex;
	float		planey;
	int			activate_minimap;
	int			activate_mouse;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			f;
	int			c;
	t_imgptr	*n_addr;
	t_imgptr	*s_addr;
	t_imgptr	*w_addr;
	t_imgptr	*e_addr;
}				t_data;

// Project functions
int		load_map(t_data *data, char *s);
void	get_pos(t_data *data);
void	create_intmap(t_data *data);
int		init_game(t_data *data);
int		gameplay(int keycode, t_data *data);
int		displayer(t_data *data);
void	rendering(t_data *data);
void	dda(t_data *data, t_raycasting *rc);
int		exit_game(t_data *data);
void	ft_mlx_pixel_put(t_imgptr *img, int x, int y, int color);
int		draw_line(t_data *data);
int		draw_vert(t_data *data, t_raycasting *rc, int x);
int		minimap(t_data *data);
int		calculate_distance(t_data *data, t_raycasting *rc);
void	projected_distance(t_raycasting *rc);
int		mouse_hook(int keycode, int x, int y, t_data *data);
int		mouse_move(t_data *data);
int		mouse(int x, int y, t_data *data);
int		load_assets(t_data *data);
int		texture_rendering(t_data *data, t_raycasting *rc);
int		texturing(t_data *data, t_raycasting *rc, int x);
int		fill_color(int *output, char *color);
int		free_tab(char **tab);
int		ft_selftrim(char **s1, const char *set);
int		tab_len(char **tab);
int		search_args(t_data *data, int fd);
int		open_filename(char *filename);
int		move_start(t_data *data, float dist);

// Utils function
int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);
int		concat_tab(char ***tab, char *newstr);
char	*get_next_line(int fd);
void	remove_gnl_endline(char *str);
void	init_player_pos(t_data *data, int x, int y, char *ori);
int		check_around(t_data *data, char **raw, int x, int y);
int		search_map(char ***raw, int fd);
int		check_map(char **raw, t_data *data);
int		convert_map(char **raw, t_data *data);
void	display_infos(t_data *data);
int		trgb(int t, int r, int g, int b);
size_t	time_now(void);
void	fps(t_data *data);

#endif
