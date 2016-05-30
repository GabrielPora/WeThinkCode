#include "ft_fdf.h"
#include <fcntl.h>

int		my_key_funct(int keycode, void *param)
{
	ft_putendl(ft_itoa(keycode));
	if (keycode == 53)
		exit(0);
    if (keycode == 0)//A  left rotation
        f4(keycode, 0, param);
    if (keycode == 2)//D  right rotation
        f4(keycode, 0, param);
    if (keycode == 123)//l
        f4(keycode, 0, param);
    if (keycode == 124)//r
        f4(keycode, 0, param);
    if (keycode == 126)//u
        f4(keycode, 0, param);
    if (keycode == 125)//d
        f4(keycode, 0, param);
    if (keycode == 8)
		mlx_clear_window(0, param);
	return (0);
}

void    f2(int *v, int fd, char *l, void *win, void *mlx)
{
    char    **av;
    int     x;
    int     y;
    
        while (get_next_line(fd, &l) && (v[2] = -1))
        {
            //printf("%s\n", l);
            av = ft_strsplit(l, ' ');
            ++v[1];
            while (av[++v[2]])
            {
                v[0] = ft_atoi(av[v[2]]);
                f1(v, win, mlx);
            //    printf("%d", v[0]);
            }
          //  printf("\n");
        }
        close(fd);
}

int		main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	int		fd;
	int     v[6];
	char	*l;

    v[1] = -1;
    v[4] = -1;
	mlx = mlx_init();
	win = mlx_new_window(mlx, X, Y, "ft_fdf");
    if (ac > 1 && (fd = open(av[1], O_RDONLY)))
        f2(v, fd, l, win, mlx);
    v[5] = 1;
    f4(-1, v, 0);
    mlx_key_hook(win, my_key_funct, win);
    mlx_loop(mlx);
	return (0);
}
