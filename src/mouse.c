#include "../inc/cub3d.h"

int	mouse(int x, int y, t_data *data)
{
	float		mrsp;
	float	oldDirX;
	float	oldDirY;
	float	oldPlaneX;

	(void)y;
	
	if (data->activate_mouse == 1)
	{
		mrsp = ((float)(x - WIN_W / 2)) / 200.0;
		oldDirX = data->pDirX;
		oldDirY = data->pDirY;
		oldPlaneX = data->planeX;
		printf("here %f\n", mrsp);

		data->pDirX = data->pDirX * cos(mrsp) - data->pDirY * sin(mrsp);
		data->pDirY = oldDirX * sin(mrsp) + data->pDirY * cos(mrsp);
		data->planeX = data->planeX * cos(mrsp) - data->planeY * sin(mrsp);
		data->planeY = oldPlaneX * sin(mrsp) + data->planeY * cos(mrsp);
		mlx_mouse_move(data->win, (int)(WIN_W / 2), (int)(WIN_H / 2));
		mlx_mouse_hide(data->win);
	}
	else
		mlx_mouse_show(data->win);
	return (0);
}