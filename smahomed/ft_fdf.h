#ifndef FDF_H
# define FDF_H
# define X 800
# define Y 800
# include "mlx.h"
# include <math.h>
# include "mlx.h"
# include "get_next_line.h"
# include "libft.h"


typedef struct	s_2
{
	float		x;
	float		y;
	float		z;
	struct s_2	*n;
}				t_2;
typedef struct
{
    float       x;
    float       y;
    float       z;
    float       vzy;
    float       hzx;
    float       s;/* scale*/
    float       a;/* alpha   angle of x, y rotation*/
    float       b;/* beta angle of zx zy vertical rotation */
    float       t;/* theta angle of horizontal rotation */
    int         n;/* active node? */
}               t_node;
typedef struct
{
    float       x;
    float       y;
    float       r;
    float       vzy;
    float       hzx;
    float       pi;
}               t_math;

t_node          a_[X * Y];

void	f1(int *v, void *win, void *mlx);
void     f3(int s, int p, void *win, void *mlx);
void    f4(int k, int *v, void *param);
#endif
