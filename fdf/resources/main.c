# include <stdio.h>
# include "mlx.h"

int	my_key_funct(int keycode, void *mlx)
{
	printf("Key event %d\n", keycode);
	//mlx_pixel_put(mlx, win, 300, 300, 0xFF00FF);
	return (0);
}

int my_mouse_funct(int mousecode, void *mlx)
{
	printf("Mouse event %d\n", mousecode);
	//mlx_pixel_put(mlx, win, 300, 300, 0x0000FF);
	return (0);
}

int main()
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	y = 50;
	while (y < 150)
	{
		x = 50;
		while (x < 150)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	mlx_key_hook(win, *my_key_funct, mlx);
	mlx_mouse_hook(win, *my_mouse_funct, mlx);
	mlx_loop(mlx);
}
