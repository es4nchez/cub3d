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

#define WIN_W 1980
#define WIN_H 1200

typedef struct s_img {
	void	*img_name;
	char	*img_path;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct s_rc {
	int		mapX;
	int		mapY;
	int		stepX;
	int		stepY;
	int		hit;
	int		side; //was a NS or a EW wall hit?
	double	posX;
	double	posY;	// x and y start position
	double	dirX;	// = -1;
	double	dirY;	// = 0; // initial direction vector
	double	planeX;	// = 0,
	double	planeY;	// = 0.66; // the 2d raycaster version of camera plane
	double	time;	// = 0; // time of current frame
	double	oldTime;	// = 0; // time of previous frame
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	double	sideDistX;  //length of ray from current position to next x or y-side
	double	sideDistY;

}				t_rc;

typedef struct s_data {
	void	*mlx;
	void	*win;
	char	*map;
	char	*buff;
	t_rc	rc;
	double		mapWidth;
	double		mapHeight;


}				t_data;

void	load_map(t_data *data, char *s);
void	create_map(t_data *data);
void	init_game(t_data *data);
int		gameplay(int keycode, t_data *data);
void	raycasting(t_data *data);
int		exit_game(t_data *data);
#endif
