/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 07:41:23 by smahomed          #+#    #+#             */
/*   Updated: 2016/05/28 08:55:20 by smahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void    f4(int k, int *v, void *param)
{
    static int  *n;
    int         x;

    if (k != -1)
        mlx_clear_window(0, param);
    if ((x = -1) && k == -1)
        n = v;
    while (k == 0 && (++x <= n[4]))
    {
        a_[x].a = a_[x].a - 5;
        f3(20, x, param, 0);
    }
    while (k == 2 && (++x <= n[4]))
    {
        a_[x].a = a_[x].a + 5;
        f3(20, x, param, 0);
    }
    while (k == 123 && (++x <= n[4]))
    {
        a_[x].hzx -= 0.1;
        f3(20, x, param, 0);
    }
    while (k == 124 && (++x <= n[4]))
    {
        a_[x].hzx += 0.1;
        f3(20, x, param, 0);
    }
    while (k == 126 && (++x <= n[4]))
    {
        a_[x].vzy -= 0.1;
        f3(20, x, param, 0);
    }
    while (k == 125 && (++x <= n[4]))
    {
        a_[x].vzy += 0.1;
        f3(20, x, param, 0);
    }

}

void     f3(int s, int p, void *win, void *mlx)
{
    float   r;
    float   x1;
    float   y1;
    
    r = sqrt(a_[p].x * a_[p].x + a_[p].y * a_[p].y);
    x1 = r * cos(a_[p].a * M_PI / 180) * s * a_[p].hzx;// + j
    y1 = (r * sin(a_[p].a * M_PI / 180) - a_[p].z) * s * a_[p].vzy;// + k
    mlx_pixel_put(0, win, X / 2 + x1, Y / 2 + y1, 0x00FFFFFF);//to add colour
}

void	f1(int *v, void *win, void *mlx)/* init */
{    float   r;
    int      p;
    float    s;

    s = 10;
    a_[++v[4]].x = v[2];
    a_[v[4]].y = v[1];
    a_[v[4]].z = v[0];
    a_[v[4]].hzx = 1.0;/* vertical rotation */
    a_[v[4]].vzy = 1.0;/* horizontal rotation */
    a_[v[4]].a = (atan(a_[v[4]].y / a_[v[4]].x)  * (180 / M_PI)) + 45;//init angle
    p = v[4];
//    r = sqrt(a_[p].x * a_[p].x + a_[p].y * a_[p].y);
   // a_[p].x = r * cos(a_[p].a * M_PI / 180) * s * a_[p].hzx;// + j
   // a_[p].y = (r * sin(a_[p].a * M_PI / 180) - a_[p].z) * s * a_[p].vzy;// + k
    //mlx_pixel_put(0, win, X / 2 + a_[p].x * 10, Y / 2 + (a_[p].y + v[0]) * 10, 0x00FFFFFF);
    //f3(10, v[4], win, mlx);
}
